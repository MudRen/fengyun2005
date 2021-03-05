// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <weapon.h>
inherit BLADE;
void create()
{
	set_name("砍柴刀", ({ "lindao" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 60);
		set("material", "iron");
		set("long", "这是一寻常的砍柴刀，专门用来砍干柴的．\n");
		set("wield_msg", "$N抽出一把黑油油的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间。\n");
	}
	::init_blade(5);
}
