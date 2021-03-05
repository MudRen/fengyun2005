// ring.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <weapon.h>
inherit RING;

void create() {
	set_name("板指", ({ "ring" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "这是一个大理石的板指\n");
		set("value", 1);
		set("material", "steel");
		set("wield_msg", "$N从怀中摸出一个$n带在手指上。\n");
		set("unwield_msg", "$N将手指上的$n拿下来藏入怀中。\n");
	}
	::init_ring(4);
}
