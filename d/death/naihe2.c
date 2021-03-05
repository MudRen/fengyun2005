// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "冥府大道");
        set("long", @LONG
这里已到冥界的中心，路的两边是冥界四司，掌管人事轮回，名为忠，孝，节，
义，彰善惩恶，天理循环，到此报应，但凡来者无不前往一睹，以警自身。
LONG
        );
        set("exits", ([
                "north" : __DIR__"naihe",
		"northwest" : __DIR__"zong",
		"southwest" : __DIR__"jie",
		"northeast" : __DIR__"xiao",
		"southeast" : __DIR__"yi",
        ]) );
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
	set("no_fight",1);
	set("no_magic",1);
	setup();
        replace_program(ROOM);
}
 
