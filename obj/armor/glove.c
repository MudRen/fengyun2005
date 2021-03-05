// gloves.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <armor.h>
inherit HANDS;

void create() {
	set_name("手套", ({ "gloves"}));
	set_weight(10);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "双");
		set("long", "一双黑布手套。\n");
		set("value", 9);
		set("material", "cloth");
	}
	::init_hands();
}

