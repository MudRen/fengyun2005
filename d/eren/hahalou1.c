inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "哈哈酒楼");
        set("long", @LONG
雅致的厅房中，摆着五六张雅致的桌子，有两张桌子上坐着几人浅浅饮酒，低
低谈笑。柜台后站着个矮矮胖胖，笑脸圆圆，和气生财的酒店掌柜。饮酒的几人，
衣衫华丽，谈笑从容。
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"vroad2",
		"east" : __DIR__"hahalou2",
	]));
        set("objects", ([
        	__DIR__"npc/haha": 1,
	]) );
	set("coor/x",50);
        set("coor/y",50);
        set("coor/z",0);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
