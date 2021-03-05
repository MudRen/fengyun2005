// annie 07.2003 && Silencer @ FY4 workgroup. Oct.2004


#include <ansi.h>
inherit F_ABILITY;

int main(object me, string arg)
{
	string *lists,temp,id;
	
	int i, a_num, saved_quest, saved_quest1, saved_ability, learned_ability;
	object ob;
	string arg1, myclass;
	
	if (wizardp(me))
	{
		if(arg && sscanf(arg, "-%s", id) == 1)
		{
			ob = present(id, environment(me));
			if (!ob) ob = find_player(id);
			if (!ob) ob = find_living(id);
			if (!ob) return notify_fail("你要察看谁的能力？\n");			
		} else
			ob = me;					
	} else
		ob = me;

	saved_quest = ob->query("saved_quest")/60;
	saved_quest1 = (ob->query("saved_quest")*100/60)%100;
	saved_ability = saved_quest/100;			// 100个Quest算一个ability
	learned_ability = ob->query("learned_ability");
	
	if (arg && ob==me)
	{
		if (!sscanf(arg,"+ %d",a_num))
			return notify_fail("提高能力的格式：ability + 能力名称 \n");
		if (a_num <1 || a_num > 20)
			return notify_fail("没有此代码的能力（请输入1-20）\n");
		if (F_LEVEL->get_level(ob->query("combat_exp"))< 80)
			return notify_fail("提高能力至少需要经验等级80。\n");
			
		if (a_num<16)
		{
			arg1 = g_ability[a_num-1];
			
			if (!check_ability_improve(ob, arg1,0))
				return notify_fail("你的经验等级还不足以掌握更高的该项能力。\n");
			if (!deduct_ability_cost(ob, arg1,0))
				return notify_fail("你没有足够的能力点储蓄来提高此项能力。\n");
			improve_ability( ob, arg1, 0);
			tell_object(ob, "该第"+ (a_num) + "能力提高完毕。\n");
			return 1;
		}
		
		if (!stringp(myclass = ob->query("class")))
			return notify_fail("你无门无派，如何能够领会门派武功的精髓？\n");
		
		if (!arrayp(m_ability[myclass]))
		{
			return notify_fail("OOPS，你所在的门派的特色还没写好耶。\n");
		} else
		{	
			arg1 = m_ability[myclass][a_num-16];
			if (!check_ability_improve(ob, arg1,1))
				return notify_fail("你的经验等级还不足以掌握更高的该项能力。\n");
			if (!deduct_ability_cost(ob, arg1,1))
				return notify_fail("你没有足够的能力点储蓄来提高此项能力。\n");
			improve_ability( ob, arg1, 1);
			tell_object(ob, "该第"+ (a_num) + "能力提高完毕。\n");
		}
				
		return 1;
	}
	
	write(WHT"\t　　		基本能力进阶\n"NOR);
	write(HIR BLK"────────────────────────────────\n"NOR);
	write(WHT    "序号		功效			  等级	    	升级点数\n"NOR);	
	write(HIR BLK"────────────────────────────────\n"NOR);
	
	for(i=0; i<sizeof(g_ability); i++)
		write(WHT + (i+1)+ NOR"\t"+ get_ability_info(ob, g_ability[i],0) + NOR);		
	write(HIR BLK"────────────────────────────────\n"NOR);

		
	write(WHT"\t　　		门派能力进阶\n"NOR);
	write(HIR BLK"────────────────────────────────\n"NOR);
	
	if (!stringp(myclass = ob->query("class")))	write("无门无派无特色。\n");
//	else if (ob->query("betrayer"))
//		write("你有叛师前科，无法领会新门派的精髓。\n");
	else if (!arrayp(m_ability[myclass]))
		write("OOPS，你所在的门派的特色还没写好耶。\n");
	else
		for(i=0; i<5; i++)
			write(WHT + (i+16)+ NOR"\t"+ get_ability_info(ob, m_ability[myclass][i],1) + NOR);		

	write(HIR BLK"────────────────────────────────\n"NOR);

	write("你现在总共完成了"YEL+ saved_quest + "."+ saved_quest1+ NOR"个能力Quest，合计"WHT + saved_ability + NOR"点能力。
你已经用去了" RED+ learned_ability +NOR "点能力，还剩下"HIG+ (saved_ability-learned_ability) + NOR"点可供分配。\n");

	write(HIR BLK"────────────────────────────────\n"NOR);
	
	return 1;
}


int help(object me)
{
write(@HELP

[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	ability [0m
[0;1;37m────────────────────────────────[0m   

ability 	让你知道你目前所学过的一切能力，
ability + n	提高第ｎ项能力的级别。

能力是风云2005中除经验值、技能值以外提高自身的一个重要途径。
相同经验等级的，能力高的人会有更多的气血，造成更大的伤害力，
或者可以有更高的学习效率。如何合理分配能力点是成为高手的一
大基本要求。

当你的经验级别到达80时，就可以提高自身的各项能力了！
输入ａｂｉｌｉｔｙ就可以看到一个清晰的列表。分两大类，第一
类共有１５项，所有门派都可以修习，大多是提高基本属性的；第
二类有五项，属于门派武功的精髓所在，不同门派各有特色。

每项能力共分十级，每级的功效都有详细说明。修习第一类能力的
要求为等级80，修习第二类能力的要求为等级100。一开始的时候，
你也许最多只能修习到第二级，随着你本身等级的提高，经验每增
长五级便可以多修习一个能力级别。

该修习什么呢？这就是由各个不同门派的特点或者个人喜好所决定
了。如果你想在战斗中持久，就多提高些增长精气神的能力，如果
你要提高杀伤力，就提高些力量，如果你是利用法术的门派，那么
提高才智可以增加命中率，或者多加些法力。。。。

修习能力的点数从哪里来？很简单，也是从完成天机老人的Quest中
得到。当你的经验等级达到80时，可以设定一个参数
		set ability 1
在此情况下，Quest将不再增加你的经验值，而是转入能力点中储存
起来，每100个Quest可以转化为一个能力点供你分配。当你想继续
提高经验时，只需要 set ability 0 就可以了。

注意，不作分配的ABILITY点数最多只能储存6点，超过6点后Quest
奖励将自动分配到经验上。

[0;1;37m────────────────────────────────[0m  
HELP
    );

    return 1;
}
 
