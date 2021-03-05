// fengyu-piaoxiang.c  风雨飘香步

inherit SKILL;
void setup() {
	set("name","风雨飘香步");
	set("type","step");
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",120);
	set("practice_limit",100);
	set("difficulty",200);
	set("skill_class","bat");
	set("dodge_msg", ({
		    "$n一个「漠漠帆来重」，随着$N的攻势飘起，从容躲过这一招。\n",
		    "$n使出一招「冥冥鸟去迟」，猛然纵起丈余，结果$N扑了个空。\n",
		    "$n身形一摇，幻出几个人影，一招「山风吹空林」躲过了$N的攻势。\n",
		    "$n一招「千峰同一色」纵身跃起，倏忽已落至$N身后。\n",
		    "$n左一摇，右一晃，一招「落月去清波」已轻松闪过。\n",
		    "$n双足一点，斜斜飞起，使出「皎皎孤月轮」已闪到$N身侧。\n",
	}) );

}
