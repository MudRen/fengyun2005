// shenji-steps.c
inherit SKILL;
void setup(){
	set("name","神机步法");
	set("type","step");
	set("difficulty",200);
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",150);
	set("skill_class","npc");
	set("dodge_msg", ({
		"$n一招「金蝉脱壳」，步法轻灵，身形飘动，$N的招式落空。\n",
		"只见$n呆立不动，等$N的招式用老，一式「假痴不癫」，轻松地躲在一旁。\n",
		"$n使出「欲擒故纵」，斜斜地窜开。\n",
		"$n左足一点，一招「暗渡陈仓」腾空而起，避了开去。\n",
		"可是$n使一招「以逸待劳」，步法飘忽不定，$N的攻击失去了准头。\n",
		"$n经藉一招「隔岸观火」，身形飘退，轻轻闪过。\n",
		"但是$n一招「李代桃僵」使出，身形晃动，幻出数道身影，自己早已飘出三丈开外！\n",
	}) );
}

