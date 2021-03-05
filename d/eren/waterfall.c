inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "三叠泉");
        set("long", @LONG
瀑布不高，却有三层，因此而得名。风至，瀑布半途忽然如花雨散开，没有直
接垂下来，而变成雾雨，洒落在水边。山风虎虎，云雾笼罩，时见山不见顶，岩山
湿冷，虽是名山胜景，却令人不愿久留。
LONG
        );
        set("exits", ([ 
	"northwest" : __DIR__"vroad5",
	]));
        set("item_desc", ([
                "瀑布": "仰首往上看，山风虎虎，云雾笼罩，难辨虚实。\n",
                "waterfall": "仰首往上看，山风虎虎，云雾笼罩，难辨虚实。\n",
        ]) );
        
        set("objects", ([
	]) );
	set("outdoors", "eren");
        set("coor/x",110);
        set("coor/y",50);
        set("coor/z",0);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
