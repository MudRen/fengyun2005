// questnpc.c
// by mimicat for QUEST_NPC
#include <ansi.h>

inherit NPC;
int do_flee();
string stt, per;
int alert,flee;
int mgin,mkee,msen;
int gin,kee,sen;
void hunting(object room);
void do_fight();

void heart_beat() {
	int wimpy_ratio, to_wimpy, cnd_flag;
	mapping my;
	object ob;
	string savemyass;
	object *enemy;
	if(!this_object()) {
		return;
	}

	if (query_temp("in_heart_beat"))
		return;


	my = query_entire_dbase();
	
	// If we are dying because of mortal wounds?
	if( my["eff_kee"] < 0 || my["eff_sen"] < 0 || my["eff_gin"] < 0  
			|| my["kee"] < -10 * my["dur"]  || my["sen"] < -10 * my["dur"] || my["gin"] < -10 * my["dur"]) {
		remove_all_enemy();
		die();
		return;
	}
	
	// If we are unconcious, just return;
	if(query_temp("is_unconcious"))  {
		return;
	}
	
	// If we're dying or falling unconcious?
	if( my["kee"] < 0 || my["sen"] < 0 || my["gin"] < 0) {
		remove_all_enemy();
		unconcious();
		return;
	}

	
	// chat() may do anything -- include destruct(this_object())
	// objectp check is added for some strange this_object() return 0 reason.
	if(objectp(this_object()) ) {
		this_object()->chat();
		if(!this_object()) {
			return;
 		}
	}


	// If busy, continue action and return here.
	if(is_busy()) {
		continue_action();
		return;
	}


	
	if(tick--) {
		return;
	} else {
		tick = 5 + random(10);
	}
	
	cnd_flag = update_condition();
	if (!living(this_object())) return;
	// If we are compeletely in peace, turn off heart beat.
	// heal_up() must be called prior to other two to make sure it is called
	// because the && operator is lazy :P

	if(!this_object()) return;
	if(!interactive(this_object())) return;
	

}

	
void setup()
{
	::setup();
	set("reward_npc",1);
	alert=query("alert_rate")?query("alert_rate"):70;
	flee=query("flee_rate")?query("flee_rate"):50;
	stt=stringp(query("strategy"))?query("strategy"):"default";
	per=stringp(query("personality"))?query("personality"):"normal";
	set_skill("iron-cloth",250);
	set_skill("jin-gang",250);
	if(!query_skill_mapped("iron-cloth"))
		map_skill("iron-cloth","jin-gang");
	add("combat_exp",random(3000000));
	set_skill("move",400+random(400));
	map_skill("move",0);
}
	

void reset_npc()
{
	// npc improve exp and skill automation
	int exp;
	mapping skl;
	string *sname,skill;
	exp=query("combat_exp");
	if(exp<99999999)
		add("combat_exp",exp/100);
	skl = query_skills();
	if(random(3)) return;
	if( !mapp(skl) ) return;
	sname=keys(skl);
	skill=sname[random(sizeof(sname))];
	set_skill(skill,skl[skill]+1);
}

// This is the chat function dispatcher. If you use function type chat
// message, you can either define your own functions or use the default
// ones.
int chat()
{
	string *msg;
	int chance, rnd;
	string new_room;
	object room,old_room;

	if( !environment() ) return 0;
	if( query_temp("is_unconcious") ) return 0;



	
	if(!this_object()->is_fighting() )
	{
		if(random(100)>90) heal_up();
		if(environment()->query_doors())
			command("open door");
		if (random(100)>50)
		{
			if (random(100)>95|| !this_object()->random_move())
			{
				old_room=environment(this_object());
				new_room=TASK_D->random_room();
				if(!room=find_object(new_room))
					room=load_object(new_room);
				this_object()->move(room);
				tell_room(old_room,this_object()->query("name")+"长啸一声，纵身而去。\n");
				tell_room(room,"人影一闪，"+this_object()->query("name")+"出现在你面前。\n");
			} ;
		}
 	 }
 	 else
 	 	do_fight();
	if( !chance = query("chat_chance") )
		return 0;

	if( arrayp(msg = query("chat_msg"))) {
		if( random(100) < chance ) {
			rnd = random(sizeof(msg));
			if( stringp(msg[rnd]) )
				say(msg[rnd]);
			else if( functionp(msg[rnd]) )
				return evaluate(msg[rnd]);
		}
		return 1;
	}
}

int random_move()
{
	mapping exits;
	string *dirs, direction, dest, last_room;
	object env;
	int i;
	
	if( !mapp(exits = environment()->query("exits")) ) return 0;
	last_room = query("last_room");
	
	dirs = keys (exits);
	if(!sizeof(dirs)) return 0;
	dest = last_room;
	i=0;
	while(dest==last_room&&i<20)
	{
		direction = dirs[random(sizeof(dirs))];
		dest = environment()->query("exits/"+direction);
		i++;
	}
//	if(i==5)
//		return 0;
	set("last_room",file_name(environment()));			
	command("go " + direction);

	return 1;
}


