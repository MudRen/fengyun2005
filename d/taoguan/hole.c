#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "洞口");
	set("long", @LONG
山石上已无落脚之处，再往上爬非跌个鼻青眼肿不可。奇怪的是，这么高的山
壁上竟然有一个洞口，洞里黑漆漆的，洞口的岩石十分光滑，似乎经常有人进出。
你心里有一种不祥的感觉，堂堂的三清观怎么会在这洞里呢？
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"north" : __DIR__"hole3",
	]));
        set("item_desc", ([
                "up": "山石上已没有落脚之处。\n",
                "mountain": "山石上已没有落脚之处。\n",
                "山": "山石上已没有落脚之处。\n",
        ]) );
        set("outdoors", "taoguan");
	set("coor/x",0);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要爬什么？\n");
                return 1;
        }
        me = this_player();
        if( arg == "up" || arg == "山" || arg == "mountain")
        {
        	message_vision("$N慢慢地往山上爬去。\n", me);
        	message_vision(RED "不好！$N一个不小心掉了下去！\n"NOR , me);
        	me->move(__DIR__"road5.c");
        	me->receive_wound("kee", 50);
        	me->receive_wound("sen", 50);
        	me->receive_wound("gin", 50);
        	me->set_temp("last_damage_from","登山不慎摔死了。");
        	return 1;
        }
        else if( arg == "down") {
        	message_vision("$N慢慢地往山下爬去。\n", me);
                me->move(__DIR__"ping_tai.c");
	        return 1;
        }
        else
        {
                write("你不可以爬"+arg+"\n");
                return 1;
        }
}
