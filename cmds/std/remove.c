// remove.c

#include <ansi.h>
inherit F_CLEAN_UP;

int 	do_remove(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	int i, count;

	if( !arg ) return notify_fail("你要脱掉什麽？\n");

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if (do_remove(me, inv[i])) count++;
		if (!count)
			write("你没有装备任何衣物。\n");
		return 1;
	}

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");
	return do_remove(me, ob);
}

int do_remove(object me, object ob)
{
	string str;

	if( (string)ob->query("equipped")!="worn" )
		return notify_fail("你并没有装备这样东西。\n");

	if( ob->unequip() ) {
		str = ob->query("unequip_msg")? ob->query("unequip_msg") : ob->query("unwield_msg");
		if( !stringp(str) )
			switch(ob->query("armor_type")) {
				case "cloth":
				case "armor":
				case "surcoat":
				case "boots":
					str = YEL "$N将$n"YEL"脱了下来。\n" NOR;
					break;
				case "bandage":
					str = YEL "$N将$n"YEL"从伤口处拆了下来。\n" NOR;
					break;
				default:
					str = YEL "$N卸除$n"YEL"的装备。\n" NOR;
			}
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
[0;1;36m指令格式 : 	remove all | <物品名称>[0m
[0;1;37m────────────────────────────────[0m   
	
这个指令让你脱掉身上某件防具。

注意：即使在战斗中甚至忙乱状态下你都可以执行此指令，但是一心难以
	二用，在执行此指令的回合中招架和攻击力会有所下降。
	
你可以使用set来屏蔽自己或他人装备/脱卸的信息
	set equip_msg <1，2 或者 3>	
此参数的目的是为了减少频繁的穿戴脱卸刷屏。如果设为１，你将看不到
自己装备／去除武器的信息；如果是２，你将看不到别人装备／去除武器
的信息；如果是３，则两个都看不到。为节省系统资源，新人登陆时自动
设为2。

其他相关指令: wear | wield | unwield

[0;1;37m────────────────────────────────[0m   
 
HELP
    );
    return 1;
}
 
