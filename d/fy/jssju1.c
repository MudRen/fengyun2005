#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "弘祖阁");
    set("long", @LONG
二楼进门便是一扇屏风，画着一个手持竹杖、身背行囊的中年儒生，书案上整
整齐齐地堆放着丝轴，是各地的图经地志。门楣上挂着副联子：
    途穷不忧，瞑则寝树石之间	行误不悔，饥则啖草木之实
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"down" : __DIR__"jssju",
	"up" : 	__DIR__"jssju2",
      ]));
    set("objects", ([
	__DIR__"npc/mapseller" : 1,
      ]) );

    set("coor/x",-40);
    set("coor/y",80);
    set("coor/z",10);
    set("map","fynorth");
    setup();
    replace_program(ROOM);
}

