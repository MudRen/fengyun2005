inherit SKILL;

void setup(){
	set("name","无尘步法");
	set("type","step");
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",170);
	set("difficulty",200);
	set("practice_limit",100);
	set("skill_class","bonze");
	set("dodge_msg", ({
	        "$n一招「轻烟缥缈」轻轻巧巧地避了开去。\n",
	        "只见$n身影一晃，一式「青云直上」早已避在七尺之外。\n",
	        "$n使出「凌空飞渡」，轻轻松松地闪过。\n",
	}) );
}


int help(object me)
{
	write(@HELP   
L100	『空灵』(dodge.kongling) 
消除自身的杀气

L150	『绝尘』(dodge.juechen) 
提高自身的速度(+无尘步法/20)

HELP
    );
    return 1;
}
