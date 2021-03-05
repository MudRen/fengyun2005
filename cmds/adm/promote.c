// promote.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string old_status, new_status;
	int my_level, ob_level, level;

#ifdef	ENCRYPTED_WRITE	
		string *allowed = ({ "(wizard)","(immortal)","(player)" });
#endif   

#ifdef	NONENCRYPTED_WRITE	
		string *allowed = ({ "(admin)","(arch)","(wizard)","(immortal)","(player)" });
#endif   

	if( me!=this_player(1) ) return 0;

	if( !arg || sscanf(arg, "%s %s", arg, new_status)!=2 )
		return notify_fail("指令格式：promote <使用者> <等级>\n");

	if( member_array(new_status,allowed) == -1) 
		return notify_fail("没有这种等级。\n");
	
	if( !objectp(ob = present(arg, environment(me))) 
	||	!userp(ob) )
		return notify_fail("你只能改变使用者的权限。\n");

	if( wiz_level(me) < wiz_level(new_status) )
		return notify_fail("你没有这种权力。\n");

	old_status = wizhood(ob);

	seteuid(getuid());
	if( !(SECURITY_D->set_status(ob, new_status)) )
		return notify_fail("修改失败。\n");

	message_vision("$N将$n的权限从 " + old_status + " 改为 " + new_status + " 。\n", me, ob);
	log_file( "static/promotion", getuid(me)+" promoted " + getuid(ob) 
		+ " from "+ old_status + " to " + new_status + " on " + ctime(time()) + "\n" );
	seteuid(getuid());
	ob->setup();

	return 1;
}

int help(object me)
{
write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	promote <某人> (权限等级)[0m
[0;1;37m────────────────────────────────[0m   

用来提升权限等级, (player) (immortal) (wizard) (arch) (admin)
一个 admin 能提升权限至任何等级, 而 arch 只能提升至 arch。

注：加密站点promote只能用于wizard、immortal、player，对其他等级
的提升必须通过wizlist进行。

[0;1;37m────────────────────────────────[0m 

HELP
    );
    return 1;
}
