inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "二郎山");
        set("long", @LONG
二郎山的风景是诱人的，登上观景台眺望：青衣江的涛声，溪沟两边的泉声，
茂密的松林，不时飘过的几片白云。每年五月，大小杜鹃盛开，红、兰、紫、白交
相辉映，飞来飞去的高原彩蝶衬托得花儿更加绚丽多彩。
LONG
        );
        set("exits", ([ 
		"south": __DIR__"wild1",
		"northdown": __DIR__"mroad1",
	]));
	set("item_desc", ([
		"flower": "山上的杜鹃花开的正灿烂，你忍不住想去摘上（pick）几朵。\n",
		"杜鹃":  "山上的杜鹃花开的正灿烂，你忍不住想去摘上（pick）几朵。\n",
	
	]));
        set("objects", ([
        	__DIR__"npc/butterfly": 	1,
        	__DIR__"npc/butterfly2": 	1,
        	__DIR__"obj/scenery":		1,
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1300);
        set("coor/y",750);
        set("coor/z",0);
	set("map","zbeast");
	set("flower",2);
	setup();

}


void init() {
	add_action("do_pick","pick");
}


int do_pick(string arg) {
	
	object butterfly,flower;
	
	if ( arg!= "杜鹃" && arg!="flower" && arg!="花" && arg!="azalea" )
		return notify_fail("你想摘什么？\n");
	if (!query("flower"))
		return notify_fail("花儿已经被摘完了。\n");
	if (butterfly=present("butterfly",this_object()))
		return notify_fail(butterfly->name()+"展翼飞舞，似乎不愿意让你把花儿摘去。\n");
	flower=new(__DIR__"obj/flower1");
	flower->move(this_object());
	message_vision("$N伸手摘下了一朵花儿。\n",this_player());
	add("flower",-1);
	return 1;
}

	
void reset(){
	::reset();
	set("flower",2);
}