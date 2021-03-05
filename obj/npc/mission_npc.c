#include <ansi.h>

inherit SMART_NPC;
int randommove();
int do_exp(string arg);
int holiday_bonus = 200;   
void give_reward(object who,object accomplisher);
#include <names.h>


void create()
{
	object ob;
	mapping qname;
	string name;
	int k;
	string *id;
	k=random(2)-1;
	qname=(NAMES_D->random_name(k, 0, 0, 0, 0));
	name = qname["name"];
      id= qname["id"];
      set("no_fly",1);
	set_name(name,id);
      set("gender", "男性" ); 
	   if (k ==0){
	set("gender", "女性" ); 
	       } 
	set("str",40);
        
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(:auto_smart_fight(80):),
	}) );
	set("attitude", "aggressive");
	//set("real_boss",1);
        set("boss",1);
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

int query_holiday(){
	return holiday_bonus;	 
}

int invocation(int exp)
{
	mapping list, tlist;
	mixed *klist, *tlist2;
	string text, *tmp;
	int loop,k;
	string tmp1, tmp2;
	int flag, best_basic_skill=1, best_adv_skill=1;
	mapping skl, map;

	object ob;


	if( !exp ) {
		exp = 10000000;
	}
	set("combat_exp",exp);
//	set("tasker",1);
         k=random(sizeof(nickn));     
        if( exp > 6100000 ) {
		set("title",HIR"魔教"+nickn[k]+ ""NOR);
	} else {
		set("title",HIR""+nickn[k]+""NOR);
	}
	auto_npc_setup("bandit",300,220,1,"/obj/weapon/","random","random",5);

	set("chat_chance", 100);
 set("chat_msg_combat", ({
	     (: auto_smart_fight(70) :),
     }) );
	do_exp(query("combat_exp")+"");
	set("long", "一个黑衣人，忙忙碌碌地在赶路。\n");
	ob = carry_object("/obj/money/gold");
	ob->set_amount(3+random(3));
	return 1;
}


object select_opponent() 	
{
	object * enemy;
	int i;
	enemy = query_enemy();
	if(!sizeof(enemy)) {
		return 0;
	}
	clean_up_enemy();
	if(!sizeof(enemy)) {
		return 0;
	}
	for(i=0; i<sizeof(enemy); i++)
		if (userp(enemy[i]))
			return enemy[i]; // focus user. ; annie 6.25.03
	return enemy[random(sizeof(enemy))];
}

int random_move()
{
	mapping exits;
	string *dirs, direction, dest, last_room;
	object env;
	int i;

	if( !mapp(exits = environment()->query("exits")) ) {
		return 0;
	}
	last_room = query("last_room");
	dirs = keys (exits);
	if( !sizeof(dirs) ) {
		return 0;
	}
	dest = last_room;
	i = 0;
	while( dest==last_room && i < 20 ) {
		direction = dirs[random(sizeof(dirs))];
		dest = environment()->query("exits/"+direction);
		i++;
	}
	set("last_room",file_name(environment()));
	command("go " + direction);
	return 1;
}


int do_exp(string arg)
{
	// exp calc inherited from my in ^^
	int exp;
	int pow_exp;
	int loop;
	int a_skill, b_skill;
	mapping skl, map;
	string *sname, *mapped;
	int flag, enforce, best_force = 1;

	if( !arg ) {
		return notify_fail("[Usage]: Exp <NPC-EXP>\n");
	}
	exp = atoi(arg);
	set("combat_exp",exp);
	b_skill = 250;
	pow_exp = to_int(pow(to_float(exp*10),0.3334));
	skl = query_skills();
	if( sizeof(skl) ) {
		// 设置skills
		sname  = sort_array( keys(skl), (: strcmp :) );
		map = query_skill_map();
		if( mapp(map) ) {
			mapped = values(map);
		}
		if( !mapped ) {
			mapped = ({});
		}
		for( loop = 0; loop < sizeof(skl); loop++) {
			if( sname[loop] == "xuezhan-spear") {
				a_skill = 250;
			} else {
				a_skill = 200;
			}
			// Basic skill : cap @ 300 | 按系数1.6计算.
			if( SKILL_D(sname[loop])->effective_level() == 50 ) {
				set_skill(sname[loop], b_skill > pow_exp*100/160 ? pow_exp*100/160 : b_skill);
			}
			// Advance skill : cap @ 200.
			if( SKILL_D(sname[loop])->effective_level() != 50 ) {
				set_skill(sname[loop],a_skill > pow_exp*100/SKILL_D(sname[loop])->effective_level() ? pow_exp*100/SKILL_D(sname[loop])->effective_level() : a_skill);
			}
			if( SKILL_D(sname[loop])->valid_enable("force") ) {
				if( SKILL_D(sname[loop])->effective_level() * skl[sname[loop]] > best_force ) {
					best_force = skl[sname[loop]];
				}
			}
		}
	}
	"/feature/nada.c"->reset_npc(this_object());
	
	full_me();
	message_vision("\n",this_object());
	return 1;
}

