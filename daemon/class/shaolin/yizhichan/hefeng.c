// 将目标除自己以外的所有Hate清到最低，将自己的Hate设置为zen*20

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    string msg;
    int extra, i, num, hate, duration, timer;
	string name;
	object weapon, *enemy;
		
    if(me->query("class")!="shaolin")
	return notify_fail("和风是少林绝技，你怎么可能会使呢？\n");

    extra = me->query_skill("yizhichan",1);
    if(extra<140) return notify_fail("和风需要140级的一指禅修为。\n");

    timer = 600 - F_ABILITY->check_ability(me,"hefeng_add")*20;	
    duration = me->query("timer/pfm/sl_hefeng")+timer-time();
	if (duration>0)
    	return notify_fail("『和风』需要"+chinese_number(duration)+"秒后才能再次使用。\n");
    
    if( !target ) target = offensive_target(me);
    if( !target
      ||      !target->is_character()
      ||      !me->is_fighting(target) )
	return notify_fail("和风只能对战斗中的对手使用。\n");

	weapon = target->query_weapon();
	if (objectp(weapon))	name = weapon->query("name");
	else					name = "手腕";

    message_vision(BBLU + YEL"
地上黄叶，忽尔飘起，游游荡荡，忽又轻轻地贴到地上，像遇到了风，和风。

那是一只手指。

$N"NOR+BBLU + YEL"的手指按捺在$n"+name+NOR+BBLU + YEL"上，就像拈在花瓣上一般轻柔。

风吹叶飘，如鱼游水中。

那只拈花一般的手指捺在"+name+ NOR+BBLU + YEL"上，然后又缓缓地收回去。

留下来了一句话：

"NOR+BBLU+HIY"“阿弥陀佛”"NOR"\n\n",me,target);

	me->set("timer/pfm/sl_hefeng",time());
	enemy = target->query_enemy();
    num = sizeof(enemy);
    if (!enemy || num<1)	return 1;
	      
    for (i=0;i< num; i++){
    	if ( !enemy[i])			continue;
    	hate = target->query_hate(enemy[i]);
    	if (hate<10 && enemy[i]!=me)	continue;
    	target->add_hate(enemy[i], -hate + 10);
    	if (enemy[i]==me)	target->add_hate(me, me->query_skill("zen",1)*20);
    }	
       
    return 1;        
}     
