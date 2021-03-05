
#include <ansi.h>
inherit MONEY;
void create()
{
	//set_name("镖银", ({"silver", "ingot", "silver_money"}));
	set_name("镖银", ({"biaoyin"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "silver");
		set("long", "白花花的银子，人见人爱的银子。\n");
		set("unit", "些");
		set("base_value", 1);
		set("base_unit", "两");
		set("base_weight", 37);
		set("illegal",1);
	}
	set_amount(1);
}

void init()
{
	
	add_action("do_deposit","deposit");
	add_action("do_buy","buy");

}

int check_money(object me)
{
	object cash, tencash, gold, silver, coin;
	
	tencash = present("tenthousand-cash_money", me);
	cash = present("thousand-cash_money", me);
	gold = present("gold_money",me);
	silver = present("silver_money",me);
	coin = present("coin_money",me);

	if ( tencash || cash || gold || silver || coin )
		return 1;
	else
		return 0;

}

int do_buy(string arg)
{
	object me;
	string item, targ;
	object ob, owner;
	me = this_player();
	if (!present(this_object(),me))
	{
		return 0;
	}
	if( me->is_busy() || !arg || sscanf(arg, "%s from %s", item, targ)!=2 )
		return notify_fail("指令格式：buy <某物> from <某人>\n");

	if( !objectp(owner = present(targ, environment(me))) )
		return notify_fail("你要跟谁买东西？\n");

	if (!check_money(me))
	{
		tell_object(me,"这些银子是见不得光的，不能就这么拿出来。。。 \n");
		return 1;
	}
	return 0;
}


int do_deposit(string arg)
{
	object me,bankowner;
	object bukuai1,bukuai2,*inv;
	int amount,i;
	string type;
	me = this_player();
	if (!present(this_object(),me))
	{
		return 0;
	}
	if (present("shiyi",environment(me)))
	{
		bankowner = present("shiyi",environment(me));
	}
	if (present("nangong",environment(me)))
	{
		bankowner = present("nangong",environment(me));
	}

	if (present("ying",environment(me)))
	{
		bankowner = present("shiyi",environment(me));
	}

	if (bankowner)

	{
		if(!arg || sscanf(arg, "%d %s", amount, type)!=2 ) {
			return notify_fail("指令格式：deposit <数量> <货币种类>\n");
		}
		if(amount <= 0) {
			return notify_fail("指令格式：deposit <数量> <货币种类>\n");
		}
		if (type == "biaoyin")
		{
			message_vision("$n看着$N手中镖银，忽然抬头对$N笑道：这位"+ RANK_D->query_respect(me) + "很有胆量嘛。\n",me,bankowner);
			message_vision("$n朝暗处拍了拍手。 \n",me,bankowner);
//			bukuai1 = new("/d/fy/npc/bukuai");
//			bukuai2 = new("/d/fy/npc/bukuai");
//			bukuai1->move(environment(me));
//			bukuai2->move(environment(me));
			message_vision(HIR"\n突然从暗中跳出来几个捕快对$N嚷道：胆敢劫镖银！我们埋伏在这里好久了！\n"NOR, me);
			message_vision(HIR"捕快对$N狞笑道：如今人赃俱获，乖乖跟我们走吧！ \n"NOR,me);
			message_vision(HIR"捕快将$N押向大牢。 \n\n"NOR,me);
//			destruct(bukuai1);
//			destruct(bukuai2);
			me->set("vendetta/authority", 1);
			me->move("/d/jinan/laofang2");
			message_vision(HIY"$N被搜空所有的东西，一脚踢进了牢房！\n"NOR,me);
			inv = all_inventory(me);
			for(i=0; i<sizeof(inv); i++) 
			{
                if (inv[i] != this_object())
                {
					if (inv[i]->query("id")=="treasure box")	
						inv[i]->do_qqsave(me);
                	else if (!inv[i]->query("no_drop"))
                		destruct(inv[i]);
                }

			}
			destruct(this_object());
			return 1;
		}
	}
	return 0;
	
}
