// hat.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <armor.h>
inherit HEAD;

void create() {
	set_name("茱萸花", ({ "zhuyu flower", "flower" }) );
	set_weight(6);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "朵");
		set("long", "一朵茱萸花散发着淡淡的香气。\n");
		set("value", 8);
		set("material", "wood");
		set("holiday", "重阳节");
	}
	::init_head();
}
