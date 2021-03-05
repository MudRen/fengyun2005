// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
    	string msg;
    	int lvl, num, i;
	mapping buff;
	object *team, *team1;
		
	if (me->query("class")!= "wudang")
		return notify_fail("只有武当弟子才能使用七星总诀。\n");
		
   	if((int)me->query_skill("qixing",1) < 150 )
   	     return notify_fail("『七星诀』需要150级七星法！\n");
      	
    	if( target ) 
    		return notify_fail("『七星诀』不需要指定目标。\n");
    
    	target = me;
    	
	if( ANNIE_D->check_buff(target, "armorup")
		|| ANNIE_D->check_buff(target,"damageup")
		|| ANNIE_D->check_buff(target,"powerup2"))
        	return notify_fail("你已经在使用类似的心诀了。\n");

    	if(me->query("mana") < 200 )
        	return notify_fail("『七星诀』需要200点法力！\n");
    	if (userp(me))	me->add("mana", -200);
       	
       	msg = HIR"\n\n$N口中念念有词，数道光芒从$N头顶射出，缭绕在$N周围！\n"NOR ;
	
	message_vision(msg, me);
//	50 + 200 = 250	/5 = 50, capped at 50	
	lvl = me->query_skill("spells")/5;
                
        team1 = me->query_team();
	
	if (!team1 || me->query_skill("qixing",1)< 200) {
		buff =
		([
			"caster":me,
			"who": me,
			"type":"powerup2",
			"att":"bless",
			"name":"七星法·七星总诀",
			"buff1":"apply/armor",
			"buff1_c":lvl,
			"buff2": "apply/damage",
			"buff2_c": lvl,
			"time":   300,
			"buff_msg":HIR"光芒四射，保护住$N的全身！\n"NOR,
		]);
		ANNIE_D->buffup(buff);
	}else {	
		team = filter_array(team1,(: present($1,environment($2)) :),me);
		num = sizeof(team);	
		for (i=0; i<num; i++) {
			if ( ANNIE_D->check_buff(team[i],"damageup")
				|| ANNIE_D->check_buff(team[i],"armorup")
				|| ANNIE_D->check_buff(team[i],"qixingup")
				) continue;
			buff =
			([
				"caster":me,
				"who":  team[i],
				"type":"powerup2",
				"att": "bless",
				"name": "七星法·七星总诀",
				"buff1":"apply/armor",
				"buff1_c":lvl,
				"buff2": "apply/damage",
				"buff2_c": lvl,
				"time":   300,
				"buff_msg":HIR"光芒四射，保护住$N的全身！\n"NOR,
			]);
			ANNIE_D->buffup(buff);
		}
        }
	me->perform_busy(1);
    	return 1;
}
