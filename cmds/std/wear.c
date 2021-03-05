// wear.c

#include <ansi.h>

inherit F_CLEAN_UP;

int do_wear(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	int i, count;

	if( !arg ) return notify_fail("你要穿戴什麽？\n");

	if(arg=="all") {
		inv = all_inventory(me);
		for(count=0, i=0; i<sizeof(inv); i++) {
			if( inv[i]->query("equipped") ) continue;
			if(do_wear(me, inv[i]) ) count ++;
		}
	if (!count)
		write("能穿的都穿上了。。。。\n");
		return 1;
	}

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");

	if( ob->query("equipped") )
		return notify_fail("你已经穿戴着了。\n");

	return do_wear(me, ob);
}

int do_wear(object me, object ob)
{
	string str;

	if( ob->query("female_only")
	&&	(string)me->query("gender") != "女性" )
		return notify_fail("这是女人的衣饰，你一个大男人也想穿戴，羞也不羞？\n");

	if( ob->query("male_only")
	&&	(string)me->query("gender") == "女性" )
		return notify_fail("这是大男人的衣物，你一个女人也想穿戴？还是算了吧！\n");

	if (userp(me)) {
		if (ob->query("level_required"))
		if (ob->query("level_required") > F_LEVEL->get_level(me->query("combat_exp")))
			return notify_fail("你的实战经验等级太低，还不能穿戴此衣物（需"
				+ ob->query("level_required")+"级）\n");
		
		if (ob->query("strength"))
		if (ob->query("strength")>me->query("str"))
			return notify_fail("你不够强壮，不适合穿这件护甲。\n");
		
		if (ob->query("agility"))
		if (ob->query("agility")>me->query("agi"))
			return notify_fail("你不够敏捷，穿了这件护甲会举步维艰的。\n");	
	}
		
	if( ob->wear() ) {
		if( !stringp(str = ob->query("wear_msg")) )
			switch( ob->query("armor_type") ) {
				case "cloth":
				case "armor":
				case "boots":
					str = YEL "$N穿上一" + ob->query("unit") + "$n。\n" NOR;
					break;
				case "head":
				case "neck":
				case "wrists":
				case "finger":
				case "hands":
					str = YEL "$N戴上一" + ob->query("unit") + "$n。\n" NOR;
					break;
				case "waist":
					str = YEL "$N将一" + ob->query("unit") + "$n"YEL"绑在腰间。\n" NOR;
					break;
				default:
					str = YEL "$N装备$n。\n" NOR;
			}
//		message_vision(str, me, ob);
		me->set_temp("timer/switch_equip",time());
		F_EQUIP->selective_message(str,me,ob,"equip_msg");
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
	
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	wear all | <装备名称>[0m
[0;1;37m────────────────────────────────[0m   

这个指令让你装备某件防具。

注意：即使在战斗中甚至忙乱状态下你都可以执行此指令，但是一心难以
	二用，在执行此指令的回合中招架和攻击力会有所下降。
	
你可以使用set来屏蔽自己或他人装备/脱卸的信息
	set equip_msg <1，2 或者 3>	
此参数的目的是为了减少频繁的穿戴脱卸刷屏。如果设为１，你将看不到
自己装备／去除武器的信息；如果是２，你将看不到别人装备／去除武器
的信息；如果是３，则两个都看不到。为节省系统资源，新人登陆时自动
设为2。

其他相关指令: remove | wield | unwield

[0;1;37m────────────────────────────────[0m    
HELP
    );
    return 1;
}
