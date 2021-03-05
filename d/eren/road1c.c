inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "松林小道");
        set("long", @LONG
两旁是松林，娇嫩的松球果象黄澄澄的小灯笼似的闪亮，每一根松针都各自独
立地闪烁着红里透蓝的羽翎的色彩，鱼鳞状的绿色树干被点点阳光照耀得贝母般绚
烂。云杉挺立着，枝权互相紧紧偎依在一起，形成了一堵厚厚的墙壁，很象一支步
伐一致的军队。
LONG
        );
        set("exits", ([ 
		"eastup" : __DIR__"road1b",
		"west": __DIR__"road1d",
	]));
        set("objects", ([
             	__DIR__"npc/xuedahan":	1,   	
	]) );
	set("outdoors", "eren");
        set("coor/x",-30);
        set("coor/y",10);
        set("coor/z",10);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
