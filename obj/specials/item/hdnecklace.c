// necklace.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <armor.h>
inherit NECK;

void create() {
	set_name("红豆项链", ({ "hongdou necklace", "necklace"}) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一条用红豆编成的项链。\n");
		set("unit", "条");
		set("value", 850);
		set("wear_msg", "$N轻轻地把$n套在颈上。\n");
		set("unwield_msg", "$N轻轻地把$n从颈上除了下来。\n");
		set("holiday", "重阳节");
	}
	::init_neck();
}

