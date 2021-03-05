#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;

// 趙孟俯草書：滅
string *style_mix = ({
HIY"                                            ;;                    
                          ;;;;              ;;;;                  
                            ;;;;              ;;;;                
                              ;;;;              ;;                
                                ;;                                
                                ;;;;;;                            
                                ;;;;;;                            
            ;;;;            ;;;;;;;;;;                            
",
HIC"	      ;;        ;;;;    ;;;;;;                            
            ;;      ;;;;;;    ;;    ;;                            
                    ;;;;    ;;  ;;;;;;;;                          
                            ;;;;;;    ;;      ;;;;                
                        ;;;;;;;;;;      ;;    ;;;;                
        ;;              ;;;;  ;;        ;;    ;;                  
        ;;        ;;        ;;      ;;;;;;;;  ;;                  
        ;;      ;;;;;;      ;;    ;;;;;;  ;;;;;;                  
        ;;;;      ;;;;    ;;    ;;;;      ;;;;;;                  
",
HIW"	;;;;        ;;  ;;;;;;;;;;;;      ;;;;;;                  
          ;;        ;;    ;;    ;;;;        ;;;;                  
          ;;  ;;    ;;        ;;;;;;;;          ;;;;              
        ;;    ;;    ;;      ;;;;    ;;;;        ;;;;              
        ;;  ;;  ;;;;;;    ;;;;      ;;;;          ;;;;            
        ;;  ;;    ;;;;    ;;                        ;;            
        ;;;;;;                                      ;;;;          
        ;;;;;;                                      ;;;;;;        
                                                      ;;;;;;     
"NOR,
													  });

	int skl_me, skl_you, extra_me, extra_you,i;
	int FLAG=0;
	object you,ob,*obs;
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("绝煞剑只能对战斗中的对手使用。\n");
	
	
	if(pointerp(obs=me->query_team()) )
	{
		FLAG=1;
		for(i=0;i<sizeof(obs);i++)
		{
			if(obs[i] == me) continue;
			if(!obs[i]) {FLAG=0; continue;}
			if(environment(obs[i]) != environment(me)) {FLAG=0; continue;}
			if(!obs[i]->query_skill("tempestsword")/2) {FLAG=0; continue;}
			if(!objectp(ob=obs[i]->query_temp("weapon"))) {FLAG=0; continue;}
			if(ob->query("skill_type") != "sword"){FLAG=0; continue;}
			if(obs[i]->query_skill_mapped("sword") != "tempestsword") {FLAG=0; continue;}
		}	
		if(sizeof(obs) !=2) FLAG=0;
	}
	
	skl_me=(int)me->query_skill("blade");
	extra_me=(int)me->query_temp("apply/damage")+(int)me->query_str()*(int)me->query_str()/30;
	if(FLAG)
	{
		if(obs[0]==me) 
			you=obs[1]; 
		else you=obs[0];
		
		skl_you=(int)you->query_skill("sword");
		extra_you=(int)you->query_temp("apply/damage")+(int)you->query_str()*(int)you->query_str()/30;
        
        me->add_temp("apply/attack",(skl_you+skl_me)/3);
        me->add_temp("apply/damage",(extra_you+extra_me)/2);
        you->add_temp("apply/attack",(skl_you+skl_me)/3);
        you->add_temp("apply/damage",(extra_you+extra_me)/2);
        
        you->kill_ob(target);
		
		for(i=0;i<sizeof(style_mix);i++)
			message_vision(style_mix[i],me);

		target->add_temp("combat_no_report",1);

		for (i=0; i<2+random(4); i++)
			COMBAT_D->do_attack(me,target,TYPE_PERFORM);

		for (i=0; i<2+random(4); i++)
			COMBAT_D->do_attack(you,target,TYPE_PERFORM);

	// avg. 7hit

		COMBAT_D->report_status(target);
		target->add_temp("combat_no_report",-1);

        me->add_temp("apply/attack",-(skl_you+skl_me)/3);
        me->add_temp("apply/damage",-(extra_you+extra_me)/2);
        you->add_temp("apply/attack",-(skl_you+skl_me)/3);
        you->add_temp("apply/damage",-(extra_you+extra_me)/2);
	}
	else
	{
		return notify_fail("绝煞剑现在无法使用。\n");
	}	
	me->perform_busy(3);
	you->perform_busy(2);
	return 1;
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
