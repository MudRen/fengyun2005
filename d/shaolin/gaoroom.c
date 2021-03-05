// annie 07.2003
// dancing_faery@hotmail.com

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "高寒殿");
        set("long", @LONG
人云高处不胜寒。这里是少林寺历代先哲的埋骨之处，数开去历历都是寺里高
僧，尽管都曾名扬天下，到最后却仍免不了枯守青灯古佛，寂寞一生。纵使曾有人
私自下山，最后亦为寺规所迫，回返少林，长伴木鱼，终老寺中。
　　这里的柱子上刻着一串名字：赤无极，天意，马休，高寒．．．
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"kuoran",
]));
        set("objects", ([
                __DIR__"npc/gao" : 1,
       ]) );

//	set("no_fly",1);	able to fly; annie.
	set("coor/x",30);
	set("coor/y",-10);
	set("coor/z",-10);
	setup();

}


void reset()
{
	if (present("gao meng",this_object()))
		return;
	::reset();

}
