// damage.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
//	*** include F_ATTACK now to implement hate_list function ***
// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
#include <dbase.h>
#include <login.h>
#include <move.h>

inherit F_ATTACK;

void status_msg(string type);		// These 2 functions are designed to work in Zmud for hp bars
void dmg_msg(string type, object who);

int receive_heal(string type, int heal);
int receive_curing(string type, int heal);
varargs	int receive_fulling(string type, int heal, object who);
	
varargs int receive_damage(string type, int damage, object who);
varargs int receive_damage(string type, int damage, object who);

void unconcious();
varargs void die(int flag);
varargs void revive(int quiet);

add_hate(object who, int amount);
object query_max_damage_dealer();
void damage_record(object who, string type, int damage);

mapping hate_list;
mapping hate_list_2;
mapping damage_list;
    	
int ghost = 0;
int is_ghost() { return ghost; }


//Added by tie to deal with attribute damages boots
varargs int attr_change(string type, int change, object who)
{
    	int val;

    	if( type!="strength" && type!="courage" && type!="intelligence" &&
		type!="spirituality" && type!="composure" && type!="personality" &&
		type!="constitution" && type!="karma" && type!="agility" &&
		type!="durability" && type!="flexibility" && type!="tolerance" )

        error("F_DAMAGE: 伤害种类错误( 只能是 strength,courage,intelligence,spirituality,composure,personality,
constitution,karma,agility,durability,flexibility,tolerance其中之一 )。\n");

    	if( objectp(who) ) set_temp("last_attr_from", who);
    	val = (int)query("attr_apply/"+type) +change;

    	set("attr_apply/"+type, val);
    	set_heart_beat(1);
    	return change;
}

// This function is to support Zmud/tintin input information process
void status_msg(string type) {	
    	int value;
    	if (userp(this_object()) && query("env/dmg_msg")) {
	   	switch (type) {
	   		case "kee": 
	   			value = query("kee")< 0 ? 0 : query("kee");
	   			tell_object(this_object(),"fystatus:kee:"+ value + "/"+ query("eff_kee")+"/"+query("max_kee")+"\n");
	   			break;
	   		case "gin": 
	   			value = query("gin")< 0 ? 0 : query("gin");
	   			tell_object(this_object(),"fystatus:gin:"+ value + "/"+ query("eff_gin")+"/"+ query("max_gin")+"\n");
	   			break;
	   		case "sen": 
	   			value = query("sen")< 0 ? 0 : query("sen");
	   			tell_object(this_object(),"fystatus:sen:"+ value + "/"+ query("eff_sen")+"/"+ query("max_sen")+"\n");
	   			break;
	   		default:
	   			value = query("kee")< 0 ? 0 : query("kee");
	   			tell_object(this_object(),"fystatus:kee:"+ value + "/"+ query("eff_kee")+"/"+query("max_kee")+";");
	   			value = query("gin")< 0 ? 0 : query("gin");
	   			tell_object(this_object(),"gin:"+ value + "/"+ query("eff_gin")+"/"+ query("max_gin")+";");
	   			value = query("sen")< 0 ? 0 : query("sen");
	   			tell_object(this_object(),"sen:"+ value + "/"+ query("eff_sen")+"/"+ query("max_sen")+"\n");
	   	}
	}  
	return;
}

void force_status_msg(string type) {	
		int value;
    if (userp(this_object()) && query("env/dmg_msg")) {
	   	switch (type) {
	   		case "force": 
	   			value = query("force")< 0 ? 0 : query("force");
	   			tell_object(this_object(),"fystatus:force:"+ value + "/"+query("max_force")+"\n");
	   			break;
	   		case "mana": 
	   			value = query("mana")< 0 ? 0 : query("mana");
	   			tell_object(this_object(),"fystatus:mana:"+ value + "/"+ query("max_mana")+"\n");
	   			break;
	   		case "atman": 
	   			value = query("atman")< 0 ? 0 : query("atman");
	   			tell_object(this_object(),"fystatus:atman:"+ value + "/"+ query("max_atman")+"\n");
	   			break;
	   		default:
	   			value = query("force")< 0 ? 0 : query("force");
	   			tell_object(this_object(),"fystatus:force:"+ value + "/"+query("max_force")+";");
	   			value = query("mana")< 0 ? 0 : query("mana");
	   			tell_object(this_object(),"mana:"+ value + "/"+ query("max_mana")+";");
	   			value = query("atman")< 0 ? 0 : query("atman");
	   			tell_object(this_object(),"atman:"+ value + "/"+ query("max_atman")+"\n");
	   	}
	}  
	return;
}

