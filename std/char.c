// char.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
// Last modification:
//		- 08/21/2001 by Daniel Q. Yu.
//			* Rewrite heart_beat function.
//		--06/2005 by Silencer
//			* allow update_condition() take place in busy			
//			* add continue_action() when ppl is unconcious, otherwise busy won't count



#pragma save_binary

#include <action.h>
#include <ansi.h>
#include <command.h>
#include <condition.h>
#include <dbase.h>
#include <move.h>
#include <name.h>
#include <skill.h>
#include <team.h>
#include <user.h>

inherit F_ATTRIBUTE;
inherit F_ACTION;
inherit F_DAMAGE;
inherit F_ALIAS;
inherit F_PAWN;
inherit F_APPRENTICE;
// inherit F_ATTACK;	--- due to new features, F_ATTACK is included in F_DAMAGE now.
inherit F_COMMAND;
inherit F_CONDITION;
inherit F_DBASE;
inherit F_EDIT;
inherit F_FINANCE;
inherit F_MESSAGE;
inherit F_MORE;
inherit F_MOVE;
inherit F_NAME;
inherit F_SKILL;
inherit F_TEAM;

inherit F_ANNIE;

#define MAX_CARRY 15;

// Use a tick with longer period than heart beat to save cpu's work
nosave int tick;

void create()
{
	seteuid(0); // so LOGIN_D can export uid to us
}

// Use this function to identify if an object is a character.
int is_character() { return 1; }

// setup: used to configure attributes that aren't known by this_object()
// at create() time such as living_name (and so can't be done in create()).
void setup()
{
	seteuid(getuid(this_object()));

	set_heart_beat(1);
	tick = 5 + random(10);
    	enable_player();

	CHAR_D->setup_char( this_object() );
}

void heart_beat() {
	int wimpy_ratio, to_wimpy, cnd_flag/*, num*/;
	mapping my;
	object ob;
	string savemyass/*, file*/;
	object *enemy;
	if(!this_object()) {
		return;
	}

/*	if (sscanf(file_name(this_object()),"%s#%d", file, num)!=2)	{
		disable_commands();
		return;
	}*/
		
	if (query_temp("in_heart_beat"))
		return;

	my = query_entire_dbase();

	// If we are dying because of mortal wounds?
	if( my["eff_kee"] < 0 || my["eff_sen"] < 0 || my["eff_gin"] < 0
			|| my["kee"] < -2 * my["con"]  || my["sen"] < -2 * my["con"] 
			|| my["gin"] < -2 * my["con"]) {
		remove_all_enemy();
		die();
		return;
	}

	// If we are unconcious, just return;
	if(query_temp("is_unconcious"))  {
		if(is_busy()) 
			continue_action();
		return;
	}

	// If we're dying or falling unconcious?
	if( my["kee"] < 0 || my["sen"] < 0 || my["gin"] < 0) {
		remove_all_enemy();
		if(is_busy()) 
			continue_action();
		unconcious();
		return;
	}

	// If busy, continue action and return here.
	if(is_busy()) {
		continue_action();
//		return;				// This will cause no update_condition();
	} 
	else
	
	{
		// Is it time to flee?
		if(is_fighting() && intp(wimpy_ratio = (int)query("env/wimpy"))
				&& wimpy_ratio > 0
				&& (my["kee"] * 100 / my["max_kee"] <= wimpy_ratio
				|| my["sen"] * 100 / my["max_sen"] <= wimpy_ratio
				|| my["gin"] * 100 / my["max_gin"] <= wimpy_ratio)) {
			to_wimpy=0;
			enemy=query_enemy();
			for(int i=0; i<sizeof(enemy); i++)
					if (environment() == environment(enemy[i])) to_wimpy = 1;
			if (to_wimpy) {
				if(stringp(savemyass = (string) query("env/savemyass"))) {
					set_temp("in_heart_beat", 1);
					command(savemyass);
					set_temp("in_heart_beat", 0);
				} else {
					GO_CMD->do_flee(this_object());
				}
			}
		}

		// Do attack or clean up enemy if we have fleed.
		if(is_fighting()) {
			// as long as we are in a fight, we are nervous, our 心神 drops
			my["sen"]--;
			attack();
		}
	
		// chat() may do anything -- include destruct(this_object())
		// objectp check is added for some strange this_object() return 0 reason.
		// If you want NPC to do something in busy... inherit SMART_NPC
		if(objectp(this_object()) && !userp(this_object())) {
			this_object()->chat();
			if(!this_object()) {
				return;
			}
		}
	}

	if(tick--) {
		return;
	} else {
		tick = 5 + random(10);
	}

	cnd_flag = update_condition();
	
	if (!this_object())	return;
		
	if (!living(this_object())) return;

	// 讓我們在這裡檢測player的異常狀態。
	// 爲了減少資源佔用，並不是每次condition都會觸發...
	if (random(10) < 1 && userp(this_object()) && !wizardp(this_object()))
		if (!check_legitimate_state(this_object()))
			return;

	// If we are compeletely in peace, turn off heart beat.
	// heal_up() must be called prior to other two to make sure it is called
	// because the && operator is lazy :P

	if( ((cnd_flag & CND_NO_HEAL_UP) || !heal_up()) && !is_fighting()
			&& !interactive(this_object())) {
		if(environment()) {
			ob = first_inventory(environment());
			while(ob && !interactive(ob)) {
				ob = next_inventory(ob);
			}
		}
		if(!ob && !query("ALWAYS_ACTIVE")) set_heart_beat(0);
	}
	if(!this_object()) return;
	if(!interactive(this_object())) return;

	// Make us a bit older. Only player's update_age is defined.
	// Note: update_age() is no need to be called every heart_beat, it
	//       remember how much time has passed since last call.
	this_object()->update_age();
	if(query_idle(this_object()) > IDLE_TIMEOUT) {
		this_object()->user_dump(DUMP_IDLE);
	}
}

int visible(object ob)
{
	int lvl, invis;
	lvl = wiz_level(this_object());
	invis = ob->query("env/invisibility");

	if( lvl >= 3 || lvl > wiz_level(ob) ) return 1;

//	This period will last 0-2sec after you escape from fight due to heart-beat.
	if (ob->is_fighting())	return 1;

/*		
	// 下面两个情况，既然战斗了，wiz就不必要再隐身了。
	// 战斗中的双方始终可见
	if (is_fighting(ob) || ob->is_fighting(this_object()))	return 1;
	
	// 玩家对所有战斗中的玩家可见
	if (userp(this_object()) && userp(ob) && ob->is_fighting())	return 1;	
*/
	
	if( intp(invis) && (invis > lvl) )
		return 0;
	
	if( ob->is_ghost() ) {
		if( is_ghost() ) return 1;
		if( query_temp("apply/astral_vision") ) return 1;
		return 0;
	}
	if( ob->query("no_see")) return 0;
	return 1;
}

int ccommand(string com) {
	return	command(com);
}

int is_naked() {
	return (query("race") != "人类"
			|| query_temp("apply/not_naked") ? 0 : 1);
}