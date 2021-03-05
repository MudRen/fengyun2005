#include <ansi.h>

inherit NPC;
void huwei_perform();

//void backattack();
void create()
{

	set_name("岳云", ({ "huwei"}) );
	set("long", "撼山易，撼岳家军难，这些个血战沙场的精兵儿郎，俱是精忠 
报国，慷慨赴死之辈。。\n");
	
	set("attitude", "friendly");
	set("title",HIY"岳家军"NOR);
	set("nickname",HIG"精忠报国"NOR);
	set("class", "official");
	set("no_fly",1);
	set("no_arrest",1);
	
	set("max_atman", 300);
	set("atman", 300);
	set("max_mana", 300);
	set("mana", 300);
	
	set("combat_exp", 100000);
	
	set_skill("parry", 70);
	set_skill("dodge", 70);
	set_skill("move", 70);
	set_skill("fall-steps",70);
	set_skill("spear",70);
	set_skill("hammer",70);
	set_skill("yue-spear",70);
	set_skill("liuxing-hammer",70);
	set_skill("unarmed",70);
	set_skill("changquan",70);
	set_skill("force", 200);
	set_skill("manjianghong",80);
	
	map_skill("force","manjianghong");
	map_skill("unarmed","changquan");
	map_skill("hammer","liuxing-hammer");
	map_skill("spear","yue-spear");
	map_skill("dodge","fall-steps");
	map_skill("move","fall-steps");

	setup();
	carry_object("/obj/armor/armor")->wear();
}

void backtrace(){
	
	object owner, *enemy;
	int i;
	
	if (!objectp(owner=query("possessed")))	return;
	enemy = query_enemy();
	if (!enemy || sizeof(enemy)<1)	return;
	
	for (i = 0;i<sizeof(enemy);i++){
		if (enemy[i]->query_temp("last_damage_from")==this_object())
			enemy[i]->set_temp("last_damage_from",owner);
	}
	return;
}	
		
int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	object owner;
	
	remove_call_out("leave");
	if(objectp(owner=this_object()->query("possessed")))
	{
		if (environment())
		{
			message("vision",CYN""+name() + "化作一道青烟，冲天而去。\n"NOR , environment(), this_object() ); 
    		backtrace();
        }
    }
	// Remove all buffs to clean up annied
	ANNIE_D->debuff(this_object(),"all");                
	destruct(this_object());
}

void die()
{
	object owner;
	message_vision("\n$N惨叫一声，倒在地上断气了。\n\n", this_object());
	remove_call_out("leave");
	backtrace();
	destruct(this_object());
}

int is_ghost() { return 1; }


//	250 + 250 = 500
void invocation(object who, int level)
{
	int i, n, hp, str,base, add, chance;
	object *enemy;
	
	set("combat_exp",100000 + who->query("combat_exp")*3/4);
	set("level", F_LEVEL->get_level(query("combat_exp")));	// around 110 cap

	if (F_ABILITY->check_ability(who,"3_huwei_lvl",3)) {
		add = query("level")+ F_ABILITY->check_ability(who,"3_huwei_lvl",3);
		set("combat_exp",F_LEVEL->level_to_exp(add,0));
	}
		
	"/feature/nada"->reset_npc(this_object());

	hp = 500 + who->query("max_kee")/2
		+ who->query("max_kee")* F_ABILITY->check_ability(who,"huwei_add")/100;
	set("max_kee",hp);
	set("max_sen",hp);
	set("max_gin",hp);
	str = query_str();
	delete("force_factor");
	set("str",str/2);
	
	base = level /4;	
	set_skill("sword", 30 + base);
	set_skill("parry", 30 + base);
	set_skill("dodge", 30 + base);
	set_skill("move",  30 + base);
	set_skill("unarmed", 30 + base);
	set_skill("fall-steps",who->query_skill("puti-steps",1));
	set_skill("changquan",5 + who->query_skill("changquan",1));
	
	set("skill","spear");
	set("class","official");
	set_skill("spear", 30+base);
	set_skill("yue-spear",5 + who->query_skill("yue-spear",1)*3/4);
	set_skill("manjianghong",5 + who ->query_skill("manjianghong",1));
	map_skill("parry","yue-spear");
	carry_object("/obj/npc/obj/steel_spear")->wield();
	chance = F_ABILITY->check_ability(who,"3_huwei_pfm",3);
	
	if (chance) {
			set("chat_chance_combat", chance);
      set("chat_msg_combat", ({
				(: huwei_perform() :),
      }) );
	}
		
	full_me();
	
	set_leader(who);
	set("possessed",who);
	
	call_out("leave",120 + F_ABILITY->check_ability(who,"shi_add")*9);
		
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && (living(enemy[i])|| enemy[i]->query_temp("is_unconcious"))) {
			kill_ob(enemy[i]);
			enemy[i]->kill_ob(this_object());
		}
	}
}


void huwei_perform(){
	if (!query_temp("weapon"))	return;
		
	if (query("class")== "official")
		ccommand("perform zonghengtianxia");
	else if (query("class") == "shaolin")
		ccommand("perform fanbei");
//	ccommand("say i am here");
	stop_busy();
}



int do_kill(string arg)
{
	object victim,who;
	
	who=this_player();
	if(!arg) return 0;
	if(environment()->query("no_fight"))
		return 0;
	victim=present(arg,environment());
	if(!victim) return 0;
	if( !victim->is_character() || victim->is_corpse() )
		return 0;
	if(victim==who) return 0;
	
	if (query("possessed"))
	if (!COMBAT_D->legitimate_kill(query("possessed"), victim))	return 0;
	
	if(victim->query("possessed")==who && victim->query("id")=="huwei")
	{
		tell_object(who,"你不能杀自己的护卫，否则部下会离心离德的。\n");
		return 1;
	}
	if(victim==query("possessed") && victim->query("possessed")==query("possessed"))
	if(who->query("vendetta_mark")!="authority")
	{
		message_vision("$N喝道：“大胆匪徒，竟然敢加害朝廷命官！！”\n",this_object());
		kill_ob(who);
	}
	if(who==query("possessed")&&victim->query("vendetta_mark")!="authority")
	{
		message_vision("$N对"+victim->query("name")+"喝道：“大胆匪徒，还不速速束手就擒？”\n",this_object());
		kill_ob(victim);
	}
	return 0;
}

void init()
{
	::init();
	if( !query_heart_beat(this_object()) ) set_heart_beat(1);
	add_action("do_kill","kill");
}