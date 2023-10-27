/*
 * Copyright (c) 2017, NVIDIA CORPORATION.  All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __NVGPU_NVHOST_PRIV_H__
#define __NVGPU_NVHOST_PRIV_H__

struct nvhost_fence {
        u32 syncpt_id; /* syncpoint id or sync fence fd */
        u32 value;     /* syncpoint value (discarded when using sync fence) */
};


struct host1x;

struct host1x_syncpt_intr {
        spinlock_t lock;
        struct list_head wait_head;
        char thresh_irq_name[12];
        struct work_struct work;
};


/* Reserved for replacing an expired wait with a NOP */
#define HOST1X_SYNCPT_RESERVED                  0

struct host1x_syncpt_base {
        unsigned int id;
        bool requested;
};

struct host1x_syncpt {
        struct kref ref;

        unsigned int id;
        atomic_t min_val;
        atomic_t max_val;
        u32 base_val;
        const char *name;
        bool client_managed;
        struct host1x *host;
        struct host1x_syncpt_base *base;

        /* interrupt data */
        struct host1x_syncpt_intr intr;

        /*
         * If a submission incrementing this syncpoint fails, lock it so that
         * further submission cannot be made until application has handled the
         * failure.
         */
        bool locked;
};



#include <nvgpu/os_fence_syncpts.h>

struct nvgpu_nvhost_dev {
	struct platform_device *host1x_pdev;
};

int nvgpu_nvhost_fence_install(struct nvhost_fence *f, int fd);
struct nvhost_fence *nvgpu_nvhost_fence_get(int fd);
void nvgpu_nvhost_fence_put(struct nvhost_fence *f);
void nvgpu_nvhost_fence_dup(struct nvhost_fence *f);
struct nvhost_fence *nvgpu_nvhost_fence_create(struct platform_device *pdev,
					struct nvhost_ctrl_sync_fence_info *pts,
					u32 num_pts, const char *name);
u32 nvgpu_nvhost_fence_num_pts(struct nvhost_fence *fence);
int nvgpu_nvhost_fence_foreach_pt(struct nvhost_fence *fence,
	int (*iter)(struct nvhost_ctrl_sync_fence_info, void *),
	void *data);

#endif /* __NVGPU_NVHOST_PRIV_H__ */
