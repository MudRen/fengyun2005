/*
annie. 10.2003
------------------
长庚指
Venus Finger
------------------

「又闻子规啼夜月」
「孤灯不明思欲绝」
「卷帷望月空长叹」
「美人如花隔云端」
「碧纱如烟隔窗语」
「银箭金壶漏水多」
「但愿长醉不愿醒」
「东方渐高奈乐何」
*/

inherit SKILL;
#include <ansi.h>
int check_skill(object victim) ;


void setup() {
	set("name","长庚指");
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("type","unarmed");
	set("difficulty",250);
	set("effective_level",200);
	set("skill_class","berserker");
		
	set("parry_msg",			({
        	"$n长袖甩一招「但愿长醉不愿醒」，身形突然就悠悠的飘了出去。\n",
		"$n身随诗动，封住$N的攻击，长吟道：「东方渐高奈乐何」！\n"
	})	);
	set("unarmed_parry_msg",		({
         	"$n长袖甩一招「但愿长醉不愿醒」，身形突然就悠悠的飘了出去。\n",
		"$n身随诗动，封住$N的攻击，长吟道：「东方渐高奈乐何」！\n"
	})	);
	action = ({
([      "action" : "$N微微一笑，侧指身前，竟似是要等$n自行撞上这招「又闻子规啼夜月」！",
        "force" : 100,
        "dodge" : 5,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N俯身斜倚，左手半推，右手无名指一式「孤灯不明思欲绝」，向$n划过。",
        "force" : 140,
        "dodge" : 5,
        "damage" : 25,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N右腕一转，使出「卷帷望月空长叹」，五指自下而上拂了上来。",
        "force" : 180,
        "dodge" : 8,
        "damage" : 55,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N双目微睁，一式「美人如花隔云端」，双手幻化出千百个指影，一起刺向$n。",
        "force" : 220,
        "dodge" : 5,
        "damage": 65,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N施出一式「碧纱如烟隔窗语」，食中二指飘飘的向$n点去。",
        "force" : 260,
        "dodge" : 15,
        "damage": 80,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N长叹一声，无限寥落的一招「银箭金壶漏水多」捺向$n。",
        "force" : 330,
        "dodge" : 20,
        "damage": 100,
        "damage_type" : "瘀伤"
]),
});

}

int help(object me)
{
	write(@HELP   
L40『盘古斧』（panguaxe）：利用指力击碎敌人的武器，遇到这样的敌人
	要特别小心，即使是自制武器也会被打断，好在该特技使用时有一
	定延迟，要看清敌人的动向及时将自己武器收起。
HELP
    );
    return 1;
}
