#include <room.h>
inherit ROOM;
void create()
{
  set("short","长廊");
  set("long",@LONG
松木的廊栏已被香客和游人摸的发亮，廊脊上塑有九鲤化龙，双凤朝牡丹的图
像，颇据闽南建筑艺术风格。令人怀疑此寺与佛教南宗一脉相承。
LONG
  );
  set("exits",([
         "north":__DIR__"chanfang2.c",
//         "south":__DIR__"xiangji.c",
         "west" :__DIR__"houyuan.c"
               ]));
          set("objects", ([
                __DIR__"npc/bigmonk" : 1,
       ]) );

   
	set("coor/x",10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
}
