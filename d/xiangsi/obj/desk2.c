
#include <ansi.h>
inherit ITEM;
int do_put(object me,object obj,object  dest);

void create()
{
	set_name("妆台", ({"妆台","台","desk","table"}) );
	set_weight(500);
	set_max_encumbrance(850);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","on");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("cat",1);
		set("long", "一张小小的黄梨木妆台，妆台上趴着一只正在打呼噜的小猫咪。\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }

void init()
{
	add_action("do_putitem","put");
}

int do_putitem(string arg)
{
	object me = this_player(),dest=this_object();
	string target, item;
	object obj, *inv, obj2;
	int i, amount;

	if(!arg) return notify_fail("你要将什麽东西放进哪里？\n");

	if( sscanf(arg, "%s in %s", item, target)!=2 )
		return notify_fail("你要给谁什麽东西？\n");

	if (present(target,environment(me)) != dest)
		return 0;

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
				if (do_put(me, obj2, dest))
				{
					obj->set_amount( (int)obj->query_amount() - amount );
					return 1;
				}		
				if (obj2) destruct(obj2);
				return 0;
		}
	}

	if(item=="all")
	{
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
	mixed *info;
	object cat;
	info = filter_array(call_out_info(), (: $1[0]==$2 :), obj);
	
    if((int) obj->query("no_drop") ||(int) obj->query("no_get")||obj->query("lore"))
                return notify_fail("你不可以这么做。\n");
	if (obj->is_container())
		return notify_fail("你不能把容器放在另一个容器里。\n");	

	if( obj == dest)
			return notify_fail("你不可以这么做。\n");
	
	if(dest->is_closed())
		return notify_fail("你要先把" + dest->name() + "打开。\n");

	container_size = 2;

	if(sizeof(all_inventory(dest)) >= container_size)
	{
		tell_object(me,dest->name() + "里面最多只能放" + chinese_number(container_size) +
				"件物品。\n");
		return 1;
	}
	
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

		if (obj->query("name") == "烤大老鼠肉" && query("cat") == 1)
		{	
			cat=present("catty",dest);
			if (me->query_temp("annie/xiangsi_master") >= 3 && cat)
			{
				set("long", "一张小小的黄梨木妆台。\n");
				destruct(cat);
				set("cat",0);
				message_vision(CYN"小猫抽了抽鼻子睁开眼睛，用爪子揉了揉耳朵。\n"NOR,me);
				message_vision(CYN"小猫抬眼看了看$N，叼起烤大老鼠肉＂哧溜＂一声窜了开去。\n"NOR,me);
				me->set_temp("annie/xiangsi_master",4);
				message_vision(CYN"\n你看到原本小猫趴着的地方似乎有个压得扁扁的小纸袋．．．\n\n"NOR,me);
				cat=new(__DIR__"drug");
				cat->move(dest);
				destruct(obj);
			}
		}

		return 1;
	}
	else return 0;
}


/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/
