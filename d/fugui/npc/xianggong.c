#include <ansi.h>
#define GOLD_COST 50
inherit NPC;

void create()
{
	set_name("俊俏相公", ({ "playman" }) );
	set("title", HIM "风流倜傥"NOR);
	set("gender", "男性" );
	set("age", 22);
	set("per", 30);
	set("long", @LONG
无论多么能干的江湖女子，都有需要男人的时候，尤其是想传宗接代
或者是享受一下不同感受的女人。如果你感兴趣的话，请（ｅｎｊｏｙ）．
LONG
);
	set("combat_exp", 10000);
	set("no_arrest",1);
	set("attitude", "friendly");

	setup();
	carry_object(__DIR__"obj/cyan_cloth")->wear();
}

int accept_fight(object me)
{
	command("say 小生哪里是您的对手？");
	return 0;
}

int accept_object(object me, object obj)
{
        command("smile");
        command("say 多谢这位" + RANK_D->query_respect(me) +
"，您一定会在这儿玩的开心的！");
}

void init()
{
        ::init();
	add_action("do_enjoy","enjoy");
	
}

int do_enjoy()
{
	object me,gold;
	me = this_player();
	gold = present("gold_money", me);
	if( (string)me->query("gender") == "男性" )
		return notify_fail("俊俏相公连忙避到一旁，义正词严道：在下还有自尊，不接男客！\n");
        if(!gold) 
        	return notify_fail("你身上没有金子，想白玩啊！\n");
        if((int) gold->query_amount() < GOLD_COST)
        	return notify_fail("你身上没有"+chinese_number(GOLD_COST)+"两金子，攒够金子再来吧。\n");
	message_vision(HIM"$N轻飘飘地向$n走过来，为$n宽衣解带．．．
一股异样的感觉令$n意乱情迷，想入非非！\n\n"NOR,this_object(),me);
	call_out("enjoyit",20,me);
	return 1;
}

void enjoyit(object me)
{
	if (living(this_object()) && environment(me) == environment())
	{
		message_vision(HIR"“嗯！喔…………碍………呀！”$N毫无顾忌的娇哼著．．．平坦的小腹．．．
修长的玉腿．．．．．．完全裸露着．．．．\n\n"NOR,me);
		call_out("finishit",20,me);      
	}
	else
		remove_call_out("enjoyit");
}	

void finishit(object me)
{
	object *inv;
	int i;
	if (living(this_object()) && environment(me) == environment())
	{
		message_vision(HIY"$N．．．感觉象在飞．．．突然，
$N“啊~~！啊~~！啊~~！啊~~！”一次一次兴奋的尖叫起来，接着昏死过去．．．．\n"NOR,me);
     		me->change_condition_duration("hehe");
     		me->unconcious();
   	} 	else
		remove_call_out("finishit");
}

