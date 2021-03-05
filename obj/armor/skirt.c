// skirt.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <armor.h>
inherit CLOTH;

void create() {
	set_name("长裙", ({ "skirt" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "一条长裙。\n");
		set("material", "cloth");
		set("value", 30);
		set("armor_prop/armor", 1);
	}
	::init_cloth();
}