void dmg_msg(string type, object who) {
	int ratio;
	if (userp(who) && who->query("env/dmg_msg")) {
		switch (type) {
	   		case "kee": 
	   			ratio = query("kee") < 0 ? 0 : query("kee")* 100 / query("max_kee");
	   			tell_object(who,"Enemy:kee:"+ ratio + "/100\n");
	   			break;
	   		case "gin": 
	   			ratio = query("gin") < 0 ? 0 : query("gin") * 100 / query("max_gin");
	   			tell_object(who,"Enemy:gin:"+ ratio + "/100\n");
	   			break;
	   		case "sen": 
	   			ratio = query("sen") < 0 ? 0 : query("sen")* 100/ query("max_sen");
	   			tell_object(who,"Enemy:sen:"+ ratio + "/100\n");
	   			break;
	   	}
	}
}

varargs int receive_damage(string type, int damage, object who)
{
    	int val, fate, amount;
    	int reduction/*,r_damage*/, h_damage;
    	
		//  if( damage < 0 ) error("F_DAMAGE: 伤害值为负值。\n");
    	if (damage <0) damage =0;
    	if( type!="gin" && type!="kee" && type!="sen" )
        	error("F_DAMAGE: 伤害种类错误( 只能是 gin, kee, sen 其中之一 )。\n");

		// Backfire	
		if ((query_temp("buffup/backfire") == type || query_temp("buffup/backfire") == "all") 
			&& who && !query_temp("annie/backfire_damage"))
		{
			who->set_temp("annie/backfire_damage",1);
			set_temp("annie/backfire_msg",1);
			who->receive_damage(type,damage * query_temp("buffup/backfire_amount")/ 100,this_object());
			who->delete_temp("annie/backfire_damage");
			message_vision(query_temp("buffup/backfire_msg"),this_object(),who);
		}

		// Resistance
    	if (query("resistance/"+type) || query_temp("resistance/"+type)){
			reduction=query("resistance/"+type) + query_temp("resistance/"+type);
			if (reduction >= 100)	reduction = 100;
			damage = damage - damage * reduction / 100;
		}

		if( objectp(who) ) {
			set_temp("last_damage_from", who);
    		    		
    		if (!userp(this_object())) {			
				// NPC纪录 damage_list;
				damage_record(who,type,damage);
				//	NPC记录HATE_LIST。
				h_damage = damage;
				add_hate(who, h_damage);
			}
    	}
    	
    	val = (int)query(type) - damage;
	
    	// here add for the usage of lifesave potion, only effective when "val is still > 0"
    	if ( val < query("max_"+type)/5 && val>0 && is_fighting())
    	if( (time()- query("timer/lifesave"))< 3600 )//最多一个小时
    	{
       		fate = 20 + query("pfm/chunquye_pw");		// 21% chance
	    	if( fate + 100 > random(100))
	    	{
				delete("timer/lifesave");
				message_vision(RED"\n$N"NOR+RED"强运一口真气，脸上泛出一丝红光，伤势竟然好了大半。\n\n"NOR,
					this_object());
				amount = 4000 + F_ABILITY->check_ability(this_object(),"chunquye_amt")* 300;
				receive_fulling("gin", amount);
				receive_fulling("sen", amount);
				receive_fulling("kee", amount);
	      	    tell_object(this_object(),WHT"『落花流水春去也』将你从死亡边缘唤回。\n"NOR);
				status_msg("all");
				return (damage> amount)? (damage- amount): 0 ;
			}
		}
	
		set(type, val);   	
		
			
    	set_heart_beat(1);

		// Mesmerize fuction
		if(query_temp("mesmerize")) {	
			this_object()->stop_busy();
			delete_temp("mesmerize");
			delete_temp("condition_type");
			tell_object(this_object(), YEL"你身上一痛，从迷迷糊糊中清醒了过来。\n"NOR);
		}
		
		status_msg(type);
		if (objectp(who))	{
			dmg_msg(type, who);
			set_temp("last_damage_time",time());
		}

//		if (who)
//			ANNIE_D->debuff(this_object(),"manatwist");			
    	return damage;
}

