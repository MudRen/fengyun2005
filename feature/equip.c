//	equip.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
// Last modification:
//		- 07/05/2001 by Daniel Q. Yu.
//		- 07/15/2004 by Silencer
//			**	扩展武器护具的属性范围


#include <dbase.h>
#include <weapon.h>

int div = 10;		// 此参数决定武器/护具上的属性与人物属性的比例，div=10意味着武器上10点相当于人物1点。
string *att = ({"intelligence", "strength", "composure", "karma","agility","constitution"});

 		

int wear() {
	object owner;
	mapping armor_prop, applied_prop, applied_prop_real;
	string *apply, type;
	int i, a;

	// Only character object can wear armors.
	if(!objectp(owner = environment()) || !owner->is_character()) {
		return 0;
	}
	
	// If already worn, just recognize it.
	if(query("equipped")) {
		return 1;
	}
	
	// Check if we have "armor_prop" defined.
	if(!mapp(armor_prop = query("armor_prop"))) {
		return notify_fail("你只能穿戴可当作护具的东西。\n");
	}
	
	// Check for armor_type
	type = query("armor_type");
	if(!stringp(type)) {
		return notify_fail("你只能穿戴可当作护具的东西。\n");
	}
	if(owner->query_temp("armor/" + type)) {
		return notify_fail("你已经穿戴了同类型的护具了。\n");
	}
	if(type == "shield") {
		if(owner->query_temp("left_hand")) {
			return notify_fail("你必须空出左手来使用盾牌。\n");
		}
		owner->set_temp("left_hand",this_object());
	}
	owner->set_temp("armor/" + type, this_object());
	
	// Add armor prop to charactor apply prop.
	apply = keys(armor_prop);
	
	applied_prop_real = owner->query_temp("apply_real");
	if(!mapp(applied_prop_real)) {
		applied_prop_real = ([]);
	}
	
	applied_prop = owner->query_temp("apply");
	if(!mapp(applied_prop)) {
		applied_prop = ([]);
	}
			
	for(i = 0; i<sizeof(apply); i++) {
		if(undefinedp(applied_prop_real[apply[i]])) {
			applied_prop_real[apply[i]] = armor_prop[apply[i]];
			if (member_array(apply[i], att) == -1){
				if (applied_prop[apply[i]])
					applied_prop[apply[i]] += armor_prop[apply[i]];
				else
					applied_prop[apply[i]] = armor_prop[apply[i]];
				}
			else{
				if (applied_prop[apply[i]])
					applied_prop[apply[i]] += armor_prop[apply[i]]/div;
				else
					applied_prop[apply[i]] = armor_prop[apply[i]]/div;
			}
		} else {
			a = applied_prop_real[apply[i]];
			applied_prop_real[apply[i]] += armor_prop[apply[i]];
			if (member_array(apply[i], att) == -1)
				applied_prop[apply[i]] += armor_prop[apply[i]];
			else
				applied_prop[apply[i]] = applied_prop[apply[i]] 
					+ (applied_prop_real[apply[i]]/div - a/div);
		}
	}
	

/*	tell_object(owner, sprintf("%O\n", applied_prop_real));
	tell_object(owner, sprintf("%O\n", applied_prop));*/
	owner->set_temp("apply_real", applied_prop_real);
	owner->set_temp("apply", applied_prop);

	if (query("armor_prop/max_gin"))
	{
		owner->add("max_gin",query("armor_prop/max_gin"));
		owner->add("eff_gin",query("armor_prop/max_gin"));
	}

	if (query("armor_prop/max_sen"))
	{
		owner->add("max_sen",query("armor_prop/max_sen"));
		owner->add("eff_sen",query("armor_prop/max_sen"));
	}

	if (query("armor_prop/max_kee"))
	{
		owner->add("max_kee",query("armor_prop/max_kee"));
		owner->add("eff_kee",query("armor_prop/max_kee"));
	}

	if (owner->query("kee") > owner->query("eff_kee"))
		owner->set("kee",owner->query("eff_kee"));
	if (owner->query("sen") > owner->query("eff_sen"))
		owner->set("sen",owner->query("eff_sen"));
	if (owner->query("gin") > owner->query("eff_gin"))
		owner->set("gin",owner->query("eff_gin"));

	set("equipped", "worn");
	
	return 1;
}

