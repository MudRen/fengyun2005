// 风撼梧桐寂寞凉，梧桐叶上写离肠。咛叮一夜梧桐雨，乍醒犹疑在郎旁。
// 天降丹凤栖桐乡，安然临水照羽裳。冬来起舞发清唱，雪落歧山是故乡。
// annie.6.28.03

#include <ansi.h>
inherit SKILL;
void setup() {
	set("name","天舞轮回刀法");
	set("practice_limit",100);
	set("type","blade");
	set("difficulty",230);
	set("usage/blade",1);
	set("usage/parry",1);
	set("effective_level",230);
	set("skill_class","demon");
        set("parry_msg", ({
        "$n刀锋轻转，一式「雪落歧山是故乡」折出一片雪也似的光华护住全身。\n",
                })
        );
        set("unarmed_parry_msg", ({
        "$n收刀齐眉，轻踏蹁跹，一式「安然临水照羽裳」迫退$N。\n",
                })
        );
        action = ({
        ([      "action":               "$N身影随风而去，乍然敛眉回首，挥出一刀「风撼梧桐寂寞凉」。",
                "dodge":                60,
                "damage":               200,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N轻攒眉心，手中$w在身边低晃，仿佛间就似一个女子执着兔毫小笔，\n正于「梧桐叶上写离肠」。",
                "dodge":                40,
                "damage":               320,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N施出「咛叮一夜梧桐雨」，碎密的刀光自天幕中落下，有若夜半冬雨，\n滴滴垂泪，点点断肠。",
                "dodge":                240,
                "damage":               280,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N眉目间倦意盈然，手下$w一式「乍醒犹疑在郎旁」滑向$n，切切如情\n人初醒的呢喃。",
                "dodge":                160,
                "damage":               360,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N提裙而起，跃在空中的身子轻旋，带着$w破空落向$n，正是「天降丹\n凤栖桐乡」。",
                "dodge":                100,
                "damage":               420,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N曼声而歌，轻笑宛然，突展「冬来起舞发清唱」从$n头上掠过，裙裾\n如浮云飘过$n的头顶，谁也没有看见裙下一抹刀光。",
                "dodge":                200,
                "damage":               480,
                "damage_type":  "割伤"
        ]),
        });
}
int valid_learn(object me)
{
        if(!::valid_learn(me))
                return 0;
        if (me->query("gender") != "女性")
                return notify_fail("一个大男人，也好意思学这扭扭捏捏的刀法？\n");
        if( me->query_skill("move", 1) < me->query_skill("heavendance",1) )
                return notify_fail("你的轻身功底火候不足，怎能修习天舞轮回刀法？\n");
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int skill;
        skill = me->query_skill("heavendance",1);
        if (me->query("age") < 16 || me->query("age") > 36)     return 0;
        if (victim->query("gender") != "男性")  return 0;
        if (victim->query("age") < 16)  return 0;
        if (!userp(me))
                skill += 100;
        if ((random(skill) > 100 || me->query_temp("annie/perform_heavendance")) && random(me->query_per()) > random(victim->query_cps()))
        {
                victim->perform_busy(1);
                return CYN"$n痴痴的望着$N，那深情的眼神和口中流下的一丝．．．说明了一切。\n"NOR;
        }
        return 0;

}

int help(object me)
{
	write(@HELP   
女子独有武功，命中时如果自身魅力够高，有一定几
率令对方忙乱一轮

『月斜人静』（yuexierenjing）
一个延时的四连击，间隔约为1-2轮，在使用期间会有一个很
大的气盾挡住所有非魔法气血伤害。
无攻击加成，
额外伤害力=天舞轮回刀法*i

HELP
    );
    return 1;
}
