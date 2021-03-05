// Silencer @ FY4 workgroup. Oct.2004

#include <ansi.h>
inherit NPC;

void create()
{	
        set_name( "狼" , ({ "wolf" }) );
        set("race", "野兽");
        set("age", 10);
        set("long", "一头双眼泛着绿光，嗷嗷嚎叫的恶狼。\n");
        set("max_kee", 100);
		set("str",50);
		set("limbs", ({ "头部", "身体", "尾巴","爪子" }) );
        set("verbs", ({ "bite","claw"}) );
        set("attitude","heroism");
        set("no_arrest",1);
        set("no_fly",1);        

		set("combat_exp", 200000);
		set_skill("unarmed", 50);
		set_skill("parry", 50);
		set_skill("dodge", 50);
		set_skill("move", 50);
		setup();

}

void backtrace(){
	
	object owner, *enemy;
	int i;
	
	if (!objectp(owner=query("possessed")))	return;
	if (owner->is_ghost())		return;
		
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
	message_vision("\n$N"HIB"仰天长嚎一声，几个起落消失在苍茫雾色中。\n\n"NOR , this_object());
    if(objectp(owner=this_object()->query("possessed")))
	{
		owner->add_temp("max_guard",-1);
		
	}
	backtrace();
	// Remove all buffs to clean up annied
	ANNIE_D->debuff(this_object(),"all");
	destruct(this_object());
}


void invocation(object who, int level)
{
	int i;
	object *enemy;
	
	set("combat_exp", 200000 + who->query("combat_exp")*2/3);
	
	set_skill("unarmed", 100 + level/2+random(level)/2);
	set_skill("parry", 100 + 3*level);
	set_skill("dodge", 100 + 3*level);
	
	set("force_factor", 0);
	set("str",who->query_str());
	set("cps",who->query("cps"));
	set("agi",who->query("agi"));
	set("kar",who->query("kar"));
	set("con",who->query("con"));
	
	set("kee",50 + level*3 + who->query("kee")/5);
	set("sen",50 + level*3 + who->query("sen")/5);
	set("gin",50 + level*3 + who->query("gin")/5);
	
	set("max_kee", query("kee"));
	set("eff_kee", query("kee"));
	set("max_sen", query("sen"));
	set("eff_sen", query("sen"));
	set("max_gin", query("gin"));
	set("eff_gin", query("gin"));
	
	enemy = who->query_enemy();

	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && (living(enemy[i]) || enemy[i]->query_temp("is_unconcious")) ) {
			kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else enemy[i]->kill_ob(this_object());
			if (objectp(this_object()))
			message("vision", name() + "对"+enemy[i]->name()+"嗷嗷嘶叫着，看来充满了敌意。\n" NOR,
		 			environment(), this_object() );
		}
	}
	set_leader(who);
	set("possessed",who);
	if (!who->query("sticky_wolf"))	
		call_out("leave",20);
}

void die()
{
	object owner;
    if(objectp(owner=this_object()->query("possessed")))
    	owner->add_temp("max_guard",-1);
	message_vision("\n$N惨叫一声，倒在地上断气了。\n\n", this_object());
	remove_call_out("leave");
	backtrace();
	destruct(this_object());
}

