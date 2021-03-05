#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int exert(object me, object target)
{
	string msg,temp,temp1;
	int extra,num,num1,i;
	int myexp,yourexp, exp_bonus;
	object weapon,shadow,hisweapon,newweapon;
	object *enemy;
	int cond;
	
	extra = me->query_skill("qingpingforce",1);
	
	if (userp(me))
		return notify_fail("你的武功中没有这一特技。\n");
	
	if(me->query("class")!="shenshui")
    		return notify_fail("『扭转乾坤』只有神水弟子才能使用。\n");
	
	if( !me->is_fighting() )
		return notify_fail("『扭转乾坤』只能对战斗中的对手使用。\n");
	
	if (me->query("force")<100)
		return notify_fail("『扭转乾坤』需要耗费100点的内力。\n");
	if (userp(me))	me->add("force", -100);
	
	weapon = me->query_temp("weapon");
	myexp=me->query("combat_exp");
	enemy =	me->query_enemy();
	
	exp_bonus = me->query("combat_exp")/5000*extra/1000;
	if (exp_bonus>extra) exp_bonus = extra;
		
	for (i = 0 ; i< sizeof(enemy); i++) {	
		if( enemy[i]&& enemy[i]->is_character()
        		&& me->is_fighting(enemy[i]) )
		
		{	target = enemy[i];	
			yourexp=target->query("combat_exp");	
		   	msg = HIM +"$N双手转动，施展出『扭转乾坤』，企图用强烈的内力将$n"+HIM"的攻势引向$n。\n" NOR;
			message_vision(msg,me,target);
		    	if (( myexp*3/4 + random(myexp)*4>yourexp ||!userp(me)) 
		    		&& !target->query_temp("is_unconcious")) {
		    			
			seteuid(getuid());
			
			if (!userp(target)) {
				sscanf(file_name(target),"%s#%d",temp,num);
				shadow=new(temp);
			} else  	{
				shadow=new("/obj/npc/shadefigure");
				shadow->changeshape(target);
				if(hisweapon=target->query_temp("weapon"))
				{
					sscanf(file_name(hisweapon),"%s#%d",temp1,num1);
					newweapon=new(temp1);
					newweapon->move(shadow);
					newweapon->wield();
				}
			}	
			shadow->set("owner",me);
			shadow->set("possessed",me);
			shadow->move(environment(me));
			if (!target->query_temp("weapon"))
			if (newweapon=shadow->query_temp("weapon"))
			newweapon->unequip();
			
			shadow->set("kee",target->query("kee"));			
			shadow->set("sen",target->query("sen"));
			shadow->set("gin",target->query("gin"));
			shadow->set("eff_kee",target->query("eff_kee"));
			shadow->set("eff_gin",target->query("eff_gin"));
			shadow->set("eff_sen",target->query("eff_sen"));
			shadow->set("max_kee",target->query("max_kee"));
			shadow->set("max_sen",target->query("max_sen"));
			shadow->set("max_gin",target->query("max_gin"));
			shadow->set("name",target->query("name"));
			
			shadow->add_killer(target->query("id"));
			shadow->add_temp("apply/attack", extra+exp_bonus);
			shadow->add_temp("apply/damage", extra*2 );
			COMBAT_D->do_attack(shadow,target,msg);
	   		shadow->add_temp("apply/attack", -extra-exp_bonus);
	   		shadow->add_temp("apply/damage", -extra*2);
	   		if (target->query_temp("damaged_during_attack"))
	   			target->set_temp("last_damage_from",me);
   			if (me->is_killing(target->query("id"))) cond=1;
   			destruct(shadow);
   		   }  else {
   			message_vision(WHT"但是并没有成功！\n"NOR,me);
   			me->add_temp("apply/damage", extra*2);
			me->add_temp("apply/attack", extra);   
			msg =HIY"$N只得顺势向$n击去。\n"NOR;
        		COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
			me->add_temp("apply/damage", -extra*2);
			me->add_temp("apply/attack", -extra);
			}
		}
	}
	if (cond) 
		me->add_killer(target->query("id"));		
	me->add_enemy(target);
	me->perform_busy(1+random(2));
	return 1;
}
