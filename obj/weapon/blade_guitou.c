// blade_gui_tou.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <weapon.h>
inherit BLADE;

void create() {
	set_name("鬼头刀", ({ "blade" }) );
	set_weight(5000);
	if( clonep() )
	set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 1);
		set("material", "iron");
		set("long", "这种厚重的大刀，强盗喜欢用，份量大约十斤重。\n");
		set("wield_msg", "$N抽出一把表面斑驳的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插回腰间。\n");
	}
	::init_blade(15);
}
