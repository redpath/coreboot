/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2015 Intel Corp.
 * (Written by Andrey Petrov <andrey.petrov@intel.com> for Intel Corp.)
 * (Written by Alexandru Gagniuc <alexandrux.gagniuc@intel.com> for Intel Corp.)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <boot_device.h>
#include <cbfs.h>
#include <commonlib/region.h>
#include <console/console.h>
#include <fmap.h>
#include <intelblocks/fast_spi.h>

/*
 * BIOS region on the flash is mapped right below 4GiB in the address
 * space. However, 256KiB right below 4GiB is decoded by read-only SRAM and not
 * boot media.
 *
 *                                                +-----------+ 0
 *                                                |           |
 *                                                |           |
 *                                                |           |
 *                                                |           |
 *                                                |           |
 *                                                |           |
 *                                                |           |
 *                                                |           |
 *                  +--------+                    |           |
 *                  |  IFD   |                    |           |
 * bios_start +---> +--------+------------------> +-----------+ 4GiB - bios_size
 *     ^            |        |          ^         |           |
 *     |            |        |          |         |           |
 *     |            |        |  bios_mapped_size  |    BIOS   |
 *     |            |  BIOS  |          |         |           |
 * bios_size        |        |          |         |           |
 *     |            |        |          v         |           |
 *     |            |        +------------------> +-----------+ 4GiB - 256KiB
 *     |            |        |                    | Read only |
 *     v            |        |                    |    SRAM   |
 * bios_end   +---> +--------+                    +-----------+ 4GiB
 *                  | Device |
 *                  |   ext  |
 *                  +--------+
 *
 */

static size_t bios_size;

static struct mem_region_device shadow_dev;
static struct xlate_region_device real_dev;

static void bios_mmap_init(void)
{
	size_t size, start, bios_mapped_size;
	uintptr_t base;

	size = bios_size;

	/* If bios_size is initialized, then bail out. */
	if (size != 0)
		return;
	start = fast_spi_get_bios_region(&size);

	/* BIOS region is mapped right below 4G. */
	base = 4ULL * GiB - size;

	/*
	 * The 256 KiB right below 4G are decoded by readonly SRAM,
	 * not boot media.
	 */
	bios_mapped_size = size - 256 * KiB;

	mem_region_device_ro_init(&shadow_dev, (void *)base,
			       bios_mapped_size);

	xlate_region_device_ro_init(&real_dev, &shadow_dev.rdev,
				 start, bios_mapped_size,
				 CONFIG_ROM_SIZE);

	bios_size = size;

	/* Check that the CBFS lies within the memory mapped area. It's too
	   easy to forget the SRAM mapping when crafting an FMAP file. */
	struct region cbfs_region;
	if (!fmap_locate_area("COREBOOT", &cbfs_region) &&
	    !region_is_subregion(&real_dev.sub_region, &cbfs_region))
		printk(BIOS_CRIT,
		       "ERROR: CBFS @ %zx size %zx exceeds mem-mapped area @ %zx size %zx\n",
		       region_offset(&cbfs_region), region_sz(&cbfs_region),
		       start, bios_mapped_size);
}

const struct region_device *boot_device_ro(void)
{
	bios_mmap_init();

	return &real_dev.rdev;
}
