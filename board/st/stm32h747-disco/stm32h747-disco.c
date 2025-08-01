// SPDX-License-Identifier: GPL-2.0+
/*
 * stm32h747i-disco support
 *
 * Copyright (C) 2025 Dario Binacchi <dario.binacchi@amarulasolutions.com>
 */

#include <dm.h>
#include <init.h>
#include <log.h>
#include <asm/global_data.h>

DECLARE_GLOBAL_DATA_PTR;

int dram_init(void)
{
	struct udevice *dev;
	int ret;

	ret = uclass_get_device(UCLASS_RAM, 0, &dev);
	if (ret) {
		debug("DRAM init failed: %d\n", ret);
		return ret;
	}

	if (fdtdec_setup_mem_size_base() != 0)
		ret = -EINVAL;

	return ret;
}

int dram_init_banksize(void)
{
	fdtdec_setup_memory_banksize();

	return 0;
}
