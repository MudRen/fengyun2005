// 一體同觀(奇運術)

#include <ansi.h>

int exert(object me, object target, int amount)
{
	string msg;
	int lvl, num, i,teampf;
	mapping buff;
	object *team, *team1;

	if (userp(me))
		return notify_fail("你的武功中没有这项特技。\n");

	if(me->query("class")!="beggar")
		return notify_fail("只有穷苦人家才有趋利避害的本能。\n");

	if(me->query("deposit") > 100000)
		return notify_fail("只有穷苦人家才有趋利避害的本能。\n");

	if(me->query_skill("huntunforce",1) < 160 )
		 return notify_fail("『同观诀』需要160级馄饨功！\n");
	
	if(me->query_skill("betting",1) < 50 )
		 return notify_fail("『同观诀』需要50级赌之道！\n");
	
	if(me->query_skill("begging",1) < 160 )
		 return notify_fail("『同观诀』需要160级乞讨之术！\n");
	
	if (me->query_skill("betting",1) >= 100)
		teampf =1;

	target = me;

	team1 = me->query_team();
	if (!team1)
		teampf=0;

	if(me->query("force") < 100 )
		return notify_fail("『同观诀』需要100点内力！\n");

	if (ANNIE_D->check_buff(me,"criticalup") && !teampf)
		return notify_fail("你已经在受『同观诀』的影响了。\n");

	if (userp(me))
		me->add("force", -100);

	msg = WHT"\n\n$N纳气容心，默运馄饨心法，"NOR ;
	message_vision(msg, me);

	lvl = me->query_skill("huntunforce",1);

	// huntunforce 150,+75%
	// full foreknowledge 200lv. = 40 kar,vs 3-5M npc(25-30) rate = 17.5% ~ 26%

	if (!teampf) {
		buff =
		([
			"caster":me,
			"who": me,
			"type":"criticalup",
			"att":"bless",
			"name":"馄饨心法·同观诀",
			"buff1":"apply/critical_strike",
			"buff1_c":lvl/2,
			"time":   30+lvl/2,
			"buff_msg":YEL"身边隐现出浅浅祥光。\n\n"NOR,
		]);
		ANNIE_D->buffup(buff);
	}
	else
	{	
		team = filter_array(team1,(: present($1,environment($2)) :),me);
		num = sizeof(team);	
    	msg = WHT"用手虚虚抱住周围众人。\n"NOR ;
		message_vision(msg, me);
		for (i=0; i<num; i++)
		{
			if (ANNIE_D->check_buff(me,"criticalup"))
				continue;
			buff =
			([
				"caster":me,
				"who":  team[i],
				"type":"criticalup",
				"att":"bless",
				"name":"馄饨心法·同观诀",
				"buff1":"apply/critical_strike",
				"buff1_c":team[i]->query("class") == "beggar"?(lvl-10)/2:(lvl-10)/3,
				"time":   25+lvl/2,
				"buff_msg":YEL"$N身边泛起似有似无的浅浅祥光．．．\n"NOR,
				"disa_msg":YEL "\n\n你周身的光甲发出耀眼的一闪就消失了。\n\n" NOR,
				"special_func":0,
			]);
			ANNIE_D->buffup(buff);
		}
    }
	me->start_busy(1);
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
