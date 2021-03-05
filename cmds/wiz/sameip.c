#include <ansi.h>
#include "/doc/help.h"

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	object *ob_list;
	string msg="";
	string subip, temp, *unique_list;
	int i;
		
		
	unique_list= ({});
	
	if (!arg) 
	{
		ob_list = sort_array(users(),"sort_user",this_object());
		for(i=0;i<sizeof(ob_list);i++){
			msg += sprintf("%-10s %-10s %-20s %-20s\n",
				ob_list[i]->query("id"),
				ob_list[i]->query("name"),
				query_ip_number(ob_list[i]),
				query_ip_name(ob_list[i]));
			temp = query_ip_number(ob_list[i]);
			if (member_array(temp,unique_list) == -1)
				unique_list += ({temp});		
		}	
		me->start_more("", msg, 0);
		write(WHT"\n共计有"+ sizeof(unique_list)+"个不同的ip连线。\n"NOR);
		return 1;
	}
	if(!ob=find_player(arg))
	{
		msg = "含有＜"+arg+"＞IP的玩家的讯息：\n";
		subip=arg;
	}
	else
	{
		subip=query_ip_number(ob);
		msg="含有＜"+subip+"＞IP的玩家的讯息：\n";
	}
	ob_list = filter_array(users(),"select_user",this_object(),subip);
        for(i=0;i<sizeof(ob_list);i++)
        msg += sprintf("%-10s %-10s %-20s %-20s\n",
                ob_list[i]->query("id"),
                ob_list[i]->query("name"),
                query_ip_number(ob_list[i]),
                query_ip_name(ob_list[i]));
        me->start_more("", msg, 0);
        return 1;
}

int sort_user(object a, object b)
{
	return strcmp(query_ip_number(a), query_ip_number(b));
} 
int select_user(object a, string subip)
{
	if(strsrch(query_ip_number(a),subip) == -1) return 0;
	else return 1;
}

int help(object me)
{
   write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	sameip <id/arg/none>[0m
[0;1;37m────────────────────────────────[0m   

让你察看有关一个IP的所有在线玩家。

[0;1;37m────────────────────────────────[0m 
HELP
   );
   return 1;
}

string tot_usr(object me)
{
return chinese_number(sizeof(filter_array(users(),"select_user",this_object(),query_ip_number(me))));
}
