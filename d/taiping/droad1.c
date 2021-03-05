#include <ansi.h>
inherit ROOM;

int event_msg();

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
		"west": __DIR__"droad0",
		"east": __DIR__"droad2",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
		"grass":	"小巷无人，野草已经有数寸高了。\n",
		"野草":		"小巷无人，野草已经有数寸高了。\n",    
		"corner":	"墙角排污水的小洞，大概只有老鼠能钻过。\n",
		"洞":		"墙角排污水的小洞，大概只有老鼠能钻过。\n",
	]));
	set("coor/x",10);
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
	message("vision",BLU"不知什么东西从你脚下窜过，钻进墙角的洞里不见了。\n\n"NOR,this_object());
	return 1;
}