#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "下坡道");
        set("long", @LONG
这是一条笔直的坡道，北高南低，道路两旁长满了许多松树，从松林间隐约可
以听到东边传来流水的声音。绿草茵茵，似锦缎一般铺在地上，踩上去却又沙沙作
响，说不出的惬意。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"spath1",
  "south" : __DIR__"spath3",
]));

        set("outdoors", "oldpine");

	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",30);
	setup();

}


void init() {
	object me;
	add_action("do_search", "search");
}

int do_search() {
	object me, ob;
	
	me = this_player();
	
	message("vision", me->name() + "在草丛中仔细寻找。\n", environment(me), me);
	
	if (me->query("marks/turtle_room")==base_name(this_object())
			&& me->query_temp("marks/search_turtle")!=2) {
		if (me->query_temp("marks/search_turtle")==1) {	
			tell_object(me, "你拨开草丛仔细寻找，竟然发现一只背壳上生满细细绿毛乌龟在慢慢爬。\n"); 
			me->set_temp("marks/search_turtle",2);
			ob = new(AREA_HUANGSHAN"npc/turtle");
			if(objectp(ob)) {
				ob->set("turtle_owner",me);
				if (!ob->move(this_object()))
				{
					destruct(ob);
					tell_object(me,"绿毛乌龟向你怀里钻了钻，没找到地方就爬开了。\n");
				}
			}
			return 1;
		}
	
		if (!present("green turtle", this_object())) {
			tell_object(me, YEL"花草丛中似乎有什么慢慢动了一下，你以为自己眼花了。\n"NOR); 
			me->set_temp("marks/search_turtle", 1);
			return 1;
		} 
	}
	
	tell_object(me,"你在花草中找来找去，什么也没有发现。\n");
	return 1;
}