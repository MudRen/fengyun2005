// shield.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <armor.h>
inherit SHIELD;

void create() {
	set_name("盾牌", ({ "shield" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "面");
		set("value", 5000);
		set("armor_prop/armor", 10);
		set("armor_prop/parry", 10);
	}
	::init_shield();
}
