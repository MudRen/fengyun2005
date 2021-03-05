// buy.c
#include <ansi.h>
inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string *name, item, targ;
	object ob, owner, buyer;
	int i,num;
	mapping goods;
	
	if( me->is_busy())
		return notify_fail("你上一个动作还没有完成，不能察看物品。\n");
		
	if( !arg || sscanf(arg, "%d from %s", num, targ)!=2 )
		return notify_fail("指令格式：sample <物品序列号> from <某人>\n");

	if( !objectp(owner = present(targ, environment(me))) )
		return notify_fail("你要从谁那儿察看样品？\n");

	if (!(owner->is_vendor())) 
		return notify_fail("此人不做买卖，没东西可察看。\n");

	// 这里我们增加一个可调用的判断，比如说你可以设晚上不开门了，心情不好不做生意了。。。。
	if (!owner->legit_buyer(me))
		return notify_fail(owner->name()+"不愿意与你做交易。\n");
	
	
	if( !mapp(goods = owner->query("vendor_goods")) ) 
		return notify_fail("这儿还没进货。\n");
	
	name = keys(goods);
	if(!sizeof(name))
		return notify_fail("这儿的东西全卖光了。\n");
	
	if ( num > sizeof(name) || num <= 0 )
		return notify_fail("没有这个编号的物品。\n");
	
	if (me->query_temp("timer/sample")+2 > time())
		return notify_fail(owner->name()+"堆笑道：“客官稍候，马上就来招呼！”\n");
	me->set_temp("timer/sample",time());
	
	num = num - 1;
		
	ob = new (name[num]);
	if (!objectp(ob))
		return notify_fail("这个东西好像出了点问题，快点报告巫师吧。\n");	
	
	buyer = this_player();
	buyer->set_temp("checking_goods",1);
	"/cmds/std/look"->look_item(buyer,ob);
	buyer->delete_temp("checking_goods");	
	destruct(ob);
	
		
	return 1;
	
	
}

int help(object me)
{
   write( @HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	sample <某物品序号> from <someone>[0m
[0;1;37m────────────────────────────────[0m   

这一指令让你可以从商贩那里察看货物的信息。

是不是还在为大风丸和虎骨丸到底有什么用处发愁？
是不是还在由于是否应该投资购买一件昂贵的物品？
此命令让你在购买前察看货物的信息。

其中，物品序号为“list”的时候物品前面的编号。

[0;1;37m────────────────────────────────[0m   

HELP
   );
   return 1;
}