int die_action()
{
	return 0;
}
void die()
{
	object objReward;
	object killer,owner;
	
	if(die_action())
		return;
	if (this_object()->query_temp("last_damage_from")) 
	{
			killer = this_object()->query_temp("last_damage_from");
            if(owner=killer->query("possessed"))    killer = owner;
	}
	switch (query("quality"))
	{
		case "evil":
			
			objReward = new("/questnpc/obj/dragon-card");		
			break;
		case "good":
			objReward = new("/questnpc/obj/shanliu-scroll");
			//objReward ->set("name",query("name")+"的"+objReward->query("name"));
			//objReward ->set("dynamic_quest",query("dynamic_quest"));
			//objReward->move(this_object());
			break;
	}
	if (objectp(objReward))
	{
			objReward ->set("name",query("name")+"的"+objReward->query("name"));
			objReward ->set("dynamic_quest",query("dynamic_quest"));
			objReward ->set("killer",killer);
			objReward->move(this_object());
	}
	::die();
}

object victim_target()
{
	int n,i;
	object *all_enm,enm;
	
	all_enm=query_enemy();
	n=sizeof(all_enm);
	if(!n) return ;
	enm=all_enm[random(n)];
	if(stt=="default"||"brave");
		return  enm;
	if(stt=="hero")
		for(i=0;i<n;i++)
			enm=enm->query("combat_exp")>all_enm[i]->query("combat_exp")?enm:all_enm[i];
	if(stt=="conservative")
		for(i=0;i<n;i++)
			enm=enm->query("combat_exp")<all_enm[i]->query("combat_exp")?enm:all_enm[i];
	return enm;
}
	
int enemy_value(object *all_enm)
{
	int i,val,exp;
	
	val=0;
	exp=query("combat_exp");
	for(i=0;i<sizeof(all_enm);i++)
	{
		if(all_enm[i]->query("combat_exp")<exp*2/3)
			val+=1;
		else if(all_enm[i]->query("combat_exp")<exp)
			val+=3;
		else if(all_enm[i]->query("combat_exp")<exp*2)
			val+=6;
		else val+=10;
	}
	return val;
}
int universe_busy(object *all_enm)
{return 0;}
int normal_busy(object opp)
{return 0;}
int normal_att(object opp)
{return 0;}
int alert_busy(object opp)
{return 0;}
int alert_att(object opp)
{return 0;}
int flee_busy(object opp)
{return 0;}
int flee_att(object opp)
{return 0;}

int avoid_busy()
{

	
	if(!query_busy())
		return 1;
	if(random(100)>80) return 0;	

	message_vision(HIY"$N冷笑道：“这等雕虫小技，却也难我不倒。”\n"NOR,this_object());
	if(query_busy()>1)
	{
		start_busy(1);
		 return 0;
	}

	stop_busy();
	return 1;
	
}
int normal_attack()
{
	object opp, *all_enm;
	int i;
	string perf;
	
//	if(random(100)>50) return 0;
	if(query_busy()) return 0;
	all_enm=query_enemy();
	opp=victim_target();
	if(random(100)>50)
		universe_busy(all_enm);
	if(!query_busy())
	{
		if(!opp->query_busy())
			normal_busy(opp);
		if(!query_busy())
			normal_att(opp);
	}
	return 1;
}

int alert_attack()
{	
	object opp, *all_enm;
	int i;
	string perf;
	if(query_busy()) return 0;
	//	if(random(100)>50) return 0;
	all_enm=query_enemy();
	opp=victim_target();
	if(random(100)>20)
		universe_busy(all_enm);
	if(!query_busy())
	{
		if(!opp->query_busy())
			alert_busy(opp);
		if(!query_busy())
			alert_att(opp);
	}
	return 1;
}

int flee_attack()
{
	object opp, *all_enm;
	int i;
	string perf;
	if(query_busy()) return 0;	
//	if(random(100)>50) return 0;
	all_enm=query_enemy();
	opp=victim_target();
	if(random(100)>60)
		avoid_busy();
	universe_busy(all_enm);
	if(!query_busy())
	{
		if(!opp->query_busy())
			flee_busy(opp);
		if(!query_busy())
			flee_att(opp);
	}
	return 1;
}

