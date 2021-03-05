// friend.c 
// -silencer@fy4.com

#include <ansi.h>

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	string msg, name, *friends,*new_friends;
	object body,ob;
	int i;
	
	if (me->query_temp("timer/big_cmd")+10 > time())
		return notify_fail("此命令比较耗费系统资源，每十秒只能执行一次。\n");
	else
		me->set_temp("timer/big_cmd",time());
			
	friends = me->query("friends_list");
	if (!friends) 
		friends=({});
	
	new_friends=friends;
	
	if( (int)me->query("sen") < 150 && !wizardp(me))
			return notify_fail("至少需要１５０点心神。\n");
	
	if( !arg ) {
		if (!sizeof(friends)) {
			write("你的通讯录是空的。\n");
			return 1;
		}	
		write(HIR"\n你的好友录名单如下:"HIY"
===========================================================\n\n"NOR);			
		for (i=0;i<sizeof(friends);i++) {
			name=friends[i];
			ob = new(LOGIN_OB);
			ob->set("id", name);
			if (!ob->restore() || ob->query("id")=="hippo" || ob->query("id")=="gygao" || ob->query("id")=="silencer" ) {
				msg=sprintf(YEL"%-26s\t不存在，已自动从你的通讯录中除名。\n"NOR, name);
				new_friends=new_friends-({name});
				write(msg);
				continue;
			}	
			if( objectp(body = find_player(name)) && geteuid(body)==name && ob->query("id")!="hippo" && ob->query("id")!="gygao" && ob->query("id")!="silencer" ) 
                		msg = sprintf(HIG"%-16s%-10s\t目前正在连线中。\n"NOR, ob->query("name"),name); 
			else 
				msg=sprintf(CYN"%-16s%-10s\t目前不在连线中。\n"NOR, ob->query("name"),name);
			write(msg); 
			destruct(ob);
		}
		write(HIY"
============================================================\n"NOR);
		me->set("friends_list",new_friends);
		if (!wizardp(me)) me->receive_damage("sen",150);
	}
	else	{
		ob = new(LOGIN_OB);
		ob->set("id", arg);
		if( !ob->restore() || ob->query("id")=="hippo" || ob->query("id")=="gygao" || ob->query("id")=="silencer" ) {
			write ("没有这个玩家。\n");
			return 1;
		}
		if ( !friends || member_array(arg,friends)==-1) { 
			if (sizeof(friends)>=15) {
				write(HIR"通讯录中最多只能有十五个名字，请删去一些不常用的。\n"NOR);
				return 1;
			}
			me->set("friends_list",friends+({arg}));
			write(WHT"你将玩家 "+ob->query("name")+"（"+arg+"） 加入通讯录。\n"NOR);
		}else 	{
			me->set("friends_list",friends-({arg}));
			write(WHT"你将玩家 "+ob->query("name")+"（"+arg+"） 从通讯录中去除了。\n"NOR);
		}
		destruct(ob);
	
	}

	return 1;
}

int help(object me)
{
  write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	friend [玩家英语代号][0m
[0;1;37m────────────────────────────────[0m   
  
此指令为开关式，第一次打入将把一个玩家名字加入你的通讯录，
对同样的玩家名字再次操作将把此名字从通讯录中删除。如果不
跟任何参数则将显示通讯录中所有玩家的在线状况。通讯录中最
多可存储十五个名字。

see also : who, finger

[0;1;37m────────────────────────────────[0m 
HELP
    );
    return 1;
}
 
