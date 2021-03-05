/*
annie. 10.2003
------------------
快雨无行剑法
Tempest Sword
------------------

「富贵浮云两无定」
「残山剩水总无情」
「秋风吹醒英雄梦」
「成败起落不关心」
「祸福依伏从无路」
「吉凶悲欢有尽头」
「画图有约春无价」
「情深不寿梦乍醒」
*/

#include <ansi.h>
inherit SKILL;
int check_skill(object victim) ;

void setup(){
        set("name","快雨无行剑法");
        set("type","sword");
        set("usage/sword",1);
        set("usage/parry",1);
        set("difficulty",250);
        set("effective_level",200);
        set("skill_class","berserker");

        set("parry_msg",                        ({
                "$n一式「画图有约春无价」萧疏落寞的挥出，架开了$N。\n",
                "可$n突然一叹，「吉凶悲欢有尽头」已斜斜的架住了$N的攻击。\n",
                })
        );
        set("unarmed_parry_msg",        ({
                "$n一式「画图有约春无价」萧疏落寞的挥出，封开了$N。\n",
                "可$n突然一叹，「吉凶悲欢有尽头」已斜斜的封住了$N的攻击。\n",
                })
        );

        action = ({
        ([      "action":               
"$N身旋剑转，一招「祸福依伏从无路」似有似无的向$n点去",
                "parry":                150,
                "damage":               130,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N手中$w一低又乍然卷起，如长蛇吐信般一招「情深不寿梦乍醒」刺向$n",
                "parry":                120,
                "damage":               130,
                "damage_type":  "刺伤"
        ]),
([      "action":               
"$N一振$w，身影有若分为二人，合使一式「富贵浮云两无定」刺向$n",
                "parry":                155,
                "damage":               237,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$w在$N手中滑过，暴长的青芒划出一道弯弧，自右上方落向$n－－「残山剩水总无情」",
                "parry":                471,
                "damage":               139,
                "damage_type":  "刺伤"
        ]),
        });
}

int help(object me)
{
	write(@HELP   
L100『醒梦』（knockdown）
试图击落敌人的武器，若失败则向敌人攻击一招

L150『混元訣』（hunyuanjue）20分钟使用一次，另需150乞讨之术
L150『倏忽訣』（shuhujue）30分钟使用一次，另需190乞讨之术
HELP
    );
    return 1;
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

