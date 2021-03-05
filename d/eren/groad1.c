inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "村外鱼塘");
        set("long", @LONG
村外景色尤佳，石砌上的苔痕，垣墙外的野草，虬干的古梅，清幽的竹径，路
边有一方很深的池塘，塘内养着许多鱼鳖，有的白鲤已长到“丈大丈长”。如果你
抛下一块面饼，那些鱼会成团起来吞食，嘴皮伸到水面有茶碗样大，吞起东西来
“通通”地响。
LONG
        );
        set("exits", ([ 
	"southwest" : __DIR__"valley1",
	"northeast" : __DIR__"groad2a",
	]));
        set("objects", ([
        	__DIR__"obj/pond": 1,
	]) );
	set("outdoors", "eren");
        set("coor/x",20);
        set("coor/y",70);
        set("coor/z",0);
	set("map","eren");
	setup();
}

void reset()
{
        object *inv;
        object con, item;
        ::reset();
        con = present("pond", this_object());
        inv = all_inventory(con);
        if(!sizeof(inv)) {
        	item = new(__DIR__"obj/fish");
        	item->move(con);
        	item = new(__DIR__"obj/fish");
        	item->move(con);
        }
}