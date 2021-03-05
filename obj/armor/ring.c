// ring.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <armor.h>
inherit FINGER;

void create() {
	set_name("扳指", ({ "ring"}) );
	set_weight(10);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一支黑乎乎的扳指。\n");
		set("unit", "支");
		set("value", 15);
		set("wear_msg", "$N轻轻地把一个$n戴在手指上。\n");
		set("unwield_msg", "$N轻轻地把$n从手指上除了下来。\n");
	}
	::init_finger();
}

