#include <ansi.h>

inherit SKILL;
void setup(){
        set("name","铁山破拳");
        set("damage_level",200);
        set("type","unarmed");
        set("usage/unarmed",1);
        set("effective_level",300);
        set("difficulty",500);
        set("skill_class","npc");
        set("parry_msg", ({
                "$n左拳击下，右拳自保，一招「过桥抽板」，将$N封于尺外。\n",
        }) );

        set("unarmed_parry_msg", ({
                "$n左拳击下，右拳自保，一招「过桥抽板」，将$N封于尺外。\n",
        }) );
        action = ({
        ([      "action":               
"$N五指成拳，一招「泰山压顶」向$n闪电般的击下",
                "damage_type":  "内伤"
        ]),
        ([      "action":               
"$N左手虚晃，右拳「中宫直进」迅捷无比的往$n击出",
                "damage_type":  "内伤"
        ]),
        ([      "action":               
"$N步履一沉，左拳拉开，右拳使出「老汉推车」带着一阵劲风击向$n",
                "damage_type":  "内伤"
        ]),
        ([      "action":               
"$N左拳下击封开$n手腕，一式「白鹤亮翅」向$n击去",
                "damage_type":  "内伤"
        ]),
        });
}

int valid_learn(object me)
{
        if( me->query("class") || me->query("once_menpai"))
        {
                return notify_fail("你出身名门，这种平凡无奇的拳法如何能看得上眼？\n");
        }
        return ::valid_learn(me);
}




/* Dancing_Faery @ Hotmail.com */
