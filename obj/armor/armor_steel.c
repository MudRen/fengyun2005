// armor_steel.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <armor.h>
inherit CLOTH;

void create() {
	set_name("钢甲", ({ "gangjia" }) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value", 50);
		set("material", "steel");
		set("armor_prop/armor", 20);
	}
	::init_cloth();
}
