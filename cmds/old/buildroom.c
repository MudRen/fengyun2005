inherit F_CLEAN_UP;
int check_legal_name(string name);
int check_legal_long(string name);
void enter_desc(object me,object gold,string s_title, int flag,string dir, string text);
#define SCORE_COST 5000
#define GOLD_COST  1000
#define MIN_EXP	100000
int main(object me, string arg)
{
	int flag;
	string stitle;
	string ltitle;
	string dir;
	object env;
	object gold;
        seteuid(getuid());
        if(!arg || sscanf(arg,"%s %s %d",dir,stitle,flag) != 3)
		return notify_fail("指令格式：　buildroom north 我的小屋 0\n");
	if((int)me->query("score") < SCORE_COST)
		return notify_fail("你的评价点不够"+chinese_number(SCORE_COST)+	"点。\n");
        if((int)me->query("combat_exp") < MIN_EXP)
        	return notify_fail("你的实战经验不够。（需15级）\n");
	gold = present("gold_money",me);
		if(!gold) return notify_fail("你身上没有金子。\n");
        if((int) gold->query_amount() < GOLD_COST)
        	return notify_fail("你身上没有"+chinese_number(GOLD_COST)+"两金子。\n");
	if((int)me->query("created_room") > 3)
		return notify_fail("你不可再建房了！\n");
        
        env = environment(me);
        if(!env->query("owner") && (string)env->query("owner") != "public" 
	&& (string)env->query("owner") != (string) me->query("id"))
        	return notify_fail("你不可在这建房！\n");
	if(check_legal_name(stitle))
		 me->edit( (: enter_desc , me,gold, stitle, flag, dir :) );
	return 1;
	
}
void enter_desc(object me,object gold, string s_title, int flag,string dir,string text)
{
string *direc= ({"north", "south", "east", "west", "northup", 
"southup", "eastup", "westup", "northdown",
"southdown", "eastdown", "westdown", "northeast", 
"northwest", "southeast", "southwest", "up", "down"});
	int i;
	int okey=0;
	object env;
	if(!check_legal_long(text)) return;
        for (i = 0; i < sizeof(direc); i++)
	if(direc[i] == dir) {okey=1; break;}
	if(okey)	
	{
	env = environment(me);
	if(env->query("exits/"+dir))
		{
		tell_object(me,"这个方向已经有房屋了！\n");
		return;
		}
// I think by now, we should checked all conditions,
// deduct the cost and go build it!
		gold->add_amount(-GOLD_COST);
		me->add("score",-SCORE_COST);
		BR_D->buildroom(me,flag,s_title,text,dir);
	}
	else
	{
		tell_object(me,"你要往哪个方向建？\n");
		return;
	}
}

int check_legal_name(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 1) || (strlen(name) > 20 ) ) {
                write("对不起，中文名字必须是一到二十个中文字。\n");
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
                        write("对不起，中文名字不能用控制字元。\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("对不起，名字必需是中文。\n");
                        return 0;
                }
        }
        return 1;
}

int check_legal_long(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 60) || (strlen(name) > 300 ) ) {
                write("对不起，中文描述必须是六十到三百个中文字。\n");
                return 0;
        }
        while(i--) {
		if(name[i]==' ' || name[i] == '\n') continue;
                if( name[i]<' ' ) {
                        write("对不起，中文描述不能用控制字元。\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("对不起，描述必需是中文。\n");
                        return 0;
                }
        }
        return 1;
}

int help (object me)
{
	write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	build <讯息>[0m
[0;1;37m────────────────────────────────[0m   

此指令让玩家建造一座属于自己的房屋。

建造一所房屋的花费为5000评价、1000两黄金。每个玩家最多可以建
造三间屋子。

当玩家在风云中达到一定的地位，拥有足够的财富和声望，就可以在
风云城以北的山谷中建立属于自己的空间。众多玩家还可以合作，共
建一块区域，用于自己的门派或帮会。每个空间可以有不同的性质，
可以是自己的私人住宅（只有玩家自己可以进入），也可以是帮派的
私地（只有同派的人可以进入）；可以是禁止打杀的地方，也可以是
无法无天的地段。房间建设完成之后，所有的性质，描述都不可以再
改变，所以大家在设定房间的时候一定要多加考虑，用心选择。

制造房间的详细款项如下：

buildroom <方向> <房间名称> <标志>

方向：	方向是对你现在的位置而言，如果方向是north，就是说你要
	在现在以北的方向建房。
房间名称：是你所看到的简短描述。
标志：	你所建的房间的属性全都由标志来决定。可以选择的标志有：
	1：可以在此存档而且下次练线时在此处开始。
	2：只可以玩家进入的空间（不可打坐）。
	4：不可战斗的空间（不可打坐）。
	8：不可有法术和魔术的空间（不可打坐）。
	16：室外的空间（所有人都可以进入，如果没有这个16，其
		他玩家不可以入内）。
	512：只可以自己进入的空间。
	1024：只可以同门的人物进入的空间。
	2048：可以邀请（invite）别人进入的空间。
	
buildroom north 小木屋 2
就会在以北的地方建筑一间小屋名为“小木屋”，木屋的性质是只可
以让玩家们进入。

buildroom southdown 练武场 1040
就会在南边低处建立一个室外空间名为“练武场”，此场的性质是室
外（16）和只是同门的人（1024）才可以进入（1024+16=1040）。

buildroom eastup 黄金屋 525
就会在东方高处建立一个房间名为“黄金屋”，此屋的性质是下次
可在此连线进入（1），不可打杀（4），不可施展魔法（8），和只
可以自己进入（512）（1＋4＋8＋512＝525）。

当几个人配合建立连在一起的房间时，有必要用setowner这个指令，将
房间的主人暂时定为他人。

[0;1;37m────────────────────────────────[0m   
HELP
	);
	return 1;
}