varargs int receive_wound(string type, int damage, object who)
{
    	int val,reduction, fate;
		int r_damage, h_damage, amount;
	
		//  if( damage < 0 ) error("F_DAMAGE: 伤害值为负值。\n");
    	if (damage <0) damage =0;
    	if( type!="gin" && type!="kee" && type!="sen" )
        	error("F_DAMAGE: 伤害种类错误( 只能是 gin, kee, sen 其中之一 )。\n");

		if ((query_temp("buffup/backfire") == type || query_temp("buffup/backfire") == "all") 
			&& who && !query_temp("annie/backfire_damage"))
		{
			who->set_temp("annie/backfire_damage",1);
			who->receive_wound(type,damage * query_temp("buffup/backfire_amount")/ 100,this_object());
			who->delete_temp("annie/backfire_damage");
			if (!query_temp("annie/backfire_msg"))
				message_vision(query_temp("buffup/backfire_msg"),this_object(),who);
			else
				delete_temp("annie/backfire_msg");
		}

		if (query("resistance/"+type) || query_temp("resistance/"+type)){
			reduction=query("resistance/"+type) + query_temp("resistance/"+type);
			if (reduction >= 100)	reduction = 100;
			damage=damage - damage * reduction / 100;
		}

    	val = (int)query("eff_" + type) - damage;
    	
    	if( objectp(who) ) {
    		set_temp("last_damage_from", who);
					
			if (!userp(this_object())) {			
				// Sometimes Wound doesn't do anything, we don't calculate in this case.
				r_damage = query(type) - query("eff_"+type);
				if (r_damage >0) {
					// NPC纪录 damage_list;
					damage_record(who,type,damage);
					//	NPC记录HATE_LIST。
					h_damage = damage;		
					add_hate(who, h_damage);
				}
			}	
    	}
    	
    	
    
        // here add for the usage of lifesave potion
    	if ( val < query("max_"+type)/5 && val > 0 && is_fighting())
    	if( (time()- query("timer/lifesave"))< 3600 )//最多一个小时
    	{
       		fate = 20 + query("pfm/chunquye_pw");
	    	if( fate + 100 > random(100))
	    	{
				delete("timer/lifesave");
				message_vision(RED"\n$N"NOR+RED"强运一口真气，脸上泛出一丝红光，伤势竟然好了大半。\n\n"NOR,
						this_object());
				amount = 4000 + F_ABILITY->check_ability(this_object(),"chunquye_amt")* 300;
				receive_fulling("gin", amount);
				receive_fulling("sen", amount);
				receive_fulling("kee", amount);
		       	tell_object(this_object(),WHT"『落花流水春去也』将你从死亡边缘唤回。\n"NOR);
				status_msg("all");
				return (damage> amount)? (damage- amount): 0 ;
			}
		}
        
    	set("eff_" + type, val);
    	if(query(type) > val)	set(type, val);
    	    	   	    	
    	set_heart_beat(1);

		if(query_temp("mesmerize")) 	{		
			this_object()->stop_busy();
			delete_temp("mesmerize");
			delete_temp("condition_type");
			tell_object(this_object(), YEL"你身上一痛，从迷迷糊糊中清醒了过来。\n"NOR);
		}
		
    	status_msg(type);
    	
    	if (objectp(who))	{
    		dmg_msg(type, who);
    		set_temp("last_damage_time",time());	
    	}
    	
//    	if (who)
//			ANNIE_D->debuff(this_object(),"manatwist");
			
    	return damage;
}


int receive_heal(string type, int heal)
{
    	int val;

    	if( heal < 0 ) error("F_DAMAGE: 恢复值为负值。\n");
    	if( type!="gin" && type!="kee" && type!="sen" )
        	error("F_DAMAGE: 恢复种类错误( 只能是 gin, kee, sen 其中之一 )。\n");

		if (ANNIE_D->check_buff(this_object(),"cursedflesh") > 0)
			return receive_damage(type,heal,ANNIE_D->get_buff_caster(this_object(),"cursedflesh"));

    	val = (int)query(type) + heal;
    	if( val > (int)query("eff_" + type)) {
    		set(type, (int)query("eff_" + type));
    	} else {
    		set( type, val );
    	}
    	status_msg(type);
    	
    	return heal;
}


