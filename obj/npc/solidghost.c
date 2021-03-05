#include <ansi.h>
inherit NPC;
int mimicurse();

void create()
{

        set_name("的亡灵", ({ "spirit"}) );
        set("long", "这是一个借尸还魂的亡灵，双眼茫然无神地注视着前方。\n");
        set("attitude", "friendly");
        set("title",BLU"借尸还魂"NOR);
        set("class","yinshi");
        set("max_atman", 100);
        set("atman", 100);
        set("max_mana", 100);
        set("mana", 100);
        set_temp("apply/astral_vision", 1);
        set("no_arrest",1);
        set("no_fly",1);
        set("combat_exp", 100000);
        set_skill("cursism",100);
        set_skill("celecurse",100);
        map_skill("cursism","celecurse");
        setup();

        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: mimicurse() :),
        }) );

        carry_object("/obj/armor/ghost_cloth")->wear();
}


void init()
{
        ::init();
        if( !query_heart_beat(this_object()) ) set_heart_beat(1);
        add_action("do_kill","kill");
}

void leave()
{
        object owner,*pros;
        if (environment())
        message("vision",
                 name() + "消失不见了。\n" , environment(),
                this_object() );
        if(objectp(owner=this_object()->query("possessed")))
        {
                owner->add_temp("timer/solidghost",-1);
                pros = owner->query_temp("protectors");
                        pros -= ({ this_object() });
                owner->set_temp("protectors",pros);
        }
	// Remove all buffs to clean up annied
	ANNIE_D->debuff(this_object(),"all");                
        destruct(this_object());
}

int attack() {
	object opponent;
	opponent = select_opponent();
	if(objectp(opponent)) {
		set_temp("last_opponent", opponent);
//		COMBAT_D->fight(this_object(), opponent);
		return 1;
	} else {
		return 0;
	}
}

