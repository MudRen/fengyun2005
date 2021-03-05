#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY"天坛"NOR);
    set("long",
"天坛为历代帝王祭天之所在，神庙庄严肃穆，依“天圆地方”而建，布局呈回
字形，分内外两坛，内坛二十八根金丝楠木大柱，里圈的四根寓意春夏秋冬四季，
中间十二根寓意十二个月，最外十二根寓意十二时辰以及周天星宿。殿顶覆盖上青、
中黄、下绿三色琉璃，寓意天、地、万物。琉璃门上高悬金匾："+HIY"

                      天         坛
                      
"NOR 
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"nwind1",
	"south" : __DIR__"fysquare",
	"east"  : __DIR__"fyge", 
"west"  : __DIR__"lotto", 
      ]));
    set("outdoors", "fengyun");
    set("objects", ([
	//        __DIR__"npc/mei": 1,
      ]) );

    set("coor/x",0);
    set("coor/y",40);
    set("coor/z",0);
    set("map","fynorth");
    setup();
    replace_program(ROOM);       //add by ldb 希望刷掉乱走的NPC 

}
