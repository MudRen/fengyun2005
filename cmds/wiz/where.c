// where.c
// 06-14-95

inherit F_CLEAN_UP;

int main(object me, string str)
{
	object ob, where, *ob_list;
	int i;
        if(!me->query("env/yesiknow")) return notify_fail("这个指令已经被废除了！\n");
	if (!str)
		return notify_fail("指令格式：where <人物或档名>\n"); 
	ob = find_player(str);
	if( !ob ) ob = find_living(str);
/*	if( !ob || !me->visible(ob)) {
		str = resolve_path(me->query("cwd"), str);
		ob_list = children(str);
		for(i=0; i<sizeof(ob_list); i++) {
			if( !ob = environment(ob_list[i]) ) continue;
			printf("%O\n", ob );
		}
		return 1;
	}*/
	if (!ob) return notify_fail("现在没这个人。\n");
	where = environment(ob);
	if (!where) return notify_fail("这个人不知道在那里耶。。。\n");
	printf("%s(%s)现在在%s(%s)。\n",
		(string)ob->name(),
		(string)ob->query("id"),
		(string)where->query("short"),
		(string)file_name(where));
	return 1;
}

int help(object me)
{
	write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	where <玩家的 ID>[0m
[0;1;37m────────────────────────────────[0m   

这个指令是用来得知玩家目前所在的位置.

[0;1;37m────────────────────────────────[0m
HELP
	);
	return 1;
}