int receive_curing(string type, int heal) {
    	int max, val;

    	if( heal < 0 ) error("F_DAMAGE: 恢复值为负值。\n");
    	if( type!="gin" && type!="kee" && type!="sen" )
        	error("F_DAMAGE: 恢复种类错误( 只能是 gin, kee, sen 其中之一 )。\n");

		if (ANNIE_D->check_buff(this_object(),"cursedflesh") > 0)
			return receive_wound(type,heal,ANNIE_D->get_buff_caster(this_object(),"cursedflesh"));

    	val = (int)query("eff_" + type);
    	max = (int)query("max_" + type);

    	if( val + heal > max ) {
        	set("eff_" + type, max);
			status_msg(type);
        	return max - val;
    	} else {
        	set("eff_" + type, val + heal);
        	status_msg(type);
        	return heal;
    	}
}


varargs	int receive_fulling(string type, int heal, object who) {
    	int max, val, eff, h_damage;
    	int num, i;
//  	mapping e_hate_list;
    	object *enemy;

    	if( heal < 0 ) error("F_DAMAGE: 恢复值为负值。\n");
    	if( type!="gin" && type!="kee" && type!="sen" )
        	error("F_DAMAGE: 恢复种类错误( 只能是 gin, kee, sen 其中之一 )。\n");

		if (ANNIE_D->check_buff(this_object(),"cursedflesh") > 0)
		{
			receive_damage(type,heal,ANNIE_D->get_buff_caster(this_object(),"cursedflesh"));
			return receive_wound(type,heal,ANNIE_D->get_buff_caster(this_object(),"cursedflesh"));
		}

    	//	这个是用来记录NPC的HATE_LIST。	
    	//	HEAL--> 所有NPC enemy 的 hate_list 增加 who。
    	
    	if (objectp(who))
    	{
    		enemy = query_enemy();
			if ( num = sizeof(enemy)){
				for (i = 0; i<sizeof(enemy);i++){
					if (userp(enemy[i])) continue;
					h_damage = heal;		
					if (h_damage > 4000)	h_damage = 4000;  // cap heal hate at 4000.
					enemy[i]->add_hate(who, h_damage);
				}
			}
		}
	    	
    	val = (int)query(type);
    	eff = (int)query("eff_" + type);
    	max = (int)query("max_" + type);

    	if( eff + heal > max ) {
        	set("eff_" + type, max);
        	if (val + heal > query("eff_"+ type) )
        		set(type, query("eff_"+ type));
        	else 
        		set(type, val + heal);	
        	status_msg(type);
        	return max - eff;
    	} else {
        	set( "eff_" + type, eff + heal);
        	if (val + heal > query("eff_"+ type) )
        		set(type, query("eff_"+ type));
        	else 
        		set(type, val + heal);	
        	status_msg(type);
        	return heal;
    	}
}

void unconcious()
{
    	object defeater;

    	if( !living(this_object()) ) return;
    	//if(query_temp("unconsious")
    	if( wizardp(this_object()) && query("env/immortal") ) return;
	// set the unconcious flag
    	
    	if(this_object()->query_temp("is_unconcious")) return;
    	this_object()->set_temp("is_unconcious",1);
    
    	if( objectp(defeater = query_temp("last_damage_from")) )
        	COMBAT_D->winner_reward(defeater, this_object());
    	COMBAT_D->loser_penalty(defeater, this_object());
    	if(!this_object()->query("possessed"))
			this_object()->remove_all_enemy();

    	message("system", HIR "\n你的眼前一黑，接著什麽也不知道了....\n\n" NOR,this_object());
    	
    	this_object()->disable_player(" <昏迷不醒>");
    	set("gin", 0);
    	set("kee", 0);
    	set("sen", 0);
    	status_msg("all");
    	add_temp("block_msg/all", 1);
    	COMBAT_D->announce(this_object(), "unconcious");
    	if(this_object()->query_temp("mark/no_uncon")) 
    		call_out("revive",1);
    	else 
    		call_out("revive", random(50 - (int) this_object()->query_con()) + 10);
}


