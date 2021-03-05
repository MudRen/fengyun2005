// purge.c

#include <ansi.h>
#define SYNTAX	"指令格式：purge [<未上线天数>] | <使用者姓名> because <原因>\n"

inherit F_CLEAN_UP;
int rmhirdir(string dir);
private int do_purge_players(int day);
int main(object me, string arg)
{
	string name, reason;
	string status;
	int day;

	status = wizhood(me);
	if( me!=this_player(1)
		|| wiz_level(me) < wiz_level(status))
		return notify_fail("你没有权力使用这个指令。\n");

	if( !arg ) return notify_fail(SYNTAX);

	if( sscanf(arg, "%d", day) && day >= 30) return do_purge_players(day);

	if( sscanf(arg, "%s because %s", name, reason)!=2 )
		return notify_fail(SYNTAX);

	if (reason == "bad")
		return notify_fail("请详细写明杀档原因。\n");
		
	seteuid(getuid());
	
	if( file_size(DATA_DIR + "login/" + name[0..0] + "/" + name + "/" + name + SAVE_EXTENSION)<0 )
		return notify_fail("没有这位使用者。\n");

	if( (string)SECURITY_D->get_status(name)!="(player)" )
		return notify_fail("不能直接删除管理人员的档案（你总该知道怎么做吧）。\n");

       	LOGIN_D->cphirdir(DATA_DIR + "login/" + name[0..0] + "/" + name, "/suicide/login/"+  "purged"+ name+time());
        LOGIN_D->cphirdir(DATA_DIR + "user/" + name[0..0] + "/" + name, "/suicide/user/"+ "purged"+ name + time());
        
      	rmhirdir(DATA_DIR + "login/" + name[0..0] + "/" + name );
      	rmhirdir(DATA_DIR + "user/" + name[0..0] + "/" + name );

	write( "使用者 " + capitalize(name) + " 删除掉了。\n");
	write( "被删除的档案保存在suicide目录下，以purged" +  name + time() +"命名。\n");
	
	log_file("static/PURGE", sprintf("[%s] %s purged %s because %s.\n",
		ctime(time())[0..15], geteuid(this_player(1)), name, reason));

	return 1;
}

private int do_purge_players(int day)
{
	int i, j, ppl_cnt, count;
	string *dir, *ppls, name;
	mixed info;
	int info2;

	seteuid(getuid());
	message("system", "\n*** 整理玩家储存档中，请稍候.... ***\n", users());
	write("处理中：");
	count = 0;
	ppl_cnt = 0;
	dir = get_dir(DATA_DIR + "login/");
	for(i=0; i<sizeof(dir); i++) {
		reset_eval_cost();
		write(dir[i]);
		ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
		ppl_cnt += sizeof(ppls);
		for(j=0; j<sizeof(ppls); j++) {
			if( sscanf(ppls[j], "%s", name)==1 )
				if( (string)SECURITY_D->get_status(name)!="(player)" )
					continue;
			info = stat(DATA_DIR + "login/" + dir[i] + "/" + ppls[j] +"/" +  ppls[j] + SAVE_EXTENSION);
			info2 = file_size(DATA_DIR + "login/" + dir[i] + "/" + ppls[j]
			 +"/" +  ppls[j] + SAVE_EXTENSION);  
			if( info2 < 0 || time()-info[1] >= day*86400 ) {
				rmhirdir(DATA_DIR + "login/" + dir[i] + "/" + ppls[j] );
				rmhirdir(DATA_DIR + "user/" + dir[i] + "/" + ppls[j] );
				count ++;
			}
		}
	}
	write("\n\n原来总共有 " + ppl_cnt + " 位使用者。\n");
	write( count + " 个超过 " + day + " 天未上线的使用者被清除掉了。\n");
	write("现在总共有 " + (ppl_cnt - count) + " 位使用者。\n");
	log_file("static/PURGE", sprintf("[%s] %s cleaned up %d characters who didn't login for more than %d days\n"
		"\t\tResulting statistics: %d characters remaining.\n",
		ctime(time())[0..15], geteuid(this_player(1)), count, day, ppl_cnt - count));


	return 1;
}


int rmhirdir(string dirstr)
{
string *dir;
int i;
dir = get_dir(dirstr+"/");
        for(i=0; i<sizeof(dir); i++) {
		if(file_size(dirstr+"/"+dir[i]) == -2 ) {
				rmhirdir( dirstr +"/"+dir[i]);
				rmdir(dirstr+"/"+dir[i]);
						}
		rm(dirstr+"/"+dir[i]);
	}
rmdir(dirstr);

return 1;

}
int help(object me)
{
write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : purge [<未上线天数>] | <使用者姓名> because <原因>[0m
[0;1;37m────────────────────────────────[0m   

清除一个使用者或清除超过一定天数不曾上线地使用者。
现在把purged档案也备份下来以留纪录。

[0;1;37m────────────────────────────────[0m 
HELP
	);
    return 1;
}

