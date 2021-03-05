#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "庄稼地");
	set("long", @LONG
一块绿油油的麦田。田中半人高的麦杆儿随风而动，正如江湖中的你，随著江
湖之中汹涌的波涛，四处飘摇。你想到江湖中的无奈,不禁沧然泪下。 
LONG
	);
	set("exits", ([
		"north" : __DIR__"farm3",
		"south" : __DIR__"farm5",
		"east" : __DIR__"road1",
		"west" : __DIR__"farm3",
	]));
	set("objects", ([
		__DIR__"npc/farmer" : 1,
		__DIR__"npc/bull"   : 1,
	]));
	set("outdoors", "wudang");
	set("coor/x",-10);
	set("coor/y",60);
	set("coor/z",-50);
	setup();

}


void init(){
	add_action("do_search","search");
}


int do_search(){
	object ob, me = this_player();
	
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你现在正忙。\n");
		
	message_vision("$N沉思片刻，在麦田里走了几个来回，不时蹲下身子察看。\n", me);
	me->perform_busy(1);
	
	if (random(5) || present("scorpion", this_object()))
		return notify_fail("你蹲下身子在麦田里看了看，没发现什么异常。\n");
		
	ob = new(__DIR__"npc/scorpion");
	message_vision(HIR"。。。。忽然，麦堆里跳出一只三寸长的大蝎子，张牙舞爪地向$N扑去。\n"NOR, me);
	if (!ob ->move(this_object()))	destruct(ob);
	else
		ob->kill_ob(me);
	return 1;
}
	
		
		