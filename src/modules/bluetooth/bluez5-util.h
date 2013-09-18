#ifndef foobluez5utilhfoo
#define foobluez5utilhfoo

/***
  This file is part of PulseAudio.

  Copyright 2008-2013 João Paulo Rechi Vita

  PulseAudio is free software; you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as
  published by the Free Software Foundation; either version 2.1 of the
  License, or (at your option) any later version.

  PulseAudio is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with PulseAudio; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
  USA.
***/

#include <pulsecore/core.h>

typedef struct pa_bluetooth_device pa_bluetooth_device;
typedef struct pa_bluetooth_adapter pa_bluetooth_adapter;
typedef struct pa_bluetooth_discovery pa_bluetooth_discovery;

typedef enum pa_bluetooth_hook {
    PA_BLUETOOTH_HOOK_DEVICE_CONNECTION_CHANGED,          /* Call data: pa_bluetooth_device */
    PA_BLUETOOTH_HOOK_MAX
} pa_bluetooth_hook_t;

struct pa_bluetooth_device {
    pa_bluetooth_discovery *discovery;
    pa_bluetooth_adapter *adapter;

    int device_info_valid;      /* 0: no results yet; 1: good results; -1: bad results ... */

    /* Device information */
    char *path;
    char *alias;
    char *address;
    uint32_t class_of_device;
};

struct pa_bluetooth_adapter {
    pa_bluetooth_discovery *discovery;
    char *path;
    char *address;
};

pa_bluetooth_device* pa_bluetooth_discovery_get_device_by_path(pa_bluetooth_discovery *y, const char *path);
pa_bluetooth_device* pa_bluetooth_discovery_get_device_by_address(pa_bluetooth_discovery *y, const char *remote, const char *local);

pa_hook* pa_bluetooth_discovery_hook(pa_bluetooth_discovery *y, pa_bluetooth_hook_t hook);

pa_bluetooth_discovery* pa_bluetooth_discovery_get(pa_core *core);
pa_bluetooth_discovery* pa_bluetooth_discovery_ref(pa_bluetooth_discovery *y);
void pa_bluetooth_discovery_unref(pa_bluetooth_discovery *y);
#endif