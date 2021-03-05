// silencer@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void simulate_set(object target,object shadow);

int perform(object me, object target)
{
	string msg,temp,temp1;
	int extra,num,num1;
	int myexp,yourexp, exp_bonus,cond;
	object weapon,shadow,hisweapon,newweapon, shadowweapon;
	
	extra = me->query_skill("xinyue-dagger",1);
	exp_bonus = (me->query("combat_exp")-3000000)/3000*extra/1000;
	if (exp_bonus> extra) exp_bonus=extra;
		
	if ( extra < 106) return notify_fail("你的[新月斩］还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［斗转星移］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	myexp=me->query("combat_exp");
	yourexp=target->query("combat_exp");
	
	msg = HIR "$N一声长啸："NOR+"      "+HIC"斗"NOR+"      "+HIY"转"NOR+
	"      "+HIW"星"NOR+"      "+HIB"移"NOR+"\n"; 
	message_vision(msg,me);
	
	if ((myexp*3/4+random(myexp*4)>yourexp)&& !target->query_temp("is_unconcious")) {
		
		msg= MAG"\n$N仿佛置身于一个极大的漩涡中，攻出的招式竟然反击回来！\n\n"NOR;
		message_vision(msg,target);
			
		seteuid(getuid());
		if (!userp(target)) {
			sscanf(file_name(target),"%s#%d",temp,num);
			shadow=new(temp);
			
			}
		else  	{
			shadow=new("/obj/npc/shadefigure");
			shadow->changeshape(target);		
			if (shadowweapon = shadow->query_temp("weapon"))
				shadowweapon->unequip();
			if(hisweapon=target->query_temp("weapon"))	{
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
//		shadow->add_killer(target->query("id"));
		shadow->set_temp("fight_to_death",1);		
//		CHANNEL_D->do_sys_channel( "sys",
//					sprintf("%O",shadow->query_rival()));
		simulate_set(target,shadow);
		shadow->add_temp("apply/attack", extra/2);
		message_vision(HIC "    斗\n" NOR,me);
		COMBAT_D->do_attack(shadow,target,msg);
		if (target->query_temp("damaged_during_attack"))
		   			target->set_temp("last_damage_from",me);
	     	
	     	message_vision(YEL "            转\n" NOR,me);
		simulate_set(target,shadow);
		COMBAT_D->do_attack(shadow,target,msg);
	   	if (target->query_temp("damaged_during_attack"))
		   			target->set_temp("last_damage_from",me);
	   	
	   	message_vision(HIW "                    星\n" NOR,me);
		simulate_set(target,shadow);
		COMBAT_D->do_attack(shadow,target,msg);
	   	if (target->query_temp("damaged_during_attack"))
		   			target->set_temp("last_damage_from",me);
	   	
	   	message_vision(HIB "                              移\n" NOR,me);
		simulate_set(target,shadow);
		COMBAT_D->do_attack(shadow,target,msg);
	   	if (target->query_temp("damaged_during_attack"))
		   			target->set_temp("last_damage_from",me);
	   	
	   	shadow->add_temp("apply/attack", -extra/2);
//		CHANNEL_D->do_sys_channel( "sys",
//					sprintf("%O",shadow->query_rival()));
//	   	if (me->is_killing(target->query("id"))) cond=1;
	   	destruct(shadow);
   	}
   	else {
   		if (!target->query_temp("is_unconcious"))
   			message_vision(WHT"$N不为$n所惑，内力一圈一转，将$n的攻势化为无形。\n",target,me);
   		else message_vision(WHT"$N昏昏沉沉，不为$n的幻象所迷惑。\n",target,me);
   		}
   	
/*	if (cond) 
		me->add_killer(target->query("id"));		
	me->add_enemy(target);*/
	
	me->add_temp("apply/damage", extra*2+exp_bonus*2);
	me->add_temp("apply/attack", extra);   
	msg =HIY"      嗟！顺我者昌，逆我者亡，上天入地，唯我是王！\n\n"NOR;
        msg= msg+HIR"  $N如鬼魅般欺到$n身前，"NOR+ weapon->name()+ HIR "朝$n当心刺去！\n" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	me->add_temp("apply/damage", -extra*2-exp_bonus*2);
	me->add_temp("apply/attack", -extra);

	if (me->query_busy()<3) me->start_busy(3);
		
	return 1;
}

	
void simulate_set(object target, object shadow)	{
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
//	message_vision("my kee is "+(string)shadow->query("kee")+"\n",shadow);	
}


