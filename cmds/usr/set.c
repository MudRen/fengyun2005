
// set.c

#define MAX_ENV_VARS    20
#include <ansi.h> 
inherit F_CLEAN_UP;

int help(object me);
int main(object me, string arg)
{
    int i;
    string term, *terms, *wiz_only;
    mixed data;
    mapping env;

    if (arg) arg = replace_string(arg, "/", "");
    wiz_only = ({"invisibility", "immortal"});

    if( me != this_player(1) ) return 0;

    env = me->query("env");

    if( !arg || arg=="" ) {
	write("你目前设定的环境变数有：\n");
	if( !mapp(env) || !sizeof(env) )
	    write("\t没有设定任何环境变数。\n");
	else {
	    terms = keys(env);
	    for(i=0; i<sizeof(terms); i++)
		printf("%-20s  %O\n", terms[i], env[terms[i]]);
	}
	return 1;
    }

    if( sscanf(arg, "%s %s", term, data)!=2 ) {
		term = arg;
		data = "YES";
    }

    //      if(term == "wimpy") return notify_fail("请用WIMPY这个指令。\n"); 

    if( term && term!="" ) {
		if( mapp(env) && undefinedp(env[term]) && sizeof(env) >= MAX_ENV_VARS )
		    return notify_fail("你设的环境变数太多了，请先用 unset 删掉几个吧。\n");
		sscanf(data, "%d", data);
		if(!wiz_level(me) && (member_array(term, wiz_only) != -1))
		    return notify_fail("只有巫师才能使用这个设定。\n");
		    
		if (term=="msg_mout" || term=="msg_min"){
		    if (!stringp(data)) return 0;
		    data = replace_string(data, "$BLK$", BLK);
		    data = replace_string(data, "$RED$", RED);
		    data = replace_string(data, "$GRN$", GRN);
		    data = replace_string(data, "$YEL$", YEL);
		    data = replace_string(data, "$BLU$", BLU);
		    data = replace_string(data, "$MAG$", MAG);
		    data = replace_string(data, "$CYN$", CYN);
		    data = replace_string(data, "$WHT$", WHT);
		    data = replace_string(data, "$HIR$", HIR);
		    data = replace_string(data, "$HIG$", HIG);
		    data = replace_string(data, "$HIY$", HIY);
		    data = replace_string(data, "$HIB$", HIB);
		    data = replace_string(data, "$HIM$", HIM);
		    data = replace_string(data, "$HIC$", HIC);
		    data = replace_string(data, "$HIW$", HIW);
		    data = replace_string(data, "$NOR$", NOR);
		    data+= NOR;
		}
		if (term && data)			
		if (term == "savemyass"){
			if (!stringp(data))	
				return notify_fail("savemyass 后面只能跟命令，跟数字没有意义。\n");
			if (strsrch(data,"quit")!=-1)
				return notify_fail("风云战斗中不能退出，此参数没有意义。\n");
		}
		
		if(term == "wimpy") //return notify_fail("请用WIMPY这个指令。\n"); 
		    if( !intp(data) || data <0 || data >99  )
			return notify_fail("WIMPY后的参数请设置0-99内的某一数值。\n");
		
		if (term == "e_money" && !REWARD_D->check_m_success(me,"四海金卡"))
			return notify_fail("你还不持有四海金卡，无法享受该项业务。\n");
		
		if (term == "target" && me->query_temp("timer/lost_target")+ 20 > time())
			return notify_fail("你脑中一片混乱，暂时无法正确地锁定目标。\n");
			
		me->set("env/" + term, data);
		printf("设定环境变数：%s = %O\n", term, data);
		return 1;
    }
    return 1;
}


int help(object me)
{
	write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : set 变数名 [变数值][0m
[0;1;37m────────────────────────────────[0m
你可以用 set 指令设定一些有用的环境变数，这些变数也会随著你的
人物被储存下来，如果有不需要的环境变数，可以用 unset 删除。
详细的使用方法请看 help set 及 help unset。

以下是目前有用的环境变数：

brief		<任何非零的值>	移动时只看所在地简短的名称，如果
				您的网路速度不是很快，或者是对区域
				已经十分熟悉，建议您打开 brief以减
				轻网路负担。
brief2				移动时只看所在地简短的名称和人和物。
brief3				移动时只看所在地简短的名称和人物及出口。
				
wimpy		<百分比>	当您的精气神低於这个百分比时就会自动执
				行savemyass所指定的命令。如果savemyass
savemyass	<任何指令>	没有设置，则自动让你尝试逃离当前位置。
				
no_tell		<id/all>	使玩家（id）或所有玩家（all）都无法
				和你说话。

no_give         <1 或 0>	如果是1，将不接受任何来自于其他玩家的外
				来物品。缺省值为0。				
				
revive          <1 或者 0>      如果是1，他人可利用心识神通等帮助
				你复活，如果是0则不能。缺省设置0，
				每次复活后复零。
	
equip_msg 	<1，2 或者 3>	此指令的目的是为了减少频繁的穿戴
				脱卸刷屏。如果设为１，你将看不到自
				己装备／去除武器装备的信息；如果是
				２，你将看不到别人装备／去除武器装
				备的信息；如果是3，两个都看不到。
				为节省系统资源，新人登陆时自动设为2。
							
savemymoney     <1 或 0>	如果是1，杀天骄的奖励将直接存入你的
				银行账号。	

ability				将Quest的奖励转为能力点

e_money		<1 或 0>	如果是1，买卖将直接从银行转账，该功能
				只能在四海金卡激活后使用。

target		<id>		设定攻击对象

dmg_msg		<1 或 0>	如果是1，系统将输出一系列状态信息

no_cbm		<1 或 0>	屏蔽所有打斗信息

no_others_cbm   <1 或 0>	屏蔽他人打斗信息

[0;1;37m────────────────────────────────[0m
HELP
		);
	return 1;
}
