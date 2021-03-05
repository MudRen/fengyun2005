// blade_dan.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <weapon.h>
inherit BLADE;

void create() {
	set_name("单刀", ({ "blade" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("material", "iron");
		set("long", "这是一寻常的单刀，份量大约十六、七斤重。\n");
		set("wield_msg", "$N抽出一把绣迹斑斑的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	}
	set("value", 0);

	::init_blade(5);
}
