inherit F_CLEAN_UP;

mixed main(object me, string arg, int remote)
{
	object *ulist, *ilist;
	int i, j;
	int k, num;
	string file;
	
	if (! arg)
		return notify_fail ("指令格式 whohas <id>\n");
    
    if( wiz_level(me) < wiz_level("(wizard)") )
		return notify_fail("你的巫师等级太低，没有使用这个指令的权力。\n");
//        ulist = filter_array(objects(), (: userp($1) :));
 	ulist = objects();
	i = sizeof(ulist);
	k = 0;
	while (i--) {
		if (! present (arg,ulist[i]))
			continue;
//		if (sscanf(file_name(ulist[i]),"%s#%d",file, num)!= 2)
//			continue;
		k = k+1;
		write ("  "+ulist[i]->query("name")+ "（" + ulist[i]->query("id") 
				+ "）	(" + file_name(ulist[i]) +"） :\n");
		ilist = all_inventory(ulist[i]);
		j = sizeof(ilist);
		while (j--) {
			object ob = ilist[j];
			string *ids = ob->parse_command_id_list();
			if (member_array(arg, ids) == -1)
				continue;
			write ("               "+ob->short());
		}
		write ("\n");
	}
	if (k == 0) write ("没有人携带你要寻找的物品。\n");
	return 1;
}

int help (object me)
{
        write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	whohave <id>[0m
[0;1;37m────────────────────────────────[0m   

可列出目前携带某个物品的玩家/生物等。

[0;1;37m────────────────────────────────[0m   
HELP
);
        return 1;
}
