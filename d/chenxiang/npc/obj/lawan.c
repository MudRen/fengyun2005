// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit F_FOOD;
inherit ITEM;
#include <ansi.h>

void create()
{
	set_name( "蜡丸", ({ "lawan"}) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","这是一个拇指大小的蜡丸，颜色腊黄，并不很起眼。\n");
		set("unit", "个");
		set("no_drop",1);
    	set("value",0);
    	set("food_remaining", 1);
		set("food_supply", 0);
		set("material", "food");
	}
	::init_item();
}


int finish_eat()
{
	object me;
	
	me = this_player();
	me->unconcious();
	destruct(this_object());
    return 1;
}