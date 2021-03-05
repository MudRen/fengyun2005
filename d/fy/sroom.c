// Tie@fengyun
#include <room.h>
inherit ROOM;
void create()
{
    set("short", "堂屋");
    set("long", @LONG
走过窄门，前面是一件破旧的堂屋，屋子里潮湿而阴暗，并不十分窄小，但只
有一桌，一床，一凳．更显得四壁箫然，空洞寂寞，也衬得那一盏孤灯更昏黄暗淡。
壁上的积尘未除，墙角上还结着蛛网．
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"southwest" : __DIR__"stone2",
      ]));
    set("objects", ([
	__DIR__"npc/yan": 1, 
	__DIR__"obj/bcloth": 2, 
      ]) );
    set("coor/x",260);
    set("coor/y",100);
    set("coor/z",0);
    set("map","fyeast");
    setup();

}
