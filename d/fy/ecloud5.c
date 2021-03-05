inherit ROOM;
#include <ansi.h>
void create()
{
    set("short",HIG"东门西"NOR);
    set("long", @LONG
再往东就是东城门了，东门外是通向山里的一条路。东门和其他的城门没有什
么不同，上面贴满了告示和通缉令。听说当年大盗祈潼就是在东门被人发现，报告
了官府后被抓住的。城门内有几幢不起眼的红房，是城里守军的行营。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"egate",
	"west" : __DIR__"ecloud4",
	"south" : __DIR__"barracks1",
      ]));
    set("objects", ([
	__DIR__"npc/dtz": 2,
      ]) );

    set("outdoors", "fengyun");
    set("coor/x",280);
    set("coor/y",0);
    set("coor/z",0);
    set("map","fyeast");
    setup();
}



int valid_leave(object me, string dir)
{
//  object *inv,ob;
//  int i;

    if( userp(me))
    {
	if (dir == "east" && me->query_temp("annie/xiangsi_enterance") == 3)
	    me->set_temp("annie/xiangsi_enterance",4);
	else
	    me->delete_temp("annie/xiangsi_enterance");
    }
    return 1;
}