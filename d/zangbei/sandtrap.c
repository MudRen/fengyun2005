#include <ansi.h>
inherit ROOM;

void create()
{
	object me;
	me = this_player();
	set("short", "沙穴");

	set("long", @LONG
一个沙子的洞穴，脚下是柔软的沙子，四周的沙墙象随时就可能坍塌而把你埋
葬，头顶不时的有细沙落下，漆黑中有什么东西不停地在你身边蠕动，软软的，湿
湿的，你不禁头皮都麻了。
LONG
	);
	set("indoors", "eren");
	set("objects", ([
		__DIR__"npc/sandworm" : 2,
	]) );
	set("coor/x",0);
    	set("coor/y",0);
	set("coor/z",0);
	setup();
}

void init()
{	
	add_action("do_climb", "climb");
}


int do_climb(string arg)
{
    object obj, me;
    int	kar;
    
    if(!arg || arg=="") return notify_fail("你要往哪里爬？\n");
    me = this_player();
    if( arg == "wall" || arg == "洞壁" || arg == "up")
    {
        if( me->is_busy() )
            return notify_fail("你的动作还没有完成，不能移动。\n");
        message_vision("$N使出吃奶的力量，顺着沙壁向上爬去。\n", me);
        me->start_busy(1);
        call_out("climb_wall", 2, me);
        return 1;
    }
    return notify_fail("你不可以爬"+arg+"！\n");
}       

int climb_wall(object me)
{
    int kar;
    
    if (me->is_ghost()) return 0;
    kar = (int)me->query("kar");
    if( kar > 60 ) kar = 60;
    if( random(60 - kar) < 15 )
    {
        me->move(__DIR__"yangguan2.c");
        message_vision("$N从沙穴中艰难地爬了出来。\n", me);
    }
    else message_vision("$N手上一个没抓稳，又掉了下来。\n", me);
    return 1;
}