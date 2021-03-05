inherit ROOM;

#include <ansi.h>

void create()
{
    set("short", HIG"东地巷"NOR);
    set("long", @LONG
与西城区的豪富奢华相对，这里道路两旁是普普通通的民居，三教九流，龙蛇
混杂，南侧原是风云城扩建前的衙门旧址，两个石狮子已经倒了一双，落漆的朱红
大门前用白粉写了“长乐坊”三字。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"ecloud3",
	"west" : __DIR__"ecloud1",
	"south": __DIR__"manhome",
      ]));
    set("objects", ([
	__DIR__"npc/fatman" : 1,
      ]) );

    set("outdoors", "fengyun");
    set("coor/x",120);
    set("coor/y",0);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    replace_program(ROOM);
}

