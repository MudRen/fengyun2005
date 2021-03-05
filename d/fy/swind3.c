#include <ansi.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIC"南云街"NOR);
    set("long", @LONG
南云街到这儿向两侧延伸开去，称环云道。东侧是一些小饭馆，打铁铺，缝衣
店等；西首是供风云大老爷们儿泡澡聊天的浸龙堂，和当今武林第一美人天天要去，
风云城里无人不晓的浣凰堂，再往西面是千金楼，自从金钱帮涉猎商会，赌坊，妓
业以后，千金楼便和金钱帮一并控制了风云城和大江南北所有的妓寨青楼。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"swind31",
	"north" : __DIR__"swind2",
	"east" : __DIR__"huanyun6",
	"west" : __DIR__"huanyun1",
      ]));


    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",-120);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);
}

