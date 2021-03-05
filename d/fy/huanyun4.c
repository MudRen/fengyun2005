#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", CYN"环云道"NOR);
    set("long", @LONG
环云道以南云街为中轴，贯穿整个风云南城，东侧是江湖人常去的客栈铁铺祭
剑亭等，西侧则是灯红酒绿的烟花之地，热闹非凡。虽然来来往往的好多都是初闯
江湖的男男女女，谁敢说不会有将来的将相王侯，高僧奇侠。路东侧是[1;31m凤求凰客栈[0;32m，
别看它小，初入风云的都是从这儿起步踏入江湖。西侧不知是什么去处，只是常常
可以听到喜庆的烟花爆竹之声。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"huanyun5",
	"east" :__DIR__"fqkhotel",
	"west" :__DIR__"marry_room",
	"south" :__DIR__"huanyun8",
      ]));
    set("outdoors", "fengyun");
    set("objects", ([
	//        __DIR__"npc/mei": 1,
      ]) );

    set("coor/x",60);
    set("coor/y",-200);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    //	replace_program(ROOM);
}

