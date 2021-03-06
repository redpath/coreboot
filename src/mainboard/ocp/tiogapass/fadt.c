/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2019 - 2020 Intel Corporation.
 * Copyright (C) 2019 - 2020 Facebook Inc
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

#include <arch/acpi.h>
#include <soc/acpi.h>

void motherboard_fill_fadt(acpi_fadt_t *fadt)
{
	fadt->reserved = 0;
	fadt->preferred_pm_profile = PM_ENTERPRISE_SERVER;
}
