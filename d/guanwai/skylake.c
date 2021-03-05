inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIB"天湖"NOR);

	set("long", @LONG
转过一个山拗，群峰环抱之中，竟然是白茫茫的一片湖水。原来这个大湖，便
是世界的第一高湖，藏名叫做“腾格里海”，但见湖水清澈，碧波荡漾，湖中有片
片闪光的浮冰，湖边水连天，天连水，恍如湖泊就在天上。藏胞称为『纳木错』,
意即天湖。天湖的西侧是个小小的瀑布，水花飞溅。      
LONG);

	set("type","street");
	set("exits",([
		"southup":__DIR__"shanyao",
	]) );
        set("item_desc", ([
        	"lake": "天湖的水是天山上的寒雪所化，其寒似冰。\n",
        	"湖": 	"天湖的水是天山上的寒雪所化，其寒似冰。\n",
        	"腾格里海": 	"天湖的水是天山上的寒雪所化，其寒似冰。\n",
        	"瀑布": 		"水花飞溅，下面是一条小河，通向圣母峰山脚（jump）。\n",
        	"waterfall":"水花飞溅，下面是一条小河，通向圣母峰山脚（jump）。\n",
        ]));
        
        set("outdoors", "guanwai");
		set("coor/x",-50);
		set("coor/y",-90);
		set("coor/z",100);
        set("resource/water",1);
     	set("liquid",([
            "name":"冰水",
            "container":"腾格里海",
            ]));

	setup();
}

int valid_leave(object me, string dir)
{
	if( userp(me) && dir == "southup" )
	{
        if( me->query("cps")< 20 )
            	return notify_fail("抬头远眺，圣母雪峰直插云霄，雪连天，天接雪，不知何处才是尽头，
你心中一悚，刚刚迈出去的脚不自禁又收了回来。。。（需２０内在定力）\n");
        else
        {
                 message_vision(HIR "\n\n$N但觉热血沸腾，壮怀激烈，仰天长啸一声，大步向着世界之颠迈进。\n\n"NOR,me);
        	 return 1;
        }
	}
	return 1;
}


void	init(){
	add_action("do_dip","dip");
	add_action("do_jump", "jump");
}


int do_dip(string arg){
	
	object weapon, me;
	
	me = this_player();
	
	if (me->is_busy())
		return notify_fail("你现在正忙。\n");
		
	weapon = me->query_temp("weapon");
	
	if (objectp(weapon))
	{
		tell_object(me, WHT"你把"+ weapon->name()+NOR WHT"浸入湖水之中，只觉一股寒气传了上来，几乎拿捏不住。\n"NOR);
		weapon->set_temp("icy_dipped",1);
	} else
		tell_object(me,WHT"你蹲下身子把手浸入湖水之中，透心的寒意啊！\n"NOR);
	
	me->perform_busy(1);	
	return 1;
}


int do_jump(string arg)
{
        object 	me;
		me = this_player();
		if (me->is_fighting() || me->is_busy())
		{
			write("你现在正忙，没空跳下去。\n");
			return 1;
		}

		if(!arg) 
		{
			write("你要跳向哪里？\n");
			return 1;
		}

		if( arg == "down" || arg == "waterfall" || arg=="瀑布")
        {
				message_vision("$N深深吸了口气，纵身向瀑布下跃去！\n",me);
				me->perform_busy(2);
        		call_out("fliping",2,me);
        		return 1;
        }
        else
        {
                write("你不可以跳"+arg+"。\n");
                return 1;
        }
}


int fliping(object me)
{
		object room;
		if( !me->is_ghost() && environment(me) == this_object()) 
		{
			room=find_object(__DIR__"shanjiao");
			if (!objectp(room)) room=load_object(__DIR__"shanjiao");
			tell_room(room, me->name() + "湿淋淋地从河里爬了上来。\n");
			me->move(room);      		
		}
        return 1;
}
