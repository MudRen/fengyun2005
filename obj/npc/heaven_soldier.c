// hell_guard.c

#include <ansi.h>

inherit NPC;

void backattack();
void smart_fight();


void create()
{
	string *order = ({"甲", "乙", "丙", "丁", "戊", "己", "庚", "辛", "壬", "癸"});

	set_name("天" + (order[random(10)]) + "神兵", ({ "heaven soldier", "heavensoldier" }) );
	set("long", "这是一位来自天界的守护神，专门担任护法之责。\n");
	set("attitude", "friendly");
	set("no_fly",1);
	set("no_arrest",1);
	
	set("combat_exp", 100000);
	set("chat_msg_combat", ({
        	 (: smart_fight() :),

	}) );

	set_skill("fork", 90);
	set_skill("parry", 70);
	set_skill("dodge", 50);
	set_skill("move", 70);
	set_skill("notracesnow",70);
	set_skill("sword", 70);
	set_skill("snowshade-sword",70);
	map_skill("sword","snowshade-sword");
	map_skill("dodge","notracesnow");
	map_skill("parry","snowshade-sword");
	setup();

	carry_object(__DIR__"obj/golden_armor")->wear();
	carry_object(__DIR__"obj/golden_sword")->wield();
}



int heal_up()
{
	if( environment() && !is_fighting() && !query("is_leaving")) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	object owner,*pros;
	if (environment())
	message("vision",
		HIY + name() + "说道：末将奉法主召唤，现在已经完成护法任务，就此告辞！\n"
		+ name() + "化成一道金光，冲上天际消失不见了。\n\n" NOR, environment(),		this_object() );
        if(objectp(owner=this_object()->query("possessed")))
        {
                 if (owner->query_temp("max_guard")>0)
                		owner->add_temp("max_guard",-1);
                pros = owner->query_temp("protectors");
			pros -= ({ this_object() });
		owner->set_temp("protectors",pros);
	}                
	
	// Remove all buffs to clean up annied
	ANNIE_D->debuff(this_object(),"all");
	destruct(this_object());
}

void init()
{
        ::init();
        add_action("do_dismiss","dismiss");	
}  

int do_dismiss(string arg)
{
        object who,obj;
        if(!arg) return 0;
        if(!obj=present(arg,environment()))
        	return 0;
        if(obj!=this_object()) return 0;
       
       	who=this_player(); 
                
        if(who!=obj->query("possessed")) 
        	return 0;

		if (obj->is_fighting())
        {
        	tell_object(who,"此召唤兽正在战斗中，无法驱散。\n");	
        	return 1;
        }
        
        if (query("is_leaving")) {
        	tell_object(who,"你已经使用了此法术了。\n");
        	return 1;
        }
        	
        if(who->query("sen")<300)
        {
        	tell_object(who,"此诀耗费需要300点心神。\n");
            return 1;
        }
        who->receive_damage("sen",300);
        message_vision(HIB"$N喃喃念个“疾”字，一缕黑气，细若烟尘，从指端点向$n。\n"NOR,who,obj);
        set("is_leaving",1);
        remove_call_out("leave");
        call_out("leave",1);
        return 1;
} 

void smart_fight()
{
	object me = this_object();
	object who = select_opponent();// annie. 
	int i;

	if (!who)
		return;
	
	if (!ANNIE_D->check_buff(this_object(),"dodgeup"))
		ccommand("perform dodge.mantianfeixue");
	
	if (query("init_shout"))	stop_busy();
		
//	CHANNEL_D->do_sys_channel("sys"," time is "+ time() + " vs " + query_temp("pfm/shout") + "\n");
	
	if (query_temp("pfm/shout")+ 6 > time())	return;
		
	message_vision(HIY"\n$N须发皆张，仰天大笑：天下英雄，舍我其谁！\n\n"NOR,me);
	
	// annie: hate增加约等同于当前普通bolt伤害*80%->random120%的数值。	
	i = me->query_skill("spells");		
	i = 60 + i*i/540 + random(i*i/540); 
	
	set_temp("pfm/shout",time());
	
	if (who)	who->add_hate(me,i);
	
}

