// wimpy.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
        int wmp;

        if( !arg ) {
                write("当你现在的精力，气血，或心神低於 " + (int)me->query("env/wimpy") 
                        + "% 时就会尝试逃跑。\n");
                return 1;
        }
        if( sscanf(arg, "%d", wmp)!=1 || wmp < 0 || wmp > 99)
                return help(me);

        me->set("env/wimpy", wmp);
        write("Ok.\n");
        return 1;
}

int help(object me)
{
        write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	wimpy [<逃跑时精力，气血，或心神的百分比>][0m
[0;1;37m────────────────────────────────[0m   

这个指令让你设定当精力，气血，或心神剩下百分之多少时，要开始「转进」。

[0;1;37m────────────────────────────────[0m 
HELP
        );
        return 1;
}

