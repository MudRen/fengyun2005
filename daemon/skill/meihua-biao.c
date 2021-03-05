// silencer@fy4

#include <ansi.h>
inherit SKILL;

string* xuedao = ({
        "四白穴",
        "地仓穴",
        "大迎穴",
        "峡车穴",
        "头维穴",
        "下关穴",
        "隐白穴",
        "太白穴",
        "商丘穴",
        "地机穴",
	"少冲穴",
        "少海穴",
        "通理穴",
        "神门穴",
        "印堂穴",
        "金律穴",
        "玉液穴",
        "鱼腰穴",
        "百劳穴",
        "百会穴",
        "灵台穴",
        "太阳穴",
        "膻中穴",
        "命门穴",
        "鸠尾穴",
        "气海穴"
});

void setup(){
	set("name","梅花镖法");
	set("type","throwing");
	set("usage/throwing",1);
	set("usage/parry",1);
	set("skill_class","npc");
	set("effective_level",150);
	set("difficulty",200);
	set("damage_level",200);
	set("parry_msg", ({
	        "$n无名指弹出，$v无声无息地飞向$N曲池穴。$N急忙撤肘收招。\n",
		"$n右手轻弹，$v分两路直取$N双目。$N赶紧收招格击。\n",
	}) );
	set("unarmed_parry_msg", ({
		"$n无名指弹出，$v无声无息地飞向$N曲池穴。$N急忙撤肘收招。\n",
		"$n右手轻弹，$v分两路直取$N双目。$N赶紧收招格击。\n",
	}) );	
		
	action = ({
        ([      "action":               
"$N双手一分，四枚$w往左右飞出，半途一转，竟直往$n" + xuedao[random(sizeof(xuedao))]+ "打到",
                "dodge":                120,
                "parry":		300,
                "damage":               30,
		"damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N倏然出手，左右中指一弹，“的的”二声，$w直射向$n"+xuedao[random(sizeof(xuedao))],
                "dodge":                140,
                "parry":		320,
                "damage":               30,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N双手上下一扬间，一道白色的光芒，向$n"+xuedao[random(sizeof(xuedao))]+"射了过来",
                "dodge":                140,
                "parry":		200,
                 "damage_type":  "刺伤"
        ]),
	([      "action":               
"$N右手往空中微微一扬，手中的$w化作一道弧光射向$n的"+xuedao[random(sizeof(xuedao))],
                "dodge":                120,
                "parry":		300,
                "damage":               40,
                "damage_type":  "刺伤"
        ]),
       	([      "action":               
"$N双手连挥，两枚$w带着呼啸风声，划成二弧射向$n的"+xuedao[random(sizeof(xuedao))]+"和"+xuedao[random(sizeof(xuedao))],
                "dodge":                120,
                "parry":		100,
                "damage":               70,
                "damage_type":  "刺伤"
        ]),
       	([      "action":               
"$N飞身跃起，居高临下向$n猛射三枚$w，直取$n的双目和"+xuedao[random(sizeof(xuedao))],
                "dodge":                50,
                "parry":		210,
                "damage":               240,
                "damage_type":  "刺伤"
        ]),
       	([      "action":               
"但见$N将双手拢入袖中，无声无息地发出一枚$w，斜射到$n的"+xuedao[random(sizeof(xuedao))]+"，迅捷无比",
                "dodge":                120,
                "parry":		40,
                "damage":               140,
                "damage_type":  "刺伤"
        ]),
	});
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob;
    if( random(damage_bonus) < 150 ) return 0;
    if( victim->query_temp("weapon")==0) {
    	if(victim->query_skill_mapped("unarmed") == "dragonstrike" 
    		&& me->query_skill("tanzhi-shentong",1)+50 > victim->query_skill("dragonstrike",1)) {
    	switch(random(3)) {
            case 0:
                    message_vision(HIR "\n因武功路数相克，$N占尽了上风！" NOR,me,victim);
                    break;
            case 1:
                    message_vision(HIR "\n$N轻而易举地抢入$n的空隙之间！" NOR,me,victim);
                    break;
            case 2:
                    message_vision(HIR "\n$N射出满天指气，$n逐渐施展不开了！" NOR,me,victim);
                    break;
                    }
    	return random(me->query_skill("throwing")) * 2;
    	}
    }
    return 0;
}
