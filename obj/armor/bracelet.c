// bracelet.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <armor.h>
inherit WRISTS;

void create() {
	set_name("手镯", ({ "bracelet"}) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一支手镯。\n");
		set("unit", "支");
		set("value", 0);
		set("wear_msg", "$N轻轻地把一个$n戴在手腕上。\n");
		set("unequip_msg", "$N轻轻地把$n从手腕上除了下来。\n");
	}
	::init_wrists();
}

