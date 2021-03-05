
#include <ansi.h>

inherit NPC;


void create()
{
        set_name("狄青麟", ({ "di qinglin","di","qinglin" }) );
        set("long",
                "一身雪白的衣裳，一尘不染；一张苍白清秀的脸上，总是带着冷冷淡淡的
的表情。这就是视功名富贵如尘土、却把名马美人视如生命的狄小侯爷。\n");

        set("attitude", "friendly");
        set("reward_npc", 1);
	set("difficulty", 20);
	set("age",27);
        set("str", 100);
        set("cor",50);
        set("agi",50);
        set("cps",75);
        set("con",70);
	set("title", HIY"世袭一等侯"NOR);

        set("combat_exp", 3000000+random(1000000));
        set("max_force",2000);
        set("force",2000);
        set("force_factor",50);
        

	set_skill("unarmed",200);
    	set_skill("dagger",200);
    	set_skill("xinyue-dagger",150);
	set_skill("parry",1000);
	set_skill("dodge",200);
	set_skill("fall-steps",200);
    	map_skill("dagger","xinyue-dagger");
	map_skill("dodge","fall-steps");
        set("chat_chance", 1);
        set("chat_msg", ({
"狄青麟轻轻抖了下一尘不染的雪白绸衣，嘴角突然泛起一种冷酷的笑意。”\n"
}) );
/*
        set("inquiry", ([
                "劫镖案" : (: answer_robery :),
                "robery" : (: answer_robery :),
                "杨铮" : (: answer_yang :),
                "yang" : (: answer_yang :),
                "yang zheng" : (: answer_yang :),
                "狄青麟" : (: answer_di :),
                "di" : (: answer_di :),
                "di qinglin" : (: answer_di :),
        ]));

*/
        setup();

        carry_object(__DIR__"obj/shirt")->wear();
        carry_object(__DIR__"obj/thinblade")->wield();
}

void init()
{
	::init();
	add_action("do_sitdown","sitdown");
	add_action("do_answer","answer");
}

int kill_him(object ob)
{
	if(!ob||environment(ob)!=environment())
		return 0;
	message_vision(HIC"狄青麟对$N微微的叹了口气：“你真是敬酒不吃吃罚酒。。。”\n"NOR,ob);
	//dont allow player answer now
	ob->delete_temp("answering");
	kill_ob(ob);
	ob->kill_ob(this_object());
	return 1;
}

int greeting(object ob)
{
	message_vision(HIY"狄青麟向$N微一颔首，说道：“坐（sitdown）。”\n"NOR,ob);
	call_out("kill_him",10,ob);
	return 1;
}

int do_sitdown(string arg)
{
	object me=this_player();
	
	message_vision(HIW"$N诚惶诚恐的坐在了蒲团上。\n"NOR,me);
	message_vision(HIC"狄青麟冷冷的向$N问道：“这位"+RANK_D->query_respect(me)+"光临敝处，可是为了杨铮和那一百八十万两镖银而来？
（answer yes/no）\n"NOR,me);
	me->set_temp("answering",1);
	remove_call_out("kill_him");
	call_out("kill_him",10,me);	
	return 1;
}

int player_leave(object me)
{
	message_vision("狄青麟将$N赶出了麒麟阁。\n",me);
	me->move("/d/libie/corrider");
	return 1;
}

int do_answer(string arg)
{
	object me=this_player();
	
	if(!me->query_temp("answering"))
		return 0;
	if(arg=="yes")
	{
		remove_call_out("kill_him");		
		if(me->query("libie/离别钩_小虎子的警告"))
		{
			message_vision(HIW"狄青麟忽然微笑道：“想见杨铮，倒也不那么困难。”\n"NOR,me);
			message_vision(HIR"狄青麟不经意的按了一下身边的一处地面，$N身下的蒲团忽然发出吱吱的声响。\n"NOR,me);
			if(me->query("libie/离别钩_花四爷的提醒"))
			{
				tell_object(me,HIW"你心念一动，忽然想起花四爷的禁告。\n"NOR);
				message_vision(CYN"$N连忙跳了起来，只见蒲团下的地板忽然陷了下去，露出了一个黑洞。蒲团落入洞中，一下子就消失了。\n"NOR,me);
				message_vision(HIY"狄青麟微微一愕，随即又微笑着对$N道：“何苦，其实那样痛苦反而少一些。。。”\n"NOR,me);
				this_object()->kill_ob(me);
				me->kill_ob(this_object());
			}
			else
			{
				message_vision(HIC"蒲团下的地面忽然裂开，$N只觉身体一轻，竟直坠下去！！\n"NOR,me);
				message_vision(RED"在落入黑洞的一瞬间，$N的脸上忽然显露了无比恐惧的表情，因为$P看到的景象，是尚在生的所有人
都无法想象的恐怖！！！\n"NOR,me);
				me->set("kee",-1000);
				me->move("/d/libie/void");
			}
			return 1;
		}
		else
		{
			message_vision(HIC"狄青麟忽然大笑道：“怎么会有这种事情，只怕你是搞错了吧。”\n"NOR,me);
			me->set_temp("libie/小叶子杀",1);
			call_out("player_leave",2,me);
			return 1;
		}
	}
	if(arg=="no")
	{
		remove_call_out("kill_him");		
		message_vision(HIC"狄青麟道：“既然是这样，恕不奉陪了，你走吧。”\n"NOR,me);
		call_out("player_leave",2,me);
		return 1;
	}
	return 0;
}
int return_home(object home)
{
	destruct(this_object());
	return 1;
}

	
