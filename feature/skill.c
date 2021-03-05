// skill.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
// Last modification:
//		- 07/20/2001 by Daniel Q. Yu.
//			* Change death penalty.
//		- 6/20/2004 by SIlencer
//			* Change spi penalty

//	此feature用来处理skill的设置、增长及降低。




#include <ansi.h>
#include <dbase.h>

mapping skills;
mapping learned;
mapping skill_map;

mapping query_skills() { return skills; }
mapping query_learned() { return learned; }

void set_skill(string skill, int val)
{
    	if( !find_object(SKILL_D(skill))
		&&	file_size(SKILL_D(skill)+".c") < 0 )
        	error("F_SKILL: No such skill (" + skill + ")\n");

    	if( !mapp(skills) ) skills = ([ skill: val ]);
    	else skills[skill] = val;
}

int delete_skill(string skill)
{
    	if( !mapp(skills) ) return 0;
    	if(undefinedp(skills[skill])) return 0;
    	if( mapp(skills) ) map_delete(skills, skill);
    	if( mapp(learned) ) map_delete(learned, skill);
    	if( mapp(skill_map) )
    	{
        	int i;
        	string *name;
        	name = keys(skill_map);
        	for(i=0;i<sizeof(name);i++)
            	if(name[i]==skill || skill_map[name[i]] == skill)
			map_delete(skill_map, name[i]);
    	}
    	return undefinedp(skills[skill]);
}

// This function 'map' a skill <skill> to another skill <mapped_to>.
// If 2nd argument not given, cancel the mapped skill <skill>.
varargs void map_skill(string skill, string mapped_to)
{
    	if( !mapped_to && mapp(skill_map) ) {
        	map_delete(skill_map, skill);
        	return;
    	}

    	if( !find_object(SKILL_D(skill))
		&&	file_size(SKILL_D(skill)+".c") < 0 )
        	error("F_SKILL: No such skill (" + skill + ")\n");

    	if( !mapp(skills) || undefinedp(skills[mapped_to]) )
        	return;
		
    	if( !mapp(skill_map) ) skill_map = ([ skill: mapped_to ]);
    	else skill_map[skill] = mapped_to;
}

string query_skill_mapped(string skill) {
    	if(mapp(skill_map) && !undefinedp(skill_map[skill]))
        	return skill_map[skill];
    	return 0;
}


//	This function query real skill level:
varargs int query_skill(string skill, int raw) {
	if(!raw) {
		int s , level;
		if(mapp(skills)) {

			level = (int) (SKILL_D(skill)->effective_level(this_object()));
			s += skills[skill] * level / 100;
			if(mapp(skill_map) && skill_map[skill]) {


			if (skill == "parry")
				level = (int)(SKILL_D(skill_map[skill])->eff_parry_level(this_object()));
			else
				level = (int)(SKILL_D(skill_map[skill])->effective_level(this_object()));

				s += skills[skill_map[skill]] * level / 100 ;
			}
		}
		return s;
	}
	if(mapp(skills) && !undefinedp(skills[skill])) {
		return skills[skill];
	}
	return 0;
}

//	This function query modifiers on skill

int query_skill_modifier(string skill) {
	int s;
	s=query_temp("apply/"+skill);
	if (skill=="unarmed"|| skill == "dodge" || skill == "move" || skill== "parry") 
			s+=query_skill("advanced-"+skill,1)/4;	
	return s;
}


//	This function query the combined/final level of skills

int query_skill_combined(string skill) {
	return query_skill_modifier(skill) + query_skill(skill) ;
}


mapping query_skill_map() {
    	return skill_map;
}


int skill_death_penalty(int combat_exp) {
	string *sk, *good_sk, *pen_sk, top_sk;
	int top/*, count*/,i/*,j,k*/,s;
	mapping combat_level;
	
	//	66k 为 L 10, 以下死亡没有损失。
	combat_level = F_LEVEL->exp_to_level(combat_exp);
	
	if(!mapp(skills) || combat_level["level"] < 10) {
		return 0;
	}
	
	top = 0;
	sk = keys(skills);
	good_sk = ({});
	for(i=0;i<sizeof(skills);i++) {
		//Only try those more than 20 (avoid flushing by junk skills)
		if((s = skills[sk[i]]) >=20) {
			good_sk = good_sk + ({sk[i]});
			if(s > top) {
				top_sk = sk[i];
				top = s;
			}
		}
	}
	if(sizeof(good_sk) == 0) {
		return 0;
	}
	pen_sk = ({top_sk});
	good_sk = good_sk - ({top_sk});
	
	// Add one random skill for combat exp > 1216,000 (L50)
	if(combat_level["level"] >= 50) {
		s=sizeof(good_sk);
		if(s > 0) {
			top_sk = good_sk[random(s)];
			pen_sk = pen_sk + ({top_sk});
			good_sk = good_sk - ({top_sk});
		} 
	}
	
	// Decrease skills
	
	delete("death");		//	清除上次的死亡纪录。
	for(i=0; i<sizeof(pen_sk); i++) {
		set("death/"+pen_sk[i],query_skill(pen_sk[i],1));
		skills[pen_sk[i]]--;
		tell_object(this_object(), "你的"RED+SKILL_D(pen_sk[i])->name()+NOR"降低了！\n");
	}
}

