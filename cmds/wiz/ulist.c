// user list

inherit F_CLEAN_UP;

int main(string str)
{
        object *ob;
        int i;
        ob=users();
        i = sizeof(ob);
        while (i--) {
        write(sprintf("%15s : %30s\n",ob[i]->query("id"),
        file_name(ob[i])));
        }
        return 1;
}

int help(object me)
{
write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	ulist[0m
[0;1;37m────────────────────────────────[0m   

将线上所有玩家的/obj/user number 显示出来。

[0;1;37m────────────────────────────────[0m   
HELP
    );
    return 1;
}
