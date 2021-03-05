
inherit SKILL;

void setup(){
	set("name","千金方");
	set("type","knowledge");
	set("skill_class","theorem");
	set("usage/theorem",1);
	set("effective_level",100);
	set("difficulty", 50);	
}


int help(object me)
{
	write(@HELP   
需至少/2等级的无有之术，学成后可提高各类药物的治疗效率，
（包括普生、冷红儿、宋夫子、万小春处药品）
同时也可提高各门派基本自疗心法（兴国、华山等除外）的效率。
在万春流处学得。

药物治疗效率=药物本身疗效*（100+千金方等级/2）/100
心法治疗效率＝心法本身疗效*（100+千金方等级/4）/100
HELP
);
    return 1;
}
