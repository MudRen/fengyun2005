inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "大漠");
        set("long", @LONG
在这又神秘，又可怕的沙漠上，你实在做梦也想不到会看见一只船的。只见这
艘船长而狭，船头和船尾，都有雕刻得极为细致的装饰，华丽的船舱四面，还悬着
珠。纵是烟雨西湖上最是逗人遐思的画舫，纵是月影笼纱，夜泊秦淮酒家旁的轻艇，
看来也没有这艘船如此华丽。
LONG
        );
        set("exits", ([ 
		"east":	__DIR__"yangguan1a",
	]));
        set("objects", ([

	]) );
	
	set("outdoors", "zangbei");
        set("coor/x",-350);
        set("coor/y",100);
        set("coor/z",0);
	set("map","zbeast");
	setup();
}

void init(){
	add_action("do_look","look");
	add_action("do_jump","jump");
}

int do_look(string arg) {
	object me, room;
	
	me = this_player();
	
	if (!arg || (arg!= "boat" && arg!="in" && arg!="船舷"
				&& arg!="船" && arg!="ship"))
		return 0;
		
	room = find_object(__DIR__"eagleboat");
	if (!room) room = load_object(__DIR__"eagleboat");
	
	if (room->usr_in()) {
		tell_object(me,"这艘船像雪橇般在平滑的沙地上滑行起来，愈行愈远，你来迟了。\n");
		return 1;
	}
	
	tell_object(me,"船舷不高，也许你可以跳进去。(jump)\n");
	return 1;
}
	
		

int do_jump(string arg){
	object me, room;
	
	me = this_player();
			
	if (!arg || (arg!= "boat" && arg!="in" && arg!="船舷"
			&& arg!="船" && arg != "ship")){
		tell_object(me,"你要往哪儿跳？\n");
		return 1;
	}
	
	if (me->is_busy()) {
		tell_object(me,"你现在正忙。\n");
		return 1;
	}
	
	room = find_object(__DIR__"eagleboat");
	if (!room) room = load_object(__DIR__"eagleboat");
	if (room->usr_in()) {
		tell_object(me,"船愈行愈远，你跳迟了。\n");
		return 1;
	}
	
	tell_object(me, YEL"\n你提气纵身，向船舷上跃去。\n"NOR);
	
	if(!me->query_temp("zangbei/龟兹_龟兹送宝")) {
		tell_object(me,WHT"
忽然一股劲风迎面扑来，你的咽喉、双目、前胸、下腹，身上所有的要害，都已在
掌风笼罩中。。。。你被逼回了原地。\n"NOR);
		return 1;
	}
		
	tell_object(YEL"\n你稳稳地落在船舷上。\n"NOR);
	me->move(room);
	room->depart(me);
	return 1;
}


		