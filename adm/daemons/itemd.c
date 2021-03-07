// itemd.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

// #pragma optimize all

#include <ansi.h>
inherit F_DBASE;

void create() {
    seteuid(getuid());
    set("name", "物品精灵");
    set("id", "itemd");
}

void setup_unique(object obj) {
	int max_num;
	string id;

	if(!clonep(obj)) {
		return;
	}
	max_num = obj->query("unique_amount");
	if(max_num < 1) {
		max_num = 1;
	}
	id = base_name(obj);
	add(id, 1);
	if(query(id) > max_num) {
		destruct(obj);
		return notify_fail("复制物品达到最大量！\n");
	}
	return;
}

void remove_unique(object obj) {
	string id;

	if(!clonep(obj)) {
		return;
	}
	id = base_name(obj);
	if(query(id) > 0) {
		add(id, -1);
	}
}
