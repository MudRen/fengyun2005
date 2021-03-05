// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <room.h>
inherit DOOR_ROOM;
string look_stone();

void create()
{
	set("short", "扶桑古木的树根里");
    set("long", @LONG
你从小小的门里爬进，只见树根里竟然还有着一个小小的房间，房间中摆
满了坛坛罐罐，杂乱无章。你又梭巡了一次房间，才见到有方小小的木床摆在
角落，有个小小的人正躺在床上。
LONG
NOR
        );
	set("no_fight",1);
	set("objects", ([
		__DIR__"npc/woodwaiter":1,
	]));
	set("no_fly",1);
	set("item_desc", ([
		"小小的木床":	"小小的人睡的小小的床。\n",
		"木床":			"小小的人睡的小小的床。\n",	
		"床":			"小小的人睡的小小的床。\n",	
	]) );
	set("exits",([
  		"out" : __DIR__"bottom7",
	]) );

	set("coor/x",-20);
	set("coor/y",40);
	set("coor/z",-200);
	setup();
    create_door("out","door","小小的门","enter",DOOR_CLOSED);
}


/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/


