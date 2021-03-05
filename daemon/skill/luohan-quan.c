inherit SKILL;
void setup() {
	set("name","罗汉拳");
	set("usage/parry",1);
	set("usage/unarmed",1);
	set("type","unarmed");
	set("practice_limit",100);
	set("difficulty",200);
	set("effective_level",120);
	set("skill_class","task");
	set("unarmed_parry_msg", ({
	        "$n左腿略挫，右掌虚晃，呼的一声，左拳猛击而出，劲雄势急，$N只得撤手换招。\n",
	        "$n不退不避，运劲出拳，往$N面门猛击过去，卸去了$N的攻势。\n",
	        "$n下盘不动，上盘不避，将腰向左一挪，斗然移开半尺，右手送出，将$N格开。\n",
	        "$n右脚原地跺步，左脚踏前勾出，一招『跺脚崩挂』，右手向右横拉而出。\n",
	        "$n左脚虚踏，一招『平步栽掌』，左手化掌，向前直封而出。\n",
	}) );
	set("parry_msg", ({
	        "$n左腿略挫，右掌虚晃，呼的一声，左拳猛击而出，劲雄势急，$N只得撤手换招。\n",
	        "$n举手一挡，反腕钩出，竟已拿住了$N击来的$w。\n",
	        "$n立定马步，扬声吐气，嘿的一声，一拳打在$N的$w正中。\n",
	        "$n衣袖轻抖，人向右转，左手衣袖突从身后向$N肩头拂去，以巧劲化去了$N的招式。\n",
	        "$n下盘不动，上盘不避，将腰向左一挪，斗然移开半尺，右手送出，将$N格开。\n",
	        "$n手腕翻处，伸手硬抓$N的兵刃。\n",
	}) );
	action = ({
	([	"action":		"$N连续上步，一式『黄莺落架』，左右手分靠，变拳为掌，击向$n的$l",
                "damage_type":	"瘀伤"
	]),
	([	"action":		"$N左脚虚踏，全身右转，一招『丹凤朝阳』，右掌猛地插向$n的$l",
                "damage_type":	"瘀伤"
	]),
	([	"action":		"$N双手大开大阖，宽打高举，使一招『洛钟东应』，双拳向$n的$l打去",
                "damage_type":	"瘀伤"
	]),
	([	"action":		"$N左掌圈花扬起，屈肘当胸，虎口朝上，一招『偏花七星』打向$n的$l",
		"damage_type":	"瘀伤"
	]),
	([	"action":		 "$N使一招『苦海回头』，上身前探，双手划了个半圈，击向$n的$l",
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N左掌圈花扬起，屈肘当胸，虎口朝上，一招『偏花七星』打向$n的$l",
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N双掌划弧，一记『挟山超海』，掌出如电，一下子切到$n的手上",
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N施出『慑服外道』，双拳拳出如风，同时打向$n头，胸，腹三处要害",
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N右脚拖进，右手反拳一式『跟步击砸』向前劈落，左掌更翻掌而出",
		"damage_type":	"瘀伤"
	]),
	([	"action":		 "$N一招『移步截砸』，左掌前托，右拳顺势向前低劈$n",
		"damage_type":	"瘀伤"
	]),
	});
}

int help(object me)
{
	write(@HELP   
L10『雏凤展翅』（chufeng）一个很不错的空手攻击特技。
HELP
    );
    return 1;
}
