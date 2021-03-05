#include <ansi.h>
inherit NPC;

inherit F_MASTER;
void mimicurse();

void create()
{
	set_name("姜仙公", ({ "jiang xiangong", "jiang" }) );
	set("title", HIG "鹤发童颜"NOR);
	set("gender", "男性" );
	set("age", 80);
	set("per", 25);
	set("class","yinshi");
	set("long", "满头的华发如银丝，红润的脸膛却又婴孩一样没有一丝皱纹。\n");
	set("combat_exp", 800000);
	set("attitude", "friendly");
    	set("chat_chance", 1);
    	set("chat_msg", ({
		"姜仙公看看四周点头道：不错，不错，灵山有仙气。\n",
		"姜仙公嘀嘀咕咕：不知道这儿有什么奇珍异宝？ \n",
    	}) );
	
	set_skill("incarnation", 150);
	
        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("flying-dragon", 100);
	set_skill("zuixian-steps", 100);
	        
     	set_skill("cursism", 100);
    	set_skill("celecurse", 100);
    	  
        map_skill("unarmed","flying-dragon");
        map_skill("dodge","zuixian-steps");
	map_skill("cursism", "celecurse");
		
	set("skill_public",1);
	setup();
	carry_object("/obj/armor/cloth")->wear();
}


int accept_fight(object me)
{
	command("say 我老人家哪里是您的对手？");
	return 0;
}

int recognize_apprentice(object ob)
{
    	if(ob->query("free_learn/incarnation"))
        	return 1;
	return 0;
}

int accept_object(object who, object ob)
{

	if (ob->name() == HIY"琥珀"NOR){
		if (ob->query("inc"))
		{
			message_vision("$N拿着"+ ob->name() + "仔细看了看道：“好，好，我正需此物。”\n",this_object());
			message_vision("$N转头看了看$n道：老夫无以为报，你如有意可随我学修仙术。\n", this_object(), who);
			who->set("free_learn/incarnation", 1);
			REWARD_D->riddle_done( who, "华山修仙", 10, 1);
		} else
			message_vision("$N气愤地说：竟然敢拿假货来骗我老人家！\n", this_object());			
		return 1;
	}
	return 0;
}

int prevent_learn(object me, string skill)
{
  	if (skill != "incarnation")
  	{
      		command("shake");
      		command("say 我可只答应教你修仙术啊。");
      		return 1;
  	}
  	return 0;
}


int prevent_shown(object me, string skill)
{
	if (me->query("free_learn/incarnation")	&& skill == "incarnation")
		return 0;
	
	return 1;
}


object offensive_target(object me)
{
	int sz;
	object *enemy;
	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;
	sz = sizeof(enemy);
	if( sz > 6 ) sz = 6;
	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}

void mimicurse()
{
	object target;
	
		target = offensive_target(this_object());
		command("curse bloodcurse on "+target->query("id"));
		return;
}

void die(){
	if (!this_object()->is_unconcious()){
		message_vision(HIR"\n$N叫道：我老头子和你拼了！！\n"NOR, this_object());
		mimicurse();
	}
	::die();
}
	