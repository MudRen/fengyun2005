// id.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int i, j;
        object obj, *inv;
        string *id;

        if (me->query_temp("timer/big_cmd")+1 > time())
		return notify_fail("此命令比较耗费系统资源，每秒只能执行一次。\n");
	else
		me->set_temp("timer/big_cmd",time());
        
        if( !arg ) {
                inv = all_inventory(me);
                if( !sizeof(inv) )
                        return notify_fail("你身上没有任何东西。\n");
        write( "你身上携带物品的别称如下(右方) :\n");
                for(i=0; i<sizeof(inv); i++) {
                        if( !me->visible(inv[i]) ) continue;
                        printf("%-20s = %s\n", inv[i]->name(),
                                implode(inv[i]->parse_command_id_list(), ", ") 
);
                }
                return 1;
        }

        if( arg=="here" ) {
            if (environment(me)->query("brief_objects"))
            	return notify_fail("此地无法使用此命令。\n");
            inv = all_inventory(environment(me));
            if( !sizeof(inv) )
                	return notify_fail("这里没有任何东西。\n");
        		write( "在这个房间中, 生物及物品的(英文)名称如下 :\n");
                for(i=0; i<sizeof(inv); i++) {
                    if( !me->visible(inv[i]) ) continue;
					if( (int) inv[i]->query("no_shown") ) 
					if(! wizardp(me))	continue;
                    if (wizardp(me) && inv[i]->query("id")!= inv[i]->get_id())
                    	printf("%-20s = %s （%s：%s）\n", inv[i]->name(),
                    	implode(inv[i]->parse_command_id_list(), ","), inv[i]->name(1), inv[i]->query("id"));
                    else
                    	printf("%-20s = %s\n", inv[i]->name(),
                    	implode(inv[i]->parse_command_id_list(), ",") ); 
                }
                return 1;
        }
}
int help(object me)
{
write(@HELP

[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	id [here][0m
[0;1;37m────────────────────────────────[0m   

这个指令可以让你知道物品的英文名称及名字. 只打 id 会显示
你身上所携带物品的名称. 'id here' 则显示所有跟你在同一个
环境里的物件名称.

[0;1;37m────────────────────────────────[0m  
HELP
    );
    return 1;
}
 
 