int fetch_weapon(string wtype)
{
	object weapon, *all_enm;
	string wtype1;
	int i;
	
	if(random(100)<30) return 0;
	all_enm=query_enemy();
	if(!sizeof(all_enm)) return 0;
	for(i=0;i<sizeof(all_enm);i++)
	{
		if(!weapon=all_enm[i]->query_temp("weapon"))
			continue;
		if(wtype!=weapon->query("skill_type"))
			continue;
		message_vision(HIG"$n只觉手腕一麻，手中兵刃竟已被$N抄去！！\n"NOR,this_object(),all_enm[i]);
		weapon->move(this_object());
		weapon->wield();
		break;
	}
	return 1;
}

/*		
	if(stringp(perf=query_perform("universe_busy")))
		for(i=0;i<sizeof(all_enm);i++)
		{
			add("busy_object/"+all_enm[i]->query("id"),1);
			command("perform"+perf+" "+all_enm[i]->query("id")+" "+(string)query("busy_object/"+all_enm[i]->query("id")));
		}
	if(query_busy())
		return 1;
	else
	if(stringp(perf=query_perform("
	
	
*/

void go_fight(string type)
{
	object opp;
	int n,p;
	string wtype;
	

	n=sizeof(query_enemy());
	p=enemy_value(query_enemy());
	say(type+"\n");
	if(!query_temp("weapon")&&wtype=query("w_type"))
		fetch_weapon(wtype);
	switch(stt)
	{
		case "hero":
			switch(type)
			{
				case "normal":
					normal_attack();
					break;
				case "alert":
					avoid_busy();
					alert_attack();
					break;
				case "flee":
					avoid_busy();
					flee_attack();	
					break;
			}
							
			break;
					
				
		case "brave":
			switch(type)
			{
				case "normal":
					normal_attack();
					break;
				case "alert":
					alert_attack();
					avoid_busy();
					break;
				case "flee":
					flee_attack();	
					avoid_busy();
					do_flee();
					break;	
			}
			break;
			
		case "default":
			switch(type)
			{
				case "normal":
					if(p>10||n>4)
					{
						alert_attack();
						avoid_busy();
						do_flee();
					
					}
					else
						normal_attack();
					break;
				case "alert":
					if(p>6||n>3)
					{
						flee_attack();
						avoid_busy();
						do_flee();
					}
					else
						alert_attack();
					break;
				case "flee":
					case "flee":
					flee_attack();	
					avoid_busy();
					do_flee();
					break;	
			}						
			break;
		
		case "conservative":
			switch(type)
			{
				case "normal":
					if(p>6||n>3)
					{
						alert_attack();
						avoid_busy();
						do_flee();
					}
					else
						normal_attack();
					break;
				case "alert":
					if(p>3||n>1)
					{
						flee_attack();
						avoid_busy();
						do_flee();
					}
					else
						alert_attack();
					break;
				case "flee":
					case "flee":
					flee_attack();	
					avoid_busy();
					do_flee();
					break;	
			}						
			break;					
	}	
}		

void do_fight()
{
	mgin=query("max_gin");
	mkee=query("max_kee");
	msen=query("max_sen");
	gin=query("gin");
	kee=query("kee");
	sen=query("sen");	

	say("do_fight\n");
	if(gin<mgin*flee/100||kee<mkee*flee/100||sen<msen*flee/100)
		go_fight("flee");
	else
	if(gin<mgin*alert/100||kee<mkee*alert/100||sen<msen*alert/100)
		go_fight("alert");
	else
		go_fight("normal");
	// Do attack or clean up enemy if we have fleed.
	if(is_fighting())
		attack();


}
		




int do_flee()
{
	int i,j;
		

	j=3+random(5);
	for(i=0;i<j;i++)
		random_move();
	return !is_fighting();
	
}

void init()
{
    object room;

	::init();    
    if(!query("hunting"))
     	return 0;
     if(find_call_out("hunting")>0) return 0;
    if(!room=environment()) return 0;
	if(!room->query("no_fight"))
       call_out("hunting",1,environment());
}
/*
void hunting(object ob)
{

	//if (!interactive(ob = this_player())) return;

    if( ob->is_character() && living(ob) && !userp(ob) && !ob->query("quality"))
	CHANNEL_D->do_sys_channel("sys","I am killing "+ob->name());
	{
		kill_ob(ob);
		ob->kill_ob(this_object());
	}
}
*/



void hunting(object room)
{
	int i;
	object *ob;
	if(room!=environment()) return ;
	ob=all_inventory(room);
        for(i=sizeof(ob)-1; i>=0; i--) {
                if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])||userp(ob[i])||(ob[i]->query("quality")&&ob[i]->query("quality")==query("quality"))
                ||ob[i]->query_str()>300) continue;
                kill_ob(ob[i]);
                ob[i]->kill_ob(this_object());
        }
}

int kill_ob(object enemy)
{
	::kill_ob(enemy);
	if(!query_busy())
		do_fight();
}