varargs void revive(int quiet)
{
    	remove_call_out("revive");
		// unset unconcious flag
    	this_object()->delete_temp("is_unconcious");
    	while( environment()->is_character() )
        	this_object()->move(environment(environment()));
    	if( (int) this_object()->query("gin") < 0 ) this_object()->set("gin",0);
    	if( (int) this_object()->query("kee") < 0 ) this_object()->set("kee",0);
    	if( (int) this_object()->query("sen") < 0 ) this_object()->set("sen",0);
		
		status_msg("all");
    	
    	if( !quiet )
    	{
        	COMBAT_D->announce(this_object(), "revive");
        	message("system", HIY "\n慢慢地你终于又有了知觉....\n\n" NOR,this_object());
    	}
		if (query_temp("block_msg/all")>=1)
	    	add_temp("block_msg/all", -1);
		
    	this_object()->enable_player();
}


void be_ghost(int flag)
{
    	ghost = flag;
}


varargs void die(int flag) {
    	object corpse/*, trap_room,me*/, *inv;
    	mixed killer;
    	int /*i,*/ j/*,fate*/;
//  	string special_death_place;
   /* function f;
if (environment() && environment()->alternative_die(this_object())) {
	return;
    }
    if (environment() && functionp(f=environment()->query("alternative_die"))) {
	if (evaluate(f,this_object())) return;}*/
    	if(this_object()->query_temp("is_unconcious")) revive(1);
    		//if( !living(this_object()) ) revive(1);
    	if( wizardp(this_object()) && query("env/immortal") ) return;

    	// Clear all the conditions by death.
		// Remove all buffs to clean up annied
		ANNIE_D->debuff(this_object(),"all");
    	this_object()->clear_all_condition();
    	this_object()->delete_temp("block_msg/all");

     // Clear all attribute changes by death. --- NOPE, we will apply attr_penalty in 4.1.
     //	this_object()->delete("attr_apply");

     // remove all wearing items to clear mask-related identity problem.
    	inv = all_inventory(this_object());
		for(j=0; j<sizeof(inv); j++)
			inv[j]->unequip();

    	COMBAT_D->announce(this_object(), "dead");
    	if( objectp(killer = query_temp("last_damage_from")) ) {
        	set_temp("my_killer", killer->query("id"));
        	set_temp("my_killer_name", killer->query("name"));
        	COMBAT_D->killer_reward(killer, this_object());
    	}
    	
    	killer = query_temp("last_damage_from");	// Redefine because it might get changed in last step.    	
    	if(!flag)
    		COMBAT_D->victim_penalty(this_object(), killer);
    	else
		COMBAT_D->victim_penalty(this_object(), killer,flag);
		
    	if (!query_temp("no_death_penalty"))
    	if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer))) {
        	corpse->move(environment());
        	corpse->set("real_death",1);		// There are quite a few places using fake-corpse, need prevent ppl abuse.
        }

    	this_object()->remove_all_killer();
    	all_inventory(environment())->remove_killer(this_object());

		if(userp(this_object()) ) {
        	if(query_temp("no_death_penalty"))
        	{
        	    set("eff_gin",query("max_gin"));
        		set("eff_kee",query("max_kee"));
        		set("eff_sen",query("max_sen"));
				set("gin",query("max_gin")/2);
        		set("kee",query("max_kee")/2);
        		set("sen",query("max_sen")/2);
        		status_msg("all");
        		delete_temp("no_death_penalty");
        		move("/d/fy/church");
        	}else
        	{
		        set("gin", 1);	set("eff_gin", 1);
        		set("kee", 1);	set("eff_kee", 1);
        		set("sen", 1);	set("eff_sen", 1);
        		status_msg("all");
        		ghost = 1;
            	move(DEATH_ROOM);
	        	DEATH_ROOM->start_death(this_object());
           	}
        	this_object()->save();
    	} else
        	destruct(this_object());
}

void reincarnate()
{
    	ghost = 0;
    	set("eff_gin", query("max_gin"));
    	set("eff_kee", query("max_kee"));
    	set("eff_sen", query("max_sen"));
}

int max_food_capacity() 	{ return query_weight() / 200; }

int max_water_capacity() 	{ return query_weight() / 200; }

int calc_heal_up(string val, int change, mapping my)
{
	int update_flag=0;
	int show_stat;
	
	if (my[val] < my["max_"+val])
		show_stat = 1;
	
	if(my[val] > my["eff_"+val]) {
		my[val]-=change;
		if(my[val] < my["eff_"+val] ) {
			my[val]=my["eff_"+val];
		}
		update_flag++;
	} else {
		my[val]+=change;
		if(my[val] > my["eff_"+val] ) {
			my[val]=my["eff_"+val];
			if( my["eff_"+val] < my["max_"+val] ){
				my["eff_"+val]++;
				update_flag++;
			}
		}
	}
	if (show_stat)	status_msg(val);
	
	return update_flag;
}

