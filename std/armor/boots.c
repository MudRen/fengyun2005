// boots.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <armor.h>
inherit WEAR;

void create() {
	if(clonep(this_object())) {
		destruct(this_object());
		return notify_fail("CAN NOT CLONE STARNDARD OBJECT!\n");
	}
}

void init_boots() {
	if(!clonep()) {
		set("armor_type", TYPE_BOOTS);
		set("armor_worn", WORN_BOOTS);
	}
	::init_wear();
}
