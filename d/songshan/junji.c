#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "峻极峰");
        set("long", @LONG
太室山滂礴如卧，“峻极于天”，有卧龙之称，峻极峰是太室山的主峰，高耸
入云，两面悬崖，下面则是险关要隘，顺此下去便是大大有名的箕山，巢父，许由
皆避官于此。
LONG
        );
        set("exits", ([ 
  		"southdown" : __DIR__"laomu",
	]));
        set("outdoors", "songshan");
        set("objects", ([
                __DIR__"npc/xian2" : 1,
        ]) );
	set("coor/x",20);
	set("coor/y",40);
	set("coor/z",10);
	setup();

}
