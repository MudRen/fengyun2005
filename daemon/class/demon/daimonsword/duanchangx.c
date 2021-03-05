/* 娇嗔浅笑俱因痴，断肠旧事知为谁？
两地相隔的愁思，生死永诀的别离，终于化作了这断肠绝灭的一剑。
甚么山盟海誓，甚么地老天荒，终是抵不住一次阴阳相隔的午夜梦回。
剑在人亦在，剑碎人断肠！——　三叹剑法·断肠绝灭式,annie 07.01.03
*/

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

	string *msg=     ({
	HIW"——明月照高楼，含君千里光；"NOR,
	HIW"　　巷中情思满，断绝孤妾肠。\n"NOR,
	HIW"\n　　－－悲风荡帷帐，瑶翠坐自伤；\n"NOR,
	WHT"　　　　妾心依天末，思与浮云长。\n"NOR,
	WHT"\n　　　　－－怨歌视秋草，幽叶岂再扬？\n"NOR,
	WHT"　　　　　　暮兰不待岁，离华能几芳？\n"NOR,
	HIR BLK"　　　　　　　　愿作张女引，流悲绕君堂；\n"NOR,
	});

	string *msg3=     ({
	HIW"明月照高楼，含君千里光，巷中情思满，断绝孤妾肠。\n"NOR,
	WHT"悲风荡帷帐，瑶翠坐自伤，妾心依天末，思与浮云长。\n"NOR,
	WHT"怨歌视秋草，幽叶岂再扬？暮兰不待岁，离华能几芳？\n"NOR,
	HIR BLK"愿作张女引，流悲绕君堂；君堂严且密－－\n"NOR,
	});

	string *msg2=     ({
	HIR BLK"重来云山，愁情盈袖，满目皆秋。"NOR,
	HIR BLK"飘渺仙缘，独遗梦影，浮生寻遍，云散风流。\n"NOR,
	HIR BLK"关山千回，历劫又生，看取豪情动九州。\n"NOR,
	WHT"今逝矣，纵天下事了，物非人旧。\n"NOR,
	WHT"一剑来去苍茫，枉平生笑傲逍遥游。\n"NOR,
	WHT"嗟逝者如水，侬情随风，悲歌忍继，此恨长留。\n"NOR,
	HIW"凄狂为谁？\n"NOR,
});

