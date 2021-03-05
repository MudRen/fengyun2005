// drop.c

inherit F_CLEAN_UP;

int do_drop(object me, object obj);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj, *inv, obj2;
	int i, amount;
	string item;
	mixed no_drop;

	if(!arg) return notify_fail("你要丢弃什麽东西？\n");

	if(sscanf(arg, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("你身上没有这样东西。\n");
		if( stringp(obj->query("no_drop")) )
			return notify_fail( (string)obj->query("no_drop") );
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "不能被分开丢弃。\n");
		if( amount < 1 )
			return notify_fail("东西的数量至少是一个。\n");
		
		if( no_drop = obj->query("no_drop") )
			return notify_fail( stringp(no_drop) ? no_drop : "这样东西不能随意丢弃。\n");
				
		if( amount > obj->query_amount() )
			return notify_fail("你没有那麽多的" + obj->name() + "。\n");
		else if( amount == (int)obj->query_amount() )
			return do_drop(me, obj);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			return do_drop(me, obj2);
		}
	}

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			do_drop(me, inv[i]);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(arg, me)))
		return notify_fail("你身上没有这样东西。\n");
	return do_drop(me, obj);
}

int do_drop(object me, object obj)
{
	mixed no_drop;

	if( no_drop = obj->query("no_drop") )
		return notify_fail( stringp(no_drop) ? no_drop : "这样东西不能随意丢弃。\n");

	if (obj->move(environment(me))) {
		if( obj->is_character() )
			message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
		else {
			message_vision( sprintf("$N丢下一%s$n。\n",	obj->query("unit")),
				me, obj );
			me->save();
			if( (int) obj->query("value") < 4 && !obj->value() 
				&& !obj->query("dynamic_quest") ) {
				write("因为这样东西并不值钱，所以人们并不会注意到它的存在。\n");
				destruct(obj);
			}
		}
		return 1;
	}
	return 0;
}

int help(object me)
{
	write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	drop <物品名称>[0m
[0;1;37m────────────────────────────────[0m   
 
这个指令可以让你丢下你所携带的物品。

相关指令：get

[0;1;37m────────────────────────────────[0m   
 
HELP
    );
    return 1;
}
 
