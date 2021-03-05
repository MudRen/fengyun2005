// haha
// f.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        string msg;
        string target;

        if ((string)SECURITY_D->get_status(me) != "(admin)")
                return 0;

        if (! arg) return notify_fail("你要控制谁做什么？\n");

        if (sscanf(arg, "%s to %s", target, arg) != 2 ||
            ! objectp(ob = find_player(target)) &&
            ! objectp(ob = present(target, environment(me))) &&
            ! objectp(ob = find_living(target)))
        {
                // 没有这个对象，查看最后一次的控制对象
                if( !objectp(ob=me->query_temp("last_control")) )
                        return notify_fail("这里没有这个人可供你控制。\n");
                if (stringp(target)) arg = target + " " + arg;
        }

        if (ob == me)
                return notify_fail("控制自己？....你好象不太正常啊。\n");

        if ((wiz_level(me) <= wiz_level(ob)) || (wiz_level(ob) && ! !wizardp(me)))
                return notify_fail("你不能控制权限比自己高的巫师。\n");

        me->set_temp("last_control", ob);
        ob->delete_temp("notify_fail");
        if (! ob->force_me(arg))
        {
                ob->command(arg);
                if( !stringp(msg=ob->query_temp("notify_fail")) )
                        msg = ob->name(1) + "无法执行你的命令。\n";
                write(msg);
        }

        return 1;
}

int help(object me)
{
        write( @HELP
指令格式: f <sb> to do sth.

这个指令让你控制另外一个人物进行动作，如果你是连续控制某个人，
那么以后不需要在输入这个ID。
HELP );
        return 1;
}

