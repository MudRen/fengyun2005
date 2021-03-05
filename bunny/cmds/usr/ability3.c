/*	ABILITY2

str/int/comp/agi/karma/con
mana/force/atman
gin/kee/sen

shaolin/lama/legend: con, composure, str, kee/gin/sen 150+

taoist/yinshi: int, karma, agi,  mana/force/atman 50+

huashan/bonze: comp, int, con, mana/force/atman 50+

officer/beggar/wolfmount/moon/knight/fugui agi, str, karma, mana/force/atman 50+

*/

#include <ansi.h>
inherit F_ABILITY;

int main(object me, string arg)
{
	string *lists,temp,id;
	
	int i, a_num, total_count, saved_book, saved_task, saved_count, saved_ability3, learned_ability3, n;
	object ob;
	string arg1, myclass;
	string *done_class = ({"huashan", "official", "beggar", "lama", "shenshui", "fugui", "shaolin", "wolfmount", "knight", "taoist", "yinshi", "bonze", "moon", "legend", "assassin"});
	
	if( wizardp(me) ) {
		if( arg && sscanf(arg, "-%s", id) == 1 ) {
			ob = present(id, environment(me));
			if( !ob ) {
				ob = find_player(id);
			}
			if( !ob ) {
				ob = find_living(id);
			}
			if( !ob ) {
				return notify_fail("你要察看谁的能力？\n");
			}
		} else {
			ob = me;
		}
	} else {
		ob = me;
	}
	n = 300; // 300 task --> 1 ability3
	total_count = ob->query("TASK");
	saved_book = ob->query("marks/book_task");
	saved_task = total_count - saved_book;
	saved_count = saved_task + saved_book/2;
	saved_ability3 = saved_count/n;
	learned_ability3 = ob->query("learned_ability3");
	
	if( arg && ob == me ) {
		if( !sscanf(arg, "+ %d", a_num) ) {
			return notify_fail("提高能力的格式：ability3 + 能力名称 \n");
		}
		if( member_array(ob->query("class"), done_class) != -1 ) {
			if (a_num < 1 || a_num > 10) {
				return notify_fail("没有此代码的能力（请输入1-10）\n");	
			}
		} else {
			if( a_num < 1 || a_num > 6 ) {
				return notify_fail("没有此代码的能力（请输入1-6）\n");
			}
		}
		if( F_LEVEL->get_level(ob->query("combat_exp")) < 40 ) {
			return notify_fail("提高能力至少需要经验等级40。\n");
		}			
		if( !stringp(myclass=ob->query("class")) ) {
			return notify_fail("你无门无派，如何能够领会门派武功的精髓？\n");
		}
		if( !arrayp(m_ability[myclass]) ) {
			return notify_fail("OOPS，你所在的门派的特色还没写好耶。\n");
		} else {	
			arg1 = m_ability3[myclass][a_num-1];
			if( !check_ability_improve(ob, arg1, 3) ) {
				return notify_fail("你的经验等级还不足以掌握更高的该项能力。\n");
			}
			if( !deduct_ability_cost(ob, arg1, 3) ) {
					return notify_fail("你没有足够的能力点储蓄来提高此项能力。\n");
			}
			improve_ability(ob, arg1, 3);
			tell_object(ob, "该第"+ (a_num) + "能力提高完毕。\n");
		}
		return 1;
	}

	write(sprintf(WHT"\t　　	TASK %s能力进阶\n"NOR,"/std/char/master"->query_chinese_class(ob->query("class"))));
	write(HIR BLK"────────────────────────────────\n"NOR);
	write(WHT    "序号		功效			  等级	    	升级点数\n"NOR);	
	write(HIR BLK"────────────────────────────────\n"NOR);

//	if( ob->query("betrayer") ) {
//		write("你有叛师前科，无法领会新门派的精髓。\n");
//	}
	if( !stringp(myclass=ob->query("class")) ) {
		write("无门无派无特色。\n");
	} else if( !arrayp(m_ability[myclass]) ) {
		write("OOPS，你所在的门派的特色还没写好耶。\n");
	} else {
		for( i = 0; i < 6; i++) {
			write(WHT + (i+1)+ NOR"\t"+ get_ability_info(ob, m_ability3[myclass][i], 3) + NOR);		
		}
		if( member_array(myclass,done_class) != -1 ) {
			for( i = 6; i < 10; i++) {
				write(WHT + (i+1)+ NOR"\t"+ get_ability_info(ob, m_ability3[myclass][i], 3) + NOR);
			}
		}
	}
	write(HIR BLK"────────────────────────────────\n"NOR);

	write("你现在总共完成了"YEL + saved_task + NOR"个TASK，"YEL + saved_book + NOR"个怜花宝鉴，储存了"YEL + saved_count + NOR"TASK点数。
合计"WHT + saved_ability3 + NOR"点高级能力。
你已经用去了" RED+ learned_ability3 +NOR "点高级能力，还剩下"HIG+ (saved_ability3-learned_ability3) + NOR"点可供分配。\n");

	write(HIR BLK"────────────────────────────────\n"NOR);
	
	return 1;
}


int help(object me)
{
write(@HELP

[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	ability3 [0m
[0;1;37m────────────────────────────────[0m   

ability3 	让你知道你目前所学过的一切能力，
ability3 + n	提高第ｎ项能力的级别。

高级能力是风云中除经验值、技能值以外提高自身的一个重要途径。
相同经验等级的，能力高的人会有更多的气血，造成更大的伤害力，
或者可以有更高的学习效率。如何合理分配能力点是成为高手的一
大基本要求。

修习能力的点数从哪里来？是从TASK中来，每300个TASK点数可以转
化为一个高级能力点供你分配。
每完成一个TASK或者献给段公公两页《怜花宝鉴》可以获得一个点
数。

当你的经验级别到达40时，就可以提高自身的各项能力了！
输入ability3就可以看到一个清晰的列表。不同门派的高级能力是
不同的。目前每个门派共有六项选择，很快将有更多的内容加入。

每项能力共分十级，每级的功效都有详细说明。

该修习什么呢？这就是由各个不同门派的特点或者个人喜好所决定
了。如果你想在战斗中持久，就多提高些增长精气神的能力，如果
你要提高杀伤力，就提高些力量，如果你是利用法术的门派，那么
提高才智可以增加命中率，或者多加些法力。。。。

注：与普通能力ABILITY不同，高级能力中的魔力、法力、内力的提
高并不会增加相应的精气神数值。

[0;1;37m────────────────────────────────[0m  
HELP
    );

    return 1;
}
 
