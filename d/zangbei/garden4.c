inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "菊花园东");
        set("long", @LONG
菊花园很大，旁边是梅花园还有牡丹，蔷薇．芍药，茶花，甚至还有竹园。谁
也不知道究竟占了多少地，只知道一个人就是走得很快也难在一天内绕着这片地走
一圈。园中至少有十七栋单独的屋子，老伯和律香川的屋子在东侧。
LONG
        );
        set("exits", ([ 
		"east" :   	__DIR__"groom1",
		"north" : 	__DIR__"groom3",
		"southwest":	__DIR__"garden1",
	]));
        set("objects", ([
        
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1280);
        set("coor/y",970);
        set("coor/z",-50);
	set("map","zbeast");
	setup();
}

void init() {
	add_action("do_pull","pull");
	add_action("do_search","search");
}

int do_search(){
	tell_object(this_player(),"园子里的菊花长得郁郁葱葱，恐怕搜一天都不会有结果。\n");
	return 1;
}

int do_pull(string arg) {
	object me=this_player();
//	object xiaohe;
	
	if (arg== "flower" || arg == "菊花") {
		tell_object(me,YEL"你蹲下去伸手拔起一株菊花。菊花被你一拔，就连根而起。\n\n"NOR);
		return 1;
	}
	return notify_fail("你想拔/拉什么？\n");
}