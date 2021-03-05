// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
    	string msg,id;
    	int lvl, ap, dp;
		object ob,*inv;
      	
    	if (me->query("class") != "moon")
        	return notify_fail("只有皓月宫中人才能使用「他心移物」。\n");
        	
    	if((int)me->query_skill("heart-listening",1) < 40 )
        	return notify_fail("「他心移物」需要至少40级的幻念聆音！\n");

    	if((int)me->query("mana") < 300 )
        	return notify_fail("「他心移物」需要300点法力！\n");

		id = me->query("marry");
		if (!id || !(target = find_player(id)))
        	return notify_fail("没有人与你心念相通，无法使用「他心移物」(set telepathy_to 玩家ID)。\n");

		if (!target->query("env/telepathy"))
        	return notify_fail("此人不愿意接收来自「他心移物」的物品(set telepathy 1)。\n");

    	me->add("mana", -300);  
    	msg = HIG "$N"HIG"双手平托，蕴法行诀，一层浅碧色的光芒在$N"HIG"手中出现。\n\n" ;
		inv = all_inventory(me);
		
		if (sizeof(inv) >= 14)
		{
	    	msg += HIG "光芒闪动了一下就消失了（你身上的东西太多了）。\n\n" ;
			message_vision(msg+NOR,me);
		}
		message_vision(msg+NOR,me);

		tell_object(target,HIG"你心中忽然一动，似乎你最亲密的人有什么东西要给你。\n"NOR);
		
		seteuid(getuid());
		ob = new("/obj/item/magicbag");
		ob->set_max_encumbrance(me->query_skill("heart-listening",1)
			*me->query_skill("heart-listening",1));	// 1600 - 40000,bag 1000,basket 8000,mugui 80000.
		ob->move(me);
		call_out("do_trans",10,me,target,ob);
        return 1;
}

void do_trans(object me,object target,object ob)
{
	object *inv;
	if (!ob || !me)
		return;
	if (!target)
	{
		tell_object(me,"你突然感觉不到与你相通的心念了，还是快些终止这个法术吧。\n");
		return ;
	}
	inv = all_inventory(target);
	if (environment(ob) != me || sizeof(inv) >= 14)
	{
		tell_object(me,"你心下一阵不安，似乎有哪里出了差错（对方身上的东西太多了？）\n");
		return ;
	}
	message_vision(HIG"空气中突起一阵波动，$N"HIG"手中浅碧色的光芒慢慢消失．．．\n"NOR,me);
	ob->move(target);
	message_vision(HIG"空气忽然开始水波般振动，只听＂啪嗒＂一声，有什么掉进$N"HIG"怀里。\n"NOR,target);
	return ;
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
