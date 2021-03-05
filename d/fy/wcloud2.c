inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", WHT"西风道"NOR);
    set("long", @LONG
愈近金钱总舵，道路两侧的豪宅更是鳞次栉比。每家商号门前都有一面黄底金
边的锦旗飞扬，上面绣着小小的“金钱”两字，分行遍布京广，天下第一豪富的南
宫世家的钱庄前亦不例外。漫步在繁华喧嚣的大街上，一切仿佛梦幻一般。向北眺
望，一座黄金巨塔似乎就近在咫尺，耀眼的金色令人眩目窒息。（精致鸟笼需给小
胖子２０两银子） 
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"qianyin",
	"north" : __DIR__"nanbank",
	"west"  : __DIR__"wcloud3",
	"east"  : __DIR__"wcloud1",
      ]));
    set("objects", ([
	__DIR__"npc/fat" : 1,
      ]) );


    set("outdoors", "fengyun");
    set("coor/x",-120);
    set("coor/y",0);
    set("coor/z",0);
    set("map","fywest");
    setup();
    replace_program(ROOM);
}
