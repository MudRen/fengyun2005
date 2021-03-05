#include <ansi.h>
inherit ROOM;

void create()
{
	object me;
	me = this_player();
	set("short", "陷井");

	set("long", @LONG
这是一个深深的葫芦型的陷井，井壁潮湿而又光滑。井底甚为宽敞。你脚边是
三具已经腐烂的尸体，四周还散布着不少黄白之物，显然是饿虎山上的强盗们时不
时在井口方便的结果。旁边似乎还有几只大老鼠，正在黑暗中窥视着你，仿佛在等
着将你作为下一顿美餐。
LONG);
	set("type","street");
	set("no_magic",1);
	set("outdoors","bawang");
	setup();
}

void init()
{	
	object me;
	add_action("do_climb", "climb");
	if( interactive( me = this_player()))
	{
		remove_call_out("sinking");
		call_out("sinking", 1, me);
	}
}

int sinking(object me)
{
	tell_object(me,RED"\n扑鼻的恶臭猛地涌进你的鼻腔，你顿时感到一阵窒息......\n\n你觉得天旋地转，意识渐渐模糊，耳中依稀传来井口两个喽罗得意的笑声......\n\n"NOR);
	message_vision("$N脚下一个踉跄昏倒在地上。\n", me);
	me->unconcious();
	return 0;
}

int do_climb(string arg)
{
    object obj, me;
    int	kar;
    
    if(!arg || arg=="") return notify_fail("你要往哪里爬？\n");
    me = this_player();
    if( arg == "wall" || arg == "井壁" || arg == "up")
    {
        if( me->is_busy() )
            return notify_fail("你的动作还没有完成，不能移动。\n");
        message_vision("$N使出吃奶的力量，顺着井壁向上爬去。\n", me);
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
        me->move(__DIR__"shanlu2.c");
        message_vision("$N从陷阱中臭烘烘的爬了出来。\n", me);
    }
    else message_vision("$N手上一个没抓稳，又掉了下来。\n", me);
    return 1;
}