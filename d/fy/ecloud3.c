inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIG"东地巷"NOR);
    set("long", @LONG
这儿是东城最气派的地方，因为这里是金狮镖局，因为金狮镖局里有一招击毙
太行四虎的诸葛雷和拳镇大江南北的局主“金狮掌”查猛，更因为金狮镖局行走江
湖二十年，大大小小从来没有丢过一支镖。在这里进进出出的大部分都是腰带兵刃，
虎背熊腰的江湖人物。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"ecloud31",
	"west" : __DIR__"ecloud2",
	"north" : __DIR__"stopwin",
	"south" : __DIR__"goldlion",
      ]));
    set("objects", ([
	__DIR__"npc/wanfan" : 1,
      ]) );

    set("outdoors", "fengyun");
    set("coor/x",160);
    set("coor/y",0);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    replace_program(ROOM);
}
