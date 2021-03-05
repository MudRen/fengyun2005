// waist.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
// Last modification:
//		- 07/05/2001 by Daniel Q. Yu.
//

#include <armor.h>
inherit WEAR;

void create() {
	if(clonep(this_object())) {
		destruct(this_object());
		return notify_fail("CAN NOT CLONE STARNDARD OBJECT!\n");
	}
}

void init_waist() {
	if(!clonep()) {
		set("armor_type", TYPE_WAIST);
		set("armor_worn", WORN_WAIST);
	}
	::init_wear();
}
