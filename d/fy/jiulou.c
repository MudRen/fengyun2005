#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "胡姬酒肆");
    set("long", 
"自盛唐以来，胡人东至天朝，除珠宝杂货生意外，经营酒肆亦是主要行业，而
店中大多由胡姬来打理。而只有富人文生方能进出此地，人们送友远行，长在此饯
行。岑参有诗道：送君系马青门口，胡姬垆头劝君酒。酒肆中除了美酒，还有美味
佳肴和音乐歌舞。李太白诗云：何处可为别，长安青绮门。胡姬招素手，延客醉金
樽。真所谓“胡姬貌如花，当垆笑春风。笑春风，舞罗衣，君今不醉将安归？”\n"        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"yundoor",
 
]));
        set("indoors", "fengyun");
        set("objects", ([
//        __DIR__"npc/mei": 1,
                        ]) );

 set("coor/x",-20);
 set("coor/y",-40);
	set("coor/z",0);
set("map","fysouth");
	setup();
}
