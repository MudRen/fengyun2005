inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "东侧峰");
        set("long", @LONG
东侧峰，当地人叫“夏诺多吉”，水晶石般的山峰傲然耸峙，像少年，雄健刚
毅，神彩奕奕。雪线下冰川直插碧绿的原始森林。雪山、峭壁、陡崖、海子、冰川、
草场、森林、溪流，一片静谧、安详。山脚下有一片园林，当地人叫它[33m快活林[32m。
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"nianqing",
		"northeast":  __DIR__"mugecuo",
		"southdown": __DIR__"happywood",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1680);
        set("coor/y",620);
        set("coor/z",20);
	set("map","zbwest");
	setup();

}
