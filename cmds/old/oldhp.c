// hp cmds (Mon  09-04-95)
 
#include <ansi.h>
 
inherit F_CLEAN_UP;
 
string status_color(int current, int max);
 
int main(object me, string arg)
{
    object ob;
    mapping my;
 
    seteuid(getuid(me));
 
    if(!arg) ob = me;
    else if (wizardp(me))
    {
        ob = present(arg, environment(me));
        if (!ob) ob = find_player(arg);
        if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("你要察看谁的状态？\n");
    }
    else return notify_fail("只有管理员能察看别人的状态。\n");
    
    my = ob->query_entire_dbase();
    
    printf(" 精力  ： %s%4d/ %4d %s(%3d%%)" NOR "    食物： %s%3d%%\n" NOR,
           status_color(my["gin"], my["eff_gin"]),	my["gin"],	my["eff_gin"],
           status_color(my["eff_gin"], my["max_gin"]),	my["eff_gin"] * 100 / my["max_gin"],
           status_color(my["food"], ob->max_food_capacity()),
           my["food"] * 100/ob->max_food_capacity()	
        );
    printf(" 气血  ： %s%4d/ %4d %s(%3d%%)" NOR "    饮水： %s%3d%%\n" NOR,
           status_color(my["kee"], my["eff_kee"]), my["kee"], my["eff_kee"],
           status_color(my["eff_kee"], my["max_kee"]),     my["eff_kee"] * 100 / my["max_kee"],
           status_color(my["water"], ob->max_water_capacity()),
           my["water"] * 100/ob->max_water_capacity()
        );
    printf(" 心神  ： %s%4d/ %4d %s(%3d%%)" HIW "    评价： %d\n" NOR,
           status_color(my["sen"], my["eff_sen"]), my["sen"], my["eff_sen"],
           status_color(my["eff_sen"], my["max_sen"]),     my["eff_sen"] * 100 / my["max_sen"],
           my["score"]
        );
    printf(" 灵力  ： %s%4d/ %4d (%4d)" HIR "    杀气： %d\n" NOR,
           status_color(my["atman"], my["max_atman"]),     my["atman"], my["max_atman"],
           my["atman_factor"],
           my["bellicosity"]
        );
    printf(" 内力  ： %s%4d/ %4d (%4d)"  HIG "    潜能： %d\n" NOR,
           status_color(my["force"], my["max_force"]),     my["force"], my["max_force"],
           my["force_factor"],
           (my["potential"] - my["learned_points"])
        );
    printf(" 法力  ： %s%4d/ %4d (%4d)"HIM "    经验： %d\n" NOR,
           status_color(my["mana"], my["max_mana"]), my["mana"], my["max_mana"],
           my["mana_factor"],
           my["combat_exp"]
        );

    return 1;
}
 
string status_color(int current, int max)
{
    int percent;
 
    if( max>0 ) percent = current * 100 / max;
    else percent = 100;
    if( percent > 100 ) return HIC;
    if( percent >= 90 ) return HIG;
    if( percent >= 60 ) return HIY;
    if( percent >= 30 ) return YEL;
    if( percent >= 10 ) return HIR;
    return RED;
}
 
int help(object me)
{
    write(@HELP
指令格式 : hp
 
这个指令可以显示你(玩家)的一些基本状态：

 精力  ：  545/  545 (100%)    食物：  74%
 气血  ：  838/  838 (100%)    饮水：  74%
 心神  ：  544/  544 (100%)    评价： 104
 灵力  ：  220/  220 (   0)    杀气： 156
 内力  ：  543/  543 (  34)    潜能： 751
 法力  ：  350/  219 (   0)    经验： 97775

see also : score
HELP
    );
    return 1;
}
