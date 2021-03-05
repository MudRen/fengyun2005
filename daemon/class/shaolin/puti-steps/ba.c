// Silencer@fengyun workgroup	June.2005


#include <ansi.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
    int skill, num, i, duration,title;
	object *team, *team1, *shiwei;
	mapping buff;
	string msg;
	
	int timer;
		
    if (userp(me))
    if (me->query("family/master_id")!="master yue" 
        	|| me->query("class")!="official")
        	return notify_fail("只有岳飞的弟子才能使用『八卦金锁阵』。\n");
        	
	skill = me->query_skill("strategy",1);

	if (me->query_skill("strategy",1) < 220 || me->query_skill("leadership",1)< 220)
		return notify_fail("『八卦金锁阵』需要220级兵法和220级用人之技。\n");        		
	       
    if (me->query_temp("guard_count")<2)
        	return notify_fail("你的护卫太少，列不出阵法耶。\n");
	
    timer = 1200 - F_ABILITY->check_ability(me,"ba_add")*60;
    duration = me->query("timer/pfm/yue-bgjs")-time() + timer;
    if ( duration >0)
		return notify_fail("你还需要等待"+(int)(duration/60)+"分钟左右才能再次发动八卦金锁阵。\n");
		
	if( !me->is_fighting() )
        	return notify_fail("八卦金锁阵只能在战斗中发动！\n");
        	
	if (ANNIE_D->check_buff(me,"array-iron"))
		return notify_fail("你已经在发动八卦金锁阵了。\n");
		
	me->set("timer/pfm/yue-bgjs",time());
    
    msg = BGRN + HIY "$N挥动手中银枪，但见身后护卫移形换位，旌旗飘摇，鼓声阵阵，瞬间列出"HIW"八卦金锁之阵！\n" NOR; 	
  	message_vision(msg, me);		
    
    shiwei = filter_array(all_inventory(environment(me)),
        		(: $1->query("possessed")==$2 && $1->query("id")=="huwei" :),me);
    num = sizeof(shiwei);	
	for (i=0; i<num; i++) {
		if (ANNIE_D->check_buff(shiwei[i],"yue_array"))
			ANNIE_D->debuff(shiwei[i],"yue_array");
    }
    
    buff =
		([
				"caster":me,
				"who": me,
				"type":"array-iron",
				"att": "bless",
				"name":"兵法·八卦金锁阵",
				"buff1":"pfm/yue-bgjs",
				"buff1_c":1,
				"time": 120,
				"buff_msg": "",			
		]);
	ANNIE_D->buffup(buff);		
     	        
    return 1;
}
	