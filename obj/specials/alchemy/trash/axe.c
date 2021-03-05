// axe_short.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <weapon.h>
inherit AXE;

void create() {
	set_name("短斧", ({ "axe" }) );
	set_weight(6000);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("material", "iron");
		set("wield_msg", "$N从背后抽出$n，试了试重量，然後握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}
		set("value", 0);
	::init_axe(5);
}
