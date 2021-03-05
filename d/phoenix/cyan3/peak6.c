// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "百怒峰");
    set("long", @LONG
百怒峰本是此山第二高峰，却因与极高之争雄崖相连，反显得远落其下。
从此处望去，只见争雄一崖拔地而起，状若刀砍斧劈，上摩苍穹，下座长岭，
恍如擎天一柱，上锐下敛，其峥嵘峻峭是你生平仅见，令人胸间逼仄，不能喘
息。
LONG
NOR
        );
	set("objects", ([
	__DIR__"npc/xue":1,
	__DIR__"obj/tree":1,
	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"eastdown" : "path7",
  		"northdown" : "peak8",
	]) );

	set("outdoors", "cyan");
	set("area","cyan3");

	set("coor/x",-60);
	set("coor/y",50);
	set("coor/z",90);
	setup();
}


void init()
{
	::init();
	add_action("do_climb","climb");
}	

int do_climb(string arg){

	object me,room;
	me=this_player();
	if (!arg || (arg!="tree" && arg!="树")) 
		return notify_fail("你想爬什么？\n");;

	room=find_object("peak14");
	if (!objectp(room)) room=load_object("peak14");
	tell_object(me,"你手脚并用，敏捷地继续向树顶爬去。\n");
	tell_room(room, this_player()->name() + "从树下爬了上来。\n");
	this_player()->move(room);
	return 1;
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


