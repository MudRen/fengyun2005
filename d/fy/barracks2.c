#include <ansi.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "西营");
    set("long", @LONG
风云城东西两门各有一兵营镇守，主要负责紫禁城的防卫，此处为西营。随着
金钱帮的势力越来越大，据说西营的统带等或被利诱或被威慑，已渐渐为上官金虹
所用，皇上对此心知肚明，却也只挣一只眼闭一只眼。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"wcloud5",
      ]));


    set("indoors", "fengyun");
    set("coor/x",-280);
    set("coor/y",-20);
    set("coor/z",0);
    set("map","fywest");
    setup();
    replace_program(ROOM);
}

