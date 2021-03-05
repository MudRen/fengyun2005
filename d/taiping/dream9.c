#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "魔海");
        set("long", @LONG
风呼啸，雾飘飞，壁立的烈焰又开始飞扬，墙聚的寒冰又开始滚动。在你的面
前，是一道白玉阶。玉阶上风更劲，雾更凄迷。上到玉阶的尽头，赫然是一片汪洋。
一望无际的汪洋。水并不是蓝色，也并不是绿色。是红色，红得就像是鲜血。那与
其说是一片汪洋，毋宁说它是一片血海。一望无涯，却也没有与天相接。海面上根
本就没有天空，只有风和雾，烈焰与寒冰。这绝不是人间的海洋。岸边停着一个木
排，这难道就是渡过魔海的魔舟。
LONG
        );
        set("exits", ([ 
		"north":  __DIR__"dream8",
	]));
	set("objects", ([
		
    	]) );
        set("no_fly",1);
        set("item_desc", ([
		"boat": "一叶木排，在血海中飘荡，也许你可以跳上去。(jumpto)\n",
		"木排": "一叶木排，在血海中飘荡，也许你可以跳上去。(jumpto)\n",
	 ]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

void init() {
	add_action("do_jump","jumpto");
}


int do_jump(string arg) {
	object me, room;
	me=this_player();
	
	if (!arg || (arg!="boat" && arg!="木排")) {
		tell_object(me,"你要往哪儿跳？\n");
		return 1;
	}
	
	message_vision(WHT"$N一纵身，疾往魔舟上跃落。\n"NOR,me);
	message_vision(HIR"那艘魔舟竟突然消失。$N竟是跳入一片血海之中！血！触目都是血！\n"NOR,me);
	tell_object(me,WHT"刹那之间，你只觉自己是坠落一片虚无之中。张目惊顾，触目已不是血，而是一片黑暗。\n"NOR);
	tell_object(me,BLU"                无尽的黑暗。\n"NOR);
	room=find_object(AREA_TAIPING"basement");
	if (!room)
		room=load_object(AREA_TAIPING"basement");
	me->move(room);
	me->unconcious();
	return 1;
}
	