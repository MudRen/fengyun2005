#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;
void create()
{
        set("short", "大宅院二楼");
        set("long", @LONG
为了帮朝中好友毒剑常笑的忙，从来好客的韦好客三请四说，总算说动从小和
他穿同一条裤子长大、如今却已是一等威灵候的慕容秋水慕容公子作客太平镇。为
了招待这位素喜干净的候爷，韦好客还安排人在慕容来前用三百桶清水将大宅院上
上下下来来回回冲了十遍之多。
LONG
        );
        set("exits", ([ 
		"west":	__DIR__"house3a",
	]));
	set("objects", ([
        ]) );

        set("item_desc", ([
	
	 ]));
	set("coor/x",0);
	set("coor/y",-50);
	set("coor/z",10);
	set("map","taiping");
	setup();
	set("no_fly", 1);
	set("max_lv",200);	
}

int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"house3a");
	if (!exitroom)
		exitroom = load_object(__DIR__"house3a");
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") && userp(me))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"你忽然想起慕容秋水一向不喜欢江湖中的高手，不由止住脚步。\n"NOR);
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

