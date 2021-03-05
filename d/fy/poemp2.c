inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", HIG"探花阁二楼"NOR);
    set("long", 
"当年万里觅封候，匹马戍梁州。关河梦断何处？尘暗旧貂裘。胡未灭，鬓先
秋，泪空流。此生谁料，心在天山，身老沧洲！\n"                                   
        );
        set("exits", ([ 
  	"down" : __DIR__"poemp",
  	"up" : __DIR__"poemp3",
  	"west" : __DIR__"poemp2a",
]));
        set("objects", ([
 //       __DIR__"npc/mother1" : 1,
   	]) );
	set("no_death_penalty",1);
	set("NONPC", 1);
	set("PK_FREE", 1);
	set("no_fly", 1);
  	set("coor/x",-40);
 	set("coor/y",20);
  	set("coor/z",10);
	setup();
}
