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
  		"east" : __DIR__"path4",
  		"west" : __DIR__"path6",
	]) );
/*	set("objects", ([
	__DIR__"npc/wall" : 1,
					]) );*/
	set("no_fly",1);
	set("coor/x",-90);
	set("coor/y",220);
	set("coor/z",50);
	set("outdoors", "bashan");
	setup();
}

int init()
{
	object room;
	if (!query("wall"))
	{
		set("wall",1);
		new(__DIR__"npc/wall")->move(this_object());
	}
}

int valid_leave(object me, string dir)
{
	object room;
	if (userp(me))
	{
		if (!query("one"))
			set("one",me);
		else if (query("one") != me)
		{
			if (!room=find_object(__DIR__"hall"))
				room=load_object(__DIR__"hall");
			if (!room->query("done"))
			{
				room->set("interrupted",1);
				room->do_ics(me,2);
				return notify_fail(" ");
			}
		}
	}

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
