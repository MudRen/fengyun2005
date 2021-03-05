// annie 07.04.2003
// buffup改，参考模型
// 五谷月华 5 gold,45min,500 buffup.
// [银戈草]，[莲花瓣]，白露水，玉枢丹，双彩霓石

inherit SSERVER;
#include <ansi.h>

int exert(object me, object target, int amount)
{
	int lvl,duration;
	object obj;
	object drug1,drug2;

	amount = 500;	// 1k.
	duration = 2700;// 60 min

	lvl = me->query_skill("divineforce",1);	
	if( lvl < 50) 	return notify_fail("『五谷月华』需要50级的破邪心经。\n");

	if (me->query("class")!="demon")
		return notify_fail("只有魔教弟子才能运转『五谷月华』。\n");
	
	if (!(drug1 = present("lianhua",me)) || !(drug2 = present("yinge",me)) )
		return notify_fail("使用『五谷月华』需有银戈草、莲花瓣两物为引。\n");

	if (!drug1->query("is_drug") || !drug2->query("is_drug"))	// 假货?
		return notify_fail("使用『五谷月华』需有银戈草、莲花瓣两物为引。\n");
	
	if (me->query("force") < 400)	// 100,400,800,1300,1900.
		return notify_fail("你的真气不足。\n");
	
	if (!target) target=me;
	
	if(!objectp(obj = present(target, environment(me))))
			return notify_fail("这里没有这个人。\n");
	if (!obj->is_character() || obj->is_corpse() )
			return notify_fail("看清楚一点，那并不是活物。\n");
	if (target->query_temp("buffup/buffed_kee"))
			return notify_fail("此人已经纳入了类似的奇功。\n");	
	if (target->query_temp("buffup/buffed_gin"))
			return notify_fail("此人已经纳入了类似的奇功。\n");	
	if (target->query_temp("buffup/buffed_sen"))
			return notify_fail("此人已经纳入了类似的奇功。\n");	
	
/*	my_exp=me->query("combat_exp");
	your_exp=target->query("combat_exp");
	if (my_exp>your_exp*3 || my_exp<your_exp/3
		|| my_exp> your_exp+3000000 || my_exp < your_exp- 3000000)
		return notify_fail("你们之间功力相差太远了,内力无法传递.\n");	
*/	// hmm...出钱的就是大爷喔...gold gold,想要的尽管来吧

    drug1->add_amount(-1);
    drug2->add_amount(-1);

	message_vision(HIW"$N深深吸了口气，运起真气将物引融化，施起『五谷月华』。\n"NOR, me);	
	me->add("force", -400 );

	if (target!= me) 
		message_vision(HIW"$N一掌拍在$n背心，淡淡的烟气从$N顶上腾起．．．\n"NOR, me,target);
	
//	if (me->query("fy41/dwg_ih_buffup")|| me->query("fy41/all"))
//		amount = amount * 2;

	target->set_temp("buffup/buffed_kee",1);
	target->set_temp("buffup/buffed_gin",1);
	target->set_temp("buffup/buffed_sen",1);

	call_out("apply_effect",2, target,duration, amount);
	me->start_busy(3);
	return 1;
}
 
	
void apply_effect(object target, int duration,int amount)
{
	int gin,kee,sen;
	message_vision(HIW"一片浅色霞云在$N头顶收聚，一点点纳进$N天门．．．\n"NOR,target);

	gin = (int)target->query("max_gin");
	target->set("max_gin",gin+amount);
	target->set("eff_gin",target->query("eff_gin")+amount);

	kee = (int)target->query("max_kee");
	target->set("max_kee",kee+amount);
	target->set("eff_kee",target->query("eff_kee")+amount);

	sen = (int)target->query("max_sen");
	target->set("max_sen",sen+amount);
	target->set("eff_sen",target->query("eff_sen")+amount);

	call_out("warning",duration-180, target,amount);
	return;
}

void warning(object target,int amount)
{
	tell_object(target, WHT"你觉得身体中的充实之感在一点一点的流失．．．\n"NOR );
	call_out("remove_effect",180, target,amount);
	return;
}

void remove_effect(object target, int amount)
{
	tell_object(target, HIR BLK"你打个冷颤，只觉得身子一下子虚弱了许多！\n"NOR );

	target->set("max_gin",(int)target->query("max_gin")-amount);
	if (target->query("eff_gin")>target->query("max_gin"))
			target->set("eff_gin",target->query("max_gin"));
	if (target->query("gin")>target->query("max_gin"))
			target->set("gin",target->query("max_gin"));

	target->set("max_kee",(int)target->query("max_kee")-amount);
	if (target->query("eff_kee")>target->query("max_kee"))
			target->set("eff_kee",target->query("max_kee"));
	if (target->query("kee")>target->query("max_kee"))
			target->set("kee",target->query("max_kee"));

	target->set("max_sen",(int)target->query("max_sen")-amount);
	if (target->query("eff_sen")>target->query("max_sen"))
			target->set("eff_sen",target->query("max_sen"));
	if (target->query("sen")>target->query("max_sen"))
			target->set("sen",target->query("max_sen"));

	target->delete_temp("buffup/buffed_kee");
	target->delete_temp("buffup/buffed_kee");
	target->delete_temp("buffup/buffed_sen");
	return;
}
