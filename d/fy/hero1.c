inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIG"黄鹤楼"NOR);
        set("long", HIG"			昔人已乘黄鹤去，此地空余黄鹤楼。
        		黄鹤一去不复返，白云千载空悠悠。
        		晴川历历汉阳树，芳草萋萋鹦鹉洲，
        		日暮乡关何处是，烟波江上使人愁。
        		
        				崔颢《黄鹤楼》\n"NOR                                   
        );
        set("exits", ([ 
  	"down" : __DIR__"poemp",
]));
        set("objects", ([
        __DIR__"npc/yaren" : 1,
	__DIR__"npc/prince" : 1,
                        ]) );
	set("no_death_penalty",1);
	set("coor/x",-30);
	set("coor/y",3);
	set("coor/z",10);
	setup();
}
