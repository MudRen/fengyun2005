#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_LEVEL;

string status_color(int current, int max);	//颜色 
int main(object me, string arg)
{
    object ob, *t;

    mapping my;

    int num;

    seteuid(getuid(me));

    //    if (!wizardp(me) && me->query_temp("timer/big_cmd")+4 > time())
    //	return notify_fail("此类命令比较耗费系统资源，每四秒才能执行一次。\n");

    if(!arg) ob = me;
    else if (wizardp(me))
    {
	ob = present(arg, environment(me));
	if (!ob) ob = find_player(arg);
	if (!ob) ob = find_living(arg);
	if (!ob) return notify_fail("你要察看谁的状态？\n");
    }
    else 
	return notify_fail("只有管理员能察看别人的状态。\n");

    my = ob->query_entire_dbase();   	

    if (pointerp(t=ob->query_team())) {
	// If i am in a team
	me->set_temp("timer/big_cmd",time());
	num= sizeof(t);

	printf(HIC"≡"HIY"───────────────────────────────────────────────"HIC"≡\n"NOR);		
	while (num--) {
	    if(num == 0){
		printf(HIR"%-3s"NOR + CYN"%-20s"NOR, "※ ",t[num]->query("name") + "(" + t[num]->query("id") + ")");  
	    }else printf(CYN"%-23s"NOR, "   " + t[num]->query("name") + "(" + t[num]->query("id") + ")");   
	    printf("【精】%s%5d/%5d %s(%3d%%)" NOR,
	      status_color(t[num]->query("gin"), t[num]->query("eff_gin")),	t[num]->query("gin"),	t[num]->query("eff_gin"),
	      status_color(t[num]->query("eff_gin"), t[num]->query("max_gin")),	t[num]->query("eff_gin") * 100 / t[num]->query("max_gin"),
	    );
	    printf("【气】%s%5d/%5d %s(%3d%%)" NOR,
	      status_color(t[num]->query("kee"), t[num]->query("eff_kee")), t[num]->query("kee"), t[num]->query("eff_kee"),
	      status_color(t[num]->query("eff_kee"), t[num]->query("max_kee")),     t[num]->query("eff_kee") * 100 / t[num]->query("max_kee"),
	    );
	    printf("【神】%s%5d/%5d %s(%3d%%)" NOR,
	      status_color(t[num]->query("sen"), t[num]->query("eff_sen")), t[num]->query("sen"), t[num]->query("eff_sen"),
	      status_color(t[num]->query("eff_sen"), t[num]->query("max_sen")),     t[num]->query("eff_sen") * 100 / t[num]->query("max_sen"),
	    );
	    printf("\n");
	}
	printf(HIC"≡"HIY"───────────────────────────────────────────────"HIC"≡\n"NOR);	
    } else {	// Or I am not in a team	
	printf(HIC"≡"HIY"────────────────────────────"HIC"≡\n"NOR);	
	printf(CYN"  " + my["name"] + "(" + my["id"] +")\n"NOR);	
	printf(HIC"≡"HIY"────────────────────────────"HIC"≡\n"NOR);	
	printf(" 【精力】%s%5d/ %5d %s(%3d%%)" NOR "【灵力】%s%5d/ %5d (%3d)\n" NOR,
	  status_color(my["gin"], my["eff_gin"]),	my["gin"],	my["eff_gin"],
	  status_color(my["eff_gin"], my["max_gin"]),	my["eff_gin"] * 100 / my["max_gin"],
	  status_color(my["atman"], my["max_atman"]),     my["atman"], my["max_atman"],
	  my["atman_factor"],
	);
	printf(" 【气血】%s%5d/ %5d %s(%3d%%)" NOR "【内力】%s%5d/ %5d (%3d)\n" NOR,
	  status_color(my["kee"], my["eff_kee"]), my["kee"], my["eff_kee"],
	  status_color(my["eff_kee"], my["max_kee"]),     my["eff_kee"] * 100 / my["max_kee"],
	  status_color(my["force"], my["max_force"]),     my["force"], my["max_force"],
	  my["force_factor"],
	);
	printf(" 【心神】%s%5d/ %5d %s(%3d%%)" NOR "【法力】%s%5d/ %5d (%3d)\n" NOR,
	  status_color(my["sen"], my["eff_sen"]), my["sen"], my["eff_sen"],
	  status_color(my["eff_sen"], my["max_sen"]),     my["eff_sen"] * 100 / my["max_sen"],
	  status_color(my["mana"], my["max_mana"]), my["mana"], my["max_mana"],
	  my["mana_factor"],
	);
    }

    //	printf(HIC"≡"HIY"────────────────────────────"HIC"≡\n"NOR);

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
