// nick.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int gift_points;
	int used_gift_points;
	if( !arg ) return notify_fail("你要分配到哪个参数上？\n");
	gift_points = me->query("gift_points");
	used_gift_points = me->query("used_gift_points");
	if( used_gift_points >= gift_points )
	return notify_fail("你没有参数点。\n");
	if(me->is_busy())
	return notify_fail("你上个动作还没完成。\n");
	switch (arg) {
	case "才智" :
	case "caizhi" :
			if((int) me->query("int") >=20)
			return notify_fail("你的才智已达到了上限，不可以用分配的方法再提高了。\n");
			me->add("used_gift_points",1);
			me->add("int",1);
			break;
        case "体质" :
        case "tizhi" :
                        if((int) me->query("con") >=20)
                        return notify_fail("你的体质已达到了上限，不可以用分配的方法再提高了。\n");
                        me->add("used_gift_points",1);
                        me->add("con",1);
                        break;
        case "灵性" :
        case "lingxing" :
                        if((int) me->query("spi") >=20)
                        return notify_fail("你的灵性已达到了上限，不可以用分配的方法再提高了。\n");
                        me->add("used_gift_points",1);
                        me->add("spi",1);
                        break;
        case "魅力" :
        case "meili" :
                        if((int) me->query("per") >=20)
                        return notify_fail("你的魅力已达到了上限，不可以用分配的方法再提高了。\n");
                        me->add("used_gift_points",1);
                        me->add("per",1);
                        break;
        case "勇气" :
        case "yongqi" :
                        if((int) me->query("cor") >=20)
                        return notify_fail("你的勇气已达到了上限，不可以用分配的方法再提高了。\n");
                        me->add("used_gift_points",1);
                        me->add("cor",1);
                        break;
        case "力量" :
        case "liliang" :
                        if((int) me->query("str") >=20)
                        return notify_fail("你的力量已达到了上限，不可以用分配的方法再提高了。\n");
                        me->add("used_gift_points",1);
                        me->add("str",1);
                        break;
        case "耐力" :
        case "naili" :
                        if((int) me->query("dur") >=20)
                        return notify_fail("你的耐力已达到了上限，不可以用分配的方法再提高了。\n");
                        me->add("used_gift_points",1);
                        me->add("dur",1);
                        break;
        case "韧性" :
        case "renxing" :
                        if((int) me->query("fle") >=20)
                        return notify_fail("你的韧性已达到了上限，不可以用分配的方法再提高了。\n");
                        me->add("used_gift_points",1);
                        me->add("fle",1);
                        break;
        case "速度" :
        case "sudu" :
                        if((int) me->query("agi") >=20)
                        return notify_fail("你的速度已达到了上限，不可以用分配的方法再提高了。\n");
                        me->add("used_gift_points",1);
                        me->add("agi",1);
                        break;
        case "气量" :
        case "qiliang" :
                        if((int) me->query("tol") >=20)
                        return notify_fail("你的气量已达到了上限，不可以用分配的方法再提高了。\n");
                        me->add("used_gift_points",1);
                        me->add("tol",1);
                        break;
        case "运气" :
        case "yunqi" :
                        if((int) me->query("kar") >=20)
                        return notify_fail("你的运气已达到了上限，不可以用分配的方法再提高了。\n");
                        me->add("used_gift_points",1);
                        me->add("kar",1);
                        break;
        case "定力" :
        case "dingli" :
                        if((int) me->query("cps") >=20)
                        return notify_fail("你的定力已达到了上限，不可以用分配的方法再提高了。\n");
                        me->add("used_gift_points",1);
                        me->add("cps",1);
                        break;
        default :
			return notify_fail("没有这个参数。\n");

	}
	write("Ok.\n");
	me->start_busy(1);
	return 1;
}


int help(object me)
{
        write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	distribute <属性点>[0m
[0;1;37m────────────────────────────────[0m   

这个指令可以让你将属性点分配到你指定的参数上。属性点
一旦分配掉，将永远不可更改。

distribute 才智 让你将一点属性分配到才智上。

如不可输入中文，可用拼音代替。
才智 caizhi	体质 tizhi
灵性 lingxing	魅力 meili
勇气 yongqi	力量 liliang
耐力 naili	韧性 renxing
速度 sudu	气量 qiliang
运气 yunqi	定力 dingli

有关参数点，属性（才智，力量等）：参见 Help attributes.txt

[0;1;37m────────────────────────────────[0m   
HELP
        );
        return 1;
}
