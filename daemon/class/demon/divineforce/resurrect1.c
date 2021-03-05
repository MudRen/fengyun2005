// annie 07.04.2003
// dancing_faery@hotmail.com
// 参考模型
// 金针渡劫 2 gold,10%
// [符水]，茵生草，十圣金丹，流光镜玉，辉月魂石

inherit SSERVER;
#include <ansi.h>

int exert(object me, object target, int amount)
{
	int lvl,duration,exp_recovered;
	object obj;
	object drug1,drug2;
	string n1="金针渡劫",n2="符水";

	amount = 10;	 // 10%
	duration = 900;  // 15 min

	lvl = me->query_skill("divineforce",1);	
	if( lvl < 1) 	return notify_fail("『"+n1+"』需要1级的破邪心经。\n");

	if (me->query("class")!="demon")
		return notify_fail("只有魔教弟子才能运转『"+n1+"』。\n");
	
	if (!(drug1 = present("holywater",me)) )
		return notify_fail("使用『"+n1+"』需有"+n2+"为引。\n");

	if (!drug1->query("is_drug"))	// 假货?
		return notify_fail("使用『"+n1+"』需有"+n2+"为引。\n");
	
	if (me->query("force") < 100)	// 100,400,800,1300,1900.
		return notify_fail("你的真气不足。\n");
	
	if (!target) target=me;
	
	if(!objectp(obj = present(target, environment(me))))
			return notify_fail("这里没有这个人。\n");
	if (!obj->is_character() || obj->is_corpse() )
			return notify_fail("看清楚一点，那并不是活物。\n");
	if( !obj->is_ghost())
		return notify_fail(n1+"不能用在活人身上。\n");
	if( !userp(obj))
		return notify_fail(n1+"只能用在玩家身上。\n");		
	if( (int)target->query("death/time")+ duration  < time())
		return notify_fail("太晚了，他的肉身已经消失，救不活了。（死亡时间需在"+(duration/60)+"分钟内）\n");
    if (!obj->query("env/revive"))
      	return notify_fail("此人不愿意被人复生。（需要对方Set revive 1）\n"); 

	exp_recovered=obj->query("death/exp_lost");
	exp_recovered=exp_recovered/100*amount;

    drug1->add_amount(-1);

	message_vision(HIW"$N深深吸了口气，运起真气将物引融化，施起『"+n1+"』。\n"NOR, me);	
	me->add("force", -100 );

	if (target!= me) 
		message_vision(HIW"$N一掌拍在$n背心，淡淡的烟气从$N顶上腾起．．．\n"NOR, me,target);

	target->add("combat_exp", exp_recovered);
	target->set("death/time",0);
	target->set("death/exp_lost",0);
	target->reincarnate();
	message_vision( HIW "$N浑身剧烈地颤抖着，忽然间一道光芒注入$N的顶门。\n",target);
	message_vision( HIR "$N复活了！！\n"NOR,target);
	me->start_busy(3);
	return 1;
}
 