// Silencer@fy4
// 此心法是用来提供一个temp_Mark给其他丐帮技能。

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
	object *team;
	int i, skill, duration;
	mapping buff;

	if (me->query("class")!= "beggar")
		return notify_fail("只有丐帮弟子才能运用『倏忽诀』\n");
		
	skill = me->query_skill("huntunforce",1);
	if (skill < 150 || me->query_skill("begging",1)<200 || me->query_skill("advanced-unarmed",1)<200)
		return notify_fail("『倏忽诀』至少需要150级混沌功、200级乞讨之术和高级格斗之术。\n");

	duration = me->query("timer/gb_shuhu")-time() + 900 - F_ABILITY->check_ability(me,"shuhu_add")*30;
    if (duration>0)
       	return notify_fail("你还需要等待"+duration+"秒钟左右才能再次使用『倏忽诀』。\n");

	if (ANNIE_D->check_buff(me, "fastcast")>0)
               	return notify_fail("你已经在使用『倏忽诀』了。\n");  
    
    me->set("timer/gb_shuhu",time());
	
    buff =
		([
			"caster":me,
			"who": me,
			"type":"fastcast",
			"att":"bless",
			"name":"混沌功·倏忽诀",
			"time":  180,
			"buff_msg":HIG"$N一声长啸，身形陡化虚影　　　　－　－　倏　忽　来　去　－　－　\n"NOR,
			"disa_msg":YEL"你的『倏忽诀』运行完毕，将内力收回丹田。\n"NOR,
		]);
	ANNIE_D->buffup(buff);
	
	return 1;
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
