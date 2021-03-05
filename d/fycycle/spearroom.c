#include <room.h>
inherit ROOM;
void create()
{
	set("short", "铁马冰河");
	set("long", @LONG
走进此间，森森寒气扑面而来。黑色的墙壁下边，无规则地镶嵌着白色的长
石，如同冬河中破裂的浮冰。屋中空无一物，却有阵阵杀气从四壁涌来。你站在
屋中凝神观察，隐隐觉得四壁中杀气透壁而出，似乎中间隐藏十万甲兵。
LONG
        );
  	set("exits", ([ /* sizeof() == 4 */
		"center" : __DIR__"groundroom",
	]));

	set("objects", ([
               __DIR__"obj/spearbook" : 1,
                        ]) );
    	set("indoors", "fycycle");
	set("coor/x",-320);
	set("coor/y",100);
	set("coor/z",0);
	set("no_magic",1);
	set("no_spell",1);
    	setup();
}

