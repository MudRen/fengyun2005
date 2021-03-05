inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", HIM"探花阁三楼"NOR);
    set("long", 
"醉里挑灯看剑，梦回吹角连营。八百里分麾下灸，五十弦翻塞外声。沙场秋
点兵。马作的卢飞快，弓如霹雳弦惊。了却君王天下事，嬴得生前身后名。可怜
白发生！\n"NOR                                   
        );
        set("exits", ([ 
  	"down" : __DIR__"poemp2",
  	"up" : __DIR__"poemp4",
]));
        set("objects", ([
 	//__DIR__"npc/mother2" : 1,
                        ]) );
	set("no_death_penalty",1);
	set("NONPC", 1);
  	set("PK_FREE", 1);
  	set("no_fly", 1);
  	set("coor/x",-40);
 	set("coor/y",20);
   	set("coor/z",20);
	setup();
}
