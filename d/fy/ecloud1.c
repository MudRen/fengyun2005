inherit ROOM;

#include <ansi.h>

void create()
{
    set("short", HIG"东地巷"NOR);
    set("long", @LONG
与西城区的豪富奢华相对，这里道路两旁是普普通通的民居，三教九流，龙蛇
混集，不管你是达官贵人，还是贩夫走卒，只要你身上有两钱儿，在这里就会受到
热情的招呼。街上有卖菜的，卖肉的，卖玩具的，卖艺的，卖药的。。。。几个光
屁股的娃子在南面的私塾学堂里上蹿下跳，北面的鱼龙巷里熙熙攘攘热闹非凡。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"ecloud2",
	"west" : __DIR__"didoor",
	"south" : __DIR__"washroom",
	"north" : __DIR__"yulong1",
      ]));
    set("objects", ([
	__DIR__"npc/caifan2" : 1,
      ]) );

    set("outdoors", "fengyun");
    set("coor/x",80);
    set("coor/y",0);
    set("coor/z",0);
    set("map","fyeast");
    setup();

}
