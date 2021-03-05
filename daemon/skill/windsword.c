#include <ansi.h>
inherit SKILL;
void setup(){
        set("name","回风剑法");
        set("damage_level",200);
        set("usage/sword",1);
        set("usage/parry",1);
        set("effective_level",200);
        set("type","sword");
        set("difficulty",200);
        set("skill_class","npc");
        set("parry_msg", ({
        "$n身形急退，手中$v上下飞舞，一招「雨过天连青壁润」，封住$N的招式。\n",
        "$n使出一招「霜凋红叶正晚秋」，手中的$v内力激荡，$N的攻势随波而散。\n",
        "$n手中的$v挽出朵朵刀花，一招「金花玉萼影浮沉」，游刃有余。\n",
        }) );
        set("unarmed_parry_msg", ({
        "$n身形急退，手中$v上下飞舞，一招「雨过天连青壁润」，封住$N的招式。\n",
        "$n使出一招「霜凋红叶正晚秋」，手中的$v内力激荡，$N的攻势随波而散。\n",
        "$n手中的$v挽出朵朵刀花，一招「金花玉萼影浮沉」，游刃有余。\n",
        }) );   
        action = ({
                ([      "action":               
                "$N手中$w剑光宛如流水，一招「衰草斜阳流曲浦」，斜斜刺向$n的$l",
                        "damage_type":  "割伤"
                ]),
                ([      "action":               
                "$N手中$w剑光激荡，一招「黄云影日暗长堤」，斩向$n！",
                        "damage_type":  "割伤"
                ]),
                ([      "action":               
                "$N手中$w剑气森然，一招「白萍香远任依依」直劈$n$l",
                        "damage_type":  "割伤"
                ]),
                ([      "action":               
                "$N手中$w狂舞，剑光团团簇簇，一招「红萝花繁知景色」，飘飘荡荡向$n落去",
                        "damage_type":  "割伤"
                ]),
        });
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob;
    int extra;
    if(ob=victim->query_temp("weapon")) return 0;
    message_vision(HIW"\n$N剑剑连绵，招招指向$n掌法破绽之处，$n惊惶失措，连连中招。\n" NOR,me,victim);
    extra = COMBAT_D->magic_modifier(me, victim, "kee", me->query_skill("sword")* random(10));    
    return extra;
}

int help(object me)
{
	write(@HELP   
该剑法专克各类拳脚，
附加伤害=random(有效剑法*10)

『沉萼落香』（luoxiang）
单击，自我忙乱两轮
额外攻击力=有效剑法*2
额外伤害力=有效剑法*4
HELP
    );
    return 1;
}