void invocation(object who, int level)
{
	int i, bonus_skill, armor;
	object *enemy,*pros;

	int exp = 20000 + level/8*level/2*level/2 *33/20;

	exp = exp/100 * (100 + F_ABILITY->check_ability(who,"tianshi_add"));

	if (exp > who->query("combat_exp"))
		exp = who->query("combat_exp");
			
	set("combat_exp", exp); 
	set("level", F_LEVEL->get_level(query("combat_exp")));

	set("class","taoist");

	set_skill("sword", who->query_skill("sword",1));
	set_skill("parry", who->query_skill("parry",1));
	set_skill("dodge", who->query_skill("dodge",1));
	set_skill("move", who->query_skill("move",1));
	set_skill("spells", who->query_skill("spells",1));
	set_skill("force", who->query_skill("force",1));
	set_skill("unarmed", who->query_skill("unarmed",1));
	set_skill("scratching", who->query_skill("scratching",1));

	set_skill("notracesnow",who->query_skill("notracesnow",1)+1);
	set_skill("snowshade-sword",who->query_skill("snowshade-sword",1)+1);
	set_skill("necromancy",who->query_skill("necromancy",1)+1);
	set_skill("gouyee",who->query_skill("gouyee",1)+1);
	set_skill("tenderzhi",who->query_skill("tenderzhi",1)+1);
	set_skill("scratmancy",who->query_skill("scratmancy",1)+1);

	map_skill("dodge","notracesnow");
	map_skill("move","notracesnow");
	map_skill("spells","necromancy");
	map_skill("force","gouyee");
	map_skill("unarmed","tenderzhi");
	map_skill("parry","snowshade-sword");
	map_skill("sword","snowshade-sword");
	map_skill("scratching","scratmancy");

	set("chat_chance_combat",level/6+random(level/6));
//	set("chat_chance_combat",100);
	
	"/feature/nada"->reset_npc(this_object());

	set("max_kee",who->query("max_kee")*12/10);
	set("max_gin",who->query("max_gin")*12/10);
	set("max_sen",who->query("max_sen")*12/10);
	set("force_factor",0);
	set("str",level/10);
	set("kar", who->query("kar"));
	set("cps", who->query("cps"));
	set("int", who->query("int"));
	set("agi", who->query("agi"));
	
	armor = query("level");
	if (armor > 60) armor = 60;		
	set_temp("apply/armor", armor);
	
	if (who->query_skill("taoism",1)>200) 
		add("resistance/kee", (who->query_skill("taoism",1)-200)/2);
		
	full_me();	
	
	pros = who->query_temp("protectors");
	if(sizeof(pros))
		pros += ({ this_object() });
	else
		pros = ({ this_object() });
	who->set_temp("protectors",pros);
	
	message("vision",
		HIY "\n一道金光由天而降，金光中走出一个身穿金色战袍的将官。\n"
		+ name() + "说道：末将奉法主召唤，特来护法！\n\n" NOR,
		environment(who), this_object() );
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else {
				enemy[i]->kill_ob(this_object());
				enemy[i]->kill_ob(who);
			}	
		}
	}
	set_leader(who);
	set("possessed",who);

	reset_action();
}


void unconcious() {
	die();
}

void die()
{
	object *pros,owner,*enemy;
	int i;
        if(objectp(owner=this_object()->query("possessed")))
        {
        	if (owner->query_temp("max_guard")>0)
                	owner->add_temp("max_guard",-1);
            pros = owner->query_temp("protectors");
			pros -= ({ this_object() });
			owner->set_temp("protectors",pros);
	
			// backfire a little bit hate to prevent chain pets.
			enemy = query_enemy();
			if (enemy && sizeof(enemy)>0){
				for (i=0;i<sizeof(enemy);i++){
					if (!userp(enemy[i]))
						enemy[i]->add_hate(owner,enemy[i]->query_hate(this_object()));
				}
			}
	}                
        message_vision("\n$N惨叫一声，化作一道金光消失了。\n\n", this_object());
	destruct(this_object());
}



void heart_beat()
{
	object leader;
	
	::heart_beat();
	
	if(!this_object()) {		// heart_beat can destruct object() through die().
		return;
	}
	
	if(query_temp("is_unconcious")||is_busy())
		return;

	if(objectp(query("possessed")))
	{
		leader = query("possessed");
		if (environment(leader)!= environment() && !leader->is_ghost() )
		{
			message_vision("$N匆匆离去。\n",this_object());
			this_object()->move(environment(leader));
			message_vision("$N走了过来。\n",this_object());
			delete("leave_room");
		}
	}
	
	else
	{
		if(!query("leave_room"))
			set("leave_room",1);
		else
			add("leave_room",1);
		if(query("leave_room")==5)
			leave();
	}
}



/*

　　　     /＼              ／\      
　　　   ▕   ＼＿＿　　　／  ︱       
　　　   ▕ ／￣    ◥██◤╲︱       
　　　    ∕                  ﹨       
　　　    ︳   /￣\    /￣\   ▕      
　　　    ︳   ︳●    ●  ︳ ▕       
　　　   ┼    \ /    \　/    ┼      
　　　    ﹨　      ●      　∕         
　　　    ˉ╲　    　   　／ˉ         
　　　    ╭─◤ˉˉˉ￣◥◤﹨           
　　　   （   ︳           /﹀﹀\◢█    
　　　  （____︳  ▕ ／  ▕ .. █◤     
　　　        \︿︿/ ︺︺︺＼●／         
                       ˉ             
　　　　　　　　- FengYun - 　　　
 　　　　　　　annie 06.2005
 　　　　dancing_faery@hotmail.com

*/
