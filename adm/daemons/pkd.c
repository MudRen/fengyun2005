/* 	pkd 		by silencer@fy4 03/08/2003	

	用于守护关于PK的一系列函数。
	一部分PK的开关只能放到具体的地方，守护无法处理不上线的玩家。
	有关文件 /adm/daemons/combatd, /adm/daemons/updated
		/d/jinan/npc/butou1, /d/jinan/npc/shiye1
	需要注意的是名单太长影响login速度或某些人flood名单
	
*/

#include <ansi.h>
inherit F_DBASE;

#define PK_LIST 	"/adm/etc/pk_list"		//	当前通缉纪录
#define PK_OLD_LIST 	"/adm/etc/pk_expired_list"	//	历史通缉纪录
#define HUNTER_LIST 		"/adm/etc/hunter_list"		//	巡捕纪录
#define MAX_LIST	50				//	最多允许名单人数


mapping *read_table(string file);			//	读取
int save_table(string filename, mapping *data);		//	存储
int add_member(string filename, mapping member);	//	添加人员
int remove_member(string filename, string name);	//	去除人员
int count_member(string filename);			//	计算人数。

mapping check_list(string player, string flag);		//	检验纪录，返回值为纪录

int refresh_pk_list(int expiration);			// 	
int refresh_old_pk_list(int expiration);		//	
int refresh_hunter_list(int expiration);		//	
void update_list();					//	每小时UPDATE，去除原有过时纪录

void print_hunter_list();
void print_pk_list();
void print_old_list();

void add_reward(string name);				// 	增加缉捕数目

mapping *pk_list;					//	当前通缉纪录
mapping *pk_old_list;					//	历史通缉纪录
mapping *hunter;					//	巡捕纪录
mapping field = allocate_mapping(3);
mapping format = allocate_mapping(3);

void create()
{
        seteuid(getuid());
    
        set("id","pkd");
        pk_list=read_table(PK_LIST);
        pk_old_list= read_table(PK_OLD_LIST);     
        hunter = read_table(HUNTER_LIST);
        
        print_hunter_list();
        print_pk_list();
        
	refresh_pk_list(86400);
        refresh_old_pk_list(86400*5);
        refresh_hunter_list(86400*7);
 	call_out("update_list",3600);
}

void	update_list(){			
	remove_call_out("update_list");
	refresh_old_pk_list(86400*5);	//每五天清除一次PK历史
	refresh_pk_list(86400);		//每天清除一次通缉名单
	refresh_hunter_list(86400*7);	//每七天清除一次巡捕名单
	call_out("update_list",3600);
}


//	OK,这里我们把通缉过时的玩家从List上去除，
//	如果当时在线，那么就立刻恢复NO_PK状态，
//	如果不在线，仍然从list上去掉，但要写在一个文件里让updated来处理，。

int refresh_pk_list(int expiration)
{
        int i;
        object player;
        if (!sizeof(pk_list)) return 0;
        for (i=0; i<sizeof(pk_list); i++) {
		if (pk_list[i]["start_time"]+ expiration < time()) {
			if (objectp(player=find_living(pk_list[i]["hunted"]))) {
				player->set("NO_PK",1);
				tell_object(player,WHT"对你的通缉终于结束了。\n"NOR);
			}	
			add_member("PK_OLD_LIST",pk_list[i]);
			pk_list -= ({ pk_list[i] });	
		}
		}       
		save_table(PK_LIST,pk_list);
		return 1;
}

int refresh_old_pk_list(int expiration)
{
        int i;
        if (!sizeof(pk_old_list)) return 0;
        for (i=0; i<sizeof(pk_old_list); i++) {
		if (!pk_old_list[i] || pk_old_list[i]["start_time"]+ expiration < time())
			pk_old_list -= ({ pk_old_list[i] });	
	}       
	save_table(PK_OLD_LIST,pk_old_list);
	return 1;
}


int refresh_hunter_list(int expiration)
{
        int i;
        object player;
        if (!sizeof(hunter)) return 0;
        for (i=0; i<sizeof(hunter); i++) {
		if (hunter[i]["join_time"]+ expiration < time()) {
			if (objectp(player=find_living(hunter[i]["id"]))) {
				player->set("NO_PK",1);
				tell_object(player,WHT"你的巡捕任期已满，自动脱离仇杀状态。\n"NOR);
			}	
			hunter -= ({ hunter[i] });	
		}
	}       
	save_table(HUNTER_LIST,hunter);
	return 1;
}


