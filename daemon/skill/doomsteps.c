//doomsteps.c

inherit SKILL;

void setup() {
	set("name","吹血步法");
	set("effective_level",150);
	set("type","step");
	set("difficulty",200);
	set("usage/dodge",1);
	set("usage/move",1);
	set("skill_class","fighter");
	
	set("dodge_msg", ({
	        "但是$n身形飘忽，轻轻一纵，一招「虚怀若谷」，举重若轻的避开这一击。\n",
	        "$n身随意转，一式「蜻蜓点水」，倏地往一旁挪开了三尺，避过了这一招。\n",
	        "可是$n侧身一让，使出「细胸巧翻云」，$N这一招扑了个空。\n",
	        "却见$n足不点地，一招「白鹤冲天」，往旁窜开数尺，躲了开去。\n",
	        "$n身形微晃，使出「鹞子翻身」，有惊无险地避开了$N这一招。\n",
	        "$n身形往上一拔，一招「大鹏展翅」，一个转折落在数尺之外。\n"
	}) );

}

