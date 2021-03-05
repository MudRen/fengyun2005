// belt.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 

#include <armor.h>
inherit WAIST;

void create() {
	set_name(  "腰带" , ({ "belt"}) );
	set_weight(60);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("value", 10);
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	::init_waist();
}
