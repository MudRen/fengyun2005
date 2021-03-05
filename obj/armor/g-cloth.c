// g-cloth.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("布衣", ({ "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("long","一件半旧的布衣，上面还有几个补丁\n");
	}
	::init_cloth();
}

void setup_cloth(string name, string long) {
	set("name", name);
    set("long", long);
}
