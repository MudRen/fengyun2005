// hell_guard.c

#include <ansi.h>

inherit NPC;

void backattack();
void smart_fight();

void create()
{
	string *order = ({BLU"黑",HIW"白"});

	set_name((order[random(2)]) + "无常"NOR, ({ "sanqing devil" }) );
	set("long", "来自冥界、受召而来的黑白无常。\n");
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
	set_skill("hunting-fork",70);
	set_skill("notracesnow",70);
	map_skill("dodge","notracesnow");
	map_skill("fork","hunting-fork");
	map_skill("parry","hunting-fork");
	setup();

	carry_object(__DIR__"obj/golden_armor",
    		([	"name"	:	HIR BLK"灰白衣装"NOR,
			"id":"cloth",
    			"value"	:	0,
				"long"	: "",
			"armor_prop/armor"	: 20, ])
    		)->wear();

/*	carry_object(__DIR__"obj/golden_sword",
			([	"name"	:	HIR BLK"无常铁锁"NOR,
				"id"	: "wuchang hammer",
				"long"	: "",
    				"value"	:	0,	])
		)->wield();*/
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
		HIY + name() + "化作一道紫烟消失了。\n\n" NOR, environment(),		this_object() );
        if(objectp(owner=this_object()->query("possessed")))
        {
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

mixed hit_ob(object me, object victim, int damage_bonus)
{
	me->receive_fulling("kee", damage_bonus, me);
   	return name()+BLU"嘎嘎怪笑，"+victim->name()+"只觉得浑身精力迅速流失．．．\n"NOR;
}

void smart_fight()
{
	object me = this_object();
	object who = select_opponent();// annie. 
	int i,type,duration,amount,lvl;
	string typ,msg;
	mapping buff;

	if (!who)
		return;
	if (ANNIE_D->check_buff(who,"lockup"))
		return;

	duration = me->query("timer/pfm/sq_no_pfm")-time()+ 30;
	if (duration<=0)
	{
		lvl = me->query_skill("necromancy",1);
		me->add_temp("apply/spells",lvl);

		msg = HIW "\n$N"HIW"一声怪啸，向$n两爪虚张，眼中精光大盛，喝咤道：缴你魂来！\n" NOR;
		message_vision(msg, me, who);

		if ( COMBAT_D->do_magic_attack( me, who, "spells", "sen", 100) 
			&& !who->query("boss") && !who->query("big_boss") ) 
		{
			buff =
			([
				"caster":me,
				"who":	 who,
				"type": "lockup",
				"att":  "curse",
				"name": "冥式轮回",
				"time":  8,
				"buff1": "till_death/lockup",
				"buff1_c": 1,
				"buff_msg": HIB"$N"HIB"一惊之下与$n"HIB"眼光对上，登时三魂出了七窍，茫然不知所措。\n\n"NOR,
				"warn_msg":"",
				"disa_msg": WHT"$N"WHT"心神渐凝，不由得出了一身冷汗。\n"NOR,
				"disa_type": 1, 
			]);
			ANNIE_D->buffup(buff);

		}
		else
		{
			msg = HIC "$n"HIC"凝定心神，不为之动。\n\n" NOR;
			message_vision(msg, me, who);
		}

		me->add_temp("apply/spells",-lvl);
		me->set("timer/pfm/sq_no_pfm", time());
		perform_busy(2);
	}

	return;
}

void invocation(object who, int level)
{
	int i, bonus_skill;
	object *enemy,*pros;

	int exp = 20000 + level/8*level/2*level/2 *33/20;

	if (exp > who->query("combat_exp"))
		exp = who->query("combat_exp");
		
	exp = exp/100 * (100 + F_ABILITY->check_ability(who,"jisi_add"));

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

	set_skill("notracesnow",who->query_skill("notracesnow",1));
	set_skill("snowshade-sword",who->query_skill("snowshade-sword",1));
	set_skill("necromancy",who->query_skill("necromancy",1));
	set_skill("gouyee",who->query_skill("gouyee",1));
	set_skill("tenderzhi",who->query_skill("tenderzhi",1));
	set_skill("scratmancy",who->query_skill("scratmancy",1));

	map_skill("dodge","notracesnow");
	map_skill("move","notracesnow");
	map_skill("spells","necromancy");
	map_skill("force","gouyee");
	map_skill("unarmed","tenderzhi");
	map_skill("parry","snowshade-sword");
	map_skill("sword","snowshade-sword");
	map_skill("scratching","scratmancy");

	set("chat_chance_combat",level/5+random(level/5));

	"/feature/nada"->reset_npc(this_object());
	set("max_kee",who->query("max_kee")*8/10);
	set("max_gin",who->query("max_gin")*8/10);
	set("max_sen",who->query("max_sen")*8/10);
	
	set("force_factor",0);
	set("str", 70);		// for now, maybe change later.
	
	full_me();

	if (who->query_skill("taoism",1)>200) 
		add("resistance/kee", (who->query_skill("taoism",1)-200)/2);

	pros = who->query_temp("protectors");
	if(sizeof(pros))
		pros += ({ this_object() });
	else
		pros = ({ this_object() });
	who->set_temp("protectors",pros);
	
	if (environment() && environment(who))
		message("vision",
			CYN "\n只听闻嗟嗟嗟几声怪笑，一阵阴风席过，有道人影凭空浮现．．．\n\n" NOR,
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
        message_vision("\n$N化作一道紫烟消失了。\n\n", this_object());
	destruct(this_object());
}



void heart_beat()
{
	object leader;
	
	::heart_beat();
	
	if (!this_object())	return;
		
	if(query_temp("is_unconcious")||is_busy())
		return ;
	if(objectp(query("possessed")))
	{
		leader=query("possessed");
		if(objectp(leader) && environment(leader)!=environment()&&(!leader->is_ghost()))
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