int heal_up() {
    	int update_flag, i;
    	mapping my;

		my = query_entire_dbase();
			
	// can't heal while fighting.
    	if( this_object()->is_fighting() ) {   	
    		return -1;
    	}
    
    //	New death mark to stop recover.
    	if (this_object()->query("death_revive")+ 180 > time())
    		return -1;
    
    // Da zuo will increase the heal points by 2x
    	update_flag = 0;
    	if (this_object()->query_temp("in_dazuo")) i = 2;
    	else 
    		i = 1;

	// Decrease water and food, and if they are zero, can't heal.
    	if( my["water"] > 0 ) { my["water"] -= 1; update_flag++; }
    	if( my["food"] > 0 ) { my["food"] -= 1; update_flag++; }

    	if( my["water"] < 1 && userp(this_object()) ) return update_flag;
    	if( my["food"] < 1 && userp(this_object()) ) return update_flag;

	// Heal points calcuated base on the spi and atman/force/mana
    	update_flag+=calc_heal_up("gin",(my["int"]  + my["atman"] / 10) * i +1,my);
    	update_flag+=calc_heal_up("kee",(my["con"]  + my["force"] / 10) * i +1,my);
    	update_flag+=calc_heal_up("sen",(my["int"]  + my["mana"] / 10) * i +1,my);

    	if( my["max_atman"] && my["atman"] < 2*my["max_atman"] ) {
        	my["atman"] += ((int)this_object()->query_skill("magic", 1) / 2) * i;
        	if( my["atman"] > 2*my["max_atman"] ) my["atman"] = 2*my["max_atman"];
        	force_status_msg("atman");
        	update_flag++;
    	}
				
    	if( my["max_force"] && my["force"] < 2*my["max_force"] ) {
        	my["force"] += ((int)this_object()->query_skill("force", 1) / 2) * i;
        	if( my["force"] > 2*my["max_force"] ) my["force"] = 2*my["max_force"];
        	force_status_msg("force");
        	update_flag++;
    	}
		
    	if( my["max_mana"] && my["mana"] < 2*my["max_mana"] ) {
        	my["mana"] += ((int)this_object()->query_skill("spells", 1) / 2) * i;
        	if( my["mana"] > 2*my["max_mana"] ) my["mana"] = 2*my["max_mana"];
        	force_status_msg("mana");
        	update_flag++;
    	}
    	    	
    	return update_flag;
}

void check_status()
{
		mapping my;
		my=query_entire_dbase();
        
        if( my["eff_kee"] < 0
         || my["eff_sen"] < 0
         || my["eff_gin"] < 0
         || my["kee"] < -2 * my["con"]
         || my["sen"] < -2 * my["con"]
         || my["gin"] < -2 * my["con"])
        {
                this_object()->remove_all_enemy();
                die();
                return;
        }
 		
 		if( my["kee"] < 0 || my["sen"] < 0 || my["gin"] < 0) {
                this_object()->remove_all_enemy();
                unconcious();
                return;
        }
}

void full_me() {
	
		int i;
		string *item = ({"gin","kee","sen"});
	
		for (i=0;i<3;i++) {
			set( item[i], query("max_" + item[i]));
			set("eff_" + item[i], query("max_" + item[i]));
		}
		status_msg("all");
		return;
}

		
mapping query_hate_list()	{
	return hate_list;
}

mapping query_hate_list2()	{
	return hate_list_2;
}

// 给出*能够打击到的*最憎恨的敌人.
object query_max_hate() {
	object *hate_id/*,badguy*/;	
	int i,num,base,flag;

	if (mapp(hate_list)) {
		hate_id = keys(hate_list);
		if (i=sizeof(hate_list)) {
			while (i--) {
				if (!objectp(hate_id[i])) {
					hate_id[i] = 0;
					continue;
				}
				if (hate_list[hate_id[i]] < 0)
					hate_list[hate_id[i]] = 0;
				if (!is_fighting(hate_id[i])	
					|| environment()!= environment(hate_id[i]))
					continue;				
				if (hate_list[hate_id[i]] > base) {
					base = hate_list[hate_id[i]];
					num = i;
					flag = 1;
				}
			}
			if (flag)
				return hate_id[num];
			else
				return 0;	
		}
	}	
}		

