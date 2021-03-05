
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "草坪");
        set("long", @LONG
这里是一片碧绿的草坪，一些巨大的松树环绕在草坪四周。草坪上散缀著一些
不知名的野花，有红的，黄的，兰的，白的。这些野花把碧绿的草坪点缀的充满了
生机。几头小鹿悠闲地走来走去。透过树干的空隙，你隐约看见粼粼的水波。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"stonelin",
  "south" : __DIR__"river",
]));
        set("objects", ([
        __DIR__"obj/flower" : 1,
                        ]) );

        set("outdoors", "palace");
	set("coor/x",-80);
	set("coor/y",70);
	set("coor/z",10);
	setup();
}
int valid_leave(object me, string dir)
{
	message_vision( HIG "一阵淡淡的花香飘过，$N不由地深吸了一口气。\n\n\n"NOR,me);
	if(!me->query_condition("green_blood"))
		me->apply_condition("green_blood",random(10)+10);

	return 1;
}
void reset()
{
	object *inv;
	object con, item, flower;
	::reset();
	flower= present("flower", this_object());
        inv = all_inventory(flower);
        if( !sizeof(inv)) {
	con = new(__DIR__"obj/wanghua");
	item = new(__DIR__"obj/wangguo");
	item->move(con);
	con->move(flower);
	}
}
