#include <ansi.h>
inherit SKILL;

void setup(){
	set("name","盘古九式");
	set("damage_level",300);
	set("type","hammer");
	set("usage/hammer",1);
	set("usage/parry",1);
	set("effective_level",200);
	set("difficulty",200);
	set("skill_class","yinshi");
	
	set("parry_msg", ({
        	"$n后退一步，一招『荡气回肠』手中的$v猛的砸向$N的$w。\n",
		"$n身形微顿，手中的$v一招『围韩救赵』反捣$N的必救之处。\n",
		"$n手中的$v从下往上急挥，一招『恶鬼还阳』磕开了$N手中的$w\n",
	}) );

	set("unarmed_parry_msg", ({
		"$n一招『钟鼓齐鸣』，手中的$v从偏锋击向$N的太阳大穴。\n",
		"$n手中的$v从左划右，一招『横扫千军』封住了$N的攻势。\n",
		"$n凌空三连翻，一招『披沙拣金』手中的$v反击$N的后脑，逼得$N中途撤招。\n",
	}) );	
	action = ({
        ([      "action":               
"$N左手化出一个圆圈，右手中的$w一招『威镇四方』向$n的$l挥去",
                "damage":               500,
                "dodge":                600,
                "parry":                200,
                "post_action":  "bash_weapon",
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N一弹手中的$w，一招『气盖山河』，手中的$w向$n的$l雷霆般地砸下",
                "damage":               150,
                "dodge":                400,
                "parry":                400,
                "post_action":  "bash_weapon",
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N暴喝一声，腾空飞起，以泰山压顶之式扑下，手中的$w带着轰轰雷声一招『千钧一发』击向$n的$l",

                "damage":               270,
		"dodge":                500,
                "parry":                700,
                "post_action":  "bash_weapon",
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N手中的$w一转，一招『狂风暴雨』从四面八方盖向$n的$l",
                "damage":               140,
		"dodge":                100,
                "parry":                400,
                "post_action":  "bash_weapon",
                "damage_type":  "挫伤"
        ]),
        ([      "action":
"$N一抖手中的$w，一招『夏日狂阳』幻出满天锤影，虚虚实实的挥向$n的$l",
                "damage" : 		150,
                "dodge":                100,
                "parry":                400,
                "post_action":  "bash_weapon",
                "damage_type":  "挫伤"
        ]),
	});
}

void skill_improved(object me)
{
    	int s;
    	s = me->query_skill("pangu-hammer", 1);
    	if (s== 100)
    		tell_object(me, HIW "你心念一动，似乎从锤法中领略了什么。\n" NOR);
    	if (s== 130)
    		tell_object(me, HIW "你心念一动，似乎从锤法中领略了什么。\n" NOR);
    	if (s== 150) {
       		tell_object(me,HIW " 也许你可以把这锤法融会贯通到你的鞭法中去。。\n"NOR);
       		me->set("marks/hammerwhip",1);
      	} 
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
    	object ob;
    	if( random(damage_bonus) < 350 ) return 0;
    	if(ob=victim->query_temp("weapon"))
    	if(ob->query("skill_type") == "blade")
    	if(	victim->query_skill_mapped("blade") == "bat-blade"
     		||victim->query_skill_mapped("blade") == "ittouryu")
    	if(me->query_skill("hammer") > victim->query_skill("blade")) {
    
    		switch(random(3)) {
            		case 0:
                			message_vision(HIR "\n$N料敌机先，渐渐占了上风！" NOR,me,victim);
                    		break;
            		case 1:
                    		message_vision(HIR "\n$N轻而易举地抢入$n的空隙之间！" NOR,me,victim);
                    		break;
            		case 2:
                    		message_vision(HIR "\n$N力大招沉，$n逐渐施展不开了！" NOR,me,victim);
                    		break;
                    	}
    	return random(me->query_skill("hammer")) * 2;
    	}
    	return 0;
}
