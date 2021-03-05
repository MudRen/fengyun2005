#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "莲花寺");
        set("long", @LONG
莲花寺，寺如其名，北方山地之中，居然有如此多，如此美的荷花，实在让人
难以相信。碧绿的潭水衬着满池粉红的荷花，寺内简朴自然，绝无金壁辉煌之世俗
之气。
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"erzu",
  "southdown" : __DIR__"qingliang",
]));
        set("objects", ([
        "/d/taoyuan/npc/rabbit": 2,
        ]) );

	set("coor/x",65);
	set("coor/y",21);
	set("coor/z",-10);
	setup();

}

void init() {
//	object me;
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