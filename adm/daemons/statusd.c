// Silencer@fengyun workgroup	July.2005

#include <ansi.h>

#define TOP_SIZE 100
#define RICH_SIZE 100
#define RIDDLE_SIZE 100
#define SKI_BLK 125

#define TOP_LST		"/data/lst_top"
#define RICH_LST	"/data/lst_rich"
#define RIDDLE_LST	"/data/lst_riddle"
#define SKILL_LST 	"/data/lst_skill"

mapping ski_lst;
mapping *rich_lst;
mapping *top_lst;
mapping *riddle_lst;

mapping read_text2(string file);
mapping *read_text(string file);


void write_list2(string arg); 

void create() { 
	string file;
	seteuid(getuid()); 
	top_lst = sort_array(read_text(TOP_LST),"sort_user",this_object(),"pot");
	rich_lst = sort_array(read_text(RICH_LST),"sort_user",this_object(),"deposit");
	riddle_lst= sort_array(read_text(RIDDLE_LST),"sort_user", this_object(),"r_num");
	ski_lst = read_text2(SKILL_LST);
}

int ski_summary(object me, string skill, int level) {
	string ski,msg,file_skill;
	string *ski_term;
	int i, record;
	int file_level;
	msg = "/cmds/usr/skills"->skill_level(SKILL_D(skill)->type(),level+1);
	ski = sprintf("%s+%d",skill,(level+1));	
	
	record = 0;
	
	// If we are not making to SKI_BLK, just return true
	if(level%SKI_BLK != SKI_BLK -1 ) return 1;
	
	if(!mapp(ski_lst) || sizeof(ski_lst)<1) {
		ski_lst[ski] = 1;	
		CHANNEL_D->do_sys_channel(
		"info",sprintf("%s(%s)的%s已经达到了"+msg+HIY"的境界（古今武林第一人）。", 
			me->query("name"),me->query("id"),SKILL_D(skill)->name()));
		record = 1;
	}
	else {
		ski_term=keys(ski_lst);		
		for (i=0;i<sizeof(ski_term);i++) {
			sscanf (ski_term[i],"%s+%d",file_skill,file_level);
			if (skill==file_skill) 
			{
				if (level+1>file_level) {
					map_delete(ski_lst,ski_term[i]);
					ski_lst[ski]=1;
					CHANNEL_D->do_sys_channel(
					"info",sprintf("%s(%s)的%s已经达到了"+msg+HIY"的境界（当今武林第一人）。", 
					me->query("name"),me->query("id"),SKILL_D(skill)->name()));
					record = 1;
					}
			
				if (level+1==file_level) {
					ski_lst[ski_term[i]] +=1;
					CHANNEL_D->do_sys_channel(
					"info",sprintf("%s(%s)的%s已经达到了"+msg+HIY"的境界（当今武林第%s人）。", 
					me->query("name"),me->query("id"),SKILL_D(skill)->name(), chinese_number(ski_lst[ski_term[i]])));
					record = 1;
					}
			
				if (level+1<file_level) {
					CHANNEL_D->do_sys_channel(
					"info",sprintf("%s(%s)的%s已经达到了"+msg+HIY"的境界。", 
					me->query("name"),me->query("id"),SKILL_D(skill)->name()));
					record = 2;
					}
			}					
		}
		if (!record)
		{
			CHANNEL_D->do_sys_channel(
				"info",sprintf("%s(%s)的%s已经达到了"+msg+HIY"的境界（自古武林第一人）。", 
					me->query("name"),me->query("id"),SKILL_D(skill)->name()));
			ski_lst[ski] = 1;
			record = 1;	
		}		
	}
		
	if (record == 1)
		write_list2(SKILL_LST);
	return 1;			
}


