// hammer.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <ansi.h>
#include <weapon.h>
inherit HAMMER;

void create() {
	set_name(CYN"巫师铁锤"NOR, ({ "hammer" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把沉重的铁锤，打造的相当坚实。\n");
		set("value", 100);
		set("material", "iron");
		set("wield_msg", "$N拿出一把$n，试了试重量，然後握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}
	::init_hammer(100);
}
