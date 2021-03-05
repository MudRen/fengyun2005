// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "冥府节司");
        set("long", @LONG
自古以来，男女大防，节字难守，多少女子，因种种诱惑，身败名裂，受那地
狱分尸之苦。节司两旁尽是贞节女子的画像，画像中簇拥着一位女子端坐案上，正
是节司的掌管--绿珠，当年虽身为石崇侍妾，可宁死不随他人，终跳楼而死，节烈
之气，名扬千古。在其光芒之中，正受分尸之刑的男男女女，更为丑陋。
LONG
        );
        set("exits", ([
		"northeast" : __DIR__"naihe2",
        ]) );
        set("objects", ([
                __DIR__"npc/greengirl":1,
        ]) );
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
 
