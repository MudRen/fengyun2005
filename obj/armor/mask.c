// mask.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <armor.h>
inherit MASK;

void create() {
	set_name("面纱", ({ "mask"}) );
	set_weight(2);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一块面纱。\n");
		set("material", "cloth");
		set("unit", "快");
		set("value", 3);
		set("armor_prop/personality", -10);
		set("armor_prop/id", ({ "unknown" }));
		set("armor_prop/name", ({ "蒙面人" }));
		set("wear_msg", "$N轻轻地把$n罩在脸上。\n");
		set("unwield_msg", "$N轻轻地把$n从脸上除了下来。\n");
	}
	::init_mask();
}
