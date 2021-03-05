// dagger.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <weapon.h>
inherit DAGGER;

void create() {
	set_name("铁笔", ({ "ironpen" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把看起相当普通的笔,却是用铁铸成的。\n");
		set("value", 400);
		set("material", "steel");
		set("wield_msg", "$N从怀中摸出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n藏入怀中。\n");
	}
	::init_dagger(15);
}
