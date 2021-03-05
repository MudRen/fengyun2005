// help.c  -- by Silencer@fengyun workgroup

#include "/doc/help.h"
#include <ansi.h>

inherit F_CLEAN_UP;
string *default_search = DEFAULT_SEARCH_PATHS;

void selete_main(string num,object ob, string file);
void back_off(string num, object ob, string file);
void quit_help(object ob);

string *game = ({ "questing", "tasking", "riddle","ability","pfm_r1",
					"marry",	"selfroom", "selfmade","death","poison", 
					"settings", "color","level", "books", "questbuff","boss",
					"questbox", "ccard", "ccard", "ccard", "ccard", "scroll",
				 });
string *cmds = ({ "cmds_1", "cmds_2", "cmds_3","cmds_4", "cmds_5", "cmds_6","cmds_7","cmds_8"});
string *newbie = ({ "newbie_1", "newbie_2","newbie_3","newbie_4","newbie_5","newbie_6","newbie_7",
				"newbie_8","newbie_9","newbie_10","newbie_11","newbie_12","newbie_13","newbie_14"});
string *rules = ({ "copyright", "rules", "people" });
string *menpai = ({ "chaoting", "gaibang", "wudang", "huashan", "wolfmount",
			"shaolin", "dazhaosi", "xingguo","diwanggu", 
			"kuaihuo", "sanqing", "shenshui", "haoyue",
			 "tiexue", "fugui",
			"mojiao", "bianfu", "baiyun", "jinqian","wanmei","shenjian", "tianfeng",
			"others",
			 });

string *maps = ({
"map.txt",
"fengyun_map.txt","biancheng_map.txt","chenxiang_map.txt","guanwai_map.txt", 
"jinan_map.txt", "laowu_map.txt","loulan_map.txt", "qianjin_map.txt","taiping_map.txt", 
"taoyuan_map.txt",

 "huashan_map.txt","huangshan_map.txt","kunlun_map.txt","manglin_map.txt","qianfo_map.txt",
 "sanqing_map.txt", "songshan_map.txt", "taishan_map.txt", "wolfmount_map.txt", "wudang_map.txt",
 "shaolin_map.txt", "daimiao_map.txt",

"diwanggu_map.txt", "ehu_map.txt","heisong_map.txt","laoyun_map.txt", "shenshui_map.txt",
"dixia_map.txt","fugui_map.txt","qingping_map.txt","tianfeng_map.txt","tiexue_map.txt",
 "wanmei_map.txt","youling_map.txt",

"baiyun_map.txt", "bat_map.txt","changchun_map.txt",

"east_map.txt","west_map.txt","wulapo_map.txt","zangbei_map.txt","diyu_map.txt",
"cyan_map.txt","xiangsi_map.txt","bashan_map.txt",
});

string *quest = ({
"fengyun.txt","chenxiang.txt","heisong.txt","diwanggu.txt",
"taoyuan.txt", "wudang.txt", "xingguo.txt", "jixiang.txt",
"fugui.txt","guanwai.txt","laowu.txt","wanmei.txt",
"qingping.txt","qianjin.txt","wolfmount.txt","taishan.txt",
"huashan.txt","huangshan.txt","shaolin.txt","changchun.txt",
"ehugang.txt","donghai.txt","bat.txt","dixiacheng.txt",
"taiping.txt","erlangshan.txt","zangbei.txt","eren.txt",
"xiangsi.txt","mingxia.txt","baiyun.txt","daimiao.txt",
"shenshui.txt","saikou.txt","biancheng.txt","sanqing.txt",
"mojiao.txt",
});
   
