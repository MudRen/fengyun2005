#include <ansi.h>
inherit DOOR_ROOM;
#include <room.h>
mapping door;

void create()
{
        set("short", "梅林");
        set("long", @LONG
眼前是一片并不十分浓密的树林，仔细看却是一片梅林，中间无一杂树，其间
更有许多百年老梅，几间很精致的瓦屋坐落其间，北面是一扇暗紫色的大门。梅林
外是一片碧绿的竹林。每当冬季梅林开得百花争艳，清香怒放，点点红白映在雪地
上，蔚成奇趣。
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
		"southwest" : __DIR__"bomboo1",
		"north" : __DIR__"meihouse",
	]));

    set("outdoors", "fengyun");
	set("coor/x",-320);
	set("coor/y",100);
	set("coor/z",0);
    setup();
	create_door("north", "door","暗紫色的大门", "south", DOOR_CLOSED);
}

void init(){
	add_action("do_knock", "knock");
	if(!doors["north"]["status"]) {
		this_player()->ccommand("close door");
	}
}

int do_knock(string arg){
	object room, hou;

	if(!arg || (arg != "door" && arg != "暗紫色的大门")) {
		return 0;
	}
	if (!doors["north"]["status"]){
		return notify_fail("门是开着的。\n");
	}
	if(arg == "door" || arg == "暗紫色的大门") {
		message_vision("$N走到门前，轻轻地拍了几下门。\n", this_player());
		room = find_object(__DIR__"meihouse");
		if(!objectp(room)){
			room = load_object(__DIR__"meihouse");
		}
		if(this_player()->query("marks/梅山民")){
			room->answer_door();
		} else {
			message_vision("室内静悄悄的没有声音。\n", this_player());
		}
	}
	return 1;
}
