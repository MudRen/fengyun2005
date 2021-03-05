inherit ROOM;
#include <ansi.h>
int blinding(object me);
int bbqthem(object me, object obj);

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
		"west": __DIR__"droad2",
		"northeast": __DIR__"droad4",
	]));
        set("outdoors", "taiping");
	set("objects", ([
        	__DIR__"npc/killer" : 1,
        ]) );
	set("item_desc", ([
 		"grass":	"小巷无人，野草已经有数寸高了。\n",
		"野草":		"小巷无人，野草已经有数寸高了。\n",    
	]));
	set("coor/x",30);
	set("coor/y",-10);
	set("coor/z",0);
	set("map","taiping");
	setup();

}
