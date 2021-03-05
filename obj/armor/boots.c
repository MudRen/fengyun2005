// boots.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <armor.h>
inherit BOOTS;

void create() {
	set_name("布鞋", ({ "shoes", "boots" }) );
	set_weight(90);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "双");
		set("value", 10);
	}
	::init_boots();
}
