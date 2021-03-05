// release.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string martial, skill;
	int result;
        
	seteuid(getuid());
	if( me->is_busy() )
		return notify_fail("（你上一个动作还没有完成，不能施用外功。） \n");

	if( !arg ) return notify_fail("你要用外功做什麽？\n");

	if( sscanf(arg, "%s.%s", martial, arg)!=2 ) {
		if( martial != "herb") return notify_fail("你不可以用这种外功。\n");
	}
	if( stringp(skill = me->query_skill_mapped(martial)) ) {
        	if( SKILL_D(skill)->perform_action(me, arg) ) {
			if( random(120) < (int)me->query_skill(skill) )
				me->improve_skill(skill, 1, 1);
			return 1;
		}
	return 0;
	}
	return notify_fail("你请先用 enable 指令选择你要使用的外功。\n");
}