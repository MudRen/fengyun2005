#include <ansi.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "彩云楼");
    set("long", @LONG
二楼窗檐下悬着的金铃，居然在风中纹丝不动。据说每当有贵客到访时，金
铃会无风自动，这个时候会有穿着镶金丝白袍的小童出门迎接。传说江山轩的主
人曾经拜在白云剑派门下学艺，又不满云之洁白，是以将此地命名彩云楼。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"down" : __DIR__"musicshop",
      ]));


    set("indoors", "fengyun");
    set("coor/x",-20);
    set("coor/y",-200);
    set("coor/z",10);
    setup();
    replace_program(ROOM);
}

