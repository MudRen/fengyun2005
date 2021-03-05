// taoism.c

inherit SKILL;
void setup(){
	set("name","天师正道");
	set("skill_class","taoist");
	set("usage/literate",1);
	set("type","knowledge");
	set("effective_level",200);
	set("difficulty",250);
	set("no_refund",({"necromancy","scratmancy","gouyee"}));
}

int valid_learn(object me) 
{
        if(me->query("bellicosity") > 100 )
                return notify_fail("你的杀气太重，无法修炼天师正道。\n");
        return 1;
}


int help(object me)
{
	write(@HELP   
天师正道是三清武功的基础，200级以上，每2级招出的四种鬼卒天兵等
增加+1%抵抗气血伤害的能力，直至220级（+10%）

HELP
    );
    return 1;
}
