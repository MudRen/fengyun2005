// annie 07.2003


inherit SKILL;
void setup(){
	set("name","六灵暗识");
	set("skill_class","legend");
	set("type","knowledge");
	set("effective_level",150);
	set("difficulty",120);
}

int valid_learn(object me)
{
	if (me->query("class")!= "legend")
		return notify_fail("唯有铁雪弟子方能掌握六灵暗识之法。\n");
	return ::valid_learn(me);
}

int help(object me)
{
	write(@HELP   
六灵暗识是铁雪多项武功的基础，能够逐步提高萧杀身法时短歌刀和蝶恋
花剑的伤害力，L100级以上每10级增加1％，总共增加20％
HELP
    );
    return 1;
}
