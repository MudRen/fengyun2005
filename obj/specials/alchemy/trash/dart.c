// dart.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <weapon.h>
inherit THROWING;

void create() {
	set_name("飞镖", ({ "dart" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"飞镖是一种十分常见的暗器。\n");
		set("unit", "些");
		set("base_unit", "枝");
		set("base_weight", 40);
	}
	set_amount(1);
	set("base_value", 0);

	::init_throwing(5);
}
