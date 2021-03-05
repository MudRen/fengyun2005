#include <ansi.h>

int rmhirdir(string dir);

int main(object me, string arg)
{
    	if( me->is_busy() )
        	return notify_fail("你上一个动作还没完成。\n");

    	if( !arg )
    	{
        	write("你想自杀，但是想了想又下不了手。\n");
        	return 1;
    	}

    	if( arg!="-f" ) 
        	return notify_fail("自杀有两种，您是要永远死掉还是重新投胎？\n");

//		if (wizardp(me))
//		return notify_fail("管理人员不允许自杀。\n");
		
		if (me->query("combat_exp")< 4000)
			return notify_fail("你的经验值太低，系统不作保留，无需自杀，退出便是。\n");
		
    if (me->query("combat_exp")>= 2100000)
    	return notify_fail("
你在风云里小有名气，已经没法轻易自杀了。（等级高于50）
风云将在不久的将来推出退隐系统，让你金盆洗手，永别江湖，为后人留下难忘的回忆。\n");
    	
    write(HIR"如果您选择永远死掉的自杀方式，您的资料就永远删除了，一旦\n"
         	 "输入密码则不可再后悔了：\n"NOR);
		if (me->query("marry"))
			write(HIY"注意！你的伴侣将因此而守寡，风云工作组亦不会对此作\n出任何补偿，请慎重决定！\n"NOR);
   	input_to("check_password", 1, me, 1);
    return 1;
}

private void check_password(string passwd, object me, int forever)
{
    	object link_ob;
    	string old_pass;
    	string name;
    	link_ob = me->query_temp("link_ob");
    	old_pass = link_ob->query("password");
    	if( crypt(passwd, old_pass)!=old_pass )
    	{
        	write("密码错误！\n");
        	return;
    	}

    	if (forever)
    	{
        	tell_object( me,WHT "
        	
        	秋风清，秋风明，
             落叶聚还散，寒鸦栖复惊。
        相思相见知何日，此时此夜难为情。
        	
    永别了，希望风云能给你留下一段难忘的回忆。\n\n\n" NOR);
        	link_ob = me->query_temp("link_ob");
        	if( !link_ob ) return 0;

        	log_file("static/SUICIDE",
                	sprintf("%s commits a suicide on %s\n", geteuid(me), ctime(time())) );

        	seteuid(getuid());

//      name = me->query("id"); CALL-ID Bug，让我们从link_ob获得这个参数。
		name = link_ob->query("id");

        	if (me->query("combat_exp")>= 3000) 
        	{
        		LOGIN_D->cphirdir(DATA_DIR + "login/" + name[0..0] + "/" + name, "/suicide/login/"+name+time());
	        	LOGIN_D->cphirdir(DATA_DIR + "user/" + name[0..0] + "/" + name, "/suicide/user/"+name+time());
        	}
        	rmhirdir(DATA_DIR + "login/" + name[0..0] + "/" + name );
        	rmhirdir(DATA_DIR + "user/" + name[0..0] + "/" + name );

        	tell_room(environment(me), me->name() +
                  	"自杀了，以后你再也看不到这个人了。\n", ({me}));
        	CHANNEL_D->do_sys_channel("info",me->name(1)+"("+me->query("id")+
                                  ")自杀了，以后你再也看不到这个人了。");
        	destruct(me);
        	return 0;
    	}
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

int help (object me)
{
        write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	suicide -f[0m
[0;1;37m────────────────────────────────[0m   
 
如果因为某种原因你不想活了, 你可以选择自杀。
自杀的方式为:
 
suicide -f : 永远的除去玩家资料, 系统会要求你
             输入密码以确认身份。
 
如果你已结婚，此指令将导致你的伴侣离异。
请慎重选择 :)

[0;1;37m────────────────────────────────[0m   
 
HELP
);
        return 1;
}

