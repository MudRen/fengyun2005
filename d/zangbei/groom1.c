inherit DOOR_ROOM;
#include <ansi.h>
#include <room.h>

void create()

{
        set("short", "书房");
        set("long", @LONG
书房是老伯的禁地，在这里无论说什么都不必怕别人听到。不管你是不是老伯
的朋友，无论你多么孤苦穷困，只要你到了菊花园，老伯都会把你带到这儿来，听
你诉说你的问题。他喜欢成全别人，喜欢公正，憎恶一切不公正的事，就像是祈望
丰收的农人，憎恶蝗虫急于除害一样。
LONG
        );
        set("exits", ([ 
		"west" :   __DIR__"garden4",
		"north":	__DIR__"groom2",
	]));
        set("objects", ([
	]) );
        set("coor/x",-1260);
        set("coor/y",970);
        set("coor/z",-50);
	set("map","zbeast");
	setup();
	create_door("north","door","纱门","south",DOOR_CLOSED);
}


int valid_leave(object me, string dir){
	
	object room, lu, laobo;
	mapping doors;
	
	room = find_object(__DIR__"groom2");
	if (!room) room = load_object(__DIR__"groom2");
	
	if ( dir == "north") {
		if ( !me->query_temp("marks/kuaihuo/lv_cook"))
			return notify_fail("没有老伯的准许，任何人不得进入卧室。\n");
		
		if (room->usr_in())
			return notify_fail("老伯已经在见别人了，请稍候片刻。\n");
		doors = this_object()->query_doors();
		if (doors["north"]["status"]==1)
			return notify_fail("纱门关着。\n");
		me->delete_temp("kuaihuo/lv_cook");
		if (lu=present("lv xiangchuan",room))
			destruct(lu);
		if (laobo = present("sun yubo",room))
			laobo->remove_all_killer();
		return ::valid_leave(me,dir);
	}
	return ::valid_leave(me, dir);
}