// ; annie 07.2003
// dancing_faery@hotmail.com
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "三清宫密道");
	set("long", @LONG
你抬起眼，发现自己正身处一条狭窄的甬道之中，甬道宽不过三尺，高却有一
丈上下。甬道的两壁都是青石所铸，所触之处手感冰凉。甬道的尽头是两扇高大的
石门，此刻正紧紧闭合着，拦住了你的去路。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"south" : __DIR__"secretpath2",
]));
	set("coor/x",-20);
	set("coor/y",40);
	set("coor/z",-10);
	set("no_fly",1);

   	set("item_desc", ([
		"gate":  "你摸了摸石门，发现它竟是异常坚固的花岩所铸，看来绝非你所能打开。\n",
		"door":  "你摸了摸石门，发现它竟是异常坚固的花岩所铸，看来绝非你所能打开。\n",
		"石门":  "你摸了摸石门，发现它竟是异常坚固的花岩所铸，看来绝非你所能打开。\n",
        ]) );
	setup();
}


void init()
{
	object room,me;
	object *olist;
	int i;
	me = this_player();
	if (userp(me))
	{
		room = this_object();
		// =5: 进room2
		// =x或已结束? 进room1
		if (REWARD_D->riddle_check(me,"无字天书") == 5 
			|| REWARD_D->riddle_check(me,"无字天书") == 7 
			|| REWARD_D->check_m_success(me,"无字天书") == 1)
			call_out("do_drop",15,me,room);
		else
			call_out("do_knockout",15,me,room);
	}
	return;
}

void do_knockout(object me,object room)
{
	if (!me || environment(me) != room || me->is_fighting())
		return;
	message_vision(CYN"\n一张泛着磷光的符纸忽然掉落在$N身上，$N的身影逐渐在空气里模糊．．\n\n"NOR,me);
	me->move(load_object("/d/taoguan/taoguan"));
	message_vision(CYN"\n大门前的空气忽然开始阵阵波动，一个模糊的轮廓慢慢的从虚空中显现出来．．．\n\n"NOR,me);
}


void do_drop(object me,object room)
{
	if (!me || environment(me) != room || me->is_fighting())
		return;
	message_vision(CYN"\n$N向石门边上摸去。\n\n"NOR,me);
	tell_object(me,CYN"你忽然发现石门边上竟有一处所在，看似坚硬的石头，却可以探进手去！
你心下略一权衡，从幻象墙壁中踏了进去。\n\n"NOR);
	if ( /**/!/**/random(3) /* || load_object(__DIR__"dimroom")->usr_in() || load_object(__DIR__"fog")->usr_in()*/)
		me->move(load_object("/d/taoguan/taoguan"));
	else
		me->move(load_object("/d/taoguan/dimroom2"));
	message_vision(CYN"\n$N穿过虚无的幻影墙壁走了过来。\n\n"NOR,me);
}


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

