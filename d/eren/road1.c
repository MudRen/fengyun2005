inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "山道");
        set("long", @LONG
山路更见崎岖，乱石丛中几棵野草顽强地伸出头来。群山似在远处，又似在近
处，在这孤寂的山谷里，却像哀伤的笛韵，流露出人间侧腓的哀息。
LONG
        );
        set("exits", ([ 
	"southdown" : __DIR__"road0",
	"southup" : __DIR__"road2",
	"westup" : __DIR__"road1a",
	]));
        set("objects", ([
        	__DIR__"obj/grass": 1,
	]) );
	set("outdoors", "eren");
        set("coor/x",0);
        set("coor/y",10);
        set("coor/z",30);
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