// wizlist.c
//	--- Credit goes to SNOWMAN@SJ, modified by Silencer@FY4

#include <ansi.h>

inherit F_CLEAN_UP;

mapping hoodname=([
	"(admin)" :  	"【"HIW" 系　统 "NOR"】",
	"(arch)" : 	    "【"HIR" 管　理 "NOR"】",
	"(wizard)" : 	"【"HIG" 开　发 "NOR"】",
	"(apprentice)": "【"HIY" 学  徒 "NOR"】",
	"(immortal)" :  "【"HIM" 顾　问 "NOR"】"
]);
int level(mixed, mixed);
int imm(string wizid);

int main(object me, string arg)
{
        string *list, hood = "", str;
        int i, j;

        list = sort_array(SECURITY_D->query_wizlist(), (: level :));
 //	    if (!wiz_level(me)) list = filter_array(list, (: imm :));
        str = sprintf("\n%-30s\n",
        	WHT"·"+MUD_NAME+"目前共有" + sizeof(list) + "位巫师·"NOR);
		str = replace_string(str, "  ", "─");
        i = sizeof(list);
        while(i--) {
                if (hood != wizhood(list[i])) {
                        hood = wizhood(list[i]);
                        if( j ){
                        	while(j > 6) j -= 6;
                        	j = 6 - j;
                        	if( j > 0){
                        		while(j--) str += "         ";
					str += "　";
                        	}
                        	else str += "　";
                        }
                        str += sprintf("\n　%-12s："NOR, hoodname[hood]);
                        j = 0;
                }

                j++;
                if( j > 6 && j%6==1 )
                	str += "　\n　\t\t";
		str += sprintf("%-9s", capitalize(list[i]));
        }

        if( j ){
                while(j > 6) j = j - 6;
                j = 6 - j;
                if( j > 0) {
                	while(j--) str += "         ";
			str += "　";
                }

                else str += "　";
        }
        
        write(str+"\n");
        
        if (wiz_level(me))
		write("
===================================================================
风云工作组分工：

"WHT"1。IMMORTAL 顾问"NOR"
IMMORTAL本身是玩家，非正式巫师，无法进入巫师频道，不能处理改动与游戏
或玩家有关的命令和数据。随着开站时间的延长，管理人员不可能二十四小时
在线，此权限可以交给一些可信任的又能长期在线、熟悉游戏规则的玩家，其
主要责任是帮助玩家，活跃气氛，解决一些蓄意捣蛋的问题。
目前可以处理的命令: edemote, nulock

"WHT"2。WIZARD 开发人员"NOR"
所有不管理当前站点的风云工作组人员，其主要目的在于观察了解游戏运行情
况，为进一步开发风云作准备。其责任为检查系统运行，寻找ＢＵＧ，此权限
无法修改或查看玩家数据。
可以处理的影响玩家命令: ban,exec,nuke,summon
full(自身), get(非NPC)，halt(自身)，goto（非内部）,update(玩家)

"WHT"3。ARCH 管理人员"NOR"
当前站点的管理人员，其责任为管理维护站点，处理玩家矛盾，修正错误（可
修改除系统记录外的数据）

"WHT"4。ADMIN 系统人员"NOR"
责任：协调风云工作组的任务，提供当前站点的硬件支持
===================================================================
\n");        
        return 1;
}

int imm(string wizid)
{
	return wiz_level(wizid) == 4;
}

int level(mixed ob1, mixed ob2)
{
        if (wiz_level(ob1) != wiz_level(ob2))
                return wiz_level(ob1) - wiz_level(ob2);
        return ob1 > ob2?-1:1;
}


int help(object me)
{
write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	wizlist[0m
[0;1;37m────────────────────────────────[0m   

用途 : 列出该游戏站点所有巫师名单。

[0;1;37m────────────────────────────────[0m 
HELP
     );
     return 1;
}
