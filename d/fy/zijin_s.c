// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h>
string *fight_rooms = ({"zijin1", "zijin2", "zijin3", "zijin4"});	
void create()
{
        set("short", RED"朱雀门之巅"NOR);
        set("long", @LONG
琉璃玉瓦有如黄金般灿烂辉煌，远远望去，红墙之下，风起云涌，四方云动！ 
LONG
        );
    set("exits", ([ 
  		"northwest" : __DIR__"zijin4",
		"north" : __DIR__"zijin_e",
		"west" : __DIR__"zijin_w",
	]));
        set("outdoors", "fengyun");
	set("coor/x",150);
	set("coor/y",60);
	set("coor/z",20);
	setup();

}
void init(){
	add_action("do_jump", "jump");
	add_action("do_juezhan", "juezhan");
}

int do_juezhan(string arg){
	object *all, *fighters, me, room;
	int i, j;
	me = this_player();
	if(!arg) {
		tell_object(me, "你要与谁决战？\n");
		for(i=0; i<sizeof(fight_rooms); i++) {
			if(room = find_object(__DIR__+fight_rooms[i])) {
//write(sprintf("%O", room));
				all = all_inventory(room);
//write(sprintf("%O", fighters));
				fighters = filter_array(all, (: interactive($1) :));
				for(j=0; j<sizeof(fighters); j++){
					write(sprintf("%s （%s）\n", fighters[j]->name(), fighters[j]->query("id")));
				}
			}
		}	
	} else {
		for(i=0; i<sizeof(fight_rooms); i++) {
			if(room = find_object(__DIR__+fight_rooms[i])) {
				all = all_inventory(room);
				fighters = filter_array(all, (: interactive($1) :));
				for(j=0; j<sizeof(fighters); j++){
					if(arg == (string)fighters[j]->query("id")) {
						me->move(room);
						message_vision("$N闪身冲到$n面前喝道：“看招！”\n", me, fighters[j]);
						me->kill_ob(fighters[j]);
						fighters[j]->kill_ob(me);
						return 1;
					} 
				}
			}
		}	
		message_vision("上面没有你要决战的人。\n", me);
	}
	
	return 1;
}

int do_jump(string arg){
	object room, me;
	if(!arg || (arg != "down" && arg != "下")){
		return notify_fail("你要往哪里跳？\n");
	}
	me = this_player();
	room = find_object(__DIR__"taihedian");
	if(!objectp(room)){
		room = load_object(__DIR__"taihedian");
	}
	message_vision("$N踊身向下跳去。\n", me);
	tell_object(room, me->name()+"轻盈的落在你的身旁。\n");
	me->move(room);
	return 1;
}

int valid_leave(object ob, string arg){
	object *inv, *fighters, room;
	int i, j;

	if(arg == "northwest"){
		for(i=0; i<sizeof(fight_rooms); i++) {
			if(room = find_object(__DIR__+fight_rooms[i])) {
				inv = all_inventory(room);
				fighters = filter_array(inv, (: interactive($1) :));
				if(sizeof(fighters) != 0){
					return notify_fail("作为观众请待在这里，如果要决战请输入你要决战的人。（juezhan）\n");
				}
			}
		}
		return 1;
	} else {
		return 1;
	}
}