int wield() {
	object owner, old_weapon;
	mapping weapon_prop, applied_prop, applied_prop_real;
	string *apply/*, type*/;
	int flag, i, a;

	// Only character object can wear armors.
	if(!(owner = environment())->is_character()) {
		return 0;
	}
	
	// If already wielded, just recognize it.
	if(query("equipped")) {
		return 1;
	}
	
	// Check if we have "weapon_prop" defined.
	if(!mapp(weapon_prop = query("weapon_prop"))) {
		return notify_fail("你只能装备可当作武器的东西。\n");
	}
	
	// if both hands has something, then forget about it
	// the rule is also that primary weapon can only be in RIGHT hand
	if(owner->query_temp("left_hand") && owner->query_temp("right_hand")) {
		return notify_fail("你必须至少空出一只手来。\n");
	}
	flag = query("flag");
	if(flag & NO_HANDED) {
		if(!(owner->query_temp("left_hand"))) {
			owner->set_temp("left_hand", this_object());
		} else {
			owner->set_temp("right_hand",this_object());
		}
	} else if (flag & UNARMED_TWO_HANDED) {
		if( owner->query_temp("left_hand") || owner->query_temp("right_hand")) {
			return notify_fail("你必须空出双手才能装备此对武器。\n");
		}
		owner->set_temp("weapon", this_object());
		owner->set_temp("left_hand", this_object());
		owner->set_temp("right_hand", this_object());
	} else if (flag & TWO_HANDED) {
		if( owner->query_temp("left_hand") || owner->query_temp("right_hand")) {
			return notify_fail("你必须空出双手才能装备双手武器。\n");
		}
		owner->set_temp("weapon", this_object());
		owner->set_temp("left_hand", this_object());
		owner->set_temp("right_hand", this_object());
	} else if ( flag & SECONDARY ) {
		if(!(owner->query_temp("right_hand"))) {
			owner->set_temp("right_hand",this_object());
		} else {
			owner->set_temp("left_hand",this_object());
		}
		if(!(owner->query_temp("weapon"))) {
			owner->set_temp("weapon",this_object());
		} else {
			owner->set_temp("secondary_weapon",this_object());
		}
	} else { //  we try to wield a single hand primary weapon
		// both hand empty
		if(!(owner->query_temp("left_hand")) && !(owner->query_temp("right_hand"))) {
			owner->set_temp("right_hand",this_object()); owner->set_temp("weapon",this_object());
		} else {
			if(old_weapon = owner->query_temp("right_hand")) {
				if(!((int)old_weapon->query("flag") & SECONDARY)) {
					return notify_fail("你必须先放下你目前装备的武器。\n");
				}
				// do a switch
				owner->set_temp("left_hand",old_weapon);
				owner->set_temp("secondary_weapon",old_weapon);
				owner->set_temp("right_hand",this_object());
				owner->set_temp("weapon",this_object());
			} else {
				owner->set_temp("right_hand",this_object());
		    	owner->set_temp("weapon",this_object());
			}
		}
	}

	apply = keys(weapon_prop);
		
	applied_prop_real = owner->query_temp("apply_real");
	if(!mapp(applied_prop_real)) {
		applied_prop_real = ([]);
	}
	
	applied_prop = owner->query_temp("apply");
	if(!mapp(applied_prop)) {
		applied_prop = ([]);
	}
			
	for(i = 0; i<sizeof(apply); i++) {
		if(undefinedp(applied_prop_real[apply[i]])) {
			applied_prop_real[apply[i]] = weapon_prop[apply[i]];
			if (member_array(apply[i], att) == -1){
				if (applied_prop[apply[i]])
					applied_prop[apply[i]] += weapon_prop[apply[i]];
				else
					applied_prop[apply[i]] = weapon_prop[apply[i]];
				}
			else{
				if (applied_prop[apply[i]])
					applied_prop[apply[i]] += weapon_prop[apply[i]]/div;
				else
					applied_prop[apply[i]] = weapon_prop[apply[i]]/div;
			}
			
		} else {
			a = applied_prop_real[apply[i]];
			applied_prop_real[apply[i]] += weapon_prop[apply[i]];
//			tell_object(owner,sprintf("i=%d, att=%O\n", i, att)); 
			if (member_array(apply[i], att) == -1)
				applied_prop[apply[i]] += weapon_prop[apply[i]];
			else
				applied_prop[apply[i]] = applied_prop[apply[i]] 
					+ (applied_prop_real[apply[i]]/div - a/div);
		}
	}

	owner->set_temp("apply", applied_prop);
	owner->set_temp("apply_real", applied_prop_real);		
	owner->reset_action();
	set("equipped", "wielded");
	return 1;
}

