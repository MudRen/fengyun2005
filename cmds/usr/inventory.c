//inventory.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int i, n;
	object *inv, ob, *inv_shown;
	string msg;
	
	if( wizardp(me) && arg ) {
		ob = find_player(arg);
		if( !ob ) ob = find_living(arg);
		if( !ob ) ob = present(arg, environment(me));
	}

	if( !ob ) ob = me;

	inv = all_inventory(ob);
	n = sizeof(inv);
	if( !n ) {
		write((ob==me)? "目前你身上没有任何东西。\n"
			: ob->name() + "身上没有携带任何东西。\n");
		return 1;
	}
	inv_shown = inv[0..26];
	
	msg = "%s身上带著下列这些东西(负重 %d%%, 携带量 %d/26 )：";
	if (sizeof(inv)>26)
		msg += HIR"\n已超过可携带最大数14，请尽快减少，以免遗失物品！！"NOR"\n%s\n";
		else 
		msg += "\n%s\n";
	
//	printf("%s身上带著下列这些东西(负重 %d%%, 携带量 %d/15 )：\n%s\n",
	printf(msg,
		(ob==me)? "你": ob->name(),
		(int)ob->query_encumbrance() * 100 / (int)ob->query_max_encumbrance(),
		n,
		implode(map_array(inv_shown, "inventory_desc", this_object()), "\n") );

	return 1;
}

string inventory_desc(object obj) {
	string str, desc;
	object me, left, right;

	return sprintf("  %s%s", obj->query("equipped")? HIC "√" NOR: "  ",
			obj->short());
}

int help (object me)
{
        write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	inventory[0m
[0;1;37m────────────────────────────────[0m   

可列出你(玩家)目前身上所携带的所有物品。
一个玩家可携带的正常物品数为14，
系统在玩家携带超过14件时将不显示最底下的物品，同时发出警告，
系统不允许玩家携带超过17件的物品。
 
注 : 此指令可以 " i " 代替。

[0;1;37m────────────────────────────────[0m 
 
HELP
);
        return 1;
}
