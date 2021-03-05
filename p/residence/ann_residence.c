#include <ansi.h>

int check_legal_name(string name);
int check_legal_long(string name);
void enter_desc(object me,object gold,string s_title, int flag,string dir,int gold_cost,int s_cost,int space, int w, string text);
string get_free_dir();

inherit ROOM;

int init()
{
	add_action("do_buildroom","build");
}

string get_free_dir()
{
	string *direc= ({"01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17"});
	int i;
	for (i=0;i<sizeof(direc);i++ )
		if (!query("exits/"+query("floor")+direc[i]))
			return query("floor")+direc[i];
	return 0;
}

int do_buildroom(string arg)
{
	int flag,gold_cost,s_cost;
	string stitle;
	string ltitle;
	string dir;
	object env;
	object gold;
	int w;
	int space;
	object me = this_player();
    seteuid(getuid());
		
//	if (me->query("created_mainroom"))
//		return notify_fail("你已经建造过一间主屋了。\n");

	if (!arg){
		write("\n╭════════════════════════════╮\n");
		write(HIR"
		风云城建屋价格一览表"NOR+YEL"

 空间　　买断价格	 贷款型：首期	 月金（周） 
 1　　　 150g/120pj　	10g/20pj 	　1.4g/1pj　		　 
 2　　　 300g/240pj　	20g/40pj 	  2.8g/2pj　　 
 3　　　 600g/380pj　	40g/80pj 	  5.6g/3pj　　 
 4　　　1200g/560pj 　	80g/160pj 	  11.2g/4pj　 
 5　　　2400g/820pj 　	160g/320pj	  22.4g/5pj　  
\n"NOR);		
		write("╰════════════════════════════╯\n");
		return 1;
	}	
			
    if(me->query("created_room") >= 1)
		return notify_fail("目前风云每个人只能造一间房！\n");
	
    if (me->query("combat_exp")< 100000)
		return notify_fail("可不是随便什么人都能在风云城里建房的，至少得等级十以上才行。\n");
		
    if(sscanf(arg,"%s %d %d %d",stitle,flag,space,w) != 4)
		return notify_fail("指令格式：　build [屋名] [特性] [空间] [支付]	\n");
	
	dir=get_free_dir();
	if (!dir)
		return notify_fail("这里已经没有空屋子可以住了。\n");
			
	switch (space)
	{	// lazy . annie
		case 1:
			gold_cost = 10;
			break;
		case 2:
			gold_cost = 20;
			break;
		case 3:
			gold_cost = 40;
			break;
		case 4:
			gold_cost = 80;
			break;
		case 5:
			gold_cost = 160;
			break;	
		default:
			return notify_fail("空间只能为１－５。\n");
	}

	if (me->query("created_room") == 1)
		gold_cost *= 2;
	else if (me->query("created_room") == 2)
		gold_cost *= 4;
	else if (me->query("created_room") == 0)
		gold_cost *= 1;
	else 
		gold_cost *= 100;	// bug.
	
	if (w != 0 && w != 1)
		if(!gold) return notify_fail("支付只能为０（正常交税）或１（一次买断）。\n");

	if (w==1)
	{
		s_cost = gold_cost*2;
		gold_cost = gold_cost*15;
		s_cost = s_cost+space*100;
	}
	else
		s_cost=gold_cost*2;

	gold = present("gold_money",me);
		if(!gold) return notify_fail("你身上没有金子。\n");

	if(gold->query_amount() < gold_cost)
       	return notify_fail("你身上没有"+chinese_number(gold_cost)+"两金子。\n");

	if(me->query("score") < s_cost)
       	return notify_fail("你的评价不足"+chinese_number(s_cost)+"点！\n");

    env = environment(me);
	if(check_legal_name(stitle))
		 me->edit( (: enter_desc , me,gold, stitle, flag, dir,gold_cost,s_cost,space,w :) );
	return 1;
	
}

void enter_desc(object me,object gold, string s_title, int flag,string dir,int gold_cost,int s_cost,int space, int w, string text)
{
	int i;
	int okey=0;
	object env;
	if(!check_legal_long(text)) return;

	// double checks here because of the delay in enter_desc.
	if(query("exits/"+dir))
	{
		tell_object(me,"这个方向已经有房屋了！\n");
		return;
	}
	if (gold->query_amount() < gold_cost)
	{
		tell_object(me,"你的钱不够！\n");
		return;
	}
	if(me->query("score") < s_cost) {
       	tell_object(me,"你的评价不足"+chinese_number(s_cost)+"点！\n");
		return;
	}

	BR_D->buildroom(me,gold,flag,s_title,text,dir,1,gold_cost,s_cost,space,w);

}


int check_legal_name(string name)
{
        int i;
        i = sizeof(name);
        if( (sizeof(name) < 1 || (sizeof(name) > 20 ))){
                write("对不起，中文名字必须是一到二十个中文字。\n");
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
                        write("对不起，中文名字不能用控制字元。\n");
                        return 0;
                }
             
        }
           if(  !is_chinese(name) ) {
                        write("对不起，名字必需是中文。\n");
                        return 0;
                }
        return 1;
}

int check_legal_long(string name)
{
        int i;
        i = sizeof(name);
        if( (sizeof(name) < 60) || (sizeof(name) > 300 ) ) {
                write("对不起，中文描述必须是六十到三百个中文字。"+sizeof(name)+"\n");
                return 0;
        }
        while(i--) {
		if(name[i]==' ' || name[i] == '\n') continue;
                if( name[i]<' ' ) {
                        write("对不起，中文描述不能用控制字元。\n");
                        return 0;
                }
             
        }
           if(  !is_chinese(name) ) {
                        write("对不起，描述必需是中文。\n");
                        return 0;
                }
        return 1;
}