mapping *read_table(string filename)
{
        string *line;
        mapping *data;
        int i, rn, fn;
        string *field_1, *format_1;
        write(sprintf("file is %s\n",filename));
        line = explode(read_file(filename), "\n");
        data = ({});
        // For some reason, the first line in some file format gives error
        // So let's just do it from 2nd line.
        for(i=1; i<sizeof(line); i++) {
                if( line[i]=="" || line[i][0]=='#' ) continue;
//        	write(sprintf("line[%d]= %O\n field=%O\n format= %O \n",i,line[i],field_1,format_1));
//          write("i =="+ i + "\n");
                if( !pointerp(field_1) ) {
                        field[filename] = line[i];
                        field_1 = explode( line[i], ":" );
//                      write("i =="+ i + " field line == "+line[i]+" \n");
                        continue;
                }
                if( !pointerp(format_1) ) {
                        format[filename]= line[i];
                        format_1 = explode( line[i], ":" );
//                      write("i =="+ i + " field line == "+line[i]+" \n");
	                continue;
                }
                break;
        }
//        write(sprintf("field=%O\n format= %O \n",field_1,format_1));
        i++;
        for( rn = 0, fn = 0; i<sizeof(line); i++) {
                if( line[i]=="" || line[i][0]=='#' ) continue;
                if( !fn ) data += ({ allocate_mapping(sizeof(field_1)) });
                sscanf( line[i], format_1[fn], data[rn][field_1[fn]] );
                fn = (++fn) % sizeof(field_1);
                if( !fn ) ++rn;
        }
        
//     	print_table(data);
        return data;
}




int save_table(string filename, mapping *data) {
	int i, j/*, num*/;
	string comment;
	string *field_2;
	
	switch (filename) {
		case PK_OLD_LIST:
		case PK_LIST:	comment = "
#  by Silencer@fy4 3/6/2003
#  The two lines defines the data format
#
#  field1:field2:field3....
#  format1:format2:format3....
#
#  hunted: 通缉犯 id
#  name:  通缉犯名字		
#  start_time:  开始通缉时间
#  reward: 悬赏
#  initializer 发起人\n\n"; break;
		case HUNTER_LIST: comment = "
#  by Silencer@fy4 3/6/2003
#  The two lines defines the data format
#
#  field1:field2:field3....
#  format1:format2:format3....
#
#  name:  巡捕名字 
#  id:    巡捕 id		
#  join_time:  加入巡捕日期
#  rewarded:   缉捕成功次数\n\n"; break;
	}

	comment = comment + field[filename]+"\n";
	comment = comment + format[filename]+"\n\n";
	
	field_2 = explode( field[filename], ":" );	
	if( !write_file(filename, comment,1))
		return 0;
	
	for (i=0;i<sizeof(data);i++) {
		for (j=0;j<sizeof(field_2);j++) 
			if (!write_file(filename,(string)(data[i][field_2[j]])+"\n"))
				return 0;
		write_file(filename,"\n");
	}
	return 1;
}


