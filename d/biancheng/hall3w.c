inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "万马堂左厅");
        set("long", @LONG
无论谁第一眼看到这大厅，都难免要吃一惊。大厅虽然只不过有十来丈宽，简
直长得令人无法想象。一个人若要从门口走到另一端去，说不定要走上一两千步。
大厅左边的墙上，画着的是万马奔腾，有的引颈长嘶，有的飞鬃扬蹄，每匹马的神
态都不同，每匹马都表现得栩栩如生，神骏无比。
LONG
        );
        set("exits", ([ 
	"east": __DIR__"hall3",
	]));
        set("objects", ([
        	__DIR__"npc/leleshan":	1,
	]) );
        set("coor/x",-15);
        set("coor/y",120);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