void write_list2(string arg) {

	int i;
	string outp, *mterm;
	
	if (arg == SKILL_LST){
		if(mapp(ski_lst) && sizeof(ski_lst)) {
			rm(SKILL_LST);
			mterm = keys(ski_lst);
			for(i=0;i<sizeof(mterm);i++) {
				outp = sprintf("%s,%d\n",mterm[i],ski_lst[mterm[i]]); 
				write_file(SKILL_LST,outp,0); 
			}       
		}
	}	
	
	if (arg == TOP_LST) {
//		CHANNEL_D->do_sys_channel("sys","writing\n");
//		CHANNEL_D->do_sys_channel("sys",sprintf("%O\n",top_lst));
		if (sizeof(top_lst)) {
			rm(TOP_LST);
			for(i=0;i<sizeof(top_lst);i++){
				outp = sprintf("%s,%s,class:%s,exp:%d,pot:%d,score:%d,dep:%d,hour:%d,riddle:%d\n",
					top_lst[i]["id"],top_lst[i]["name"],top_lst[i]["class"],
					top_lst[i]["exp"],top_lst[i]["pot"],top_lst[i]["score"],
					top_lst[i]["deposit"],top_lst[i]["hour"],top_lst[i]["r_num"]);
//				CHANNEL_D->do_sys_channel("sys",outp);
				write_file(TOP_LST,outp,0);
			}
		}
	}
	
	if (arg == RICH_LST) {
//		CHANNEL_D->do_sys_channel("sys","writing\n");
//		CHANNEL_D->do_sys_channel("sys",sprintf("%O\n",rich_lst));
		if (sizeof(rich_lst)) {
			rm(RICH_LST);
			for(i=0;i<sizeof(rich_lst);i++){
				outp = sprintf("%s,%s,class:%s,exp:%d,pot:%d,score:%d,dep:%d,hour:%d,riddle%d\n",
					rich_lst[i]["id"],rich_lst[i]["name"],rich_lst[i]["class"],
					rich_lst[i]["exp"],rich_lst[i]["pot"],rich_lst[i]["score"],
					rich_lst[i]["deposit"], rich_lst[i]["hour"],rich_lst[i]["r_num"]);
//				CHANNEL_D->do_sys_channel("sys",outp);
				write_file(RICH_LST,outp,0);
			}
		}
	}

	if (arg == RIDDLE_LST) {
//		CHANNEL_D->do_sys_channel("sys","writing\n");
//		CHANNEL_D->do_sys_channel("sys",sprintf("%O\n",rich_lst));
		if (sizeof(riddle_lst)) {
			rm(RIDDLE_LST);
			for(i=0;i<sizeof(riddle_lst);i++){
				outp = sprintf("%s,%s,class:%s,exp:%d,pot:%d,score:%d,dep:%d,hour:%d,riddle:%d\n",
					riddle_lst[i]["id"],riddle_lst[i]["name"],riddle_lst[i]["class"],
					riddle_lst[i]["exp"],riddle_lst[i]["pot"],riddle_lst[i]["score"],
					riddle_lst[i]["deposit"], riddle_lst[i]["hour"],riddle_lst[i]["r_num"]);
//				CHANNEL_D->do_sys_channel("sys",outp);
				write_file(RIDDLE_LST,outp,0);
			}
		}
	}	
}

mapping read_text2(string file)
{
	string *line,lines;
	string ski;
	int num;
	int i;
	mapping data;
	data = ([]);
	lines =  read_file(file);
	if(lines) {  
		line = explode(lines,"\n");
		for(i=0;i<sizeof(line);i++) {
			sscanf(line[i],"%s,%d",ski,num);
			data[ski] = num;
 		}
	}
 	return data;
}


mapping *read_text(string file)
{
	string *line, *field;
	mapping *data;
	string lines;
	int i,j;
	data = ({});
	lines= read_file(file);
	if(lines){
		line = explode(lines, "\n");
		for(i=0;i<sizeof(line);i++) {
			data += ({ allocate_mapping(6) });
			sscanf(line[i],"%s,%s,class:%s,exp:%d,pot:%d,score:%d,dep:%d,hour:%d,riddle:%d",
				data[i]["id"],	data[i]["name"],data[i]["class"],
				data[i]["exp"], data[i]["pot"],
				data[i]["score"],data[i]["deposit"],data[i]["hour"],data[i]["r_num"]);
		}
	}	
	return data;
}

int sort_user(mapping a, mapping b, string item)
{
	return b[item] - a[item];
}

int update_list(mapping mydata, string item, mapping *data, int limit, string filename) {
	
	int i;
	int T_ALREADY =0;
	
	//	update top_lst if I was one of it.	
		
/*	CHANNEL_D->do_sys_channel(
			"sys",sprintf("\n updating %O\n %s %O %d %s\n",
			mydata,
			item,
			data,
			limit,
			filename
			));*/
				
	for(i=0;i<sizeof(data);i++)
	if(data[i]["id"] == mydata["id"]) {
		data -= ({ data[i] });
		data += ({ mydata });
		T_ALREADY =1;
		break;
	}
	
	//	if there is a list, if I am not top_lst, and I am lower than top_lst, no need to continue;
	if (sizeof(data)> limit-1)
	if (!T_ALREADY && mydata[item] < data[sizeof(data)-1][item])
		return 1;
		
	//  Now it's cool to temperorily put me in the list and make it +1
	if (!T_ALREADY) data += ({ mydata });
	
	//	Sorting	
	data = sort_array(data,"sort_user",this_object(),item);
	
	//  get rid of extras from the bottom of the list
	if (sizeof(data)>limit)
		data -= ({ data[sizeof(data)-1] });
			
	switch (filename)	{
		case TOP_LST:	top_lst = data;
						write_list2(TOP_LST);
						break;
		case RICH_LST:	rich_lst = data;
						write_list2(RICH_LST);
						break;
		case RIDDLE_LST:riddle_lst= data;
						write_list2(RIDDLE_LST);
						break;				
	}		
	return 1;	
	
}

