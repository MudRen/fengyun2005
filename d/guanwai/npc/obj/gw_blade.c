// blade_dan.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <weapon.h>
inherit BLADE;

void create() {
    set_name("藏刀", ({ "blade" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
        set("value", 500000);
		set("material", "iron");
        set("long", "一柄藏边汉子用来防身的弯刀，十分锋利。\n");
		set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	}
	
	::init_blade(20);
}
