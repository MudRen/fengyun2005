// blade_dan.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create() {
	set_name(WHT"秋鱼刀"NOR, ({ "blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 1000);
		set("material", "iron");
		set("level_required",120);
		set("long", "
秋鱼是产于天竺峰天池里的一种通体透明的鱼，潜泳的人碰上它，便全身发麻。
这种鱼因只在秋天里出现，故谓“秋鱼”。这柄秋鱼刀乃是一尾秋鱼吞噬了一
柄神刃后嵌入背脊所致。\n");
		set("wield_msg", "$N从银鞘中抽出一把明晃晃的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的银鞘。\n");
		set("experience",3000000);
	}
	::init_blade(105);
}
