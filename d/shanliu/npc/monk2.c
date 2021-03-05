// yangfan.c

inherit NPC;

#include <ansi.h>
void answer_shanliu();
void create()
{
	set_name("无色", ({ "old monk","monk" }) );
	set("gender", "男性" );
	set("age", 78);
	create_family("少林寺",17,"大师");
	set("long",
"这是个看上去很老的和尚，长得胖胖的，笑起来简直就活脱脱一个弥勒佛，面前还
摆了个木鱼。\n");
        set("chat_chance", 1);
        set("chat_msg", ({
            "无色敲着木鱼，喃喃道：我不入地狱，谁入地狱？和尚不糊涂，谁糊涂？\n",
            "无色露出一丝笑容，冲你笑道：山流无处不在，因为它原本就在每个正义之士的心中。\n",
    }) );
	set("combat_exp", 2000000);
	set("attitude", "friendly");
	set("per",10);
	set("str", 30);
	set("force",1000);
	set("max_force",1000);
	set("force_factor",50);
	set_skill("dodge",100);
        set_skill("unarmed",100);
        set_skill("parry", 100);
        
 	setup();
    carry_object("obj/armor/cloth")->wear();

}


void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()))
	if(ob->query_temp("山流/七个半"))
	{
		remove_call_out("greeting");
                call_out("greeting", 3, ob);
        }
	add_action("do_kill","kill");
}

void greeting(object me)
{

	if(environment(me)!=environment())
		return ;
	me->delete_temp("山流/七个半");
	if(me->query("山流/失败")&&me->query("山流/失败")+86400>time())
	{
		message_vision("$N冷冷的对$n说：“阁下与山流无缘，还是请回吧。”\n",this_object(),me);
		return ;
	}
	message_vision(HIY"$N微笑着对$n说：“舍身崖就在佛殿后面，快去吧。”\n"NOR,this_object(),me);
	me->set_temp("山流/舍身崖",1);
	me->move("/d/shanliu/sheshenya");
	return ;
}

int do_kill(string arg)
{
	object me;

	me=this_player();
	if(!arg) return 0;
	if(this_object()==present(arg,environment()))
		me->set("山流/失败",time());
	return 0;
}
