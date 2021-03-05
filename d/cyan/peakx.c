// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
	set("short", "湖畔小径");
    set("long", @LONG
沿着明湖边的草地缓行，走上一刻路程就能来到这里，此处的湖水比方才
更显清澈，湖中还可见到几条鱼虾游动，只是原本十分安宁的景色被一个人所
坏，一个站在湖边撑着一把油纸伞，正阴阴打量着你的老人。
LONG
NOR
        );
	set("objects", ([
	]));
	set("exits",([
  		"eastup" : __DIR__"peak11",
	]) );

	set("outdoors", "cyan");

	set("coor/x",-40);
	set("coor/y",40);
	set("coor/z",-70);
	setup();

	set("no_fly", 1);
	set("max_lv",105);	
}

int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"peak11");
	if (!exitroom)
		exitroom = load_object(__DIR__"peak11");
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") && userp(me))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"多一事不如少一事……还是算了吧。\n"NOR);
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


