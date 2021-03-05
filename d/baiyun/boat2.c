#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "一叶小舟中");
	set("long", @LONG
一叶轻盈的小舟，可以用来航海（ｓａｉｌ）。\n
LONG
	   );
	set("no_fight",1);
	set("no_magic",1);	
	set("no_fly",1);	
	set("coor/x",30);
	set("coor/y",-40);
	set("coor/z",-20);
	setup();	   
}

void init()
{
    add_action("do_sail","sail");
}

void boat_sail(int counter,object me)
{
    if (me->query_skill("dodge",1) < 30 )
		{
		  message_vision(HIB"一个大浪打来，$N脚下不稳，被抛入大海之中！……\n"NOR,me);
		  me->delete_temp("counter");
		  me->move(__DIR__"seabutton1");
		  return;
		}
	switch (counter)
		{
		  case 1:
		  tell_object(me,HIC"海水在脚下时而咆哮，时而低沉。时而汹涌，时而柔顺。放眼
望去，海天相接，无边无际，一片空蒙。仿佛永远没有尽头。\n"NOR);
		  break;
	                 
		  case 2:
		  tell_object(me,HIC"黄昏过去，黑夜来临，前方已是茫茫黑夜。抬头望天，但见繁
星满天，闪烁不已……但听海风咆哮，海浪翻滚。长夜将逝，
黎明即来。太阳又要升起。\n"NOR);
		  break;

		  case 3:
		  tell_object(me,HIC"黎明时分，海天之际隐约浮现出陆地的影子，经久方近。\n\n"NOR);
		  me->delete_temp("counter");
		  tell_object(me,HIY"你拼命用力划了几下，终于到了岸边。你怀着激动的心情离开小船，踏上陆地。\n"NOR);
          me->move("/d/manglin/seaside");
		  break;
		} 
	return;
}

int do_sail(string arg)
{   
	object me;
	me = this_player();
	if( !arg || (arg != "north") ) 
	return notify_fail("大陆在北边，向北划吧。(sail north)\n");
	if (me->is_busy())	return notify_fail("你现在正忙。\n");
		
	if( arg=="north" ) 
	{
		me->add_temp("counter", 1);
		write("你试著把小船往北划去....\n");
		me->perform_busy(1);
		call_out("boat_sail",0,me->query_temp("counter"),me);
    }
	return 1;
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
