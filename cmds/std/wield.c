// wield.c

inherit F_CLEAN_UP;

int do_wield(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	int i, count;

	if( !arg ) return notify_fail("你要装备什麽武器？\n");
	
	if(arg=="all") {
		inv = all_inventory(me);
		for(count=0, i=0; i<sizeof(inv); i++) {
			if( inv[i]->query("equipped") ) continue;
			if(do_wield(me, inv[i]) ) count ++;
		}
		if (!count)
			write("能拿的都拿上了。。。。\n");			
		return 1;
	}
	

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");

	if( ob->query("equipped") )
		return notify_fail("你已经装备著了。\n");

	return do_wield(me, ob);
}

int do_wield(object me, object ob)
{
	string str;

	if (ANNIE_D->check_buff(me,"disarmed"))
		return notify_fail("你手臂酸麻，一时无法拿起这件武器。\n");
		
	if (userp(me)) {
		if (ob->query("class"))
		if (ob->query("class")!= me->query("class"))
			return notify_fail("你的门派武功不适合用这件武器。\n");
		
		if (ob->query("experience"))
		if (ob->query("experience")>me->query("combat_exp"))
			return notify_fail("你的实战经验太低，发挥不了这件武器的威力。\n");
		
		if (ob->query("level_required"))
		if (ob->query("level_required") > F_LEVEL->get_level(me->query("combat_exp")))
			return notify_fail("你的实战经验等级太低，发挥不了这件武器的威力（需"
				+ ob->query("level_required")+"级）\n");
		
		if (ob->query("strength"))
		if (ob->query("strength")>me->query_str())
			return notify_fail("你的臂力太弱，举不起这件武器。\n");
		
		if (ob->query("agility"))
		if (ob->query("agility")>me->query_agi())
			return notify_fail("你不够敏捷，无法将这件武器运转如意。\n");
			
		if (ob->query("score"))
		if (ob->query("score")<me->query("score"))
			return notify_fail("这件武器太过阴毒，你这样有身份的人不适合用吧。\n");	
	}
	
	if (ob->query("item_damaged") && ob->query("weapon_prop/damage") < 5)
		return notify_fail("这件武器已经严重损坏，不合再用。\n");
		
	if( ob->wield() ) {
		if( !stringp(str = ob->query("wield_msg")) )
			str = "$N装备$n作武器。\n";
//		message_vision(str, me, ob);
		F_EQUIP->selective_message(str,me,ob,"equip_msg");
		ob->query("equip_fun");
		me->set_temp("timer/switch_equip",time());	
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
	
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	wield all | <装备名称>[0m
[0;1;37m────────────────────────────────[0m   

这个指令让你装备某件物品作武器, 你必需要拥有这样物品.

注意：即使在战斗中甚至忙乱状态下你都可以执行此指令，但是一心难以
	二用，在执行此指令的回合中招架和攻击力会有所下降。
	
你可以使用set来屏蔽自己或他人装备/脱卸的信息
	set equip_msg <1，2 或者 3>	
此参数的目的是为了减少频繁的穿戴脱卸刷屏。如果设为１，你将看不到
自己装备／去除武器的信息；如果是２，你将看不到别人装备／去除武器
的信息；如果是３，则两个都看不到。为节省系统资源，新人登陆时自动
设为2。
				
其他相关指令: unwield | wear | remove

[0;1;37m────────────────────────────────[0m 
 
HELP
    );
    return 1;
}
