// - rewriten by neon 06-09-2002
// - new daojianruomeng
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target, object friend)
{
		string msg,yourname,myname,targetname;
        int skl_me, skl_you, extra_me, extra_you, k;
        object you, ob, sword, blade;		

		if(me->query("gender")!="女性")
			return notify_fail("蝶恋花剑法的『刀剑若梦』必须由女子发动。\n");
			
		if(me->query_skill("diesword",1)<30)
        	return notify_fail("刀剑若梦需要30级的蝶恋花剑法。\n");
				
		
		if (!friend || friend == me)
			return notify_fail ("『刀剑若梦』需要与同伴一起使用。\n");
	
		you = friend;
		if ( you->team_member(me) 
			|| (!userp(me) && you->query("npc_team")==me->query("npc_team")))
		k = 1;
		if (!k)
			return notify_fail("同伴必须是与你在同一个队伍中。\n");  
        
		if(you->query("gender")!="男性")	
			return notify_fail("『刀剑若梦』必须一男一女才能够使用。\n");
        	
		if(!you->query_skill("shortsong-blade",1) 
			|| you->query_skill_mapped("blade") != "shortsong-blade") 
        	return notify_fail("同伴没有配合的武功。\n");
        if(you->query_skill("shortsong-blade",1)<30)
        	return notify_fail("同伴需要30级短歌刀法。\n");
        if(!objectp(blade=you->query_temp("weapon"))) 
        	return notify_fail("同伴必须拿刀。\n");
        if(blade->query("skill_type") != "blade")
        	return notify_fail("同伴必须拿刀。\n");
        if(you->query("class")!="legend" && me->query("class")!="legend")
			return notify_fail("至少有一个人必须是铁雪弟子才能用『刀剑若梦』\n");
		if (you->is_busy())
			return notify_fail("同伴正忙着，没法和你一起施展『刀剑若梦』\n");
        if (you->query_temp("till_death/lockup") || you->query_temp("is_unconcious")
        	|| you->query("force")< 50)
			return notify_fail("同伴现在无法使用特技。\n");
		
        if (!target) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("『刀剑若梦』只能对战斗中的对手使用。\n");
        
		if(you == target )
        	return notify_fail(MAG"你怎么狠得下这个心？\n"NOR);
        if (userp(you) && !you->is_fighting(target))
			return notify_fail("同伴与对方并不在战斗中。\n");
	        
		if (userp(me))
		if (!COMBAT_D->legitimate_kill(you, target)) {
			if (stringp(target->query("NO_KILL")))
				return notify_fail(target->query("NO_KILL"));
			if (stringp(target->query("NO_PK")))
				return notify_fail(target->query("NO_PK"));	
			else 
				return notify_fail("想用这办法把同伴扯进来？不成！\n");
		}
	
	 	if (!me->is_killing(target->get_id())){
 			me->kill_ob(target);
 			target->kill_ob(me);
 		}
 		
 		if (!you->is_killing(target->get_id())){
        	you->kill_ob(target);
        	target->kill_ob(you);
        }  
                    
	// Now determine the bonus for same menpai and couple
		if (you->query("marry") == me->query("id") 
			&& you->query("id") == me->query("marry"))  {
			message_vision(HIG"\n$N与$n凝目对望一眼，忽然间柔情蜜意充满心头，清光闪动，刀剑如梦幻般挥出。。。\n\n"NOR,me,you);		
		}
	
	    if (me->query("class") == "legend") {
	    	skl_me= me->query_skill("diesword",1);
    	} else
    		skl_me = 0;
    	extra_me = skl_me;
    	
    	if (you->query("class") == "legend") {
    		skl_you= you->query_skill("shortsong-blade",1);
    	} else
    		skl_you = 0;
        extra_you= skl_you;
        
        // The enable has to be lower than 3sword/3blade
        
        if (extra_me > 100) 	extra_me = 100;
        if (extra_you > 100) 	extra_you = 100; 
        
        me->add_temp("apply/attack",extra_me);
        me->add_temp("apply/damage",extra_me);     
        you->add_temp("apply/attack",extra_you);
        you->add_temp("apply/damage",extra_you);
 		 		 		        
        myname=me->name();
        yourname=you->name();
        targetname=target->name();
        sword=me->query_temp("weapon");

		msg=HIY"\n$N和$n刀剑合壁，使出了一式“刀剑若梦”，丝丝入扣，滴水不漏的向"+targetname+HIY"斩去。 \n\n";
       		msg+=HIC"迢迢牵牛星，皎皎河汉女。\n"NOR;
        	msg+=HIC"$N手中的"+sword->name()+HIC"百转千回，变幻不定，"+targetname+HIC"眼前一花，$n手中的"
                +blade->name()+HIC"早已杀到面前。 "NOR;
		message_vision(msg,me,you);
		COMBAT_D->do_attack(you,target, TYPE_REGULAR," ");

        	msg=CYN"\n纤纤擢素手，札札弄机杼。\n";
        	msg+="$N移行换步上前，反手就是一剑！ \n"NOR;
        	COMBAT_D->do_attack(me,target,TYPE_REGULAR,msg);

        	msg=HIW"\n\n终日不成章，涕泣零如雨。\n";
        	msg+="$n手中的"+blade->name()+HIW"不住虚晃，$N乘机攻出一片剑影，将"+targetname+HIW"全身笼罩其中。" NOR;
		message_vision(msg,me,you);
        	COMBAT_D->do_attack(me,target,TYPE_REGULAR," ");

        	msg=MAG"\n\n河汉清且浅，相去复几许。\n";
        	msg+="$n左手轻搂$N的蛮腰，右手"+blade->name()+MAG"斜斜挥出，直取"+targetname+MAG"的要害。 "NOR;
		message_vision(msg,me,you);
        	COMBAT_D->do_attack(you,target, TYPE_REGULAR," ");

        	msg=HIG"\n\n盈盈一水间，脉脉不得语。\n";
        	msg+="$n和$N心意相通，一刀一剑，有如缠绵中的情侣，竟合而为一，直向"+targetname+HIG"飞去。"NOR;
		message_vision(msg,me,you);
        	COMBAT_D->do_attack(you,target, TYPE_REGULAR," ");
        	COMBAT_D->do_attack(me,target,TYPE_REGULAR," ");


        me->add_temp("apply/attack",-extra_me);
        me->add_temp("apply/damage",-extra_me);
        you->add_temp("apply/attack",-extra_you);
        you->add_temp("apply/damage",-extra_you);
                
        me->perform_busy(3);
        you->perform_busy(3);
        return 1;
}
