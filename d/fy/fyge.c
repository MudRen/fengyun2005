#include <room.h>
inherit ROOM;
string look_sign(object me);
void create()
{
    set("short", "风云阁");
    set("long", @LONG
风云阁的主人就是当年天下大名鼎鼎的小李飞刀。虽然李探花已经隐退多时，
但是还有客人慕名来到此阁，以求一面之缘。阁中大红波斯地毯铺地，富丽堂皇。
朱红的大门两侧各挂一幅石刻的对联儿：
[33m
                	一门七进士
                	父子三探花
[2;37;0m
LONG
    );
    set("valid_startroom", 1);
    set("item_desc", ([
//		"sign": (: look_sign :),
      ]) );

    set("exits", ([
	"west"    	: __DIR__"tiandoor",
	"up"		: __DIR__"fyyage",
      ]) );

    set("objects", ([
		__DIR__"npc/fywaiter" : 1,
      ]) );
    set("NONPC",1);
    set("coor/x",40);
    set("coor/y",40);
    set("coor/z",0);
    set("map","fynorth");
    setup();

    // To "load" the board, don't ever "clone" a bulletin board.
    call_other( "/obj/board/common_fy", "???" );
}