int main(object me, string arg)
{
        int i;
        string file, map, *search;
        object ob;
        ob = this_player();

	
	if (ob->query_temp("timer/help_list")+1 > time())
		return notify_fail("帮助系统正在恢复中，请在一秒后使用。\n");
	ob->set_temp("timer/help_list",time());
	
	// 如果没有选项，提供主菜单及五个选项。
	if( !arg ) {
		write(CLR);
        	write(read_file("/doc/help/help_main"));
        	return 1;
	}

//	ｃｍｄｓ／ｎｅｗｂｉｅ／ｇａｍｅ／ｒｕｌｅｓ／ｍｅｎｐａｉ／－ｑｕｅｓｔ产生菜单，其他ｍａｐｓ直接文件。
	
	if (arg == "cmds" || arg == "newbie" || arg == "game" || arg == "rules" || arg == "menpai" || arg == "where"|| arg == "book" || arg == "maps" || arg == "quest" || arg == "road" || arg == "boss" || arg == "boss2" || arg == "boss3" ) {
		write(CLR);
		file = "/doc/help/help_"+arg;
		write(read_file(file));
		input_to("selete_main",ob,file);
		return 1;
	}

	// Else, try if a command name is specified.
	seteuid(getuid());
	if( stringp(file = me->find_command(arg)) ) {
		notify_fail("有这个指令存在，但是并没有详细的说明文件。\n");
		return file->help(me);
	}

	// Search the individual search path first.
	if( pointerp(search = me->query("help_search_path")) ) {
		i = sizeof(search);
		while(i--) if( file_size(search[i] + arg)>0 ) {
			me->start_more("", read_file(search[i] + arg), 0);
			return 1;
		}
	}

	// Support efun/lfun help with same name as other topics such as
	// ed() and ed command.
	sscanf(arg, "%s()", arg);

	// Finally, search the default search paths.
	if( pointerp(default_search) ) {
		i = sizeof(default_search);
		while(i--) if( file_size(default_search[i] + arg)>0 ) {
			me->start_more("", color_filter(read_file(default_search[i] + arg)), 0);
			return 1;
		}
	}

	return notify_fail("没有针对这项主题的说明文件。\n");

}

void selete_main (string num, object ob, string file)
{
        
        int number, total;
        string type, *data;
               
        if (ob->query_temp("timer/help_list")+2 > time())
        {
        	ob->add_temp("marks/repeat_help",1);
//        	CHANNEL_D->do_sys_channel(
//				"info",sprintf("%d",ob->query_temp("marks/repeat_help")));
        }	else
        	ob->delete_temp("marks/repeat_help");    
        
        if (ob->query_temp("marks/repeat_help")<4) {
	        ob->set_temp("timer/help_list",time()); 
	        if (sscanf(num,"%d",number)== 1) {
	        	sscanf( file, "/doc/help/help_%s", type);
	        	switch (type) {
	        		case "game": 	data = game; 	break;
	        		case "newbie":  data = newbie;	break;
	        		case "cmds":	data = cmds; 	break;
	        		case "rules":   data = rules;   break;
	        		case "menpai":  data = menpai;  break;
	        		case "maps":	data = maps;	break;
	        		case "quest":	data = quest;	break;
	        		default:	
	        	}
	        	
	        	if (data) {
		        	total = sizeof(data);
		        	if ( number <= total && number) {
		                	write(CLR);
					
		                	if ( type != "menpai") {
		                		write(read_file("/doc/help/"+type+"/"+ data[number-1]));
		                		input_to("back_off",ob, file);	
		                	} else 
		                		ob->start_more("", color_filter(read_file("/doc/help/"+type+"/"+ data[number-1]+".txt")), 0);
		                	return;
			       	}else if( number == 0) 		{
		    	    	quit_help(ob);
		        		return;	
		        	}
	        	}
	        }
        }  

        ob->delete_temp("marks/repeat_help");    
       	quit_help(ob);
//     	input_to("selete_main", ob, file);
}

void back_off(string num, object ob, string file)
{
	write(CLR);
//      write("file is "+file+"\n");
        write(color_filter(read_file(file)));
        input_to("selete_main", ob, file);
}

void quit_help(object ob)
{
     	write(HIC"\n 谢谢使用风云命令帮助系统，进一步的说明可参见各具体命令！\n\n"NOR);
        return;
}


int help(object me)
{
	write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	help <主题>    例如：> ｈｅｌｐ　ｓｔｕｄｙ[0m
[0;1;37m────────────────────────────────[0m   

这个指令提供你针对某一主题的详细说明文件，

相关选项有：
ｈｅｌｐ　				主目录
ｈｅｌｐ　ｎｅｗｂｉｅ			初入风云指南
ｈｅｌｐ　ｃｍｄｓ			风云所有指令汇编
ｈｅｌｐ　ｇａｍｅ			详尽介绍游戏内容
ｈｅｌｐ　ｍｅｎｐａｉ			风云中的武功门派
ｈｅｌｐ　ｒｕｌｅｓ			风云游戏规则
ｈｅｌｐ　ｍａｐｓ			风云地图汇总
ｈｅｌｐ　ｑｕｅｓｔ			风云任务帮助
ｈｅｌｐ　＜某一个具体指令＞		对某一个指令的具体说明

注意为了减轻系统负担，连续输入的选择将不做反应。

[0;1;37m────────────────────────────────[0m 
HELP
	);
	return 1;
}