int self_destruct()
{
	if( is_fighting() || is_busy() ) {
		call_out("self_destruct", 30);
		message_vision(CYN"$N叹道：晚了、晚了，居然被屑小之辈误了我的大事！"NOR, this_object());
		return 1;
	}
	message_vision(WHT"$N叹了口气，纵身一跃，转瞬间消失的无踪无影。\n"NOR, this_object());
	destruct(this_object());
	return 1;
}

void init()
{
	object tasker, player;
	object room;
	int tasker_exp, player_exp;
	int taker_level, player_level;
	int chance;
	int tasks;


      

	tasker = this_object();
        if(tasker->query("marks/time")+1800<time()){
       
       
        self_destruct();
        }

        
	if( !tasker ) {
		return;
	}
	player = this_player();
	if( !player ) {
		return;
	}
	room = environment(tasker);
	if( !room ) {
		return;
	}
	if( room->query("no_fight") || room->query("no_magic") ) {
		return;
	}
	if( interactive(player) && !is_fighting() ) {
		
          if( player->query("marks/mission/name")==tasker->query("name")){				
	
			remove_call_out("greeting");
			call_out("greeting", 1, player);
		  
}

		
   }

	return;


}





void greeting(object player)
{
	if( !interactive(player) || environment(player) != environment() ) {
		return;
	}
if(	player->query("marks/mission/name")==this_object()->query("name")){
	message_vision("
$N嘿嘿道：够胆量！居然敢追到这里来了，拿命来吧！\n", this_object());
	this_object()->kill_ob(player);
	player->kill_ob(this_object());
}
}

void die()
{
	object who, owner;
      int r,team_size,i;
      object* mem;
	
	
	if(objectp(who = query_temp("last_damage_from")))
    {
    	if ( objectp(owner = killer->query("possessed")))
    		    		
    		who = owner;

        mem = pointerp(who->query_team()) ? who->query_team() : ({ who });
	team_size = sizeof(mem);
        if( team_size ) {
		for( i = 0; i < team_size; i++ ) {
              mem[i]->delete("marks/mission/time"); 
              mem[i]->delete("marks/mission/name"); 
			}

              }
     
	if (objectp(who))
	{
		// random drop code..
		ANNIE_D->generate_drop_item(this_object(),who);
         }

	
    		r=random(10);
    		give_reward(who,who);
            if(r<1) {
			message_vision(CYN"
$n呕出口血，脸色比胜雪的长袍还要苍白，惨然一笑道： 
跑了这么远还是没躲过六扇门的追杀，难道真是该有此命？我不甘啊！"WHT"

$n怒喝一声，脸上顿时光芒大盛，拼死向$N击去。。。 

说时迟那是快！ "HIR"


$N竭尽全力躲闪，终还是没躲过。\n\n"NOR,who,this_object());
			who->set("kee",1);
			COMBAT_D->report_status(who);
			who->unconcious();
		
                     }
	}
	
	::die();
	return;

}


int kill_ob(object who)
{
     object player,victim;
      string name,sn;
   player=this_object();
      
  name= who->query("marks/mission/name");
    if(objectp(who->query("possessed"))){ 
     victim=who->query("possessed");
     
     name= victim->query("marks/mission/name");
   }
    
    
   if(name!=player->query("name")){
  message_vision(CYN"$N叹道：你我无冤无仇何苦性命相搏呢！\n"NOR,this_object());
  
  player->remove_all_enemy();
  who->remove_all_enemy();

  return 1;
   }
   	stop_busy();
   message_vision(CYN"$N道：躲得了初一躲不过十五，老子和你们拼了！\n"NOR,this_object());
   	::kill_ob(who);
 return 1;


}





void give_reward(object who, object accomplisher) 
{
	int team_size, i, level, base, d_bonus, team_bonus, combat_exp, silver, money, q_bonus, half;
	int h_bonus;
	string reward_msg;
	object ob;
	object* mem;
    half=1;
	mem = pointerp(who->query_team()) ? who->query_team() : ({ who });
	team_size = sizeof(mem);


	// special quest的exp_bonus按照拿Ｑｕｅｓｔ的那个人经验值计算

		q_bonus = who->query("combat_exp")/1000;


	// reward money
	if( q_bonus > 3000 ) {
		money = 20+random(30);
	}else if( q_bonus > 1000 ) {
		money = 15+random(25);
	}else if( q_bonus > 100 ) {
		money = 10+random(20);
	}else {
		money = 5+random(10);
	}

	if( team_size ) {
		for( i = 0; i < team_size; i++ ) {
			// 注意，这里用的是F_LEVEL, 直接 query("level")得到的是曾经达到的最高lvl
			level = F_LEVEL->get_level(mem[i]->query("combat_exp"));
			base = REWARD_D->quest_reward(level);

// DEBUG LINE
#ifdef NONENCRYPTED_WRITE
	if( who->query("wiz_qreward") ) {
		base = base*who->query("wiz_qreward");
	}
#endif
// DEBUG LINE END
		
				d_bonus =  who->query("combat_exp")/1000000;
		
			team_bonus = (team_size-1)*5;
			// 最终奖励经验值。 REWARD CAPPED at 10M, 多余的进入ability或者只用来增加pot
			combat_exp = base*(100+d_bonus+team_bonus)/100/team_size;

			// Holiday rewards, 50=*0.5, 100 = *2, 200= *3 
			combat_exp = combat_exp*(100+query_holiday())/100;

		
		

			if( mem[i]->query("env/ability" ) 
				&& F_LEVEL->get_level(mem[i]->query("combat_exp"))>=80
				&& mem[i]->query("saved_quest")/60/100 < mem[i]->query("learned_ability")+6 ) {
				mem[i]->add("saved_quest", 60/team_size/half);
				if( query_holiday() )
					mem[i]->add("saved_quest", 60/team_size/half*query_holiday()/100);
			} else {
				if( mem[i]->query("combat_exp") >= 10000000 ) {
					mem[i]->add("extra_exp", combat_exp);
				}
				if( mem[i]->query("combat_exp") < 10000000 ) {
					mem[i]->add("combat_exp", combat_exp);
				}
				if( mem[i]->query("combat_exp") >= 10000000 ) {
					mem[i]->set("combat_exp",10000000);
				}
			}
			silver = money*(100+d_bonus+team_bonus)/100/team_size;
		

			// Holiday rewards, 50=*0.5, 100=*2, 200=*3
			silver = silver*(100+query_holiday())/100;
			// low level 25% extra silver bonus
			if( level < 50 ) {
				silver = silver*150/100;
			}

			// 直接入帐．
			mem[i]->add("deposit", silver*100);
			mem[i] -> delete("cont_quest");
                     
 

			if( mem[i] != accomplisher) {
				if( mem[i] == who ) {
					reward_msg =YEL"你的任务被"+accomplisher->name()+"完成，你的经验值提高了" + "，奖励" + chinese_number(silver) + "两银子。\n\n" + NOR;
				} else {
					reward_msg =YEL+ who->name()+"的任务被"+accomplisher->name()+"完成，你的经验值提高了" + "，奖励" + chinese_number(silver) + "两银子。\n\n" + NOR;
				}
			} else {
				reward_msg = (accomplisher==who) ? WHT : WHT+"队友 "+who->name()+" 的";
				reward_msg +="任务被你完成，你的经验值提高了，奖励" +chinese_number(silver) + "两银子。\n" + NOR;
				if (random(100)>85)  //add by ldb 增加额外奖励，为了平衡队伍中经验少的ID。否则永远追不上来。
				{
                 ob=new("/obj/wiz_toy/baoxiang1");
                 ob->move(accomplisher);
          		 tell_object(mem[i],HIY"由于你的勤恳努力，特奖励任务宝箱一个！\n");
				}
			}
			tell_object(mem[i],reward_msg);
	
		}
	}

	who->set("quest", 0); // Quest清零
	if( who->query("cont_mission") < 20 ) {
		who->add("cont_mission",1);
	}
    if( who->query("cont_mission") == 20 ) {
		who->set("cont_mission",1);
	}
	accomplisher->add("finish_mission", 1);
	return;
}





















