inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "果园");
        set("long", @LONG
果园里的树枝上挂满了各种果实。红的苹果象牙球一样的发光。有些树木早巳
披上晚秋灿烂的装束，那是如火如茶的颜色，果实的颜色，熟透的甜瓜的颜色，橘
子与柠檬的颜色，珍馐美馔的颜色。林中到处亮出红红的光彩，
LONG
        );
        set("exits", ([ 
		"southwest" : __DIR__"orchard1",
	]));
        set("objects", ([

	]) );
	set("outdoors", "eren");
        set("coor/x",120);
        set("coor/y",70);
        set("coor/z",0);
	set("map","eren");
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