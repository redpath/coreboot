/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2018 Intel Corporation.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
 * GNU General Public License for more details.
 */

#ifndef _GPIO_X11SSM_F_H
#define _GPIO_X11SSM_F_H

#include <soc/gpe.h>
#include <soc/gpio.h>

static const struct pad_config gpio_table[] = {
	/* GPIO Group GPP_A */
	_PAD_CFG_STRUCT(GPP_A0,  0x44000700, 0x00000010), /* RCIN# */
	_PAD_CFG_STRUCT(GPP_A1,  0x44000700, 0x00000010), /* LAD0 */
	_PAD_CFG_STRUCT(GPP_A2,  0x44000700, 0x00000010), /* LAD1 */
	_PAD_CFG_STRUCT(GPP_A3,  0x44000700, 0x00000010), /* LAD2 */
	_PAD_CFG_STRUCT(GPP_A4,  0x44000700, 0x00000010), /* LAD3 */
	_PAD_CFG_STRUCT(GPP_A5,  0x44000700, 0x00000010), /* LFRAME# */
	_PAD_CFG_STRUCT(GPP_A6,  0x44000700, 0x00000010), /* SERIRQ */
	_PAD_CFG_STRUCT(GPP_A7,  0x44000700, 0x00000010), /* PIRQA# */
	_PAD_CFG_STRUCT(GPP_A8,  0x44000700, 0x00000010), /* CLKRUN# */
	_PAD_CFG_STRUCT(GPP_A9,  0x44000700, 0x00000010), /* CLKOUT_LPC0 */
	_PAD_CFG_STRUCT(GPP_A10, 0x44000700, 0x00000010), /* CLKOUT_LPC1 */
	_PAD_CFG_STRUCT(GPP_A11, 0x44000700, 0x00000010), /* PME# */
	_PAD_CFG_STRUCT(GPP_A12, 0x84000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_A13, 0x44000700, 0x00000010), /* SUSWARN#/SUSPWRDNACK */
	_PAD_CFG_STRUCT(GPP_A14, 0x44000700, 0x00000010), /* SUS_STAT# */
	_PAD_CFG_STRUCT(GPP_A15, 0x44000700, 0x00000010), /* SUS_ACK# */
	_PAD_CFG_STRUCT(GPP_A16, 0x44000700, 0x00000010), /* CLKOUT_48 */
	_PAD_CFG_STRUCT(GPP_A17, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_A18, 0x84000100, 0x00000010), /* GPIO */
	/* reserved */
	//_PAD_CFG_STRUCT(GPP_A19, 0xffffffff, 0xffffffff), /* ISH_GP1 */
	_PAD_CFG_STRUCT(GPP_A20, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_A21, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_A22, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_A23, 0x44000300, 0x00000010), /* GPIO */

	/* GPIO Group GPP_B */
	_PAD_CFG_STRUCT(GPP_B0,  0x44000201, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_B1,  0x44000201, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_B2,  0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_B3,  0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_B4,  0x44000301, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_B5,  0x44000301, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_B6,  0x84000301, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_B7,  0x44000301, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_B8,  0x44000301, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_B9,  0x44000301, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_B10, 0x44000301, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_B11, 0x44000200, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_B12, 0x44000700, 0x00000010), /* SLP_S0# */
	_PAD_CFG_STRUCT(GPP_B13, 0x44000700, 0x00000010), /* PLTRST# */
	_PAD_CFG_STRUCT(GPP_B14, 0x84000700, 0x00000010), /* SPKR */
	_PAD_CFG_STRUCT(GPP_B15, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_B16, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_B17, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_B18, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_B19, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_B20, 0x84000201, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_B21, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_B22, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_B23, 0x40000b00, 0x00000010), /* PCHHOT# */

	/* GPIO Group GPP_C */
	/* reserved */
	//_PAD_CFG_STRUCT(GPP_C0,  0x44000700, 0x00000010), /* SMBCLK */
	//_PAD_CFG_STRUCT(GPP_C1,  0x44000700, 0x00000010), /* SMBDATA */
	_PAD_CFG_STRUCT(GPP_C2,  0x44000300, 0x00000010), /* GPIO */
	/* reserved */
	//_PAD_CFG_STRUCT(GPP_C3,  0x44000700, 0x00000010), /* SML0CLK */
	//_PAD_CFG_STRUCT(GPP_C4,  0x44000700, 0x00000010), /* SML0DATA */
	_PAD_CFG_STRUCT(GPP_C5,  0x44000201, 0x00000010), /* GPIO */
	/* reserved */
	//_PAD_CFG_STRUCT(GPP_C6,  0x44000700, 0x00000010), /* SML1CLK */
	//_PAD_CFG_STRUCT(GPP_C7,  0x44000700, 0x00000010), /* SML1DATA */
	_PAD_CFG_STRUCT(GPP_C8,  0x84000100, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_C9,  0x84000100, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_C10, 0x84000100, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_C11, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_C12, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_C13, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_C14, 0x84000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_C15, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_C16, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_C17, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_C18, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_C19, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_C20, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_C21, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_C22, 0x42040100, 0x00003010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_C23, 0x84000300, 0x00000010), /* GPIO */

	/* GPIO Group GPP_D */
	_PAD_CFG_STRUCT(GPP_D0,  0x84000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_D1,  0x44000201, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_D2,  0x42020100, 0x00003000), /* GPIO */
	_PAD_CFG_STRUCT(GPP_D3,  0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_D4,  0x84000200, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_D5,  0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_D6,  0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_D7,  0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_D8,  0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_D9,  0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_D10, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_D11, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_D12, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_D13, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_D14, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_D15, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_D16, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_D17, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_D18, 0x84000201, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_D19, 0x84000201, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_D20, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_D21, 0x44000200, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_D22, 0xc4000100, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_D23, 0x44000300, 0x00000010), /* GPIO */

	/* GPIO Group GPP_E */
	_PAD_CFG_STRUCT(GPP_E0,  0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_E1,  0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_E2,  0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_E3,  0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_E4,  0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_E5,  0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_E6,  0x82020100, 0x00003000), /* GPIO */
	_PAD_CFG_STRUCT(GPP_E7,  0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_E8,  0x44000700, 0x00000010), /* SATA_LED# */
	_PAD_CFG_STRUCT(GPP_E9,  0x44000700, 0x00000010), /* USB_OC0# */
	_PAD_CFG_STRUCT(GPP_E10, 0x44000700, 0x00000010), /* USB_OC1# */
	_PAD_CFG_STRUCT(GPP_E11, 0x44000700, 0x00000010), /* USB_OC2# */
	_PAD_CFG_STRUCT(GPP_E12, 0x44000700, 0x00000010), /* USB_OC3# */

	/* GPIO Group GPP_F */
	_PAD_CFG_STRUCT(GPP_F0,  0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_F1,  0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_F2,  0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_F3,  0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_F4,  0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_F5,  0x80100100, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_F6,  0x84000201, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_F7,  0x84000201, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_F8,  0x84000201, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_F9,  0x84000100, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_F10, 0x44000700, 0x00000010), /* SATA_SCLOCK */
	_PAD_CFG_STRUCT(GPP_F11, 0x44000700, 0x00000010), /* SATA_SLOAD */
	_PAD_CFG_STRUCT(GPP_F12, 0x44000700, 0x00000010), /* SATA_SDATAOUT1 */
	_PAD_CFG_STRUCT(GPP_F13, 0x44000700, 0x00000010), /* SATA_SDATAOUT2 */
	_PAD_CFG_STRUCT(GPP_F14, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_F15, 0x44000700, 0x00000010), /* USB_OC4# */
	_PAD_CFG_STRUCT(GPP_F16, 0x44000700, 0x00000010), /* USB_OC5# */
	_PAD_CFG_STRUCT(GPP_F17, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_F18, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_F19, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_F20, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_F21, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_F22, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_F23, 0xc4000200, 0x00000010), /* GPIO */

	/* GPIO Group GPP_G */
	_PAD_CFG_STRUCT(GPP_G0,  0x44000100, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_G1,  0x44000100, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_G2,  0x44000100, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_G3,  0x44000100, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_G4,  0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_G5,  0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_G6,  0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_G7,  0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_G8,  0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_G9,  0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_G10, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_G11, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_G12, 0x84000100, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_G13, 0x84000100, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_G14, 0x84000100, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_G15, 0x84000100, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_G16, 0x84000100, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_G17, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_G18, 0x44000700, 0x00000010), /* NMI# */
	_PAD_CFG_STRUCT(GPP_G19, 0x44000700, 0x00000010), /* SMI# */
	_PAD_CFG_STRUCT(GPP_G20, 0x44000300, 0x00000000), /* GPIO */
	_PAD_CFG_STRUCT(GPP_G21, 0x44000300, 0x00000000), /* GPIO */
	_PAD_CFG_STRUCT(GPP_G22, 0x44000300, 0x00000000), /* GPIO */
	_PAD_CFG_STRUCT(GPP_G23, 0x44000300, 0x00000010), /* GPIO */

	/* GPIO Group GPP_H */
	_PAD_CFG_STRUCT(GPP_H0,  0x44000201, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_H1,  0x84000101, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_H2,  0x44000201, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_H3,  0x44000201, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_H4,  0x84000101, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_H5,  0x84000201, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_H6,  0x84000201, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_H7,  0x84000201, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_H8,  0x84000201, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_H9,  0x84000201, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_H10, 0x44000700, 0x00000010), /* SML2CLK */
	_PAD_CFG_STRUCT(GPP_H11, 0x44000700, 0x00000010), /* SML2DATA */
	_PAD_CFG_STRUCT(GPP_H12, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_H13, 0x44000700, 0x00000010), /* SML3CLK */
	_PAD_CFG_STRUCT(GPP_H14, 0x44000700, 0x00000010), /* SML3DATA */
	_PAD_CFG_STRUCT(GPP_H15, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_H16, 0x44000700, 0x00000010), /* SML4CLK */
	_PAD_CFG_STRUCT(GPP_H17, 0x44000700, 0x00000010), /* SML4DATA */
	_PAD_CFG_STRUCT(GPP_H18, 0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_H19, 0x84000201, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_H20, 0x84000201, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_H21, 0x84000201, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_H22, 0x84000201, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_H23, 0x84000201, 0x00000010), /* GPIO */

	/* GPIO Group GPP_I */
	_PAD_CFG_STRUCT(GPP_I0,  0x44000700, 0x00000010), /* DDPB_HPD0 */
	_PAD_CFG_STRUCT(GPP_I1,  0x44000700, 0x00000010), /* DDPC_HPD1 */
	_PAD_CFG_STRUCT(GPP_I2,  0x44000700, 0x00000010), /* DDPD_HPD2 */
	_PAD_CFG_STRUCT(GPP_I3,  0x84000700, 0x00000010), /* DDPE_HPD3 */
	_PAD_CFG_STRUCT(GPP_I4,  0x44000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPP_I5,  0x44000700, 0x00000010), /* DDPB_CTRLCLK */
	_PAD_CFG_STRUCT(GPP_I6,  0x44000700, 0x00000010), /* DDPB_CTRLDATA */
	_PAD_CFG_STRUCT(GPP_I7,  0x44000700, 0x00000010), /* DDPC_CTRLCLK */
	_PAD_CFG_STRUCT(GPP_I8,  0x44000700, 0x00000010), /* DDPC_CTRLDATA */
	_PAD_CFG_STRUCT(GPP_I9,  0x44000700, 0x00000010), /* DDPD_CTRLCLK */
	_PAD_CFG_STRUCT(GPP_I10, 0x44000700, 0x00000010), /* DDPD_CTRLDATA */

	/* GPIO Group GPD */
	_PAD_CFG_STRUCT(GPD0,    0x04000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPD1,    0x04000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPD2,    0x04000700, 0x00000010), /* LAN_WAKE# */
	_PAD_CFG_STRUCT(GPD3,    0x04000700, 0x00000010), /* PWRBTN# */
	_PAD_CFG_STRUCT(GPD4,    0x04000700, 0x00000010), /* SLP_S3# */
	_PAD_CFG_STRUCT(GPD5,    0x04000700, 0x00000010), /* SLP_S4# */
	_PAD_CFG_STRUCT(GPD6,    0x04000700, 0x00000010), /* SLP_A# */
	_PAD_CFG_STRUCT(GPD7,    0x04000301, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPD8,    0x04000700, 0x00000010), /* SUSCLK */
	_PAD_CFG_STRUCT(GPD9,    0x04000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPD10,   0x04000300, 0x00000010), /* GPIO */
	_PAD_CFG_STRUCT(GPD11,   0x04000300, 0x00000010), /* GPIO */
};

