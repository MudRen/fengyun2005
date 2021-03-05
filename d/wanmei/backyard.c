// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "山庄后院");
        set("long", @LONG
松软的黄土铺满后院，显然是用来练习武功的。院中零星地立着几根一尺粗细
的木桩，其中一根被斜削为两截，切口儿古怪。又一根被一剑洞穿，一柄青穗剑尚
未拔出。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"center",
  "east" : __DIR__"playground",
  "north" : __DIR__"kitchen",
  "south" : __DIR__"bathroom",
]));
	set("outdoors","wanmei");
        set("item_desc", ([
                "切口儿": "
这切口儿一看就是高手所削．．．\n",
                "青穗剑": "
这青穗剑已经锈死在木桩里，再也拔不出了．．\n",
        ]) );
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
void init()
{
	add_action("do_pull","pull");
}
int do_pull(string arg)
{
	object blood;
	if(!arg || (arg != "青穗剑" && arg != "sword")) return 0;
	write("你用尽全身力量，用力一拉！！\n");
	write("你的内力不够．．．累得狂喷鲜血．．．\n");
	this_player()->receive_damage("kee",50);
	blood= new(__DIR__"obj/blood");
	blood->move(this_object());
	return 1;

}
