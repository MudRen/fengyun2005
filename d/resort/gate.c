#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIG"翠竹庄门"NOR);
        set("long", @LONG
这是一座精巧的山庄，依山傍水，似乎聚集着天地间的灵气。墙是用竹子筑成
的，翠绿晶莹的竹子，摸上去像玉石一样光滑细腻。院门也是用翠竹围成，门上挂
着一块木匾，匾上入木三分的写着四个大字“铁雪山庄”，匾左下角又书：  
             江湖人身在江湖，江湖人莫入翠竹
LONG
        );
        set("exits", ([ 
	  "north" : __DIR__"front_yard",
	  "south" : __DIR__"small_river",
	]));
       	set("objects", ([
                __DIR__"npc/guard" : 1,
        ]) );

        set("indoors", "resort");
	set("coor/x",0);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
}

