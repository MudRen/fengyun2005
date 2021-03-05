// attack.c
// Copyright (C) 1995 - 2005, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

/* Enemy, Rival & Killer

	Enemy: Any object that is in fight. It is removed when Remove_enemy (leave) or 
		Remove_killer is called. And any object is unique in enemy_list.
	Rival: it is used to locate and remove killer, it is never cleared in other cases.
	Killer: First, it's a string instead of an object.


	Last Modifications
	1. this file is now included in damage.c... /std/char will only inherit damage.c 
	2. move two functions to damage.c for hate_list implementation.
		-- Silencer @ FY4 workgroup. Aug.2004
*/

#include <ansi.h>
#include <dbase.h>
#include <origin.h>
#include <skill.h>

nosave int attackTick = 0;
nosave int Max_Action_Count = 4;
nosave int actionCount = 0;
nosave object *enemy = ({});
nosave object *rival = ({});
nosave string *killer = ({});

// This function returns 1 if we are fighting anyone (or with ob)
varargs int is_fighting(object ob) {
	if(!ob) return sizeof(enemy) > 0;
	return member_array(ob, enemy)!=-1;
}

// This function returns 1 if we are fighting anyone (or with ob)
varargs int is_killing(string id){
	if(!id) return sizeof(killer) > 0;
	return member_array(id, killer)!=-1;
}

//This function starts fight between this_object() and ob
void fight_ob(object ob) {
	if(!ob || ob==this_object()) return;
	set_heart_beat(1);
	
/*	if (ANNIE_D->check_buff(this_object(),"invisible"))
		ANNIE_D->debuff(this_object(),"invisible",1);
	
	if (ANNIE_D->check_buff(ob,"invisible"))
		ANNIE_D->debuff(ob,"invisible",1);*/
		
	if( member_array(ob, enemy)==-1 )
	{
		enemy += ({ ob });
		if (member_array(ob, rival) == -1)
			rival  += ({ ob });
	}
}

// This function starts killing between this_object() and ob
void kill_ob(object ob) {
//	object *pros;
//	int i;
//	string master_id;
//	object master_ob;

	if (!ob)
		return;

/*	if (ANNIE_D->check_buff(this_object(),"invisible"))
		ANNIE_D->debuff(this_object(),"invisible",1);
	
	if (ANNIE_D->check_buff(ob,"invisible"))
		ANNIE_D->debuff(ob,"invisible",1);*/
		
	if( member_array(ob->query("id"), killer)== -1) {
		killer += ({ ob->query("id") });

	}
	if (query("race") != "元素" && !query_temp("hidden_kill_msg"))
		tell_object(ob, HIR "看起来"+this_object()->name() + HIR"想杀死你！\n" NOR);

	fight_ob(ob);
}

void clean_up_enemy() {
	if(sizeof(enemy) > 0) {
		for(int i=0; i<sizeof(enemy); i++) {
			if(!objectp(enemy[i]) || environment(enemy[i])!= environment()
					|| (!living(enemy[i]) && !is_killing(enemy[i]->query("id")))) {
				enemy[i] = 0;
			}
		}
		enemy -= ({ 0 });
	}
}

/* This function checks if the current opponent is available or
// select a new one.-- move to damage.c
object select_opponent() {
	
	object *enemy_selected, *enemy_weak, prefered;
	
	if(!sizeof(enemy)) {
		return 0;
	}
	clean_up_enemy();
	if(!sizeof(enemy)) {
		return 0;
	}
	
	if (!userp(this_object())) {
		
		// 第一步先选出快死的--〉make sure you die :D
		// 第二个选择是冒犯你最多的-->max_hate guy
		// 实在不行就随便选了
		enemy_weak = filter_array(enemy, (: $1->query("kee") < $1->query("max_kee")/5 :));
		if (sizeof(enemy_weak) >= 1)
			enemy_selected = enemy_weak;
		else if (!objectp(prefered = query_max_hate()))		
			enemy_selected = enemy;	
	
	} else
		enemy_selected = enemy;
		
	return enemy_selected[random(sizeof(enemy_selected))];
}*/

// Stop fighting ob.
int remove_enemy(object ob) {
	if(is_killing(ob->query("id"))) {
		return 0;
	}
	enemy -= ({ ob });
	return 1;
}

// Stop killing ob.
int remove_killer(object ob) {
	if(is_killing(ob->query("id"))) {
		killer -= ({ ob->query("id") });
		rival -= ({ ob });
	}
	rival -= ({ 0 });
	return remove_enemy(ob);
}

