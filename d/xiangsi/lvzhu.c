// annie 07.2003
// dancingfaery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "绿竹林");
        set("long", @LONG
走到这儿，只觉天色浑然一暗，恍如黄昏乍临。抬头看去，却原来是千竿
翠竹幢幢，覆住了半幕天空。这里的竹子青碧中透着一丝淡淡的红色，又比寻
常青竹高出两丈有余，你觉得似乎曾在哪里听说过此种异种，一时间却又是苦
思不得。
LONG
        );
	set("objects", ([
		__DIR__"obj/bamboo" : 1,
		__DIR__"npc/xx" : 1,
	]));
	set("exits",([
  		"north" : __DIR__"qishi",
  		"south" : __DIR__"qingxi",
	]) );

   	set("shoots_amount", 3);
	set("outdoors", "xiangsi");

	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",-10);
	setup();
}


void init(){
	if(NATURE_D->get_season() == 1 && NATURE_D->get_weather() == "小雨") {
		tell_object(this_player(), "雨中，只听见竹林之中不断传来哔哔啵啵的声音。\n");
	}
	add_action("do_search", "search");
}

int do_search(){
	message_vision("$N仔细的在竹林地上寻找。\n", this_player());
	if(NATURE_D->get_season() == 1 && query("shoots_amount") >= 0) {
		tell_object(this_player(), "你发现一根嫩嫩的竹笋刚刚拱出地面。可以把它刨出来。\n");
		this_player()->set_temp("marks/found_shoot", 1);
	} else {
		tell_object(this_player(), "你什么也没有发现。\n");
	}
	return 1;
}

int dig_notify() {
	object me, item;
	int i;
	
	me = this_player();
	i = NATURE_D->get_season();
	if(me->is_busy()) { 
	    write("你现在正在忙！\n");
	    return 1;
	}
	if(me->is_fighting()) return 0;
	if(NATURE_D->get_season() != 1 || !me->query_temp("marks/found_shoot")) {
	    message_vision("$N用力往地上一刨，不过除了盘绕的竹根外什么也没有发现。\n", me);
	} else {
		if (query("shoots_amount") >= 0) {
    		message_vision("$N用力往地上一刨。\n", me);
        	message_vision("一根嫩嫩的竹笋露了出来。\n", me);
        	me->delete_temp("marks/found_shoot");
        	item = new(__DIR__"obj/bshoot");
        	if(objectp(item)) {
        		item->move(this_object());
        		add("shoots_amount", -1);
			}
		}
	}
	me->start_busy(1);
}

void reset(){
	::reset();
	set("shoots_amount", 3);
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
