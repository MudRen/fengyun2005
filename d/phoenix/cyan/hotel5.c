// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "初雨阁");
    set("long", @LONG
这是一间很普通的小小木屋，几张凳子，一个小桌，旁边的梳妆台镜缘斜
斜地簪著几朵山野间随处可见的淡黄色碎蕊星花。很简单的摆设，却有著难以
名状的舒适感觉，唯一略显突兀的便是正堂之上悬著的一面匾额，书著大大的
＂杀妖狐＂三字，笔法刚中见柔，显是出自女子之手。
LONG
NOR
        );
	set("objects", ([

	]));
	set("item_desc", ([
	
	]) );
	set("exits",([
  		"east" : "bridge",
	]) );
	set("area","cyan");


	set("coor/x",-60);
	set("coor/y",20);
	set("coor/z",80);
	setup();
}



void init() {
	::init();
	add_action("do_pick","pick");
	add_action("do_get","get");
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


