//mac's qiyan.c
#include <room.h>

inherit ROOM;

void create()
{
  set("short","齐烟九点");
  set("long",@LONG
一座大牌坊出现在青石铺面的山阶上，上书四个大字：齐烟九点。山东春秋战
国时是鲁国和齐国的地盘。向下俯视可以看到远处济南城烟囱上的炊烟及山脚下福
字形的舜耕山庄。此山的古老以及此城的人丁兴旺据此可见一斑。
LONG
  );
  set("exits",([
         "westdown":AREA_JINAN"tanghuai.c",
         "eastup"  :__DIR__"fudi.c"
               ]));
        set("objects", ([
                __DIR__"npc/monk" : 2,
       ]) );
        set("outdoors", "qianfo");
	set("coor/x",-10);
	set("coor/y",-100);
	set("coor/z",-20);
	setup();
  replace_program(ROOM);
}