/* Early pad configuration in romstage. */
static const struct pad_config early_gpio_table[] = {
	/* GPIO Group GPP_A */
	/* LPC */
	_PAD_CFG_STRUCT(GPP_A1,  0x44000700, 0x00000010), /* LAD0 */
	_PAD_CFG_STRUCT(GPP_A2,  0x44000700, 0x00000010), /* LAD1 */
	_PAD_CFG_STRUCT(GPP_A3,  0x44000700, 0x00000010), /* LAD2 */
	_PAD_CFG_STRUCT(GPP_A4,  0x44000700, 0x00000010), /* LAD3 */
	_PAD_CFG_STRUCT(GPP_A5,  0x44000700, 0x00000010), /* LFRAME# */
	_PAD_CFG_STRUCT(GPP_A8,  0x44000700, 0x00000010), /* CLKRUN# */
	_PAD_CFG_STRUCT(GPP_A9,  0x44000700, 0x00000010), /* CLKOUT_LPC0 */
	_PAD_CFG_STRUCT(GPP_A10, 0x44000700, 0x00000010), /* CLKOUT_LPC1 */

	/* Serial interrupt */
	_PAD_CFG_STRUCT(GPP_A6,  0x44000700, 0x00000010), /* SERIRQ */
};

#endif /* _GPIO_X11SSM_F_H */
