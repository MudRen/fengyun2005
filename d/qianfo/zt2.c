#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
  set("short","斋堂内院");
  set("long",@LONG
一进斋堂内院，无比诱人的饭菜香气便扑鼻而来，你舔了舔口水，眼睛眨
也不眨地盯着架在炉灶上的大锅；原来素菜在妙手厨艺之下，竟也可以如此芳
香美味。
LONG
  );
  set("exits",([
            "east" :__DIR__"zhaitang",
               ]));
	set("coor/x",-40);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
	set("no_fly", 1);
	set("max_lv",95);	
}

int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"zhaitang");
	if (!exitroom)
		exitroom = load_object(__DIR__"zhaitang");
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") && userp(me))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"大师正在斋堂内院生火做饭，贸然闯入似乎有失你的身份。\n"NOR);
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

