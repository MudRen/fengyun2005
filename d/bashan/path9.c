#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "后山小道");
        set("long", @LONG
前后都是草丛和树木，左右是非常茂盛的梧桐木，小路两旁长满了各色说不出
名字的鲜艳的花草。荫翳蔽日的梧桐树下，崎岖不平的羊肠小路映着一种森森然的
感觉。梧桐的枝叶很茂盛，完全遮蔽了你头顶的天空，使路面陷入一片浓重的黑暗
中，许多圆圆的小亮点会忽然在地上成片的出现，又迅速的消失，那是枝叶的缝隙
间漏下的光线。北面是一片茂密的林木，穿过林木，你就离开了这危机四伏的奇诡
巴山。
LONG
        );
	set("exits",([
  		"south" : __DIR__"path8",
  		"north" : "/d/xiangsi/shuangtian",
	]) );
	set("item_desc", ([
		"north": "北面是一片茂密的树林。\n",
		"花草": "花草中似乎有什么在闪着点点绿光．．．\n",
		"flower": "花草中似乎有什么在闪着点点绿光．．．\n",
		"grass": "花草中似乎有什么在闪着点点绿光．．．\n",
		"花": "花草中似乎有什么在闪着点点绿光．．．\n",
		"草": "花草中似乎有什么在闪着点点绿光．．．\n",
	]) );
/*	set("objects", ([
	__DIR__"npc/wall" : 1,
					]) );*/
	set("no_fly",1);
	set("coor/x",-110);
	set("coor/y",250);
	set("coor/z",50);
	set("outdoors", "bashan");
	setup();
}

int valid_leave(object me, string dir)
{
	object room;
	if (userp(me))
	{
		if (!room=find_object(__DIR__"hall"))
			room=load_object(__DIR__"hall");
		if (!room->query("done"))
		{
			room->set("interrupted",1);
			room->do_ics(me,1);
			return notify_fail(" ");
		}
	}

	return 1;
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
