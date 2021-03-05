inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "偏厅");
        set("long", @LONG
偏厅虽远不及正厅宽阔有气势，却布置得富丽堂皇，东墙上挂着两张纯白的虎
皮，是马空群当年游猎关东的战利品。这儿是招待一般客人或者下属的地方，只要
一声令下，半盏烟的功夫就能端上一桌热腾腾的酒菜。偏厅左侧的走廊通向客房。
LONG
        );
        set("exits", ([ 
	"west": __DIR__"hall1",
	"east": __DIR__"corridor",
	]));
        set("objects", ([
		__DIR__"npc/murong1":	2,
	]) );
        set("coor/x",-5);
        set("coor/y",100);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
