// cloth.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
	set_name(HIW"银甲"NOR, ({ "silver armor" }) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "iron");
		set("armor_prop/armor", 10);
		set("long","一件银色的盔甲。\n");
		set("value", 9000);
	}
	::init_cloth();
}
