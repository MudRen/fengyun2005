#include <ansi.h>
inherit ROOM;
void create()
{
	object ob1,ob2,con;
        set("short", "藏经飞檐");
        set("long", @LONG
你正站在藏经阁以赤訇石打制的屋檐上．．．
四面没有任何的出路，看起来想要离开只能冒险自阁顶跃下(jumpdown)了。
LONG
        );
        set("exits", ([ 
//  		"enter" : __DIR__"changjing3",
	]));
	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",100);
	set("no_lu_letter",1);
	setup();

}

void call_thief(object me)
{
	object th,here=this_object();
	if (!userp(me))
		return;
	if (REWARD_D->riddle_check(me,"多事之秋") == 3 && REWARD_D->riddle_check(me,"守经楼") == 3 && !present("mysterious figure",here))
	{

		message_vision(HIR BLK"你绕到飞檐的另外一边，赫然发现黑衣人正站在角上，正准备纵身下跃！\n\n"NOR,me);

		th=new(__DIR__"npc/master_17_8");
		if (me->query("combat_exp")*10/10> th->query("combat_exp"))  // add by ldb 原为 *11/10 ，为方便过经楼 
			th->set("combat_exp", me->query("combat_exp")*10/10);  // add by ldb 原为 *11/10 ，为方便过经楼 
		"/feature/nada"->reset_npc(th);
		th->full_me();
		th->move(here);
		REWARD_D->riddle_set(me,"守经楼",4);
	}
	return;
}


void init()
{
	object ob;

        if( interactive(ob = this_player()) ) {
			add_action("do_jumpout","jumpdown");

                remove_call_out("call_thief");
                call_out("call_thief", 1, ob);
        }

	// 建议有100 move才来做这个quest.
}

int do_jumpout(string arg)
{
	object me;
	int i;
	object room;
   	me = this_player();
	i = me->query_skill("move",1);

	message_vision("\n$N深深地吸了口气，自飞檐边一跃而下！\n",me);
	room = find_object(__DIR__"changjing");
	if (!objectp(room)) room = load_object(__DIR__"changjing");
	tell_object(me,HIW"．．．啊啊啊啊啊啊啊！！！\n"NOR);


		me->add_temp("block_msg/all",1);
		me->move(room);
		message_vision(HIY"\n你眼前一花，一个人影从藏经楼上飞坠而下，"NOR,me);

		if (i <= random(100))	// 100 move可确保安全
		{
			message_vision(HIR"摔了个脑袋开花！\n"NOR,me);
			me->delete("timer/lifesave");	// 落花流水一起去:p
			me->add_temp("block_msg/all",-1);
			me->set_temp("last_damage_from","想不开从藏经阁上跳楼自尽了。");
			// 嗯，通告一下....
			me->die();
			return 1;
		}
		else
		{
			message_vision(HIW"摔了个七荤八素，昏倒在你眼前。\n"NOR,me);
			me->add_temp("block_msg/all",-1);
			me->unconcious();
			return 1;
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


