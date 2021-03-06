/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2019-2020 Intel Corporation.
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

/*
 * This file is created based on Intel Tiger Lake Firmware Architecture Specification
 * Document number: 608531
 * Chapter number: 4
 */

#ifndef _SOC_TIGERLAKE_IOMAP_H_
#define _SOC_TIGERLAKE_IOMAP_H_

/*
 * Memory-mapped I/O registers.
 */
#define MCFG_BASE_ADDRESS	CONFIG_MMCONF_BASE_ADDRESS
#define MCFG_BASE_SIZE		0x4000000

#define PCH_PRESERVED_BASE_ADDRESS	0xfc800000
#define PCH_PRESERVED_BASE_SIZE	0x02000000

#define PCH_TRACE_HUB_BASE_ADDRESS	0xfc800000
#define PCH_TRACE_HUB_BASE_SIZE	0x00800000

#define UART_BASE_SIZE		0x1000

#define UART_BASE_0_ADDRESS	0xfe03e000
/* Both UART BAR 0 and 1 are 4KB in size */
#define UART_BASE_0_ADDR(x)	(UART_BASE_0_ADDRESS + (2 * \
					UART_BASE_SIZE * (x)))
#define UART_BASE(x)		UART_BASE_0_ADDR(x)

#define DMI_BASE_ADDRESS	0xfeda0000
#define DMI_BASE_SIZE		0x1000

#define EP_BASE_ADDRESS		0xfeda1000
#define EP_BASE_SIZE		0x1000

#define EDRAM_BASE_ADDRESS	0xfed80000
#define EDRAM_BASE_SIZE		0x4000

#define REG_BASE_ADDRESS	0xfb000000
#define REG_BASE_SIZE		0x1000

#define HPET_BASE_ADDRESS	0xfed00000

#define PCH_PWRM_BASE_ADDRESS	0xfe000000
#define PCH_PWRM_BASE_SIZE	0x10000

#define SPI_BASE_ADDRESS	0xfe010000

#define GPIO_BASE_SIZE		0x10000

#define HECI1_BASE_ADDRESS	0xfeda2000

#define VTD_BASE_ADDRESS	0xfed90000
#define VTD_BASE_SIZE		0x00004000

#define ABOVE_4GB_MEM_BASE_ADDRESS	(256ULL * GiB)
#define ABOVE_4GB_MEM_BASE_SIZE	(256ULL * GiB)

#if CONFIG(SOC_INTEL_TIGERLAKE)

#define MCH_BASE_ADDRESS	0xfedc0000
#define MCH_BASE_SIZE		0x20000

#define EARLY_GSPI_BASE_ADDRESS 0xfe030000

#define EARLY_I2C_BASE_ADDRESS	0xfe020000
#define EARLY_I2C_BASE(x)	(EARLY_I2C_BASE_ADDRESS + (0x2000 * (x)))

#else /* CONFIG_SOC_INTEL_JASPERLAKE */

#define MCH_BASE_ADDRESS	0xfea80000
#define MCH_BASE_SIZE		0x8000

#define EARLY_GSPI_BASE_ADDRESS	0xfe011000

#define EARLY_I2C_BASE_ADDRESS	0xfe040000
#define EARLY_I2C_BASE(x)	(EARLY_I2C_BASE_ADDRESS + (0x1000 * (x)))

#endif

/*
 * I/O port address space
 */
#define SMBUS_BASE_ADDRESS	0x0efa0
#define SMBUS_BASE_SIZE		0x20

#define ACPI_BASE_ADDRESS	0x1800
#define ACPI_BASE_SIZE		0x100

#define TCO_BASE_ADDRESS	0x400
#define TCO_BASE_SIZE		0x20

#define P2SB_BAR		CONFIG_PCR_BASE_ADDRESS
#define P2SB_SIZE		(16 * MiB)

#endif
