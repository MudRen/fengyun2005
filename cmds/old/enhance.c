// enhance.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int points, to_pay,to_pay_exp;
	int enhanced = 0, price = 1;
	int base_exp = 50000;
	int base_pot = 10000;
	string msg, addthis;

	if( !arg ) return notify_fail("你要提高哪一项属性？\n");
	
//	points = me->query("potential") - me->query("learned_points");
	points = me->query("enhance/pot_save");
	
//	if (me->query("enhance/num")>10)
//		return notify_fail("你提高属性的次数不能超过10次。\n");
	
	if( (int) me->query("combat_exp") < 4000000 )
		return notify_fail("你的经验太低，还不能够提高任何属性。\n");
	
	if( points < 30000 )
		return notify_fail("你存入(enhancesave)的潜能不够提高任何属性。\n");

	if(me->is_busy())
		return notify_fail("你上个动作还没完成。\n");

	switch (arg) {
	case "才智" :
	case "caizhi" :
			enhanced =  me->query("enhance/int");
			msg = "才智";
			addthis = "int";
			to_pay= 90000;
			to_pay_exp=400000;
			break;
        case "力量" :
        case "liliang" :
                        enhanced =  me->query("enhance/str");
                        msg = "力量";
                        to_pay= 90000;
			to_pay_exp=400000;
                        addthis = "str";
                        break;         
        case "耐力" :
        case "naili" :
                        enhanced =  me->query("enhance/dur");
                        msg = "耐力";
                        to_pay= 80000;
			to_pay_exp=300000;
                        addthis = "dur";
                        break;
        case "体质" :
        case "tizhi" :
                        enhanced =  me->query("enhance/con");
                        msg = "体质";
                        to_pay= 80000;
			to_pay_exp=300000;
                        addthis = "con";
                        break;
        case "勇气" :
        case "yongqi" :
                        enhanced =  me->query("enhance/cor");
                        msg = "勇气";
                        to_pay= 80000;
			to_pay_exp=300000;
                        addthis = "cor";
                        break;
        case "韧性" :
        case "renxing" :
                        enhanced =  me->query("enhance/fle");
                        msg = "韧性"; 
                        to_pay= 80000;
			to_pay_exp=200000;
                        addthis = "fle";
                        break;
        case "运气" :
        case "yunqi" :
                        enhanced =  me->query("enhance/kar");
                        msg =  "运气";
                        to_pay= 80000;
			to_pay_exp=200000;
                        addthis = "kar";
                        break;
        case "灵性" :
        case "lingxing" :
                        enhanced =  me->query("enhance/spi");
                        msg = "灵性";    
                        to_pay= 30000;
			to_pay_exp=100000;
                        addthis = "spi";
                        break;
        case "魅力" :
        case "meili" :
                        enhanced =  me->query("enhance/per");
                        msg = "魅力";
                        to_pay= 30000;
			to_pay_exp=100000;
                        addthis = "per";
                        break;
        case "速度" :
        case "sudu" :                 
                        enhanced =  me->query("enhance/agi");
                        msg = "速度";
                        to_pay= 30000;
			to_pay_exp=100000;
                        addthis = "agi";
                        break;
        case "气量" :
        case "qiliang" :                    
                        enhanced =  me->query("enhance/tol");
                        msg =  "气量";
                        to_pay= 30000;
			to_pay_exp=100000;
                        addthis = "tol";
                        break;
        case "定力" :
        case "dingli" :
                        enhanced =  me->query("enhance/cps");
                        msg = "定力";
                        to_pay= 30000;
			to_pay_exp=100000;
                        addthis = "cps";
                        break;
        default :
			return notify_fail("没有这个参数。\n");

	}

	if (enhanced>4)
		return notify_fail("你已经不能继续提高"+msg+"了。\n");
	
	enhanced=enhanced? enhanced*2:1;
	
	if (points < to_pay*enhanced) 
		return notify_fail("你存入(enhancesave)的潜能不够提高"+msg+"。\n");
		
	me->add("enhance/" + addthis, 1);
	me->add(addthis, 1);
	me->add("enhance/pot_save",-to_pay*enhanced);
	me->add("combat_exp", -to_pay_exp*enhanced);
	me->add("enhance/num",1);
	write("你的" + msg + "提高了！\n");
	me->start_busy(1);
	return 1;
}

int help(object me)
{
        write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	enhance <自身属性>[0m
[0;1;37m────────────────────────────────[0m           

指令格式 : enhance <人体参数>
这个指令可以让你将存储的潜能（enhancesave）和经验用于提高你
指定的参数。需要经验值大于4M才能使用。

第一次使用：

才智/力量
enhance 力量 让你将90000潜能和400000经验用于提高一点力量。

勇气/耐力/体质
enhance 耐力 让你将80000潜能和300000经验用于提高一点耐力。

运气/韧性
enhance 定力 让你将80000潜能和200000经验用于提高一点运气。

气量/灵性/定力/速度/魅力
enhance 灵性 让你将30000潜能和100000经验用于提高一点灵性。

第N次使用的花费为第一次的2^（N-1）倍。

注意事项：
学完基本技能再使用Enhance，举例来说，如果你的Force是180，体质
是36，利用enhance将体质提高到40，以后即使学了200级force体质也
将只是40。每项属性最多只能提高五次。

如不能输入中文，可用拼音代替。
才智 caizhi	体质 tizhi
灵性 lingxing	魅力 meili
勇气 yongqi	力量 liliang
耐力 naili	韧性 renxing
速度 sudu	气量 qiliang
运气 yunqi	定力 dingli

[0;1;37m────────────────────────────────[0m 

HELP
        );
        return 1;
}
