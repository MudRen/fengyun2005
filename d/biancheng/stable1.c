inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "南马房");
        set("long", @LONG
马房前的一株孤树在寒风中不停的发抖，抖得满树秋叶一片片落下来。这里养
着的是千中选一、万金难求的种马。南间是马夫住的小屋，三丈见方的屋子里一半
摆满了马鞍，马鞭，马镫等，角落里有几张小床。
LONG
        );
        set("exits", ([ 
	"east": __DIR__"yard2",
	"north": __DIR__"stable2",
	]));
        set("objects", ([
        	__DIR__"npc/jiaolaoda":	1,
	]) );
	set("coor/x",-15);
        set("coor/y",95);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
