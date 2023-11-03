/*
 * Tegra Video Input 2 device common APIs
 *
 * Tegra Graphics Host VI
 *
 * Copyright (c) 2016-2017, NVIDIA CORPORATION.  All rights reserved.
 *
 * Author: Bryan Wu <pengw@nvidia.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __T210_VI_H__
#define __T210_VI_H__

#define V4L2_SYNC_EVENT_SUBDEV_ERROR_RECOVER	(1 << 2)
#define V4L2_SYNC_EVENT_FOCUS_POS               (1 << 0)
#define V4L2_SYNC_EVENT_IRIS_POS                (1 << 1)

extern struct tegra_vi_fops vi2_fops;

#endif
