// annie 07.2003
// dancing_faery@hotmail.com
// check status

#include <ansi.h>

int main(object me, string arg)
{
	mapping buff_list,buff;
	string *lists, name;
	int i,time,warn_time,idx;
	object ob;
	
	mapping cont_list, vend_list;
	string *show_cont;
	int *num;
	
	if (arg && wizardp(me))
	{
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("你要察看谁的状态？\n");
	} else
		ob = me;
	
	buff_list = ob->query_temp("buff");
	cont_list = ob->query_all_condition();
	vend_list = ob->query("vendetta");
	
	tell_object(me, WHT"\t　　当前状态：\n"NOR);
	tell_object(me, HIR BLK"────────────────\n"NOR);

	if( (!mapp(buff_list) || !sizeof(buff_list))
		&& (!mapp(cont_list) || !sizeof(cont_list))
		&& (!mapp(vend_list) || !sizeof(vend_list)))
	{
		tell_object(me, "没有任何异常状态作用中。\n");
		tell_object(me, HIR BLK"────────────────\n"NOR);
		return 1;
	}
	
	seteuid(getuid());
	if (mapp(buff_list) && sizeof(buff_list))
	{	lists = keys(buff_list);
		for(i=0; i<sizeof(lists); i++)
		{
			if (!sscanf(lists[i],"%d",idx))	continue;
			buff = ob->query_temp("buff/"+lists[i]);
			if (buff["att"] == "bless")
				tell_object(me, CYN);
			if (buff["att"] == "curse")
				tell_object(me, MAG);
	
			tell_object(me, ""+buff["name"]+NOR);
	
			time = buff["time"];
			warn_time = time / 40;
			if (warn_time < 15)
				warn_time = 15;
			if (warn_time > time)
				warn_time = 3;
			time = time + ob->query_temp("buff_time/"+lists[i])-time();
			if (time > warn_time)
				tell_object(me, YEL);
			else
				tell_object(me, RED);
			tell_object(me, "\t"+time+NOR" sec\n");
		}
	}
	
	if (mapp(cont_list) && sizeof(cont_list))
	{
		write(HIR BLK"────────────────\n"NOR);
		lists = keys(cont_list);
		num  = values(cont_list);
		for (i=0; i< sizeof(lists);i++)
		{
			if (CONDITION_D(lists[i])->shown_stat()
				&& stringp(name = CONDITION_D(lists[i])-> cont_name())
				&&  num[i]>0)
			{
				tell_object (me, sprintf(MAG"%-16s%3d 次\n", name, num[i]));
			}	
		} 
	}	
	
	if (mapp(vend_list) && sizeof(vend_list))
	{
		write(HIR BLK"────────────────\n"NOR);
		lists = keys(vend_list);
		num  = values(vend_list);
		for (i=0; i< sizeof(lists);i++)
		{
			if(lists[i] == "shaolin" && num[i])
				tell_object (me, sprintf(HIB"%-16s%3d \n", "少林匪", num[i]));
			else if(lists[i] == "authority" && num[i])
				tell_object (me, sprintf(HIB"%-16s%3d \n", "官匪", num[i]));
			else if(lists[i] == "demon" && num[i])
				tell_object (me, sprintf(HIB"%-16s%3d \n", "魔教匪", num[i]));
							
		} 
	}	
	 
	tell_object(me, HIR BLK"────────────────\n"NOR);


	return 1;
}


int help(object me)
{
write(@HELP

[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	stat [0m
[0;1;37m────────────────────────────────[0m   

这个指令可以让你知道你目前所拥有的所有异常状态与持续时间。

[0;1;37m────────────────────────────────[0m  
HELP
    );
    return 1;
}
 
 
