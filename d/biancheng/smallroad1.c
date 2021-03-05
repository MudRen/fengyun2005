inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "陋巷");
        set("long", @LONG
走出西街往南转，屋子就更简陋破烂，在这里住的不是牧羊人，就是赶车洗马
的，那几个大老板店里的伙计，也住在这里。一个大肚子的妇人，正蹲在那里起火。
她的背上背着个孩子，旁边还站着三个，一个个都是面有菜色，她自己看来却更憔
悴苍老得像是老太婆。
LONG
        );
        set("exits", ([ 
	"northeast" : __DIR__"road5",
	"south" : __DIR__"smallroad2",
	"west": __DIR__"cabin1",
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",-50);
        set("coor/y",-10);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