int unequip() {
	object owner;
	mapping prop, applied_prop, applied_prop_real;
	string *apply, equipped;
	int i, a/*, a1, a2, a3, a4*/;
	
	if(!(owner = environment())->is_character()) {
		return 0;
	}
	
	if(!stringp(equipped = query("equipped"))) {
		return notify_fail("你目前并没有装备这样东西。\n");
	}
	
	if(equipped=="wielded") {
		if((object)owner->query_temp("weapon") == this_object()) {
			owner->delete_temp("weapon");
			if(objectp(owner->query_temp("secondary_weapon"))) {
				owner->set_temp("weapon",(owner->query_temp("secondary_weapon")));
			 	owner->delete_temp("secondary_weapon");
			 }	
		} else if((object)owner->query_temp("secondary_weapon") == this_object()) {
			owner->delete_temp("secondary_weapon");
		}
		prop = query("weapon_prop");
		owner->reset_action();
	} else if(equipped=="worn") {
		owner->delete_temp("armor/" + query("armor_type"));
		prop = query("armor_prop");
	}
    	if((object)owner->query_temp("left_hand") == this_object()) {
    		owner->delete_temp("left_hand");
    	}
    	if ((object)owner->query_temp("right_hand") == this_object()) {
    		owner->delete_temp("right_hand");
	}
	
	apply = keys(prop);
	applied_prop_real = owner->query_temp("apply_real");
	applied_prop = owner->query_temp("apply");
	
/*	tell_object(owner, sprintf("%O\n", applied_prop_real));
	tell_object(owner, sprintf("%O\n", applied_prop));*/
	
	for(i = 0; i<sizeof(apply); i++) {
		a = applied_prop_real[apply[i]];
		applied_prop_real[apply[i]] -= prop[apply[i]];
		if (member_array(apply[i], att) == -1)
			applied_prop[apply[i]] -= prop[apply[i]];
		else	{
			applied_prop[apply[i]] = applied_prop[apply[i]] 
					+ (applied_prop_real[apply[i]]/div - a/div);
		}
	}
	
/*	tell_object(owner, sprintf("%O\n", applied_prop_real));
	tell_object(owner, sprintf("%O\n", applied_prop));*/
	
	owner->set_temp("apply", applied_prop);
	owner->set_temp("apply_real", applied_prop_real);


	if (query("armor_prop/max_gin"))
	{
		owner->add("max_gin",-query("armor_prop/max_gin"));
		owner->add("eff_gin",-query("armor_prop/max_gin"));
	}

	if (query("armor_prop/max_sen"))
	{
		owner->add("max_sen",-query("armor_prop/max_sen"));
		owner->add("eff_sen",-query("armor_prop/max_sen"));
	}

	if (query("armor_prop/max_kee"))
	{
		owner->add("max_kee",-query("armor_prop/max_kee"));
		owner->add("eff_kee",-query("armor_prop/max_kee"));
	}
	
	if (owner->query("eff_kee") < 1)
		owner->set("eff_kee",1);
	if (owner->query("max_kee") < 1)
		owner->set("max_kee",1);

	if (owner->query("eff_sen") < 1)
		owner->set("eff_sen",1);
	if (owner->query("max_sen") < 1)
		owner->set("max_sen",1);

	if (owner->query("eff_gin") < 1)
		owner->set("eff_gin",1);
	if (owner->query("max_gin") < 1)
		owner->set("max_gin",1);

	if (owner->query("kee") > owner->query("eff_kee"))
		owner->set("kee",owner->query("eff_kee"));
	if (owner->query("sen") > owner->query("eff_sen"))
		owner->set("sen",owner->query("eff_sen"));
	if (owner->query("gin") > owner->query("eff_gin"))
		owner->set("gin",owner->query("eff_gin"));

	delete("equipped");
	return 1;
}


int 	selective_message(string msg,object me,object you, string flag) {
	
	string my_gender, my_name, your_name;
	string str1, str3;
	object *exclude= ({});
	int my_flag;
//	int i;
		
	my_name= me->name();
	my_gender = me->query("gender");
	str1 = replace_string(msg,  "$P", gender_self(my_gender));
	str1 = replace_string(str1, "$N", gender_self(my_gender));
	str3 = replace_string(msg,  "$P", my_name);
	str3 = replace_string(str3, "$N", my_name);
	
	your_name= you->name();
	str1 = replace_string(str1, "$n", your_name);
	str3 = replace_string(str3, "$n", your_name);
	
	my_flag = me->query("env/"+flag);

	exclude=filter_array(all_inventory(environment(me)),(: intp($1->query("env/"+$2)) && $1->query("env/"+$2)>1 :),flag);

	exclude += ({me});
	message("vision", str3, environment(me),exclude);
	
	if (my_flag !=1 && my_flag !=3) 
		message("vision", str1, me);
//		else message("vision","\n",me);		
	return 1;

}


// 凝輕·dancing_faery@hotmail.com