void heart_beat()
{
        object leader;
        
        ::heart_beat();

        if(!this_object()) 		return;
        
        if(query_temp("is_unconcious")||is_busy())
                return ;
        if(query("possessed"))
        {
                leader=query("possessed");
                if(environment(leader)!=environment()&&(!leader->is_ghost()))
                {
                        message_vision("$N无声无息地离去了。\n",this_object());
                        this_object()->move(environment(leader));
                        message_vision("$N飘了过来。\n",this_object());
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


int do_kill(string arg)
{
        object victim,who;
        
        who=this_player();
        if(!arg) return 0;
        if(environment()->query("no_fight"))
                return 0;
        victim=present(arg,environment());
        if(!victim) return 0;
        if(victim==who) return 0;
        
        if (objectp(query("possessed")))
        if (!COMBAT_D->legitimate_kill(query("possessed"), victim))     return 0;
        
        if (!query_temp("pfm/qiankun"))	return 0;
        
        if(victim->query("possessed")==who)
        {
         	tell_object(who,"此亡灵是你的法力所聚，杀它会损伤元神的。\n");
            return 1;
        }
        
        if(victim==query("possessed") 
        	&& victim->query("possessed")==query("possessed")) {
        	message_vision("$N喃喃道：“休。。。伤。。。我。。。主。。。！！”\n",this_object());
            ccommand("kill "+who->get_id());
        }       
        if(who==query("possessed"))
        {
            message_vision("$N喃喃道："+victim->query("name")+"，拿。。。命。。。来。。。！\n",this_object());
            ccommand("kill "+ arg);
        }
        return 0;
}


// level = 400 maximum 

void invocation(object who, int level)
{
        int i;
        object *pros;
        int owner_exp,owner_hp, exp;
        
        set("str",1);
        set("agi",who->query("agi"));
        set("kar",who->query("kar"));
        set("int",who->query("int"));
        set("cps",who->query("cps"));
        set("con",who->query("con"));
	
        set_skill("cursism",who->query_skill("cursism",1));  
        set_skill("celecurse",who->query_skill("celecurse",1)); 
        
        owner_exp=who->query("combat_exp");
        owner_hp= who->query("max_kee");
        
        set("max_kee", 100 + owner_hp*3/4);
        set("eff_kee",query("max_kee"));
        set("kee",query("max_kee"));
        set("max_gin",query("max_kee"));
        set("eff_gin",query("max_gin"));
        set("gin",query("max_gin"));
        set("max_sen",query("max_kee"));
        set("eff_sen",query("max_sen"));
        set("sen",query("max_sen"));
        
        set("combat_exp", owner_exp*3/4);
        set("possessed",who);

		map_skill("cursism","celecurse");

//      Spirit can't parry
        
}


void die()
{
        object owner,*pros;
        if(objectp(owner=this_object()->query("possessed")))
        {
                owner->add_temp("timer/solidghost",-1);    
        }
        message_vision(BLU"$N惨叫一声，化成一缕黑烟消失了。\n"NOR,this_object());
        destruct(this_object());
}
			

void unconcious() {
        die();
}


object offensive_target(object me)
{
        int sz;
        object *enemy;
        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0;
        sz = sizeof(enemy);
        if( sz > 6 ) sz = 6;
        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
}


// 	All solidghost attack is caculated with owner's data.
int mimicurse()
{
        string msg,id_enemy;
        int damage, ap, dp, skill;
        int bonus_damage, my_exp, mod,ability;
        object owner,me,target;
        
        me=this_object();
        
        if (!query_temp("pfm/qiankun"))	return 1;	// 只有用了乾坤无形才会战斗。
        
        owner=this_object()->query("possessed");
        if (!objectp(owner) || owner->is_ghost())	return 1;
        
        skill = owner->query_skill("celecurse",1);
        ap = me->query_skill("cursism"); // 500
                
              
        ap = me->query_skill("cursism");	
        if (ap>500) ap = 500;
        
        // 500 + random(500) damage, 1/2 owner blood damage
        // damage = ap + random (ap);
                
        damage = ap*ap/500 + random(ap*ap/500);
                
        // 治愈主人     // 150 级 乾坤无形 
        if (owner)      
        if (me->query_temp("pfm/qiankun/heal_curse") 
        	&& (owner->query("kee")< owner->query("max_kee") *3/4
                 || owner->query("eff_kee")< owner->query("max_kee") *4/5) 
            && me->query_temp("timer/pfm/heal")+ 16 < time()
            && environment(me) == environment(owner)
             )
        {
                msg = WHT "\n$N的眼中白光一闪，一条细如发丝的银光射向$n！\n" NOR;
                message_vision(msg, me, owner);
  //              message_vision("owner is healed "+damage+"\n",me);
                
                ability= F_ABILITY->check_ability(owner,"heal_add");
                damage = damage * (100 + ability*3)/100;                
                owner->receive_fulling("kee",damage, me);
                tell_object(owner, WHT"你身上的伤口奇迹般地愈合了。\n\n"NOR);
                me->set_temp("timer/pfm/heal",time());
                me->perform_busy(2);
                return 1;
        }
                
        if( !target ) target = offensive_target(me);
 
        
        // Busy 敌人    // 170 级 乾坤无形 -- 
        
        if (me->query_temp("pfm/qiankun/busy_curse") && !target->is_busy())
        {
        	mod = COMBAT_D->can_busy(owner, target, "celecurse");
           	if (mod>5 && mod <50 && me->query_temp("timer/pfm/busy")+18 < time()) 
        	{                                                
                	msg = YEL "\n$N的眼中黄光一闪，一条细如发丝的黄烟射向$n！\n" NOR;       
                	// Pet should obey busy-timer too, but we will just set it to be >18sec per try                
                	if (COMBAT_D->do_busy_attack(owner, target, "celecurse/busy_curse", "unarmed", 300, mod))
                	{	   
                        	msg += YEL"$n神色灰暗，浑身惊颤不止。\n\n"NOR;
                        	target->force_busy(2);
                        	me->set_temp("timer/pfm/busy",time());
 //                       	message_vision("target is busied "+target->query_busy()+"\n",me);
                	}
                	else 
                        	msg += WHT"但是被$n避开了！！\n"NOR;
	                message_vision(msg, me, target);
	                me->perform_busy(2);
	                return 1;
        	}
        }
   
      
        // 一般攻击
        
        if (me->query_temp("pfm/qiankun/turn_curse")
        	&& me->query_temp("timer/pfm/hit")+ 12 <time()) {         
        	if (wizardp(owner) && owner->query("env/test") == "annie")
                tell_object(owner,"damage = "+damage+"\n");

      		msg = RED "\n$N的眼中红光一闪，一条细如发丝的血线射向$n！\n" NOR;
            
            owner->add_temp("apply/cursism", skill); 
                        
	        if(COMBAT_D->do_magic_attack(owner, target, "cursism", "kee")) {
	                message_vision(msg, me, target);
	         	if (me->query_temp("pfm/qiankun/turn_curse")==2) // L100 乾坤转
	        		target->receive_damage("gin", damage, me);
	        	else
	        		target->receive_damage("kee", damage, me);
	            COMBAT_D->report_status(target);
	            COMBAT_D->win_lose_check(me,target,1);
	            me->set_temp("timer/pfm/hit",time());
	        } else
	        {
	                msg += WHT"但是被$n发现了！！\n"NOR;
	                message_vision(msg, me, target);
	        }
        	owner->add_temp("apply/cursism",-skill);
        	me->perform_busy(2);
        }
                
        return 1;
}