void compare_status(object me)
{
	mapping mydata;
	int i, num;
	int T_ALREADY =0;
	mapping riddle;
	
//	me= this_player();	// testing
	
	if(wizardp(me)) return;
	if (me->query("class")=="demon")	
		return;		// temp. for dreamland, get another mark later on.
	
//	if((int)me->query("mud_age") < 3600) return;
	
	mydata = ([]);
	mydata["id"]= 		me->query("id");
	mydata["name"] = 	me->query("name");
	mydata["exp"] = 	me->query("combat_exp");
	mydata["pot"] = 	me->query("potential");
	mydata["score"] = 	me->query("score");
	mydata["deposit"]= 	me->query("deposit");
	mydata["hour"] 	= 	me->query("mud_age")/3600;
	if (me->query("class"))	mydata["class"] = me->query("class");
		else	mydata["class"] = "none";
	
	riddle = me->query("m_success");
	if (mapp(riddle) && sizeof(riddle))
		num = sizeof(riddle);
	else
		num = 0;
		
	mydata["r_num"]= num;
		
	update_list(mydata, "pot", top_lst, TOP_SIZE, TOP_LST);
	update_list(mydata, "deposit", rich_lst, RICH_SIZE, RICH_LST);
	update_list(mydata, "r_num", riddle_lst, RIDDLE_SIZE,RIDDLE_LST);
	
}

string show_top()
{
	int i;
	string msg;
	msg = "玩程报告经验等级前"+chinese_number(TOP_SIZE)+"名：\n";
	msg += "======================================================================================\n";
	msg += sprintf("%-10s%-12s%-10s%-10s%-10s%-6s%-10s%-10s%-6s\n",
			"英文名","中文名","门派","经验","潜能","评价","存款","在线(h)","谜题");
	msg += "======================================================================================\n";		
	for(i=0;i<sizeof(top_lst);i++)
		msg += sprintf("%-10s%-12s%-10s%-10d%-10d%-6d%-10d%-10d%-6d\n",
				top_lst[i]["id"],top_lst[i]["name"],top_lst[i]["class"],
				top_lst[i]["exp"],top_lst[i]["pot"],
				top_lst[i]["score"],top_lst[i]["deposit"],
				top_lst[i]["hour"],top_lst[i]["r_num"]);
	msg += "======================================================================================\n";
	return msg;
}

string show_rich()
{
	int i;
	string msg;
	msg = "玩程报告存款前"+chinese_number(RICH_SIZE)+"名：\n";
	msg += "======================================================================================\n";
	msg += sprintf("%-10s%-10s%-10s%-10s%-10s%-6s%-10s%-10s%-6s\n",
			"英文名","中文名","门派","经验","潜能","评价","存款","在线(h)","谜题");
	msg += "======================================================================================\n";
	for(i=0;i<sizeof(rich_lst);i++)
		msg += sprintf("%-10s%-10s%-10s%-10d%-10d%-6d%-10d%-10d%-6d\n",
				rich_lst[i]["id"],rich_lst[i]["name"],rich_lst[i]["class"],
				rich_lst[i]["exp"],rich_lst[i]["pot"],
				rich_lst[i]["score"],rich_lst[i]["deposit"],
				rich_lst[i]["hour"],rich_lst[i]["r_num"]);
	msg += "======================================================================================\n";
	return msg;
}


string show_riddle()
{
	int i;
	string msg;
	msg = "玩程报告解谜前"+chinese_number(RIDDLE_SIZE)+"名：\n";
	msg += "======================================================================================\n";
	msg += sprintf("%-10s%-10s%-10s%-10s%-10s%-6s%-10s%-10s%-6s\n",
			"英文名","中文名","门派","经验","潜能","评价","存款","在线(h)","谜题");
	msg += "======================================================================================\n";
	for(i=0;i<sizeof(riddle_lst);i++)
		msg += sprintf("%-10s%-10s%-10s%-10d%-10d%-6d%-10d%-10d%-6d\n",
				riddle_lst[i]["id"],riddle_lst[i]["name"],riddle_lst[i]["class"],
				riddle_lst[i]["exp"],riddle_lst[i]["pot"],
				riddle_lst[i]["score"],riddle_lst[i]["deposit"],
				riddle_lst[i]["hour"],riddle_lst[i]["r_num"]);
	msg += "======================================================================================\n";
	return msg;
}

mixed query_exp_list(){
	return top_lst;
}

mixed query_riddle_list(){
	return riddle_lst;
}

