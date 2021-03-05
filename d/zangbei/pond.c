inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "鱼池");
        set("long", @LONG
满天夕阳，鱼池在夕阳下鳞鳞生光。韩棠并不象个养鱼的人，但他的确养鱼，
养了很多鱼，养在鱼缸里有时他甚至会将小鱼养在自己喝茶的盖碗中。大多数时候
他都找其他那些养鱼的人在一起静静地坐在水池旁，坐在鱼缸边，静静地欣赏鱼在
水中那种悠然自得的神态，生动美妙的姿势。
LONG
        );
        set("exits", ([ 
		"southeast" :  	__DIR__"sroad3",
	]));
        set("objects", ([
		__DIR__"npc/hantang":	1,
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1420);
        set("coor/y",990);
        set("coor/z",-50);
	set("map","zbeast");
        set("home",1);
	setup();
}

