// sword_bamboo.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <weapon.h>
inherit SWORD;
	
void create() {
	set_name("竹剑", ({ "bamboo sword", "sword" }) );
	set_weight(100);
	if(clonep()) {
		set_default_object(__FILE__);
	} else {
		set("unit", "把");
		set("value", 2);
		set("material", "bamboo");
		set("long", "这是一把练习剑法用的竹剑，剑尖处用布包了起来以免误伤同伴。\n");
		set("wield_msg", "$N拿出一把练剑用的$n，握在手中。\n");
		set("unequip_msg", "$N放下手中的$n。\n");
	}
	::init_sword(1);
}
 
