#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short",CYN"环云道"NOR);
    set("long", @LONG
环云道以南云街为中轴，贯穿整个风云南城，东侧是江湖人常去的客栈铁铺祭
剑亭等，西侧则是灯红酒绿的烟花之地，热闹非凡。虽然来来往往的好多都是初闯
江湖的男男女女，谁敢说不会有将来的将相王侯，高僧奇侠。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"northeast" : __DIR__"huanyun8",
	"west" : __DIR__"huanyun10",
      ]));
    set("outdoors", "fengyun");
    set("objects", ([
	//        __DIR__"npc/mei": 1,
      ]) );

    set("coor/x",40);
    set("coor/y",-280);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    //	replace_program(ROOM);
}

