// enforce.c
// the maxium 150 enforce is added for game balance. Silencer @1-1-2002

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int pts;

        if( !arg || (arg!="none" && !sscanf(arg, "%d", pts)) ) 
                return notify_fail("指令格式：enforce <使出几成内力伤敌>|none");

        if( !me->query_skill_mapped("force") )
                return notify_fail("你必须先 enable 一种内功。\n");

        if( arg=="none" )
                me->delete("force_factor");
        else {
                if( pts < 0 || pts > (int)me->query_skill("force")/3)
                        return notify_fail("你的内功无法发挥这么大的威力。\n");
                if (pts >150)
                	return notify_fail("Enforce 最大容许值是150。\n");
                me->set("force_factor", pts);
        }

        write("Ok.\n");
        return 1;
}

int help (object me)
{
        write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	enforce|jiali <使出几点内力伤敌>|none[0m
[0;1;37m────────────────────────────────[0m   
 
这个指令让你指定每次击中敌人时，要发出几点内力伤敌。
内力越高，对敌人的伤害越大。

enforce none 则表示你不使用内力。 

风云2005中最高 enforce值为150。
[0;1;37m────────────────────────────────[0m   
HELP
        );
        return 1;
}
 
