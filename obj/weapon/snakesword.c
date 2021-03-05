// sword_long.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create() {
	set_name(HIG"寒烟翠"NOR, ({ "snake sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把薄如蝉翼，通体莹碧的软剑，剑体如秋日残阳下的碧波，一漾一漾的荡着寒光。
剑柄上却刻着繁复精致的曼陀花纹。花纹中，三条雕刻得栩栩如生的小蛇首尾相衔，盘于剑柄之上。
据传，这原本是上古时代流传下来的神兵，因带有邪异的力量而被封于万年玄冰洞中,不见天日至今。\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N的手腕轻盈的一抖，围绕在$N腰间的$n霎时之间化作三尺寒波。\n");
		set("unwield_msg", "$N将手中的$n盘入腰间。\n");
	}
	::init_sword(80);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	object snake;
	if (random(4))
	{
		if (me->query_temp("max_snake")<3)
		{
			message_vision( HIG "$N手中"+name()+ HIG "剑气暴涨，一条绿莹莹的小蛇从剑尖幽然而出，如闪电般扑向$n。\n"NOR,me,victim);
			snake = new(__DIR__"spiritsnake.c");
			snake->invocation(me);
			snake->move(environment(me));
			snake->kill_ob(victim);
			me->add_temp("max_snake",1);
		}
	}
    return 0;
}
