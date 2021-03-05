// put.c

#define MAX_ITEM 25

inherit F_CLEAN_UP;


int do_put(object me, object obj, object dest);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
	object obj, dest, *inv, obj2;
	int i, amount;

	if(!arg) return notify_fail("你要将什麽东西放进哪里？\n");

	if( sscanf(arg, "%s in %s", item, target)!=2 )
		return notify_fail("你要给谁什麽东西？\n");

	dest = present(target, me);
	if( !dest || living(dest) ) dest = present(target, environment(me));
	if( !dest || living(dest) )
		return notify_fail("这里没有这样东西。\n");

	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("你身上没有这样东西。\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "不能被分开。\n");
		if( amount < 1 )
			return notify_fail("东西的数量至少是一个。\n");
		if( amount > obj->query_amount() )
			return notify_fail("你没有那麽多的" + obj->name() + "。\n");
		else if( amount == (int)obj->query_amount() )
			return do_put(me, obj, dest);
		else {
				obj2 = new(base_name(obj));
				obj2->set_amount(amount);
							obj2->set_name(obj->query("name"),obj->parse_command_id_list());
			obj2->set("long",obj->query("long"));
			obj2->set("unit",obj->query("unit"));

				if (do_put(me, obj2, dest))
				{
					obj->set_amount( (int)obj->query_amount() - amount );
					return 1;
				}		
				if (obj2) destruct(obj2);
				return 0;
		}
	}

	if(item=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if( inv[i] != dest  && !inv[i]->query("no_drop")) 
			do_put(me, inv[i], dest);
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("你身上没有这样东西。\n");
	return do_put(me, obj, dest);
}


int do_put(object me, object obj, object dest)
{
	string prep;
	int container_size;
	
    if((int) obj->query("no_drop") ||(int) obj->query("no_get")||obj->query("lore"))
            return notify_fail("你不可以这么做。\n");
	
	if (!dest->is_container())
			return notify_fail(dest->name()+"不是容器。\n");
		
	if (obj->is_container())
		return notify_fail("你不能把容器放在另一个容器里。\n");	

	if( obj == dest)
			return notify_fail("你不可以这么做。\n");
	
	if(dest->is_closed())
		return notify_fail("你要先把" + dest->name() + "打开。\n");

	container_size = dest->query("size") ? dest->query("size") : MAX_ITEM;
	
	if(sizeof(all_inventory(dest)) >= container_size)
		return notify_fail( dest->name() + "里面最多只能放" + chinese_number(container_size) +
				"件物品。\n");
	
	switch((string)dest->query("prep")) {
		case "on" :
			prep = "放在" + dest->name() + "上";
			break;
		case "under" :
			prep = "放在" + dest->name() + "下";
			break;
		case "behind" :
			prep = "放在" + dest->name() + "后面";
			break;
		case "insdie" :
			prep = "放进" + dest->name() + "里面";
			break;
		default :
			prep = "放进" + dest->name() + "里面";
			break;
	}
	if( obj->move(dest) ) {
		message_vision( sprintf("$N将一%s%s%s。\n",
			obj->query("unit"), obj->name(), prep),
			me );
		if(obj->query("no_drop") || obj->query("no_get")|| obj->query("lore"))
			dest->add("no_give",1);
		return 1;
	}
	else return 0;
}




int help(object me)
{
write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	put <物品名称> in <某容器>[0m
[0;1;37m────────────────────────────────[0m   
 
这个指令可以让你将某样物品放进一个容器。

相关指令：get	drop
 
HELP
    );
    return 1;
}
