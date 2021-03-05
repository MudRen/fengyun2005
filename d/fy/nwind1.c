#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY"汉白玉天街"NOR);
    set("long", @LONG
天坛北行是宽阔的汉白玉街，两旁的亭台阁苑堂皇华丽，尽头就是紫禁城，街
上行人衣着雍容，神色倨傲，官家的大轿穿梭不息。西面及第街上是天下读书人的
圣地贡院，东面的则是洗礼池，水色墨绿，召见进宫的将士皆需在此肃立三刻。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"tiandoor",
	"north" : __DIR__"nwind2",
	"east" : __DIR__"ponder",
	"west" : __DIR__"jidijie",
      ]));
    set("outdoors", "fengyun");
    set("objects", ([
	__DIR__"npc/zhu": 1,
	//	__DIR__"npc/xiwei": 4,
      ]) );

    set("coor/x",0);
    set("coor/y",80);
    set("coor/z",0);
    set("map","fynorth");
    setup();
}
