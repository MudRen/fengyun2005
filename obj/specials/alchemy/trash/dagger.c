// dagger.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <weapon.h>
inherit DAGGER;

void create() {
	set_name("匕首", ({ "dagger" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把看起相当普通的匕首。\n");
		set("value", 15);
		set("material", "steel");
		set("wield_msg", "$N从怀中摸出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n藏入怀中。\n");
	}
	set("value", 0);

	::init_dagger(4);
}
