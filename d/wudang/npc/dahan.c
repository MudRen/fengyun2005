#include <ansi.h>
inherit NPC;

void create()
{
        set_name("大汉", ({ "dahan" }) );
        set("gender", "男性");
        set("age", 32);
        set("long","一个彪形大汉呆呆地坐在这里，望着飞来飞去的麻雀。\n");
		set("combat_exp",60000);
	
        set("chat_chance", 1);
        set("chat_msg", ({
                "大汉拿起手里的树枝比划了几下，又呆呆地坐下了。\n",
                "大汉说：俺的剑呢？一准是忘在家里了。\n",
        }) );

	set("inquiry", ([
        	"小媳妇儿": "咱媳妇儿在家给俺烧饭呢。\n",
        	"回家": "action大汉呆呆地坐着，似乎没听到你的问话。\n",
        	"守寡":	"俺是新婚，你才守寡呢！\n",
        	"剑":	"以俺的功夫，有没有那把铁剑关系已经不大了，不信，你拿来我给你比划比划。\n",
        	"铁剑":	"以俺的功夫，有没有那把铁剑关系已经不大了，不信，你拿来我给你比划比划。\n",
        	"树枝":"以俺的功夫，有没有那把铁剑关系已经不大了，不信，你拿来我给你比划比划。\n",
         ]) );
         
		set_skill("sword", 50);
		set_skill("three-sword", 50);
		set_skill("dodge", 50);
		set_skill("move", 50);
		set_skill("five-steps", 50);
		set_skill("parry",50);
		
		map_skill("parry","three-sword");
		map_skill("sword", "three-sword");
		map_skill("dodge", "five-steps");
		map_skill("move", "five-steps");
	
		set("can_carry",1);
        setup();
        set_temp("apply/damage",30);
		carry_object(__DIR__"obj/shuzhi")->wield();
		carry_object("/obj/armor/cloth")->wear();
}


int accept_object(object who, object ob)
{
	object		shu;
	if( ob->name() == "铁剑") {
		message_vision(CYN"大汉一摆手说：“以俺的武功，早已不需要这些破铜烂铁了。”\n"NOR,who);
		message_vision(CYN"大汉说：这位"+RANK_D->query_respect(who)+"看来也是武道中人，咱们来比划比划。\n"NOR,who);	
		full_me();
		set_temp("going_home",1);
		command("fight "+ who->query("id"));
		return 0;
	}
	return 0;
} 

void win_enemy(object loser)
{
    	command("say 哈哈，幸亏俺手中只是根树枝，不然。。。。\n");
    	delete_temp("going_home");
}

void lose_enemy(object winner)
{
	object	shu;
	string msg;
	
	if (query_temp("going_home")) {
		msg = CYN"
大汉长叹一声，“媳妇儿说得不错，俺、俺、俺只是个种地的命。。。。
俺还是回家暖炕头吧。”"NOR;
		if (shu = present("shu zhi", this_object())) {
			shu ->move(environment());
			msg += CYN"大汉手一松，树枝掉在地上。"NOR;
		}
		msg += CYN"大汉一屁股坐在地上发起呆来。\n"NOR;
		message_vision(msg, winner);
    		if (QUESTS_D->verify_quest(winner,"武当大汉")) 
    			QUESTS_D->special_reward(winner,"武当大汉");		
    	}   		
}