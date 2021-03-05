//sinny@fengyun.com
//All Rights Reserved
#include <ansi.h>
inherit ROOM;
int counter;
void create()
{
	set("short", "大海船");
	set("long", @LONG
一艘高桅、坚固、耐用的大海船，船身吃水很重，船上显然载满了货。货装得越
多，船走起来越稳，就算你没有出过海，也绝不会晕船的。只要你一声令下，就可以
把你安全的带到你想去的地方（ｏｒｄｅｒ）。\n
LONG
	   );
	set("no_fight",1);
	set("no_magic",1);
	set("coor/x",40);
	set("coor/y",-40);
	set("coor/z",-20);
	setup();	   
}

void init()
{
    add_action("do_order","order");
}

int do_order(string arg)
{   
	object me;
	me = this_player();
	if( !arg || (arg!="south" && arg!="白云岛") ) 
	return notify_fail("您要往哪儿航行？\n");
	if( arg=="south" || arg=="白云岛" ) 
		{ 
		  counter=1;	
                  write("你命令船上的水手改变航道，使大海船往南边的白云岛驶去....\n");
                  call_out("ship_sail",3,counter,me);
                }
	return 1;
}

void ship_sail(int counter,object me)
{
	switch (counter)
	       {
		  case 1:
		  message_vision(HIC"海水在脚下时而咆哮，时而低沉。时而汹涌，时而柔顺。放眼
望去，海天相接，无边无际，一片空蒙。仿佛永远没有尽头。\n"NOR,me);
		  break;
	                 
		  case 2:
		  message_vision(HIC"黄昏过去，黑夜来临，前方已是茫茫黑夜。抬头望天，但见繁
星满天，闪烁不已……但听海风咆哮，海浪翻滚。长夜将逝，
黎明即来，太阳又要升起。\n"NOR,me);
		  break;

		  case 3:
		  tell_object(me,HIC"黎明时分，海天之际隐约浮现一个小岛。经久方近，这小岛却
是十分古怪，小岛东、西两面的景色极不协调，给人一种怪异的感觉。\n"NOR);
		  tell_object(me,HIY"大海船终于到了岸边。你怀着激动的心情踏上小岛。\n"NOR);
		  me->move(__DIR__"baiyunentrance");
		  break;
	       } 
	if ( counter<3)	call_out("ship_sail",5,counter+1,me);
	else {
	      counter=0;
	      return;
	     } 
}