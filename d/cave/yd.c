// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
string ring();
void create()
{
        set("short", "黄土甬道");
        set("long", @LONG
三尺方圆的甬道，坡度相当的大，如果不是镶着的一个个铁环，人几乎站立不
住。甬道里大约每十步就有一盏油灯，所有并不是相当的黑暗。空气很凉而且也很
湿，偶尔你还感觉得到有微微的空气流动。
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
  		"south" : __DIR__"td",
	]));
	set("item_desc", ([
		"铁环" : (: ring :),
		"tiehuan" : (: ring :),
		"ring" : (: ring :),
	]));	
        set("indoors", "cave");
	set("coor/x",-5);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}

string ring(){
	object me;
	me = this_player();
	tell_object(me, "你注意到靠尽头的一个铁环似乎常被人拉（ｐｕｌｌ）。\n");
	add_action("do_pull", "pull");
	return "";
}

int do_pull(string arg){
	object me, room;
	me = this_player();
	if(!arg || (arg != "ring" && arg != "tiehuan" && arg != "铁环")){
		return notify_fail("你要拉什么？\n");
	}
        message_vision("$N爬上斜坡，用力拉了一下尽头的铁环。\n", me);
//	        if(!query("exits/up")){
		message_vision("只听咯吱吱一阵铁索绞动的声音，露出了一个向上的洞口。\n", me);
//		set("exits/up", "/d/fycycle/road3");	
		room = find_object("/d/fycycle/road3");
		if(!objectp(room)){
			room = load_object("/d/fycycle/road3");
		}
		message_vision("$N一纵身，轻轻巧巧地跃出洞口。\n\n",me);
		me->move("d/fycycle/road3");
//		room->set("exits/down", "/d/cave/yd");
//		call_out("close_path", 5, room);
//	}
	return 1;	
}

int close_path(object room){
	write("伴随着铁索绞动声，洞口有关上了。\n");
	room->delete("exits/down");
	delete("exits/up");
	return 1;
}
