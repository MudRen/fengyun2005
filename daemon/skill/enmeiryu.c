//enmeiryu.c
#include <ansi.h>
inherit SKILL;
void setup() {
	set("name","陆奥圆明流拳术");
	set("usage/parry",1);
	set("usage/unarmed",1);
	set("type","unarmed");
	set("effective_level",170);
	set("difficulty",200);
	set("skill_class","ninja");
	set("parry_msg", ({
		"$n一把刁住$N，用力向后一捌，将$N用力甩了出去，「狼牙」！！\n",
		"$n乘$N攻击时闪出的一处破绽，突然使出一招「浮狱」，一头撞向$N的额部。\n",
	        "$N眼看就要攻击到$n的一瞬间，$n一招「浮身」向后一跃，闪过了这一招。 \n",
	        "$n趁着$N攻击的间隙，突然欺近。一拳击向$N的面门，用「蔓落」化解了这一招。 \n",
	        "$n突然伸指截向$N的双眼，$N慌乱之际只能停止进攻，正是一招「指穿」。 \n",
	        "$n一口唾液吐向$N的眼睛，一招「讣霞」躲过了$N的攻击。 \n",

	}) );
	set("unarmed_parry_msg", ({
		"$n一把刁住$N，用力向后一捌，将$N用力甩了出去，「狼牙」！！\n",
		"$n乘$N攻击时闪出的一处破绽，突然使出一招「浮狱」，一头撞向$N的额部。\n",
	        "$N眼看就要攻击到$n的一瞬间，$n一招「浮身」向后一跃，闪过了这一招。 \n",
	        "$n趁着$N攻击的间隙，突然欺近。一拳击向$N的面门，用「蔓落」化解了这一招。 \n",
	        "$n突然伸指截向$N的双眼，$N慌乱之际只能停止进攻，正是一招「指穿」。 \n",
	        "$n一口唾液吐向$N的眼睛，一招「讣霞」躲过了$N的攻击。 \n",
	}) );
	action = ({
        ([      "action":               
"$N一招「牙斩」切向$n的$l ",
                "dodge":                90,
                "parry":                70,
                "damage":                50,
                "damage_type":  "瘀伤",
                "name":		"牙斩",
        ]),
        ([      "action":               
"$N悠地欺近$n，双拳贴在$n的衣服上，发出了一招「虎砲」",
                "dodge":                50,
                "parry":                70,
                "damage":                300,
                "damage_type":  "瘀伤",
                "name":		"虎砲",
                
        ]),
        ([      "action":               
"$N一招「破蛇」击向$n的肘内侧，紧接着踏前一步，肘部跟进击打$n的$l",
                "dodge":                30,
                "parry":                10,
                "damage":                80,
                "damage_type":  "瘀伤",
                "name":		"破蛇",
        ]),
        ([      "action":               
"$N一招「朔光」，右拳将$n的右拳架开，右肘突然击向$n的$l",
                "dodge":                10,
                "parry":                50,
                "damage":                120,
                "damage_type":  "瘀伤",
                "name":		"朔光",
        ]),
        ([      "action":               
"$N大吼一声「弧月」，身子突然向后一倒，单手支地，$n正在犹豫之间，
$N的右腿已到，踢向$n的$l",
                "dodge":                20,
                "parry":                100,
                "damage":                80,
                "damage_type":  "瘀伤",
                "name":		"弧月",
        ]),
        ([      "action":           
"$N使出了一招「神威」，双手揪住$n，单膝磕向$n的$l",
	        "dodge":                80,
                "parry":                10,
                "damage":                270,
                "damage_type":  "瘀伤",
                "name":		"神威",
        ]),     
        ([      "action":           
"$N向后一翻使出一招「龙破」，突然冲向$n，紧接着一个倒翻，单手支地， 
双腿似剪刀般绞向$n的$l",
                "dodge":                20,
                "parry":                30,
                "damage":                470,
                "damage_type":  "瘀伤",
                "name":		"龙破",
        ]),            
        ([      "action":           
"$N一个转身，单腿踢向$n的面门，$n正欲招架，$N突然变招「紫电」踢
向$n的$l",
                "dodge":                150,
                "parry":                10,
                "damage":                100,
                "damage_type":  "瘀伤",
                "name":		"紫电",
        ]),                    
    
	});
}

/*
int valid_learn(object me)
{
	object ob;
	if(!::valid_learn(me)) {
		return 0;
	}
	if (REWARD_D->check_m_success( me, "浪人的悲哀" )!= 1) 
		return notify_fail("天枫十四郎未答应转授你这门武功。\n");
	if ((int)me->query("tianfeng/enmeiryu")!=1){
		return notify_fail("天枫十四郎未答应教你这门武功。\n");
	}
	return 1;
}
*/

int help(object me)
{
	write(@HELP   
『紫电四连脚』（shiden）
需100级的陆奥圆明流拳术，四连踢特技，自我忙乱三轮。
额外攻击力=陆奥圆明流拳术/2
额外伤害力=陆奥圆明流拳术/2

『四门-朱雀』（shimon）
需要120级的陆奥圆明流拳术，威力巨大的垂死一击，只能在气血值
同时低于1000以及最大气血值的20%时使用。自我忙乱两轮。
额外攻击力=(有效拳脚-150)*4
额外伤害力=（有效拳脚-150）*10
HELP
    );
    return 1;
}

