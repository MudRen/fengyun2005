#include <room.h>
inherit ROOM;
void create()
{
	set("short", "搏浪飞沙");
	set("long", @LONG
你一走进这屋子，心里不由一惊，迎面竟然是一个怒目圆睁，须发戟张的壮
士。只见他手提巨大的铁锤，一副跃跃欲击的样子。细看之下，原来是一座铸铁
塑像。房间四壁均以黄沙涂嵌，身处其中，如临搏浪坡一击之处，只觉杀气罡风
凛凛而来。
LONG
        );
  	set("exits", ([ /* sizeof() == 4 */
		"center" : __DIR__"groundroom",
	]));

	set("objects", ([
               __DIR__"obj/hammerbook" : 1,
                        ]) );
    	set("indoors", "fycycle");
	set("coor/x",-320);
	set("coor/y",100);
	set("coor/z",0);
	set("no_magic",1);
	set("no_spell",1);
    	setup();
}

