// annie 6.27.03
// purge pets.

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int check_legit(object ob); 
int purgepets(object me, object obj);

int perform(object me, object target)
{
	int i;
	object env;
	object * inv;

	if(userp(me))
		return notify_fail("你所选用的武功中没有这种必杀技。。\n");

	if( !me->is_fighting())
		return notify_fail("「鬼神破灭」只能对战斗中的对手使用。\n");
	
	message_vision(HIY"\n$N反握左拳平举，右掌虚抱胸前，眉间隐隐泛起一层黑气。" NOR, me);
	message_vision(HIY"\n$N眼中精光陡然大盛，断声喝道："HIR"燹"HIY"！\n\n" NOR, me);
	message_vision(HIY"一道奇异的旋流自$N身边散开，漫过在场的每个人，幻化为七彩异境。\n" NOR, me);
	env = environment(me);
	inv = all_inventory(env);
	for(i=0; i<sizeof(inv); i++) {
		if (check_legit(inv[i])) continue;
		if (!COMBAT_D->legitimate_kill(me, inv[i])) continue;
		purgepets(me, inv[i]);
	}
	if (userp(me))
		me->start_busy(2);
	else
		me->start_busy(1);
	return 1;
}



int purgepets(object me, object obj)
{
	int a=0;
		string *msg = ({
"虹儿","西湖小青","水姑娘","胖天使","江北无言","十方妖灵","小蝶仙","猫依",
});
// 明月清辉,云中雪浅..
// hammer, who add de? *slogan
	if (base_name(obj) == "/obj/npc/solidghost")		// 帝王谷 solidspirit
		a=1;
	if (base_name(obj) == "/obj/npc/wolf")				// 狼山 wolf
		a=2;
	if (base_name(obj) == "/obj/npc/danei")				// 朝廷 alert-guard
		a=3;
	if (base_name(obj) == "/obj/npc/danei_guard")		// 朝廷 alert-guard
		a=3;
	if (base_name(obj) == "/obj/npc/shiwei")			// 朝廷 yin shiwei
		a=4;
	if (base_name(obj) == "/obj/npc/fighter1")			// 朝廷 yue huwei
		a=5;
	if (base_name(obj) == "/obj/npc/huwei")				// 朝廷 yue huwei
		a=5;
	if (base_name(obj) == "/obj/npc/zombie")			// 三清 zombie
		a=6;
	if (base_name(obj) == "/obj/npc/zombie2")			// 三清 zombie
		a=6;
	if (base_name(obj) == "/obj/npc/hell_guard")		// 三清 hell guard
		a=7;
	if (base_name(obj) == "/obj/npc/devil_guard")		// 三清 heaven soldier
		a=7;
	if (base_name(obj) == "/obj/npc/taoist_guard")		// 三清 sq-taoist
		a=8;
	if (base_name(obj) == "/obj/npc/heaven_soldier")	// 三清 sq-taoist
		a=8;
	if (base_name(obj) == "/obj/npc/fire_crane")		// 白云 fire crane
		a=9;

	switch (a)
	{
	case 0:
		return 1;
		break;
	case 1:
		message_vision(WHT"\n一阵悦耳的唱诗声从天籁中传来。\n$N"WHT"头顶上浮现出一个小小光圈，背后长出一对洁白的翅膀。\n$N"WHT"拍拍翅膀，飞上天空不见。\n"NOR,obj);
		obj->move(load_object("/obj/void"));
		obj->die();
		break;
	case 2:
		message_vision(HIG"\n不知哪里传来一阵虚无飘渺的烤肉香气。\n$N"HIG"的肚子中突然传来一阵咕噜噜的响声。\n$N"HIG"可怜兮兮的瞅了你一眼，摇摇尾巴一溜烟的跑掉了。\n"NOR,obj);
		obj->move(load_object("/obj/void"));
		obj->die();
		break;
	case 3:
		message_vision(HIR"\n不远处的一朵彩云中钻出了几个山西土匪。\n山西土匪探头探脑的看着这边，还在叽叽咕咕的商量什么。\n一把鬼头刀飞掷而来不偏不倚的穿过$N"HIR"的胸口，你听到有欢呼声渐渐远去。\n"NOR,obj);
		obj->die();
		break;
	case 4:
		message_vision(HIY"\n天空中照下一道鹅黄色的光芒，对在$N"HIY"身上。\n$N"HIY"忽然抱住肚子上下跳脚，仓皇四望。\n$N"HIY"匆匆忙忙的往一个方向冲去，一边跑一边高叫：洗手间，洗手间！\n"NOR,obj);
		obj->move(load_object("/obj/void"));
		obj->die();
		break;
	case 5:
		message_vision(HIC"\n几声暮鸦的鸣叫从天际传来，$N"HIC"拍了拍自己的头，抬头看了看天空。\n$N"HIC"说道：岳大帅约我见面的时间快到了，我还是先去为妙。\n$N"HIC"辨识了一下方向，急急忙忙的离开了。\n"NOR,obj);
		obj->move(load_object("/obj/void"));
		obj->die();
		break;
	case 6:
		message_vision(HIR BLK"\n不知哪里传来一阵大蒜的气味，一丝一缕的熏着"HIR BLK"$N。\n"NOR,obj);
		obj->die();
		break;
	case 7:
		message_vision(HIB"\n远远的似乎有叫卖红薯的声音。\n$N"HIB"摸摸腰包，自言自语道：这月的工钱还没开给我哩．．．\n$N"HIB"磨了磨牙，哧溜一下化作一道蓝光不见了。\n"NOR,obj);
		obj->move(load_object("/obj/void"));
		obj->die();
		break;
	case 8:
		message_vision(HIR BLK"\n七彩的光华映照着$N"HIR BLK"。\n$N"HIR BLK"摸了摸眉毛，沉思道：与"+msg[random(sizeof(msg))]+"定好的相亲时间快到了罢？"HIR BLK"\n$N"HIR BLK"用手指弹了一下自己的脑门儿，打了一个呼哨。\n"NOR,obj);
		obj->die();
		break;
	case 9:
		message_vision(HIW"\n远处传来几声鹤唳，似是招引同伴的声音。\n$N"HIW"引颈长啸，回望场中一眼，匆忙飞去。\n"NOR,obj);
		obj->die();
		break;
	}

	return 1;
}

int check_legit(object ob) {
	object me, *team, owner;
	me=this_player();
	
	if (ob->is_corpse() || !ob->is_character() || ob==me) return 1;
	
	team=me->query_team();
	if (team) {
		if (member_array(ob,team)!=-1) return 1;
		if (owner=ob->query("possessed"))
		if (member_array(owner,team)!=-1) return 1;
	}
	return 0;
}
