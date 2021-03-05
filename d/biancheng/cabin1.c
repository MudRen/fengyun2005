inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "小木屋");
        set("long", @LONG
一张虽然已残旧、却是红木做的八仙桌，就摆在门对面。桌上有一个缺嘴茶壶，
三个茶碗，还供着个神龛，里面供的却不是关夫子，而是手里抱着胖娃娃的送子观
音。角落里堆着三口樟木箱子，另一个角落摆着显然已经很久没有人用过的妆台。
一面菱花铜镜上满是灰尘，木梳的齿也断了好几根。
LONG
        );
        set("exits", ([ 
	"east": __DIR__"smallroad1",
	]));
        set("objects", ([
	]) );
	set("coor/x",-60);
        set("coor/y",-10);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
