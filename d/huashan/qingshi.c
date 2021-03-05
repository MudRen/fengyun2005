
inherit ROOM;

void create()
{
        set("short", "大青石");
        set("long", @LONG
一块白玉般的岩石，就像是个孤独的巨人矗立在那里，岩石上滑不留手。在这
里可以清楚的看清玉女峰全景，向南望则是雄伟挺拔的雁落峰。奇的是岩石上没有
花，却有一株碧绿的草，比花更美，比翡翠还绿（ｐｉｃｋｕｐ　ｇｒａｓｓ）。
LONG
        );

	set("no_magic", 1);    
    set("outdoors", "huashan");

	set("coor/x",-12);
	set("coor/y",-58);
	set("coor/z",47);
	setup();
}

void init(){
	add_action("do_pickup", "pickup");
}

int do_pickup(string arg){
	object me, grass, room;
	
	me = this_player();
	if(!arg || (arg != "grass" && arg != "wang you")){
		return notify_fail("你要捡什么？\n");
	}
	if(me->is_busy() || me->is_fighting()) {
		return notify_fail("你正在忙。\n");
	}
	grass = new(__DIR__"obj/grass");
	message_vision("$N小心地把忘忧草捧在手里。\n", me);
	grass->move(me);
	message_vision("$N脚下一滑，身形向下坠去。\n", me); 
	room = find_object(__DIR__"yunv");
	if(!objectp(room)){
		room = load_object(__DIR__"yunv");
	}
	me->move(room);
	message("vision", "只见" + me->name() + "的身影从岩石上滚落了下来。\n", 
			environment(me), me);
	me->start_busy(2);
	environment(me)->eagle_come(me);
	return 1;
}
