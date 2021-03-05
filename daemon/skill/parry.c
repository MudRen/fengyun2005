// parry.c

inherit SKILL;
void setup() {
	set("name","拆招卸力之法");
	set("type","martial");
	set("skill_class","basic");
	set("difficulty",100);
	set("effective_level",50);
	set("unarmed_parry_msg",  ({
	        "但是被$n格开了。\n",
	        "结果被$n挡开了。\n",
	}) );
	set("parry_msg", ({
	        "但是被$n挡开了。\n",
		"但是被$n格开了。\n",
	}) );
}
