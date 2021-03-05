#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "巷口");
        set("long", @LONG
小街东侧有一条巷子，被街边的树遮住了大半，巷口原来有个用木条围起的栅
栏，不知什么时候已经被人推倒，青石板的路面上石缝里野草竟有数寸高，显然这
地方平时很少有人来，就连玩耍的孩子都离它远远的，偶尔有几个捡破烂的会在巷
口歇歇脚，而后又快快地走开。
LONG
        );
        set("exits", ([ 
		"west": __DIR__"mroad2",
		"east": __DIR__"droad1",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
		    
	]));
	 set("objects",([
        	__DIR__"npc/scavenger": 2,
         ])  );
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",0);
	set("map","taiping");
	setup();

}

void init(){
	if (random(2)) {
		remove_call_out("event_msg");
		call_out("event_msg",random(5)+1);
	}
}

int event_msg() {
	message("vision",HIG"天空中一排人字形的大雁飞过，雁声嘹亮，凄凉。。\n\n"NOR,this_object());
	return 1;
}