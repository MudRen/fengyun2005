
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "武当观");
	set("long", @LONG
红色的围墙，黄色的大门。门上挂著一块金匾，上书“武当观”三个龙飞凤舞
的大字。大门左右各卧著一只雄伟的石狮。一名头戴黄色道冠，身穿青色道袍的知
客道人，靠门而立。
LONG
	);
	set("exits", ([ 
		"northdown" : __DIR__"road3",
		"enter" : __DIR__"wudang1",
	]));
	set("objects", ([ 
		__DIR__"npc/wtaoist" : 1,
	]));
	set("outdoors", "wudang");
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
        object *enemy, ob;
        int i;

        if( userp(me) && (ob=present("waiter taoist", this_object()))) {
		enemy = ob->query_enemy();
		i = sizeof(enemy);
		while(i--) {
                	if( enemy[i] == me )
                                return notify_fail(HIY + ob->name()+"对" + me->name() 
				+ "喝道：想跑？没那么容易！\n" + HIR + ob->name() + 
				"把" + me->name() + "挡了回来！\n" +NOR);
                }
        }
        return 1;
}

