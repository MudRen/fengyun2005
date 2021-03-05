// save.c
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object link_ob;

				if ( !wizardp(me) && me->query_temp("timer/big_cmd")+60 > time())
					return notify_fail("此类命令比较耗费系统资源，每六十秒才能执行一次。\n");
				else
					me->set_temp("timer/big_cmd",time());

        seteuid(getuid());

        if( !objectp(link_ob = me->query_temp("link_ob")) )
                return notify_fail("你不是由正常连线进入，不能储存。\n");
  
        if( environment(me)->query("valid_startroom") ) {
                me->set("startroom", base_name(environment(me)));
                write("当你下次连线时，会从这里进入。\n");
        } 
                	
// change save to fake
// for decrease harddisk operate
// 2002-11-1 
// akuma

      	if( (int)link_ob->save() && (int)me->save() ) {
        write("档案储存完毕。\n");
                return 1;
       	} else {
                write("储存失败。\n");
                return 0;
        }
}

int help(object me)
{
        write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	save[0m
[0;1;37m────────────────────────────────[0m   

存储数据以及设定你下一次联线进入的地点。

[0;1;37m────────────────────────────────[0m   
HELP
        );
        return 1;
}
