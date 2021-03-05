#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "后山小道");
        set("long", @LONG
前后都是草丛和树木，左右是非常茂盛的梧桐木，小路两旁长满了各色说不出
名字的鲜艳的花。荫翳蔽日的梧桐树下，崎岖不平的羊肠小路映着一种森森然的感
觉。梧桐的枝叶很茂盛，完全遮蔽了你头顶的天空，使路面陷入一片浓重的黑暗，
许多圆圆的小亮点会忽然在地上成片的出现，又迅速的消失，那是枝叶的缝隙间漏
下的光线。
LONG
        );
	set("exits",([
  		"west" : __DIR__"path3",
  		"east" : __DIR__"path1",
	]) );
/*	set("objects", ([
	__DIR__"npc/wall" : 1,
					]) );*/
	set("no_fly",1);
	set("coor/x",-60);
	set("coor/y",220);
	set("coor/z",50);
	set("outdoors", "bashan");
	setup();
}

int init()
{
	add_action("do_hide", "hide");
	add_action("do_comeout", "comeout");
	if (!query("wall"))
	{
		set("wall",1);
		new(__DIR__"npc/wall")->move(this_object());
	}
	if (userp(this_player()))
	{
		add("count",1);
		if (query("count") == 2)
			call_out("attack",1,this_player());
	}
}

int attack(object ob)
{
	if (environment(ob) == this_object())
		message_vision(CYN"你突然发觉这里的树长得分外茂密，或许可以借以隐藏(hide)。\n"NOR,ob);
	return 1;
}

int do_comeout(){
	object me;
	mapping who;
	int i,j,amount;
	
	me = this_player();
	if(me->query_temp("condition_type") != NOR CYN" <藏身树后>"NOR)
		return 0;		

	message_vision("$N从树后边转了出来。\n", me);
	delete("hide");
	me->delete_temp("condition_type");
	return 1;
}

int do_hide(){
	object me;
	mapping who;
	int i,j,amount;
	
	me = this_player();
	if(me->query_temp("condition_type") == NOR CYN" <藏身树后>"NOR)
		return  notify_fail("你已经藏起来了呀！？\n");		

	if (query("hide"))
		return  notify_fail("树后边藏不下这么多人．．．\n");		

	message_vision("$N转到树后边去，藏起身形。\n", me);
	tell_object(me,"你觉得没有躲藏必要的时候，可以用comeout指令离开。\n");
	set("hide",me);
	me->set_temp("condition_type",NOR CYN" <藏身树后>"NOR);
	return 1;
}

int valid_leave(object me, string dir)
{
	if (me->query_temp("condition_type") == NOR CYN" <藏身树后>"NOR)
		return notify_fail("你正藏在树后边，还是不要乱跑为妙。\n");
	if (present("wall of blossoms",this_object()) && dir == "west")
		return notify_fail("这个方向的道路被一堵花墙阻挡住了。\n");
	return 1;
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
