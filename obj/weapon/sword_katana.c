// katana.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <weapon.h>
inherit BLADE;

void create() {
	set_name( "武士刀", ({ "katana" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把似剑的东瀛武士刀。\n");
		set("value", 1);
		set("material", "steel");
		set("rigidity", 2000);
		set("wield_msg", "$N从刀鞘中抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	}
	::init_blade(8);
}
