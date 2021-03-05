// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <weapon.h>
inherit STAFF;
void create()
{
	set_name("古松琴", ({ "qin" }) );
	set_weight(40000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 500);
		set("material", "wood");
		set("long", "一个古色古香的古松琴。（琴质10）\n");
		set("timbre",10);
		set("wield_msg","$N从怀里取出一张$n，信手一划，泉水般的琴声从指尖流泻而出。\n");
		set("unwield_msg","$N将$n收起在身后。\n");
	}
	::init_staff(5);
}

void init()
{
	if (environment(this_object()) == this_player())
		add_action("do_play","play");
}


int do_play(string arg)
{
	object me;
	me = this_player();
	if (!arg || (arg!="qin" && arg!="古松琴" && arg!="琴"))
		return notify_fail("你要弹什么？\n");
	message_vision("$N一划古松琴，心中忽有所动，指下流泻出一首如泉水般的曲子。\n",me);
	me->set_temp("played_qin",1);
	me->set("annie/古松琴",1);
	return 1;
}
