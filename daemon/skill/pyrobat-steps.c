// pyrobat-steps.c

inherit SKILL;
void setup(){
	set("name","火蝠身法");
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",170);
	set("practice_limit",100);
	set("type","step");
	set("skill_class","npc");
	set("difficulty",200);

	set("dodge_msg", ({
        "但是$n身形飘忽，轻轻一纵，一招「幻蝠隐踪」，举重若轻的避开这一击。\n",
        "$n身随意转，一式「轻蝠点梢」，倏地往一旁挪开了三尺，避过了这一招。\n",
        "可是$n侧身一让，使出「寒蝠掠江」，$N这一招扑了个空。\n",
        "却见$n足不点地，一招「夜蝠旋身」，往旁窜开数尺，躲了开去。\n",
        "$n身形微晃，使出「灵蝠轻逝」，有惊无险地避开了$N这一招。\n",
        "$n身形往上一拔，一招「火蝠曳空」，一个转折落在数尺之外。\n"
	}) );
}
