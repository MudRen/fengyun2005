#include <ansi.h>
inherit SKILL;

void setup(){
	set("name","寒雪鞭法");
	set("damage_level",200);
	set("type","whip");
	set("difficulty",200);
	set("usage/whip",1);
	set("usage/parry",1);
	set("effective_level",200);
	set("skill_class","npc");
	set("parry_msg", ({
        	"$n手中的$v一抖，鞭梢象毒蛇一样咬向$N的左臂。\n",
		"$n一抖手中的$v，使出「聚鞭成枪」的功夫，鞭梢直刺$N的虎口。\n",
		"$n右臂向后一摆，手中的$v向前卷出，鞭影象雪花般罩住了$N。\n",
		"$n使出一招「白雪皑皑」，逼得$N退出丈外。\n",
		
	}) );
	set("unarmed_parry_msg", ({
	        "$n手中的$v一抖，鞭梢象毒蛇一样咬向$N的左臂。\n",
	        "$n一抖手中的$v，使出「聚鞭成枪」的功夫，鞭梢直刺$N的虎口。\n",
	        "$n右臂向后一摆，手中的$v向前卷出，鞭影象雪花般罩住了$N。\n",
	        "$n使出一招「白雪皑皑」，逼得$N退出丈外。\n",
	}) );
	action = ({
		([	"name":			"寒风起兮",
			"action":		
			"$N使一招「寒风起兮」，手中$w抖得笔直向$n的$l连刺数鞭",
			"dodge":		100,
			"parry":		200,
			"damage":		130,
			"damage_type":	"刺伤"
		]),
		([	"name":			"漫天飞雪",
			"action":		
			"$N身形一转，一招「漫天飞雪」$w幻出满天鞭影，虚虚实实地袭向$n的$l",
			"dodge":		150,
			"parry":		100,
			"damage":		200,
			"damage_type":	"瘀伤"
		]),
		([	"name":			"雪花翩翩",
			"action":		
			"$N力贯$w，一招「雪花翩翩」点点鞭影飘浮不定地点向$n的$l",
			"dodge":		240,
			"parry":		300,
			"damage":		215,
			"damage_type":	"刺伤"
		]),
		([	"name":			"积雪三尺",
			"action":	        
			"$N手中$w一抖，一招「积雪三尺」以一个怪异的角度往$n下盘卷去",
			"dodge":		240,
			"parry":		300,
			"damage":		330,
			"damage_type":	"瘀伤"
		]),
	        ([
			"name":			"狂风骤雪",
			"action":		
			"$N手中一紧，使招「狂风骤雪」，手里$w一鞭接著一鞭不停地抽向$n的$l",
			"dodge":		350,
			"parry":		100,
			"damage":		100,
			"damage_type":   "鞭伤"
	        ]),
		([	"name":			"风雪交加",
			"action":		
			"$N一招「风雪交加」手中$w舞出一片鞭影扫向$n全身",
			"dodge":		360,
			"parry":		120,
			"damage":		150,
			"damage_type":	"瘀伤"
		]),
	});
}