// Stop all fighting, but killer remains.
void remove_all_enemy() {
	if(!sizeof(enemy)) {
		return;
	}
	for(int i=0; i<sizeof(enemy); i++) {
		if(objectp(enemy[i]) && enemy[i]->remove_enemy(this_object())) {
			enemy[i] = 0;
		}
	}
	enemy -= ({ 0 });
}

// Stop all fighting and killing.
void remove_all_killer() {
	killer = ({});
	if(!sizeof(rival)) {
		return remove_all_enemy();
	}
	for(int i=0; i<sizeof(rival); i++) {
		if(objectp(rival[i]) && rival[i]->remove_killer(this_object())) {
			rival[i] = 0;
		}
	}
	rival -= ({ 0 });
	return remove_all_enemy();
}

// reset_action()
// This function serves as a interface of F_ATTACK and wielded, worn objects.
// When the living's fighting action need update, call this function.
void reset_action() {
	object ob;
	string type, skill;

	if(ob = query_temp("weapon")) {
		type = ob->query("skill_type");
	} else if(ob = query_temp("secondary_weapon")) {
		type = ob->query("skill_type");
	} else {
		type = "unarmed";
	}

	if(stringp(skill = query_skill_mapped(type))) {
		set("actions", (: call_other, SKILL_D(skill), "query_action", this_object(), ob :));
	} else {
		if(ob) {
			set("actions", (: call_other, ob, "query_action", this_object(), ob :));
		} else {
			set("actions", query("default_actions",1) );
		}
	}
}

/*	I don't think these two are used in game now.--- Silencer
void reset_action_count() {
	int level;
	level = this_object()->query_skill("move");
	Max_Action_Count = 4 + level/100;
	actionCount = 0;
}

int increase_action(int num) {
	Max_Action_Count += num;
	return Max_Action_Count;
}

*/


/*
// this is called in heart_beat() to perform attack action.-- move to damage.c
int attack() {
	object opponent;
	opponent = select_opponent();
	if(objectp(opponent)) {
		set_temp("last_opponent", opponent);
		COMBAT_D->fight(this_object(), opponent);
		return 1;
	} else {
		return 0;
	}
}
*/

int actionOK() {
	actionCount++;
	if(actionCount <= Max_Action_Count) {
		return 1;
	}
	return 0;
}

//
// init() - called by MudOS when another object is moved to us.
//
void init() {
	object ob, me;
	string vendetta_mark, mark;

	me = this_object();
	ob = this_player();

	// We check these conditions here prior to handle auto fights. Although
	// most of these conditions are checked again in COMBAT_D's auto_fight()
	// function, these check reduces lots of possible failure in the call_out
	// launched by auto_fight() and saves some overhead.
	if( !living(me) || !(ob) || environment(ob)!=environment()
			|| !living(ob) || ob->query("linkdead") || ob->query_temp("in_jiasi")) {
		return;
	}
	if(userp(me) || userp(ob) || !me->query_temp("is_unconcious")) {
		mark = "no_fight";
		if(userp(ob) && is_killing(ob->query("id"))) {
			mark = "hatred";
		} else if(stringp(vendetta_mark = query("vendetta_mark"))
				&& ob->query("vendetta/" + vendetta_mark) && me->visible(ob)) {
			mark = "vendetta";
		} else if(userp(ob) && (string)query("attitude")=="aggressive" && me->visible(ob)) {
			mark = "aggressive";
		} else if(random((int)query("bellicosity") / 80) >(int)this_object()->query_cps()
			&& me->visible(ob)) {
			mark = "berserk";
		} else if(userp(ob) && ob->is_naked()) {
			mark = "naked";
		}
		if(mark != "no_fight") {
			call_out((: call_other, COMBAT_D, "auto_fight", me, ob, mark :) , random(3));
		}
	}
	return;
}

object *query_enemy() {
	clean_up_enemy();
	return enemy;
}

object *query_rival() {
	return rival;
}

string *query_killer() {
	return killer;
}

void add_rival(object ob)
{
	if(member_array(ob, rival)==-1)
		rival += ({ob});
}

void add_enemy(object ob)
{
	if( member_array(ob, enemy)==-1)
		enemy += ({ob});
}

void add_killer(string id)
{
	if( member_array(id, killer)==-1)
		killer += ({id});
}

object query_weapon()
{
	if (query_temp("weapon"))
		return query_temp("weapon");
	else if (query_temp("secondary_weapon"))
		return query_temp("secondary_weapon");
	else if (query_temp("left_hand"))
		return query_temp("left_hand");
	else if (query_temp("right_hand"))
		return query_temp("right_hand");
}
