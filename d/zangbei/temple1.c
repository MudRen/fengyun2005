inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "冲古寺");
        set("long", @LONG
冲古寺位于仙乃日雪峰脚下，隶属贡嘎郎吉岭寺，根戈活佛派有扎巴在此念经
颂佛，小经堂内供有泥塑释迦。寺内终年香火茂盛，据藏经上说，在冲古寺转十五
次经相当于念一亿嘛呢的功德，所以就连附近的山上的土匪也会来这里转山转寺，
赎自己犯下的罪恶。
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"tianxin",
		"south":  __DIR__"zhayi",
		"northeast": __DIR__"temple1a",
	]));
        set("objects", ([
        	__DIR__"npc/monk1":	1,
	]) );
	set("coor/x",-1710);
        set("coor/y",650);
        set("coor/z",20);
	set("map","zbwest");
	setup();

}

void 	init(){
	add_action("do_around","around");
}


int do_around(){
	
	object me = this_player();
	object tong = me->query_temp("weapon");
	
	
	if (!tong || tong->name() != "转经筒")
		return notify_fail("没有经筒，如何转经？\n");
	
	if (me->is_busy())
		return notify_fail("你现在忙得很，没空转经。\n");
				
	message_vision(YEL"$N转动着手中的小经筒，虔诚地颂着经文，绕着"
		+this_object()->query("short") + "慢慢走了一圈。\n"NOR, me);
	me->start_busy(1);
	
	if (me->query("marks/转经") 	||	REWARD_D->riddle_check(me,"灵童转世")!= 1
		|| me->query_temp("zhuanjing/chonggu"))	return 1;
						
	me->add_temp("zhuan_around",1);
	
	if (random (me->query_temp("zhuan_around"))>= 10)
	{
		tell_object(me,WHT"\n你在"+ query("short")+"转经完毕，对密宗佛法的了解略有提高。\n"NOR);	
		me->delete_temp("zhuan_around");
		me->set_temp("zhuanjing/chonggu",1);
		
		if (mapp (me->query_temp("zhuanjing")))
		if (sizeof(me->query_temp("zhuanjing")) == 4)
		{
			REWARD_D->riddle_set(me,"灵童转世",2);
			me->set_skill("lamaism",me->query_skill("lamaism",1)+1);
			tell_object(me,HIC"你的密宗佛法提高了一个等级。\n"NOR);			
			me->set("marks/转经",1);
			me->delete_temp("zhuanjing");
		}
	}
	return 1;
}
	
	
