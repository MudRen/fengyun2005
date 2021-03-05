// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <weapon.h>
inherit HAMMER;
void create()
{
	set_name("铜佛钟", ({ "fozhong" }) );
	set_weight(40000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 500);
		set("material", "wood");
		set("long", "一个绿斑斑的铜佛钟。\n");
		set("weapon_prop/karma",1);
	}
	::init_hammer(5);
}
