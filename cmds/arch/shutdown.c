// shutdown.c

#include <net/daemons.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string wiz_status;
	object *user, link_ob;
	int i;

	if( me != this_player(1) ) return 0;
	
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
		return notify_fail("只有 (arch) 以上的巫师才能重新启动" + MUD_NAME + "\n");

	message( "system", "游戏重新启动，请稍候一分钟再 login 。\n", users() );

	user = users();
	for(i=0; i<sizeof(user); i++) {
		if( !environment(user[i]) ) continue;
		user[i]->save();
		link_ob = user[i]->query_temp("link_ob");
		if( objectp(link_ob) ) link_ob->save();
	}

	if( find_object(DNS_MASTER) ) DNS_MASTER->send_shutdown();

	shutdown(0);
	return 1;
}
int help (object me)
{
        write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	shutdown[0m
[0;1;37m────────────────────────────────[0m   

马上重新起动游戏，如果是正式站点的正常重启，请采用reboot。

[0;1;37m────────────────────────────────[0m  
HELP
);
        return 1;
}
 
