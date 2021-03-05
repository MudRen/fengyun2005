#include <ansi.h>

inherit ROOM;
void create()
{
    set("short", "镖局货仓");
    set("long", @LONG
金狮镖局声誉如日中天，从未失镖。顾主的货物在这里堆积如山。镖局的伙计
们正在手忙脚乱的往镖车上装载货物。虽然每个伙计都已满头大汗，尽力而为，但
还是忙不过来。如果你有心帮忙的话，可以在这里装货（ｗｏｒｋ）。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"southeast" : __DIR__"goldlion",
      ]));
    set("objects", ([
	__DIR__"npc/huoji" : 2,
	__DIR__"npc/bad_huoji" : 1,
      ]) );

    set("coor/x",140);
    set("coor/y",-40);
    set("coor/z",0);
    set("map","fyeast");
    setup();
}

void init()
{
    add_action("do_work", "work");
}

int do_work(string arg)
{
//  object ob;
    object me;

    me = this_player();
    message_vision(WHT"$N帮镖局的伙计往镖车上装载货物，差点没累昏过去！！\n"NOR,me);
    tell_object(me,"（经常检查自己的精气神状况，以免以外死亡）\n");
    
    me->receive_damage("gin",100);
    me->receive_damage("sen",100);
    me->set_temp("last_damage_from","在金狮镖局干活劳累过度而死。\n");
    me->set("marks/金狮", time());
    return 1;
}
