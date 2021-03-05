// ; annie 07.2003
// dancing_faery@hotmail.com
// 

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "三清密室");
        set("long", @LONG
这是三清宫地下不为人所知的一间密室，或许是因为在地底的缘故，空气
中带着一种让人窒闷的潮湿。密室两侧的书架上摆满了各种发黄的珍贵典籍，
一个乌衣白发，几络长须，看起来道骨仙风的老者正站在书架前一盏长明灯下
，翻动着手中的古著。
LONG
        );
	set("no_fly",1);
	set("objects", ([
		__DIR__"npc/xin2" : 1,
	]));   
	setup();
}

void pushout(object me)
{
	call_out("do_greeting",5,me,this_object());
}

void do_greeting(object me,object room)
{
	if (!me || environment(me) != room)
		return;

	message_vision(CYN"\n一张泛着磷光的符纸忽然掉落在$N身上，$N的身影逐渐在空气里模糊．．\n\n"NOR,me);
	me->move(load_object("/d/taoguan/taoguan"));
	message_vision(CYN"\n大门前的空气忽然开始阵阵波动，一个模糊的轮廓慢慢的从虚空中显现出来．．．\n\n"NOR,me);
}


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

