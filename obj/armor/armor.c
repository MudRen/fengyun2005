// armor.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <armor.h>
inherit CLOTH;

void create() {
	set_name("皮甲", ({ "armor", "leather armor" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "leather");
		set("value", 10);
		set("armor_prop/armor", 10);
		set("long","一件半旧的皮甲，上面还有几块血迹。\n");
	}
	::init_cloth();
}
