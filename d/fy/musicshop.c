#include <ansi.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "江山轩");
    set("long", @LONG
这家装饰豪华的乐器店似乎一夜之间就出现了。店铺正中赫然挂着前人的名
画--《廿四桥明月夜》，只可惜似是西贝之货。靠墙的货架上一一陈列的都是当
今天下名家制作的古琴，琵琶，笛萧等物，颇有不凡之风。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"swind32",
	"up" : __DIR__"musicshop2",
      ]));

    set("objects", ([
	__DIR__"npc/gou" : 1,
      ]) );


    set("indoors", "fengyun");
    set("coor/x",-20);
    set("coor/y",-200);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);
}

