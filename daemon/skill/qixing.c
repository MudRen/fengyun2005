// TIE@FY3

inherit SKILL;
void setup(){
	set("name","七星法");
	set("type","spells");
	set("usage/spells",1);
	set("effective_level",100);
	set("skill_class","wudang");
	set("difficulty",200);
}	


int valid_learn(object me)
{
    	object ob;
    	if( (int)me->query_skill("changelaw",1) < (int)(me->query_skill("qixing",1))){
        	return notify_fail("学习七星法需要相同等级的易经作基础。\n");
		}
	return ::valid_learn(me);
}

