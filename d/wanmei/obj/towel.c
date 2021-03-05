// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("绣着梅花的浴巾", ({ "towel" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "一条绣着梅花的浴巾，鲜红的梅花栩栩如生。\n");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	::init_cloth();
}
