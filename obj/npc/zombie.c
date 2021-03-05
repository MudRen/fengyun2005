// 	Mingyue @ Silencer @FY4 workgroup

#include <ansi.h>
inherit NPC;

void smart_fight();

void create()
{
        set_name("灭道僵尸", ({ "zombie" }) );
        set("long","这是一具被人用符咒控制的僵尸，从它苍白的脸上看不出任何喜怒哀乐。\n");
        set("class","taoist");
        set("max_atman", 100);
        set("atman", 100);
        set("max_mana", 100);
        set("mana", 100);
        
        set("is_pet",1);
	set("no_arrest",1);
        set("no_fly",1);
    	    	
    	set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                   (: smart_fight() :),
        }) );
    	
    	set("str", 30);
        set("cor", 40);
        set("cps", 30);
        set_skill("unarmed", 40);
        set_skill("dodge", 30);
        set_skill("move", 30);

        set_temp("apply/damage", 25);
        setup();
}

int is_zombie() { return 1; }

/*
varargs int receive_damage(string type, int damage, object who)
{
	object me,owner;
	me = this_object();
	owner = query("possessed");
	if (!objectp(owner) || owner->is_ghost())
	{
		die();		// bug happens when you destroy object outside of heart_beat. Combatd/Perform loses target. 
		return 1;
	}
	::receive_damage(type,damage,who);
	owner->receive_damage(type,damage,who);
	return 1;
}

varargs int receive_wound(string type, int damage, object who)
{
	object me,owner;
	me = this_object();
	owner = query("possessed");
	if (!objectp(owner) || owner->is_ghost())
	{
		die();
		return 1;
	}
	::receive_wound(type,damage,who);
	owner->receive_wound(type,damage,who);
	return 1;
}
*/

mixed hit_ob(object me, object victim, int damage_bonus)
{
	object owner;
	owner = query("possessed");
	if (!objectp(owner))	return 0;
	if (!query("advanced_zombie"))	return 0;
	receive_fulling("kee",damage_bonus*3,owner);
	owner->receive_fulling("kee",damage_bonus*3, owner);
	return ;
}


void smart_fight()
{
	int choice;
	object owner;
	
	owner = query("possessed");
	if (!objectp(owner)) 	return;
	if (!query("advanced_zombie"))	return 0;
	
	choice = owner->query_temp("last_sqpfm_used");
	switch (choice)
	{
		case 1:		ccommand("cast feeblebolt"); break;
		case 2: 	ccommand("cast drainerbolt");break;
		default: 	ccommand("cast netherbolt"); break;
	}
	return;
}	


void backattack()
{
	int i;
	object owner, *enemy;
	if(objectp(owner = this_object()->query("possessed")))
	{
		enemy = this_object()->query_enemy();
	        i = sizeof(enemy);
	        while(i--) {
	                if( enemy[i] && living(enemy[i]) ) {
	                        if (COMBAT_D->legitimate_kill(enemy[i],owner)) {
		                        owner->kill_ob(enemy[i]);
		                        enemy[i]->kill_ob(owner);
	                	}
	                }
	        }

	}

}		
			

//	Level = who->query_skill("spells"), 400.

void animate(object who, int level)
{
     
	set("possessed", who);
	set_leader(who);
	
	annie_skillcp(who,this_object());
	annie_attcp(who,this_object());
	reset_action();
	
	set("level", F_LEVEL->get_level(query("combat_exp")));     
        set("max_kee",query("max_kee"));
        set("kee",query("kee"));
        set("eff_kee", query("eff_kee"));
        set("str",who->query_str());
                
}



void die()
{
        object corpse,owner;
	if (objectp(owner = query("possessed")))	// 被人弄死了?那么amf就会被抽空
	{
		if (!query("sacrifice"))
		{
			owner->set("atman",0);
			owner->set("mana",0);
			owner->set("force",0);
			tell_object(owner,WHT"\n你只觉得胸口如遭锤击，元气大伤。\n"NOR);
		}
		owner->delete_temp("pfm/animate_count");
	}
	backattack();		
	message_vision(HIR+name()+"一声惨叫，慢慢瘫倒下去，很快就化为一滩血水。\n"NOR, this_object());
	destruct(this_object());
}

void unconcious() {
	die();
}

void init()
{
	object	ob, targ;
	string	target;
	::init();
	add_action("do_dismiss","release");	

}

int do_dismiss(string arg)
{
	object who,obj;
	who = this_player();
	
	if(!arg) {
		tell_object(this_player(),"release什么生物？\n");
		return 1;
	}
	if(!obj=present(arg,environment()))
		return 0;
	if(obj!=this_object()) return 0;
	if(who!=query("possessed")) return 0;
	message_vision(HIC"$N口中喃喃念了几句咒语，指尖射出一道青光，向"+ name(1)+HIC"一指！\n"NOR,who);
	who->perform_busy(2);
	set("sacrifice",1);
	die();	
	return 1;
}

void heart_beat()
{
	object leader;
	
	::heart_beat();
	
	if (!this_object())	return;
		
	if(query_temp("is_unconcious")||is_busy())
		return ;

	if(query("possessed"))
	{
		leader = query("possessed");
		if(environment(leader)!=environment()&&(!leader->is_ghost()))
		{
			die();
		}
	}	
	else
	{
			die();
	}
}
