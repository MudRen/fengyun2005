inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "嵩岳寺");
        set("long", @LONG
嵩岳寺建造年代在北魏永平元年至正光元年，原名闲居寺，早先是北魏皇室
的一座离宫，后改建为佛寺。寺中有著名的嵩岳寺塔，为单层密檐式砖塔，全塔
共雕十六个狮子，有立有卧，正侧各异，造型雄健。只是近年来嵩岳寺周围山贼
出没，寺内香火衰落，僧人已经走的一个不剩了。
LONG
        );
        set("exits", ([ 
		"south" : __DIR__"shike",
	]));
        set("objects", ([
        	__DIR__"obj/tower1": 	1,
        	__DIR__"obj/stonelion": 1,
	]) );
	set("outdoors", "eren");
        set("coor/x",-550);
        set("coor/y",650);
        set("coor/z",0);
	set("map","zbeast");
	setup();

}

void init() {
	add_action("do_jump","climb");
}

int	do_jump(string arg) {
	object room, me= this_player();
	if (arg == "tower" || arg == "嵩岳寺塔" || arg == "塔" || arg == "ta" || arg =="up") {
		if (this_player()->query_skill("move")>= 100) {
			message_vision("$N施展轻功，平地拔起数丈，稳稳地落在嵩岳寺塔顶。\n",this_player());
			room = find_object(__DIR__"songyue2");
			if (!room) room = load_object(__DIR__"songyue2");
			me->move(room);
			return 1;
		}else
			return notify_fail("塔对你来说太高了，可望不可及呀。\n");
		
	}	
	if (query_verb() == "jump") return notify_fail("你想向那儿跳？\n");
	else return notify_fail("你想攀登什么？\n");
}