int perform(object me, object target) 
{
	int i, skill,j,k ,l;
	object weapon,ob;
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

		if (me->query("max_force") < 20)
 			return notify_fail("你现在毫无怨气杀机，如何使得出"HIR BLK"『断肠绝灭式』"NOR"？\n");

		me->add("max_force",-20);	// *bud
	}

	
	message_vision(HIR BLK"\n$N缓缓闭上眼睛，提剑向$n行去，全然不顾$n急乱如雨的攻击。\n" NOR, me,target);
	message_vision(HIY"\n$n见势一惊，但仍不愿错过机会，向$N全力攻出！\n" NOR, me,target);

	j = target->query_busy();
	target->stop_busy();

	me->add_temp("is_unconcious",1);	// NO DODGE,NO PARRY. NO EXT FUNCTION IN COMBATD.... :( annie 
	me->add_temp("buffup/no_abs",1);		// IGNORE IRON-CLOTH
	k = me->query("resistance/kee");
	l = me->query_temp("resistance/kee");
	me->set("resistance/kee",0);
	me->set_temp("resistance/kee",0);
	for (i=0; i<4+random(5);i++)		// PFM前先硬受4-8 normal hit
	   	COMBAT_D->do_attack(target,me, TYPE_REGULAR);
	me->set("resistance/kee",k);
	me->set_temp("resistance/kee",l);
	me->add_temp("buffup/no_abs",-1);		
	me->add_temp("is_unconcious",-1);
	// 死了没?...不管死了没有,都要先打过再说...
	// 已经僵尸化了*snicker

	target->start_busy(j+1);
	me->stop_busy();

	message_vision(HIC"\n$n一轮攻势之下，$N伤痕遍体，但依然屹立不倒。\n$n正待再度击出，却见$N已近身前，慢慢睁眼，提起掌中长剑，眼里毫无生机！\n" NOR, me,target);
	message_vision(HIC"\n$N手中的剑在空中划了一个弯曲的半弧，向无措的$n落去．．．\n\n" NOR, me,target);

	target->add_temp("is_unconcious",1);	// NO DODGE,NO PARRY. NO EXT FUNCTION IN COMBATD.... :( annie 
	target->add_temp("buffup/no_abs",1);		// IGNORE IRON-CLOTH
	k = target->query("resistance/kee");
	l = target->query_temp("resistance/kee");
	target->set("resistance/kee",0);
	target->set_temp("resistance/kee",0);
	for (i=0; i<7;i++)		// counter
	   	COMBAT_D->do_attack(me,target, TYPE_REGULAR,me->query("gender") == "女性"?msg[i]:msg2[i]);
	target->set("resistance/kee",k);
	target->set_temp("resistance/kee",l);
	target->add_temp("is_unconcious",-1);	// NO DODGE,NO PARRY. NO EXT FUNCTION IN COMBATD.... :( annie 
	target->add_temp("buffup/no_abs",-1);		// IGNORE IRON-CLOTH

	weapon = me->query_temp("weapon");

	if (me->query("gender") == "女性")
	{
		message_vision(HIR BLK"\n　　　　君堂严且密－－\n" NOR, me,target);
		message_vision(BLU"\n　$N收式而立，手中"+weapon->name()+BLU"斜斜指向地面．．．\n" NOR, me,target);
		message_vision(HIR BLK"\n　　　　　　　　　　　　　　　　　－－绝调徒飞扬！\n" NOR, me,target);
		message_vision(RED"\n　　　　　　　"+weapon->name()+RED"迸裂为千点寒光，密密的向$n覆去！\n\n" NOR, me,target);
	}
	else
	{
		message_vision(HIW"\n雁过无痕，\n" NOR, me,target);
		message_vision(BLU"\n　$N收式而立，手中"+weapon->name()+BLU"斜斜指向地面．．．\n" NOR, me,target);
		message_vision(HIW"\n　　——魔障千重　总　难　休。\n" NOR, me,target);
		message_vision(RED"\n　　　　"+weapon->name()+RED"迸裂为千点寒光，密密的向$n覆去！\n\n" NOR, me,target);
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

	obn = target->name();

	if (target->query("kee") < 1)
	{
		i = 1;
		message_vision(CYN"\n$n用难以置信的眼光看着$N，似乎不敢相信世界上还有这种打法！\n" NOR, me,target);
		message_vision(CYN"$n喉头咯咯作响，似有千言万语，却再一个字也吐不出来。"NOR, me,target);
		target->die();				// 
	}

	if (me->query("kee")<1 || me->query("gin") < 1 || me->query("sen") < 1)	// misson accomplished,可以放心的去了..
	{
		if (!i)
		{
			message_vision(CYN"\n$N再也站立不稳，缓缓的倒下。\n" NOR, me,target);
			message_vision(CYN"临去之时，$N依然恨恨的看着"+obn+"，眼底是无比的遗憾。\n"NOR, me);
		}
		else
		{
			message_vision(CYN"$N看着"+obn+"倒下，强运的一口气再也支撑不住。\n" NOR, me);
			message_vision(CYN"$N脸上带着一抹了无遗憾的微笑，缓缓的合上了眼帘。\n"NOR, me);
		}
		me->die();				// 
		return 1;
	}

	if (!i)
	{
		message_vision(CYN"\n$N强运的一口气再也支撑不住，双腿一软，整个人颓然倒下。\n" NOR, me);
		me->unconcious();
	}
	else
	{
		message_vision(CYN"$N看着"+obn+"倒下，强运的一口气再也支撑不住。\n"NOR,me);
		message_vision(CYN"$N脸上带着一抹了无遗憾的微笑，慢慢的软了下去。\n"NOR,me);
		me->unconcious();
	}

	return 1;
}