varargs void improve_skill(string skill, int amount, int weak_mode) {
//  	int spi;
    	if( !find_object(SKILL_D(skill))
		&&	file_size(SKILL_D(skill)+".c") < 0 )
        	error("F_SKILL: No such skill (" + skill + ")\n");

    	if( !weak_mode || !userp(this_object()) ) {
        if( !mapp(skills) ) skills = ([]);
//		if( undefinedp(skills[skill]) ) skills[skill] = 0;
    	}

    // Give learning penalty to those learning too much skills.-- removed by Silencer
/*    	spi = this_object()->query_int();
    	if( sizeof(skills) > spi )
        	amount -= sizeof(skills) - spi;		
    	if( amount <= 0 ) amount = 1;				*/

    	if( !mapp(learned) ) learned = ([ skill : amount ]);
    	else (int)learned[skill] += amount;

//	put a upper limit here so that we can implment research_skill
    	if(learned[skill] > (skills[skill] + 1) * (skills[skill] + 1))
		learned[skill] = (skills[skill] + 1) * (skills[skill] + 1) +1;
    	if( (!weak_mode || !userp(this_object()))
		&&	learned[skill] > (skills[skill] + 1) * (skills[skill] + 1) 
		&& STATUS_D->ski_summary(this_object(),skill,skills[skill])
		) {
        	skills[skill]= skills[skill]+1;

        learned[skill] = 0;
        tell_object(this_object(), HIC "你的「" + SKILL_D(skill)->name() + "」进步了！\n" NOR);
        SKILL_D(skill)->skill_improved(this_object());
    }
}

varargs void decrease_skill(string skill, int amount, int weak_mode) {
//  	int spi;
    	if( !find_object(SKILL_D(skill))
        	&&      file_size(SKILL_D(skill)+".c") < 0 )
        	error("F_SKILL: No such skill (" + skill + ")\n");

    	if( !weak_mode || !userp(this_object()) ) {
        	if( !mapp(skills) ) skills = ([]);
    	}
    	if( weak_mode )
    	{
        	if( mapp(learned) ) {
		            if (((int)learned[skill] - amount ) > 0 )
                		(int)learned[skill] -= amount;
            		else learned[skill] = 0;
        	}
    	}
    	else
    	{
        	skills[skill]= skills[skill]-1;
        	learned[skill] = 0;
        	if( skills[skill] <= 0 ) skills[skill] = 0;
        	tell_object(this_object(), HIC "你的「" + SKILL_D(skill)->name() + "」退步了！\n" NOR);
        	SKILL_D(skill)->skill_decreased(this_object());
    	}
}


void research_skill(string skill, int amount)
{
//  	int spi;
//  	int weak_mode;
    	if( !find_object(SKILL_D(skill))
        	&&      file_size(SKILL_D(skill)+".c") < 0 )
        	error("F_SKILL: No such skill (" + skill + ")\n");

    	if( !mapp(skills) ) skills = ([]);

/* Give learning penalty to those learning too much skills.
    	spi = this_object()->query_spi();
    	if( sizeof(learned) > spi )
        amount -= sizeof(learned) - spi;
    	if( amount <= 0 ) amount = 0;	*/

    	if( !mapp(learned) ) learned = ([ skill : amount ]);
    	else (int)learned[skill] += amount;
    	if(learned[skill] > 2* (skills[skill] + 1) * (skills[skill] + 1) 
        	&& STATUS_D->ski_summary(this_object(),skill,skills[skill])
		) {
        		skills[skill]= skills[skill]+1;
		        learned[skill] = 0;
        		tell_object(this_object(), HIC "你的「" + SKILL_D(skill)->name() + "」进步了！\n" NOR);
        		SKILL_D(skill)->skill_improved(this_object());
    	}
}


void reset_skills()		{	skills = ([]);	}

void reset_learned()	{	learned = ([]);	}

void reset_skill_map()	{	skill_map = ([]);	}
