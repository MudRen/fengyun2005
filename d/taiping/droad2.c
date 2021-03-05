inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "阴暗小巷");
        set("long", @LONG
小巷向里，没有灯光，一点都没有。一种说不出的阴森笼罩着整条胡同里。青
石板的路面上石缝里野草竟有数寸高，显然这地方平时很少有人来。巷子两侧是暗
褐色的高墙，没有窗子，也没有人声。
LONG
        );
        set("exits", ([ 
		"west": __DIR__"droad1",
		"east": __DIR__"droad3",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
 		"grass":	"小巷无人，野草已经有数寸高了。\n",
		"野草":		"小巷无人，野草已经有数寸高了。\n",    
	]));
	set("coor/x",20);
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