int add_member(string filename, mapping member) {
	int i;
	object player;
	string msg;
	if (filename == "PK_LIST") {
		if (sizeof(pk_list) >= MAX_LIST)	return 0;
		for (i=0;i<sizeof(pk_list);i++) {
			if (pk_list[i]["hunted"] == member["hunted"])
				return 0;
		} 
		pk_list += ({member});
		if (objectp(player=find_living(member["hunted"]))) {
			player->set("NO_PK",0);
			player->set("pk_start",time());	
			tell_object(player,HIR"！！！！！！！！！！！！！！！！！！！！！\n"
					"官府正悬赏"+pk_list[i]["reward"]+"两黄金捉拿你，"
					"充当巡捕的玩家可以对你追杀，通缉时间将持续二十四小时。
！！！！！！！！！！！！！！！！！！！！！\n"NOR);
			switch (random(9)) {
				case 8: msg = "涉嫌南宫钱庄劫案，"; break;
				case 7: msg = "杀人越货，"; break;
				case 6: msg = "勾结匪类，"; break;
				case 5: msg = "涉嫌千金楼命案，"; break;
				case 4: msg = "聚众谋反，"; break;
				case 3:	msg = "涉嫌重案，"; break;
				case 2: msg = "图谋作乱，"; break;
				case 1: msg = "畏罪潜逃，"; break;
				default:msg = "犯莫须有罪，";
			}
				
			CHANNEL_D->do_sys_channel(
				"info",sprintf("%s(%s)"+msg+"风云官府开始通缉，格杀勿论。", player->name(1),player->query("id")));
		}
		save_table(PK_LIST,pk_list);
		return 1;
	}
	if (filename == "PK_OLD_LIST") {
		for (i=0;i<sizeof(pk_old_list);i++) {
			if (pk_old_list[i]["hunted"] == member["hunted"])
				pk_old_list -= ({pk_old_list[i]});
		} 
		pk_old_list += ({member});
		save_table(PK_OLD_LIST,pk_old_list);
		return 1;
	}
	if (filename == "HUNTER_LIST") {
		if (sizeof(hunter)>=MAX_LIST)	return 0;
		for (i=0;i<sizeof(hunter);i++) {
			if(hunter[i]["id"] == member["id"])
				return 0;
		}
		player = find_living(member["id"]);

		CHANNEL_D->do_sys_channel("sys",sprintf("Added %s is %O",member["id"], player));
		
		if (objectp(player)) {
			hunter += ({member});
			player->set("NO_PK",0);
			player->set("pk_start",time());		// 给出五分钟警告
			tell_object(player,HIG"你现已卷入江湖仇杀之中，五分钟后同类玩家可对你追杀。\n"NOR);
			save_table(HUNTER_LIST,hunter);
			return 1;
		}
	}
	write(" adding member is wrong, please report to Silencer@fengyun.com \n");		
	return 0;
}


int remove_member(string filename, string name) {
	object player;
	int i;
	if (!objectp(player=find_living(name))) 
		return 0;
	if (filename == "PK_LIST") {
		for (i=0;i<sizeof(pk_list);i++) {
			if (pk_list[i]["hunted"] == name) {
				add_member("PK_OLD_LIST",pk_list[i]);
				pk_list -= ({ pk_list[i] });
				player->set("NO_PK",1);
				save_table(PK_LIST,pk_list);
				return 1;
			}
		}
	}
	if (filename == "PK_OLD_LIST") {
		for (i=0;i<sizeof(pk_old_list);i++) {
			if (pk_old_list[i]["hunted"] == name) {
				pk_old_list -= ({ pk_old_list[i] });
				save_table(PK_OLD_LIST,pk_old_list);
				return 1;
			}
		} 
	}
	if (filename == "HUNTER_LIST") {
		for (i=0;i<sizeof(hunter);i++) {
			if (hunter[i]["id"] == name) {
				hunter -= ({ hunter[i] });
				player->set("NO_PK",1);
				save_table(HUNTER_LIST,hunter);	
				return 1;
			}
		}
	}
//	write ("NONE is removed.\n");
	return 0;
}

int count_member(string filename) {
	if (filename == "PK_LIST")		return sizeof(pk_list);
	else if (filename == "PK_OLD_LIST")	return sizeof(pk_old_list);
	else if (filename == "HUNTER_LIST")		return sizeof(hunter);

	return 0;
}


mapping check_list(string player, string type){
	int i;
	
	if (type == "PK_OLD_LIST") {
		if (!sizeof(pk_old_list)) return 0;
		for (i=0; i<sizeof(pk_old_list); i++) {
			if (pk_old_list[i]["hunted"] == player)
				return pk_old_list[i];
		}
	} else if (type=="PK_LIST"){
		if (!sizeof(pk_list)) return 0;
		for (i=0; i<sizeof(pk_list); i++) 
		if (pk_list[i]["hunted"] == player)
			return pk_list[i];
	} else if (type =="HUNTER_LIST") {
		if (!sizeof(hunter)) return 0;
		for (i=0; i<sizeof(hunter); i++) 
		if (hunter[i]["id"] == player)
			return hunter[i];
	}
//	write("ILLEGAL CHECK FLAG.\n");
	return 0;
}


void print_pk_list() {
	int i, duration;
	if (!sizeof(pk_list)) {
		write("\n现在没有正在通缉的歹徒。\n");
		return;
	}
	write (HIY"\n─────────────""通缉名单────────────\n\n"NOR);
	write (YEL"      姓名 		通缉时间    赏金          发起人\n"NOR);
	for (i=0; i<sizeof(pk_list); i++) {
		duration = ((time()-pk_list[i]["start_time"]))/60/60;
		write(sprintf("%-4d  %s（%s）  \t%d小时\t  %d两黄金\t  %s\n",
			i+1, pk_list[i]["name"],pk_list[i]["hunted"], duration, 
			pk_list[i]["reward"], pk_list[i]["initializer"]));		
	}
	write (HIY"\n─────────────────────────────\n"NOR);
	return;
}

void print_hunter_list() {
	int i, duration;
	if (!sizeof(hunter)) {
		write("\n现在没有正在执行公务的巡捕。\n");
		return;
	}
	write (HIY"\n─────────────""巡捕名单────────────\n\n"NOR);
	write (YEL"      姓名 		加入时间	缉捕成功次数\n"NOR);
	for (i=0; i<sizeof(hunter); i++) {
		
		duration = ((time()-hunter[i]["join_time"]))/60/60;
		write(sprintf("%-4d  %s（%s） \t%d小时\t\t  %d\n",
			i+1, hunter[i]["name"],hunter[i]["id"], duration, hunter[i]["rewarded"] 
			));		
	}
	write (HIY"\n─────────────────────────────\n"NOR);
	return;
}


void print_old_list() {
	int i, duration;
	if (!sizeof(pk_list)) {
		write("\n现在没有原始记录。\n");
		return;
	}
	write (HIY"\n───────────""通缉名单──────────────\n\n"NOR);
	for (i=0; i<sizeof(pk_old_list); i++) {
		duration = ((time()-pk_old_list[i]["start_time"]))/60/60;
		write(sprintf("%d：%s（%s）  通缉时间：%d小时  悬赏：%d两黄金\n",
			i+1, pk_old_list[i]["name"],pk_old_list[i]["hunted"], duration, 
			pk_old_list[i]["reward"], pk_old_list[i]["initializer"]));		
	}
	write (HIY"\n─────────────────────────────\n"NOR);
	return;
}

void add_reward(string name){
	int i;
	
	for (i=0;i<sizeof(hunter);i++){
		if (hunter[i]["id"]==name) {
			hunter[i]["rewarded"]++;
			save_table(HUNTER_LIST,hunter);
			return;
		}
	}
	return;
}