// 查询某一对手的HATE
int query_hate(object enemy)
{
	if (mapp(hate_list))	
	{
		return 	hate_list[enemy];
	}
	return 0;
	
}

//	给出一个函数来任意增加hate
int add_hate(object who, int amount){
	
	if( !mapp(hate_list) )
		hate_list = ([ who : amount ]);
	else  
		hate_list[who] = (hate_list[who] + amount)>0 
					? hate_list[who] + amount:0;
	
	// 以下的这个是用来记录总体hate供设计者参考的，不会受remove影响
	if( !mapp(hate_list_2) )
		hate_list_2 = ([ who : amount ]);
	else  
		hate_list_2[who] = (hate_list_2[who] + amount)>0 
					? hate_list_2[who] + amount:0;
	
	return 1;
}

//	我谁都不恨了．．．．供npc的char.c调用来置零
int stop_hate(){
	hate_list = ([]);
	hate_list_2 = ([]);
	return 1;
}

// 	和上面函数的区别是，这个是可以动态调用，消除hate.
int reset_hate() {
	hate_list = ([]);
	return 1;
}


// 以下为 NPC recording damage

void clear_damage_list(){
	damage_list = ([]);
}

void damage_record(object who, string type, int damage) {
		object owner;

		if (!objectp(who))	return;
		if (objectp(who->query("possessed")))
			owner = who->query("possessed");
		else
			owner = who;
			
		if( !mapp(damage_list) )
			damage_list = ([ owner : damage ]);
		else  
			damage_list[owner]=damage_list[owner] + damage;			
}


mapping query_damage_list(){
	return damage_list;
}

mapping query_combined_damage_list(){
	int i,j,n;
	mapping list;
	object *a, *team;
	int *b;
		
	n = sizeof(damage_list);
	if (n<1) return 0;
		
	a = keys(damage_list);
	b = allocate(n);
	list = allocate_mapping(n);
		
	for (i=0;i<n;i++) {
		if (!objectp(a[i])) continue;
		if (b[i])	continue;
		
		list[a[i]] = damage_list[a[i]];					
		
		team = a[i]->query_team();
		if (!team || !sizeof(team)) {
			continue;
		}
		
		for (j= i+1;j<n;j++) {
			if (!objectp(a[j])) continue;
			if (a[i]->team_member(a[j])) {
				list[a[i]] = list[a[i]]+ damage_list[a[j]];
				b[j] = 1;	
				continue;
			} 
		}	
	}
	
	return list;
}

object query_max_damage_dealer(){

	mapping list;
	int i,n,base;
	object *a;
	
	base = 0;
	
	if (sizeof(damage_list)<1)	return 0;
		
	list = query_combined_damage_list();
	if (sizeof(list)<1)	return 0;
	
	a = keys(list);
	n = 0;
	
	for (i=0;i<sizeof(list);i++){
		if (!a[i] || !objectp(a[i]))	continue;
		if (list[a[i]]> base){
			n = i;
			base = list[a[i]];
		}
	}			
	return a[n];	
}	



// 以下两个函数从attack.c转移过来
// This function checks if the current opponent is available or
// select a new one.
object select_opponent() {
	
	object *enemy_selected, *enemy_weak, prefered, *enemy;
	object target;
	string target_name;
	
	enemy = query_enemy();
	
	if(!sizeof(enemy)) return 0;
	clean_up_enemy();
	if(!sizeof(enemy)) return 0;
		
	if (!userp(this_object())) {		
		// 第一步先选出快死的 --〉make sure you die :D
		// 第二个选择是冒犯你最多的-->max_hate guy
		// 实在不行就随便选了
		enemy_weak = filter_array(enemy, (: $1->query("kee") < $1->query("max_kee")/10 
					&& userp($1) :));
		if (sizeof(enemy_weak) >= 1)
			enemy_selected = enemy_weak;
		else if (!objectp(prefered = query_max_hate()))		
			enemy_selected = enemy;	
		else
			return prefered;
		
	} else {
		enemy_selected = enemy;
		if (stringp(target_name = query("env/target"))) {
			if (objectp(target = present(target_name, environment())))
			if (member_array(target,enemy) != -1)
				return target;
		}
	}		
	return enemy_selected[random(sizeof(enemy_selected))];
}

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

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/