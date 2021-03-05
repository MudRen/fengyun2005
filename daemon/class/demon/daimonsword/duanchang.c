/* 娇嗔浅笑俱因痴，断肠旧事知为谁？
两地相隔的愁思，生死永诀的别离，终于化作了这断肠绝灭的一剑。
甚么山盟海誓，甚么地老天荒，终是抵不住一次阴阳相隔的午夜梦回。
剑在人亦在，剑碎人断肠！——　三叹剑法·断肠绝灭式,annie 07.01.03
*/

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

	string *msg3=     ({
	HIW"明月照高楼，含君千里光，巷中情思满，断绝孤妾肠。"NOR,
	WHT"悲风荡帷帐，瑶翠坐自伤，妾心依天末，思与浮云长。"NOR,
	HIR BLK"怨歌视秋草，幽叶岂再扬？暮兰不待岁，离华能几芳？"NOR,
	});

	string *msg4=     ({
	HIW"重来云山，愁情盈袖，满目皆秋。飘渺仙缘，独遗梦影，浮生寻遍，云散风流。\n"NOR"$N的剑势忽缓而不疏，剑意有余而不尽，突然左右虚指，点向$n。"NOR,
	WHT"关山千回，历劫又生，看取豪情动九州。今逝矣，纵天下事了，物非人旧。\n"NOR"$N长吸一口真气，招法一变，剑身泛出蒙蒙青气，气象浑然森严，毫无破绽。"NOR,
	HIR BLK"一剑来去苍茫，枉平生笑傲逍遥游。嗟逝者如水，侬情随风，悲歌忍继，此恨长留。\n"NOR"$N手里$w疾然回收，身势圆转，$w划出一道弯曲的半弧，落向$n。"NOR,
});

int perform(object me, object target) 
{
	int i, skill,j,k ,l;
	object weapon,ob,*pros;
	string obn;

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(HIR BLK"『断肠绝灭式』"NOR"只能对战斗中的对手使用。\n");

	skill = me->query_skill("daimonsword",1);
	if (skill < 220)
		return notify_fail(HIR BLK"『断肠绝灭式』"NOR"至少需要220级三叹剑法。\n");
	
	if (!me->is_fighting())
		return notify_fail(HIR BLK"『断肠绝灭式』"NOR"只能在战斗中使用。\n");
	
	if (userp(me))
	{
		if (me->query("class")!= "demon")
			return notify_fail("只有魔教弟子才能施展"HIR BLK"『断肠绝灭式』"NOR"。\n");

		if (!me->query("marry") || me->query("divorced"))
			return notify_fail("无论你怎样用心，总是无法把握住三叹剑法的神之所在。\n");

		ob = FINGER_D->acquire_login_ob(me->query("marry"));

		if (ob)
			return notify_fail("无论你怎样用心，总是无法把握住三叹剑法的神之所在。\n");

		if (me->query("max_force") < 100)
 			return notify_fail("你现在毫无怨气杀机，如何使得出"HIR BLK"『断肠绝灭式』"NOR"？\n");

		me->add("max_force",-100);	// *bud
	}

	message_vision(CYN"\n$N慢慢闭上眼睛，使出了三叹剑法的杀式，向$n随手击去．．．\n" NOR, me,target);

	pros = target->query_temp("protectors");
	target->delete_temp("protectors");

	target->add_temp("is_unconcious",1);	// NO DODGE,NO PARRY. NO EXT FUNCTION IN COMBATD.... :( annie 
	target->add_temp("buff/no_abs",1);		// IGNORE IRON-CLOTH
	k = target->query("resistance/kee");
	l = target->query_temp("resistance/kee");
	target->set("resistance/kee",0);
	target->set_temp("resistance/kee",0);
	for (i=0; i<3;i++)		// counter
	   	COMBAT_D->do_attack(me,target, TYPE_REGULAR,me->query("gender") == "女性"?msg3[i]:msg4[i]);
	target->set("resistance/kee",k);
	target->set_temp("resistance/kee",l);
	target->add_temp("is_unconcious",-1);	// NO DODGE,NO PARRY. NO EXT FUNCTION IN COMBATD.... :( annie 
	target->add_temp("buff/no_abs",-1);		// IGNORE IRON-CLOTH

	target->set_temp("protectors",pros);

	weapon = me->query_temp("weapon");

	if (me->query("gender") == "女性")
	{
		message_vision(HIR BLK"\n愿作张女引，流悲绕君堂；君堂严且密－－\n" NOR, me,target);
		message_vision(BLU"　　　$N收式而立，手中"+weapon->name()+BLU"斜斜指向地面．．．\n" NOR, me,target);
		message_vision(HIR BLK"　　　　　　　　　　　　　　　　－－绝调徒飞扬！\n" NOR, me,target);
		message_vision(RED"　　　　　　　"+weapon->name()+RED"迸裂为千点寒光，密密的向$n覆去！\n" NOR, me,target);
	}
	else
	{
		message_vision(HIR BLK"\n凄狂为谁？雁过无痕，\n" NOR, me,target);
		message_vision(BLU"　　$N收式而立，手中"+weapon->name()+BLU"斜斜指向地面．．．\n" NOR, me,target);
		message_vision(HIR BLK"　　　——魔障千重　总　难　休。\n" NOR, me,target);
		message_vision(RED"　　　　"+weapon->name()+RED"迸裂为千点寒光，密密的向$n覆去！\n" NOR, me,target);
	}


	i = weapon->query("weapon_prop/damage");
	i *= 10;
	for (j=0;j<i;j++)	// loop 1500-,不过会perform duanchang的NPC极稀有,应不会占用太多时间.
		if (random(target->query("combat_exp")) < random(me->query("combat_exp")) )
			k += 1 + random(10);	// 1 - 10
			
	message_vision(YEL"\n寒光一闪而没，刹那间已有"+chinese_number(k)+YEL"片"+weapon->name()+YEL"的碎片射进$n身体。\n" NOR, me,target);
	target->receive_wound("kee",k);
    COMBAT_D->report_status(target);

	weapon->unequip();
	if(weapon->query("owner"))
	{
		weapon->set("orig_name", weapon->query("name"));
		weapon->set("weapon_prop/damage",1);
	}
	else
		weapon->set("weapon_prop",0);
	me->reset_action();
	weapon->set("name","粉碎的" + weapon->query("name")+"残片");
	weapon->set_temp("apply/long",({"这是一堆"+ weapon->query("name")+"\n。"}));
	weapon->set("item_damaged", 1);
	weapon->set("value",0);
	weapon->move(environment(me));
	weapon->save();

	i = 0;

	me->perform_busy(2);

	return 1;
}


