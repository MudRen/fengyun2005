inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "果园");
        set("long", @LONG
清凉的果树园子里，浓密的树叶在伸展开去的枝条上微微的摆动，怎么也藏不
住那一累累的稳重的果子。在那树丛里还留得有偶尔闪光的露珠，就象在雾夜中耀
眼的星星一样。那些红色果皮上有一层茸毛，或者是一层薄霜，显得柔软而润湿。
LONG
        );
        set("exits", ([ 
	"west" : __DIR__"vroad5",
	"northeast": __DIR__"orchard2",
	]));
        set("objects", ([

	]) );
	set("outdoors", "eren");
        set("coor/x",110);
        set("coor/y",60);
        set("coor/z",0);
	set("map","eren");
	setup();
}
