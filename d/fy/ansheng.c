#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "安生棺材店");
    set("long", @LONG
店门口的招牌是几个已被雨淋日晒得变了颜色的花圈。店口的地上放着几口打
造好，但还没有上漆的薄皮棺材。 四面的墙上零乱的挂着几串纸钱和纸花。墙角
放着一口上好的红木棺材，但棺盖似乎并没有盖好。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"stone2",
      ]));
    set("objects", ([
	__DIR__"npc/cafen" : 1,
	__DIR__"npc/an_huoji" : 1,
      ]) );

    set("coor/x",260);
    set("coor/y",80);
    set("coor/z",0);
    set("map","fyeast");
    setup();
}

void init() {
    add_action("do_push","push");
}

int do_push(string arg) {
    object hu, me;
    me = this_player();
    if(!arg) return 0;
    if(arg != "coffin" && arg != "棺材") {
	return 0;
    }
    	if(REWARD_D->riddle_check( me, "勇探地牢")!=3
    		&& !REWARD_D->check_m_success( me, "勇探地牢")){
			return notify_fail("棺材，晦气。。还是不要碰的为妙。\n");
    }
    if(present("huo ji", this_object())) {
		hu = present("huo ji", this_object());
		message_vision("$N似不经意地拦在$n身前，笑呵呵的道：这位客官，随便看，随便看。。\n",
	  		hu, this_player());
		return 1;
    }
    message_vision(HIY"\n\n$N用力推开棺材盖子，一个不小心，整个人栽了下去！\n\n"NOR,this_player());
    this_player()->move(AREA_CAVE"storage");
    return 1;
}
