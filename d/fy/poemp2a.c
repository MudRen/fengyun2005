inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", HIG"探花阁侧楼"NOR);
    set("long", "————————————————————————————
        荷叶自碧水自柔，晓阴无赖是穷秋，残杯险把醉兰舟。
        漫想重来千万事，临波一笑忍凝眸，浮槎江海寄余愁。
        
        水自柔来天自空，长天孤雁落霞中，竟何相思几万重。
        残装浅笑沉醉后，新词赋就绿荫浓，淡山凉月水从容。
    ————————————————————————————        
        
        \n"NOR                                   
        );
    set("exits", ([ 
		"east" : __DIR__"poemp2",
	]));
    set("objects", ([
		__DIR__"npc/cici" : 1,
	]) );
   	set("resource/water", 1);
    set("liquid/container", "水壶"); 
    set("no_death_penalty",1); 
	set("no_fly",1);
	set("no_fight", 1);
 	set("coor/x",-50);
	set("coor/y",20);
	set("coor/z",10);
	setup();
}
				
