inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "上山路");
        set("long", @LONG
路随山转，景随山变，这儿方圆一里内有近百泉眼，称为“药池沸泉”，据说
不同的泉水都有不同的疗效，当地人把它们分为明目泉、健胃泉、洗脚泉等。远眺，
可见藏羚羊、野牛、鹿、熊、狼、麝等动物劲走攀崖绝技，近处有马鸡、松鸡、黄
鸭轻歌戏水、恬适醉人。
LONG
        );
        set("exits", ([ 
		"southwest" : __DIR__"mugecuo",
		"northeast":  __DIR__"linchang1",
		"westdown":   __DIR__"river",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1660);
        set("coor/y",640);
        set("coor/z",20);
	set("map","zbwest");
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