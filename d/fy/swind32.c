#include <ansi.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIC"南云街"NOR);
    set("long", @LONG
街道就象水洗过那么的干净，汉白玉砌的路面光明如镜，两侧的瓦房高大宏伟，
双人合抱的杨树十步一株，整齐的排在两边。两边的街道似乎一下子窄了很多，因
为街上三五成群的都是一些文人墨客，西面是一家乐器店，而东面画香悠远，则是
新开不久的一家画坊。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"swind5",
	"north" : __DIR__"swind31",
	"east" : __DIR__"pictureshop",
	"west" : __DIR__"musicshop",
      ]));


    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",-200);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);
}

