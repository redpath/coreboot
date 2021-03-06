/*
 * This file is part of the coreboot project.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <console/console.h>
#include <device/device.h>
#include <device/pci.h>
#include <device/pci_ops.h>

static void si_sata_init(struct device *dev)
{
	uint32_t dword;
	/* enable change device id and class id */
	dword = pci_read_config32(dev,0x40);
	dword |= (1<<0);
	pci_write_config32(dev, 0x40, dword);
	/* Set IDE Class, Native mode, two drives per channel */
	dword = 0x01018f00;
	pci_write_config32(dev, 0x08, dword);
	/* disable change device id and class id*/
	dword = pci_read_config32(dev,0x40);
	dword &= ~(1<<0);
	pci_write_config32(dev, 0x40, dword);
	printk(BIOS_INFO, "SIL3114 set to IDE compatible mode\n");
}

static struct device_operations si_sata_ops  = {
	.read_resources   = pci_dev_read_resources,
	.set_resources    = pci_dev_set_resources,
	.enable_resources = pci_dev_enable_resources,
	.init             = si_sata_init,
	.scan_bus         = 0,
};

static const struct pci_driver si_sata_driver __pci_driver = {
	.ops    = &si_sata_ops,
	.vendor = 0x1095,
	.device = 0x3114,
};

static const struct pci_driver si_sata_driver_2 __pci_driver = {
	.ops    = &si_sata_ops,
	.vendor = 0x1095,
	.device = 0x0680,
};
