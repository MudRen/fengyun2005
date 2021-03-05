// unwield.c

inherit F_CLEAN_UP;

int do_unwield(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	string str;
	int i, count;

	if( !arg ) return notify_fail("你要放下什麽？\n");

	if (me->is_busy())
		me->set_temp("timer/switch_inbusy",time());

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if (do_unwield(me, inv[i])) count++;
		if (!count)
			write("你没有装备任何武器。\n");
		return 1;
	}

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");
	return do_unwield(me, ob);
}

int do_unwield(object me, object ob){
	string str;

	if( (string)ob->query("equipped")!="wielded" )
		return notify_fail("你并没有装备这样东西作为武器。\n");

	if( ob->unequip() ) {
		if( !stringp(str = ob->query("unwield_msg")) )
			str = "$N放下手中的$n。\n";
		me->set_temp("timer/switch_equip",time());
//		message_vision(str, me, ob);
		F_EQUIP->selective_message(str,me,ob,"equip_msg");
		return 1;
	} else
		return 0;
}

int help(object me)
{
  write(@HELP

[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	unwield all | <物品名>[0m
[0;1;37m────────────────────────────────[0m   
	
这个指令让你放下手中的武器。

注意：即使在战斗中甚至忙乱状态下你都可以执行此指令，但是一心难以
	二用，在执行此指令的回合中招架和攻击力会有所下降。
	
你可以使用set来屏蔽自己或他人装备/脱卸的信息
	set equip_msg <1，2 或者 3>	
此参数的目的是为了减少频繁的穿戴脱卸刷屏。如果设为１，你将看不到
自己装备／去除武器的信息；如果是２，你将看不到别人装备／去除武器
的信息；如果是３，则两个都看不到。为节省系统资源，新人登陆时自动
设为2。

其他相关指令: wield | wear | remove

[0;1;37m────────────────────────────────[0m    
HELP
    );
    return 1;
}
 
