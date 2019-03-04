/*
 * Phoenix-RTOS --- LwIP port
 *
 * LwIP advanced routing
 *
 * Copyright 2019 Phoenix Systems
 * Author: Kamil Amanowicz
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef PHOENIX_ROUTE_H_
#define PHOENIX_ROUTE_H_

#include <net/route.h>

#include <lwip/netif.h>
#include <lwip/ip4_addr.h>


typedef struct _rt_entry {
	ip4_addr_t dst;
	ip4_addr_t gw;
	ip4_addr_t genmask;
	short flags;
	short metric;
	struct netif *netif;
} rt_entry_t;


struct rt_table {
	rt_entry_t **entries;
	int size;
	int used;
};


extern struct rt_table rt_table;


int route_add(struct netif *netif, struct rtentry *rt);


int route_del(struct netif *netif, struct rtentry *rt);


ip4_addr_t *route_get_gw(struct netif *netif, const ip4_addr_t *dest);


struct netif *route_find(const ip4_addr_t *dest);


#endif /* PHOENIX_ROUTE_H_ */
