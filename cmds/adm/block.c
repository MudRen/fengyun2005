#include <login.h>;
inherit F_CLEAN_UP;

void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
        object ob,link_ob;

        if(!arg)
                return notify_fail("请用help查看此指令用法！\n");
        ob=find_player(arg);
        if(!ob)
			return notify_fail("此指令只能对在线玩家使用。\n");

        link_ob=ob->query_temp("link_ob");
        if(link_ob)
        {
			link_ob->set("blocked",1);
			link_ob->save();
			destruct(ob);
			write("BLOCK　Ok.\n");
			return 1;
        }
        return notify_fail("Unknown error.\n");
}


int help(object me)
{
        write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	block ID[0m
[0;1;37m────────────────────────────────[0m   

使用这个指令禁用一个玩家帐号，在解除封禁前此账号将无法登陆。

[0;1;37m────────────────────────────────[0m 
HELP
    );
    return 1;
}
