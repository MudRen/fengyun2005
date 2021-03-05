// annie. 07.2003
// dancing_faery@hotmail.com
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "华山暗洞");
        set("long", @LONG
转了几个弯，入洞已深，面前漆黑一片，伸手不见五指，空气里漂浮着些
许淡淡的幽香，四周一片寂静，却似乎隐藏着看不见的杀机，你脊背有点儿发
凉，额头上渗出了滴滴冷汗。黑暗深处似乎有人影，似乎又没有，太黑了！
LONG
        );
        set("exits", ([ 
		  "southdown" : __DIR__"shanlu1",
	]));
	set("objects", ([
		__DIR__"npc/kumei2": 1,
	]));   

	set("no_fly",1);

	set("coor/x",-52);
	set("coor/y",-60);
	set("coor/z",40);
	setup();
}

void light_notify(object obj, int i)
{
	object inv, me, room;
	int j;
	me = this_player();
	inv = present("shadow",environment(me));
	if (inv)
	{
		message_vision(CYN"$N冷哼一声，喝道：你干什么？\n$N击出一道掌风，$n登时黯淡下去。\n"NOR,inv,obj);
		return;
	}
	message_vision(obj->name() + "发出的光照亮了暗洞。\n" , me);
	if ( REWARD_D->riddle_check(me,"绝世芳华") == 4)
	{
		tell_object(me,"你隐隐约约的看到地上被人用锋锐的器物刻了几个字：\n\n速速去向鹰老二报告"HIG"进程"NOR"。\n\n");
		REWARD_D->riddle_set(me,"绝世芳华",5);
	}

   return;
}

