// doomforce.c

inherit SKILL;

void setup() {
	set("name","吹血神功");
	set("type","force");
	set("usage/force",1);
	set("effective_level",130);
	set("difficulty",200);
	set("skill_class","fighter");
	
}	
int valid_learn(object me)
{
	if(!::valid_learn(me)) {
		return 0;
	}
/*	if((int)me->query("bellicosity") < (int)me->query_skill("doomforce") * 5){ 
		return notify_fail("你的杀气不够，无法领悟更高深的吹血神功。\n");
	}*/
        return 1;
}
