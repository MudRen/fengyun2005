inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "村居小院");
        set("long", @LONG
小院很清雅。挂满丝瓜、豆荚的篱笆上，绿油油的叶子淋浴在温煦的阳光下，
给人一种幽美、恬静的感觉。三间明亮的北屋，炊烟慢慢从屋顶上轻袅地飘起，远
就能闻到饭菜的香味，女主人肯定在灶台上忙碌了吧。
LONG
        );
        set("exits", ([ 
	"south" : __DIR__"groad3a",
	]));
        set("objects", ([
//        	__DIR__"npc/chunliu":1,
	]) );
        set("coor/x",60);
        set("coor/y",100);
        set("coor/z",0);
	set("map","eren");
	setup();
}
