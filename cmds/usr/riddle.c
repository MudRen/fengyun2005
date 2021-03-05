// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
    mapping riddle;
    string *list, attr;
    object ob;
    int i,j, *num;

    if (wizardp(me) && stringp(arg))	
    {
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("咦... 有这个人吗?\n");
    }else
	ob = me;

	riddle = ob->query("riddle");	 
    	
    write(WHT"\t　　		" + ob->name()+ "正在解的谜题\n"NOR);
    write(HIR BLK"───────────────────────────────────────\n"NOR);

    if (!riddle)	write (HIR "无\n"NOR);
    else
    {
		list = keys(riddle);
		i = 0;					// deal with the problem of setting riddle=0
		for(j=0; j<sizeof(list); j++)
		{
		    if (riddle[list[j]])
		 	{
		    	if(i%5!=4) 
					write(sprintf(YEL"%-16s"NOR,list[j]));
		    	else 
					write(YEL + list[j] + "\n"NOR);   
				i++;
			}
		}
    }
    write(HIR BLK"\n───────────────────────────────────────\n"NOR);
    
 
    riddle = ob->query("m_success");

    write(WHT"\t　　		"+ob->name()+ "已经解开的谜题\n"NOR);
    write(HIR BLK"───────────────────────────────────────\n"NOR);

    if (!riddle)	write (HIR "无\n"NOR,16);
    else
    {
	list = keys(riddle);
	for(i=0; i<sizeof(list); i++)
	{
	    if(i%5!=4) 
		write(sprintf(CYN"%-16s"NOR,list[i]));
	    else
		write(CYN + list[i] + "\n"NOR);   
	}
    }
    write(HIR BLK"\n───────────────────────────────────────\n"NOR);


    riddle = ob->query("imbue");

    write(WHT"\t　　		" + ob->name()+ "解谜增加的属性\n"NOR);
    write(HIR BLK"───────────────────────────────────────\n"NOR);

    if (!riddle)	write (HIR "无\n"NOR);
    else
    {
	list = keys(riddle);
	num = values(riddle);
	for(i=0; i<sizeof(list); i++)
	{
	    switch (list[i])
	    {
	    	case "agi": attr = "速度"; break;
	    	case "int": attr = "才智"; break;
	    	case "con": attr = "体质"; break;
	    	case "str": attr = "力量"; break;
	    	case "cps": attr = "定力"; break;
	    	case "kar": attr = "运气"; break;
	    	default: attr = "";
	    }		
	    
	    if (sizeof (attr)>0)
		write(HIR + attr +" +" + num[i] + "\t"NOR);   
	}
    }
    write(HIR BLK"\n───────────────────────────────────────\n"NOR);

    return 1;
}
int help(object me)
{
    write(@HELP

[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	riddle            [0m
[0;1;37m────────────────────────────────[0m   

这个指令可以让你知道你目前已经解开的谜题，以及因解密增加的属性

[0;1;37m────────────────────────────────[0m  
HELP
    );
    return 1;
}


