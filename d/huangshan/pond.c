// ; annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "寒潭");
        set("long", @LONG
潭面成不规则状，深绿色的潭水看不到底，潭边寒气刺骨，一缕缕雾气从水面
升起，潭上笼罩着一层薄薄的白色雾气。潭边的石头滑不留人，石缝中长着一些不
知名的植物。
LONG
        );
	set("exits", ([ 
		"down" : __DIR__"jiulong",
	]));

	set("item_desc", ([
		"石缝": "石缝中丛生着各种颜色的小草，其中一株鲜红如血，十分引人注目（pick）。
在红色小草边还有两撮小土坑，显然有人从这里移走了什么．．\n",
		"植物": "石缝中丛生着各种颜色的小草，其中一株鲜红如血，十分引人注目（pick）。
在红色小草边还有两撮小土坑，显然有人从这里移走了什么．．\n",
		"flower": "石缝中丛生着各种颜色的小草，其中一株鲜红如血，十分引人注目（pick）。
在红色小草边还有两撮小土坑，显然有人从这里移走了什么．．\n",
	]) );

    set("outdoors", "huangshan");
	set("coor/x",-50);
	set("coor/y",40);
	set("coor/z",20);
	setup();
}


void init()
{
	add_action("do_pick", "pick");
}


int do_pick(string arg)
{
   	object me, tea;
	int i;

   	me = this_player();
	if (!query("flower"))
		return notify_fail("小草已经被人摘走了。\n");
	tea = new(__DIR__"obj/grass");
	message_vision(CYN"$N弯身自石缝中采下一株小草。\n"NOR,me);
	tea->move(me);
	delete("flower");
	return 1;
}

void reset()
{
	::reset();
	if (NATURE_D->get_season() < 3)	// 春夏二季
		set("flower",1);
}

