inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "竹林");
        set("long", @LONG
竹林稀疏了，透过枝叶，隐约看见北面有一间竹舍，远远还可以闻到一股奇异
的气味，不似寻常农家稻米或饭菜的香味。脚边也多了许多矮小的植物，似乎是有
人专门栽种的，最引人注目的是一些深蓝色的花，形状奇特，每朵花便像是一只鞋
子，幽香淡淡，不知其名。
LONG
        );
        set("exits", ([ 
	"north" : __DIR__"chunliuju1",
	"south" : __DIR__"groad4a",
	"west" : __DIR__"groad3c",
	]));
        set("objects", ([
	]) );
	set("outdoors", "eren");
        set("coor/x",90);
        set("coor/y",90);
        set("coor/z",0);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
