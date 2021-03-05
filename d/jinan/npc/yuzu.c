// garrison.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("狱卒", ({ "yuzu", "yu zu" }) );
	set("long",
		"狱卒虽小，但也不要轻易惹到他们，他们是有组织的一群人。\n");
	set("attitude", "heroism");
	set("vendetta_mark", "authority");
	set("str", 27);
	set("cor", 26);
	set("cps", 25);
	set("combat_exp", random(10000));
	set_skill("unarmed", 70+random(50));
	set_skill("staff", 70+random(50));
	set_skill("parry", 70+random(50));
	set_skill("dodge", 70+random(50));
	set_skill("move", 100+random(50));
	set_temp("apply/attack", 70);
	set_temp("apply/dodge", 70);
	set_temp("apply/parry", 70);
	set_temp("apply/damage", random(100));
	set_temp("apply/armor", 70);
	set_temp("apply/move", 100);
	set("chat_chance", 1);
	set("chat_msg", ({
        "狱卒低声道：“这点饷银，还不够老子打酒喝。”\n",
		"狱卒自语：奇怪，最近探监的人怎么这么多？\n",
	}) );
	set("inquiry", ([
		"tanjian" : "探监呀？好说，好说。。。有钱什么都好说。\n",
		"探监" : "探监呀？好说，好说。。。有钱什么都好说。\n",
	]));    
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

int accept_object(object who, object ob)
{
	int i, value;
    
	if(ob->query("money_id")) 
	{
		i = ob->query("base_value");
		value = ob->query_amount() * i;
	}
	else 
	{
		return 0;
	}
	if(!NATURE_D->is_day_time())
	{
	        if(value > 10000) 
	        {
	        	message_vision("$N低声说道：“快去快出。”\n", this_object());
	        	environment(this_object())->add("exits/east","/d/jinan/dalao1");
	        	who->set_temp("探监", 1);

			if (!REWARD_D->check_m_success(who,"浴血天牢") && REWARD_D->riddle_check(who,"浴血天牢") <=1)
				REWARD_D->riddle_set(who,"浴血天牢",1);


	        	call_out("close_door", 30);
	        } 
	        else 
	        {
	            message_vision("$N说道：“深更半夜来探监，你打的是什么主意？”\n", this_object());
	        }
	} 
	else
	{
    		if(value > 500)
    		{
        		say("狱卒呵呵的笑道：探监呀？好说，好说。。。\n");
        		environment(this_object())->add("exits/east","/d/jinan/dalao1");
        		who->set_temp("探监", 1);
			call_out("close_door", 40);

			if (!REWARD_D->check_m_success(who,"浴血天牢") && REWARD_D->riddle_check(who,"浴血天牢") <=1)
				REWARD_D->riddle_set(who,"浴血天牢",1);

   		} 
   		else 
   		{
        		say("狱卒说道：这点钱还不够大爷喝酒的呢！\n");
    		}
	}
	return 1;
} 

void close_door()
{
	if(environment(this_object())->query("exits/east"))
	{
		message_vision("$N瞅瞅四下无人，“吱~呀~”一声，把大门关了起来。\n", this_object());
		environment(this_object())->delete("exits/east");
	}	

}
