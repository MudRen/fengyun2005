// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit DOOR_ROOM;
void create()
{
	object con,obj;
        set("short", "藏经阁");
        set("long", @LONG
空荡荡的这一层，没有家具，没有摆设，似乎是用来堆放东西的地方。正中有
六只红木大柜，上书“大乘法宝”。这些是少林寺尚未整理完毕的经文，虽然比不
上楼上的珍贵，仍然有僧人日夜看护。
LONG
        );
        set("exits", ([ 
  		"up"	: __DIR__"changjing3",
  		"down" : __DIR__"changjing",
	]));
        set("objects", ([
                __DIR__"obj/gui1" : 2,
				__DIR__"npc/monk6" : 1,
				__DIR__"npc/monk61" : 1,
       ]) );
	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",10);
	set("no_lu_letter",1);
	setup();
        create_door("down","door", "木门", "up", DOOR_CLOSED);
    	con = present("mugui" + sprintf(" %d",random(2)+1), this_object());
	if(con && obj = new(BOOKS"skill/incar_100")) obj->move(con);
}

void init(){
	add_action("do_get","get");
}

int do_get(string arg){
	
	object monk, me;
	
	monk = present("shaolin monk");
	if (!monk)	return 0;
	if (!arg)	return 0;	
	if (arg[0..4] == "mugui" || arg == "all"){
		monk->ccommand("stare");
		return 1;
	}
	
	return 0;
}
	