
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "白石道路");
        set("long", @LONG
这是一条笔直的，由晶莹的白石铺成的道路。路旁是两行修剪整齐的花草，微
风吹过，花香袭人。白色的晶石在天光下闪著迷人的色彩。一切显的是那样的宁静，
可你的内心却有一种不祥的预感。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"intersection",
]));
        set("objects", ([
        __DIR__"obj/huacao" : 1,
	__DIR__"obj/stone" : 1,
                        ]) );

        set("outdoors", "palace");
	set("coor/x",-90);
	set("coor/y",110);
	set("coor/z",10);
	setup();
}
int valid_leave(object me, string dir)
{
	message_vision( HIC "一阵淡淡的花香飘过，$N不由地深吸了一口气。\n\n\n"NOR,me);
	if(!me->query_condition("no_shadow"))
		me->apply_condition("no_shadow",random(10)+10);

	return 1;
}
void reset()
{
	object *inv;
	object con, item;
	::reset();
	con = present("huacao", this_object());
        inv = all_inventory(con);
        if(!sizeof(inv)) {
	item = new(__DIR__"obj/xuehama");
	item->move(con);
	}
	con = present("stone", this_object());
        inv = all_inventory(con);
        if( !sizeof(inv)) {
	item = new(__DIR__"obj/duancao");
	item->move(con);
	item =  new(__DIR__"obj/pearl1");
	item->move(con);
	}
}
