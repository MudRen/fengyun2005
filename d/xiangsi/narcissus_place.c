#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
	set("short", "玄冰洞暗窟");
        set("long", @LONG
冰洞处在山上的背阴一面，终年不得阳光直射，洞中的冰棱犬牙相错，粗
的需数人合抱，而细的也只不过小指宽长。从玄冰洞往上几步，寒气越来越浓，
若非提着一口真气，几乎片刻便会冻僵。
LONG
        );
        set("objects", ([
//        __DIR__"npc/song" : 1,
// 回家了..
//        __DIR__"npc/thief" : 1,
// 搬家了..
                        ]) );
	
	set("exits",([
		"down":	__DIR__"icecave",
	]) );
	
	set("coor/x",-20);
	set("coor/y",-10);
	set("coor/z",60);
	setup();
	set("no_fly", 1);
	set("max_lv",115);	
}

int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"icecave");
	if (!exitroom)
		exitroom = load_object(__DIR__"icecave");
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") && userp(me))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,WHT"冰块稀稀落落而下，堵住了你的去路。\n"NOR);
	}
}


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

