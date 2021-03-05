#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "天柱峰");
	set("long", @LONG
过了金殿阁，就已来到武当最高峰--天柱峰。你仿似置身于仙境之中。山风拂
来，仿佛要乘风而去一般。这里云雾缭绕，有如陆海奔潮。众峰争奇，千壑幽深的
武当群山被浩淼千里的云海淹没，云随阳光、风向变化，忽而狂涛翻腾，忽而巨浪
奔涌，气象万千，惊人心魄。
LONG
	);
	set("exits", ([
        "eastdown" : __DIR__"feishengya",
        "westdown" : __DIR__"yinxuanyan",
                "northdown" : __DIR__"jindian",
	]));
	set("outdoors", "wudang");
	set("coor/x",10);
	set("coor/y",-70);
	set("coor/z",50);
    	set("objects", ([
        	__DIR__"npc/tianfeng14": 1,
        ]) );
	setup();
	
}
