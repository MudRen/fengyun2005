// blade_dan.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <weapon.h>
inherit BLADE;

void create() {
	set_name("奇形弯刀", ({ "blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 1000);
		set("level_required",70);
		set("material", "iron");
		set("long", "这是一把银鞘乌柄的奇形弯刀。\n");
		set("wield_msg", "$N从银鞘中抽出一把明晃晃的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的银鞘。\n");
	}
	::init_blade(85);
}
