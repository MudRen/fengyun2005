// questd.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#define MAX_DIS 7
#define MAX_ALT  2
#define MAX_DIR  8
#define MAX_SPREAD  100

#include <ansi.h>

inherit F_DBASE;

mapping *quests;
mapping *read_table(string file);
string *roomlines;
int room_number;

int init_dynamic_quest(int hard);
void auto_reset_quest(int count);
int spread_quest(mapping one_quest, int hard);
object find_env(object ob);
int already_spreaded(string str, int hard);
int quest_reward( object me, object who,object quest_item);
string dyn_quest_list();
string locate_obj(object me,string str);
int check_room();

void create() {
	string file;
	set("name", "使命精灵");
	set("id", "questd");
	quests = read_table("/quest/dynamic_quest");
	file = read_file("/quest/dynamic_location");
	roomlines = explode(file,"\n");
	room_number = sizeof(roomlines);
	auto_reset_quest(100);
//	check_room();
}

// 增加一个函数检查合理性
int check_room(){
	object room,*inv;
	int i,j;
	CHANNEL_D->do_sys_channel("sys","Total room size is " + sizeof(roomlines) + "\n");
	for (i=0;i<sizeof(roomlines);i++) {
		if (!(i%100))
			reset_eval_cost();
//	if (i==1442) CHANNEL_D->do_sys_channel("sys", "check room "+i+" = " + roomlines[i] + "\n");
		room = find_object(roomlines[i]);
		if (!room) room = load_object(roomlines[i]);
		if (!room) {
			CHANNEL_D->do_sys_channel("sys", "No such room "+i+" = " + roomlines[i] + "\n");
		}
		if (room) {
			if (room->query("no_fight"))
				CHANNEL_D->do_sys_channel("sys", "NO fight ROOM is " + roomlines[i] + "\n");		
			if (room->query("no_fly"))
				CHANNEL_D->do_sys_channel("sys", "NO fly ROOM is " + roomlines[i] + "\n");
			if (room->query("no_death_penalty"))
				CHANNEL_D->do_sys_channel("sys", "NO death ROOM is " + roomlines[i] + "\n");
			if (room->query("perma_exist"))
				CHANNEL_D->do_sys_channel("sys", "NO perma_exist ROOM is " + roomlines[i] + "\n");
			if (!room->query("coor/x") && !room->query("coor/y") && !room->query("coor/z"))
				CHANNEL_D->do_sys_channel("sys", WHT"NO coordinate ROOM is " + roomlines[i] + "\n"NOR);
			inv = all_inventory(room);
			for(j=0; j<sizeof(inv);j++) {
				if(inv[j]->query("vendetta_mark") == "authority"){
					CHANNEL_D->do_sys_channel("sys", WHT"officer NPC ROOM is " + roomlines[i] + " " 
						+ inv[j]->query("id")+ "\n"NOR);
					break;
				}
				if(inv[j]->query("NO_KILL")){
					CHANNEL_D->do_sys_channel("sys", WHT"no kill NPC ROOM is " + roomlines[i] + "\n"NOR);
					break;
				}
				// this will be checked in distribution too.
				if(inv[j]->query("combat_exp")> 10000000){
					CHANNEL_D->do_sys_channel("sys", HIR"Super NPC ROOM is " + roomlines[i] + "\n"NOR);
					break;
				}
			}
		}
	}
	
	return 1;
}

int quest_reward(object me, object who,object quest_item) {
	mapping quest;
	int base;
		
	if(!mapp(quest = quest_item->query("dynamic_quest"))) return 0;
	if(base_name(who) != quest["owner_name"]) return 0;
	
	base = 1;
		
	//	Default 奖励 为 + 1score, +50 silver
	REWARD_D->task_reward(me,base* 50);

	// 对于NPC携带task的额外奖励.
	if (quest_item->query("big_quest")) {
		tell_object(me,HIR"你真行！！\n"NOR);
		REWARD_D->task_reward(me,base * 50);
	}
			
//	CHANNEL_D->do_sys_channel("qst", sprintf("%s完成了%s的%s。\n",
//			me->name(1)+"（"+me->query("id")+"）", who->name(1), quest_item->name()));

	if(quest_item) {
		destruct(quest_item);
	}
	return 1;
}

int init_dynamic_quest(int hard) {
	int i/*, j, usernum, numq, sq*/;
	
	
	if(hard) {
		message("system", HIR "\n重新分布所有使命．．．" NOR, users());
	}

	i = sizeof(quests);
	while(i--) {
		spread_quest(quests[i],hard);
	}

	if(hard){
		message("system", HIG "．．．重新分布完毕 \n" NOR, users());
	}

	return 1;
}

void auto_reset_quest(int count) {
	int delay;

	if(count >= 8) {
		message("system", HIY "\n\n所有使命将在一分钟后重新分布！\n\n" NOR, users());
		EVENT_D->add_event(time()+60, this_object(), (: init_dynamic_quest, 1 :));
		count = 0;
		delay = time() + 900 + random(1800);
	} else if(count >= 6) {
		message("system", HIY "\n\n所有使命将在" + chinese_number(9-count) + "分钟后重新分布！\n\n" NOR, users());
		delay = time() + 60;
	} else {
		init_dynamic_quest(0);
		delay = time() + 900 + random(1800);
	}
	count++;
	EVENT_D->add_event(delay, this_object(), (: auto_reset_quest, count :));
}

varargs int spread_quest(mapping quest, int hard) {
	int tries = 0;
	object obj0=0;
	object cur_obj=0;
//	object next_obj;
	object tar;
	object *inv;
	object *target=({});
	object boss;
	int i;
	string location;

	if(already_spreaded(quest["file_name"], hard)) return 0;
	reset_eval_cost();
// try not to put task items on floor, however, give up after 3 tries
	while(obj0 == cur_obj && tries < 3 )
	{
		location = roomlines[random(room_number)];
		obj0=find_object(location);
		if(obj0)
			obj0->reset();
		else
			obj0=load_object(location);
		cur_obj =obj0;
		if(cur_obj)
		{
			inv = all_inventory(cur_obj);
			for(i=0; i<sizeof(inv); i++) {
				if(inv[i]->is_character() 
					&& !userp(inv[i]) 
					&& !inv[i]->query("possessed")
					&& inv[i]->query("combat_exp")< 12000000	// No Super NPC
					&& !inv[i]->query("NO_KILL")				// can kill
					&& !inv[i]->query("boss")
					&& !inv[i]->query("real_boss")
					&& inv[i]->query("vendetta_mark")!= "authority"
					)
					target += ({ inv[i] });
				if(inv[i]->is_container()) target += ({ inv[i] });
			}
		}
		if(sizeof(target)) cur_obj = target[random(sizeof(target))];
		tries++;
	}
	// 放在地上的给NPC
	if (obj0 == cur_obj && tries >=3) {
		CHANNEL_D->do_sys_channel("sys", sprintf("只能放在地上 to %O",cur_obj));
		boss=new("/obj/npc/task_npc");
		if (!boss) {
				CHANNEL_D->do_sys_channel("sys", sprintf("boss is wrong"));
				return 1;
		}
		boss->invocation(8000000+ random(2000000));
		boss->set("chat_chance_combat",50+random(20));		
		boss->move(obj0);
		tar = new(quest["file_name"]);
		tar->set("value",0);
		tar->set("dynamic_quest",quest);
		tar->set("big_quest",1);
		tar->move(boss);
		CHANNEL_D->do_sys_channel("sys", sprintf("%s(%s) is moved to TASKER %O",tar->name(),tar->query("id"),boss));
	}
	else if(cur_obj)
	{
		tar = new(quest["file_name"]);
		tar->set("value",0);
		tar->set("dynamic_quest",quest);
		tar->move(cur_obj);
		CHANNEL_D->do_sys_channel("sys", sprintf("%s is moved to /%O",tar->name(),cur_obj));
	}
	
	tries = 0;
	return 1;
}

int sort_quest_list(mapping a, mapping b) {
	if(a["done"] == b["done"]) {
		return strcmp(a["item"]->query("id"), b["item"]->query("id"));
	} else {
		return b["done"] - a["done"];
	}
}

string random_room() { return roomlines[random(sizeof(roomlines))]; }


string dyn_quest_list() {
	string output="", quest_string;
	object owner,item;
	mapping *quest_list = ({ });
	int i, j, k, extra;

	for( i=0; i < sizeof(quests); i++) {
		reset_eval_cost();
		if(!objectp(owner= find_object(quests[i]["owner_name"])) &&
				!objectp(owner = load_object(quests[i]["owner_name"]))) {
			write("error: cannot load " + quests[i]["owner_name"] + "\n");
			continue;
		}
		if(!objectp(item= find_object(quests[i]["file_name"])) &&
				!objectp(item = load_object(quests[i]["file_name"]))) {
			write("error: cannot load " + quests[i]["file_name"] + "\n");
			continue;
		}
		quest_list += ({	([	"owner"		:	owner,
								"item"		:	item,
								"done"		:	already_spreaded(quests[i]["file_name"], 0) ? 0 : 1
							]) 	});
	}
	quest_list = sort_array(quest_list, (: sort_quest_list :));
	for(i=0; i<sizeof(quest_list); i++) {
		quest_string = sprintf("%s%s的『%s』(%s)%s",
				quest_list[i]["done"] ? HIY"【"NOR: "　",
				quest_list[i]["owner"]->query("name"),
				quest_list[i]["item"]->query("name"),
				quest_list[i]["item"]->query("id"),
				quest_list[i]["done"] ?HIY "】"NOR : "　");
		k = 0;
		extra = 0;
/*		for(j=0; j<strlen(quest_string); j++) {
			if(quest_string[j] == ESC[0]) {
				k = 1;
			}
			if(k == 1) {
				extra++;
			}
			if(quest_string[j] == 'm') {
				k = 0;
			}
		}*/
		output += sprintf("%-*s", (45 + extra), quest_string);
		if(i%2) {
			output += "\n";
		}
	}
	output += "\n";
	return output;
}



string locate_obj(object me,string strr) 
{
	string *distance = ({
		"极近", "很近", "比较近", "不远",
		"不近", "比较远", "很远", "极远"
	});
	string *altitude =({
		"高处", "地方", "低处"
	});
	string *directions=({
		"周围","北方", "南方", "东方","西方",
		"东北方","西北方","东南方","西南方"
	});
	object ob, tmpobj/*,where*/, *ob_list;
	object item,room;
	string output,dis,alt,dir;
	string domain1,domain2;
	int i;
	int x,y,z,x0,y0,z0;
	int realdis;
	int tmp;	
	string str="";
	
	reset_eval_cost();
	for( i=0; i < sizeof(quests); i++)
	{
		if(!objectp(item= find_object(quests[i]["file_name"])))
			item = load_object(quests[i]["file_name"]);
		if(item->query("id") == strr || item->query("name") == strr) 
			str = quests[i]["file_name"];
	}
	if(str != "") 
	{
		room = environment(me);
		ob_list = children(str);
		for(i=0; i<sizeof(ob_list); i++) 
		{
			ob=find_env(ob_list[i]);
			if(ob)
			{	
		        	sscanf(file_name(room), "/d/%s/%*s", domain1);
		        	sscanf(file_name(ob), "/d/%s/%*s", domain2);
				x0= (int)room->query("coor/x");
				y0= (int)room->query("coor/y");
				z0= (int)room->query("coor/z");
				x=(int)ob->query("coor/x")-x0;
				y=(int)ob->query("coor/y")-y0;
				z=(int)ob->query("coor/z")-z0;
				if(domain1!=domain2)//如果在同一个区域就省了
				{
					x=x-COOR_D->query_coor(domain1,"x")+COOR_D->query_coor(domain2,"x");
					y=y-COOR_D->query_coor(domain1,"y")+COOR_D->query_coor(domain2,"y");
					z=z-COOR_D->query_coor(domain1,"z")+COOR_D->query_coor(domain2,"z");
				}
				realdis=0;
				if(x<0)realdis-=x; else realdis+=x;
				if(y<0)realdis-=y; else realdis+=y;
				if(z<0)realdis-=z; else realdis+=z;
				tmp =(int)  realdis/50;
				if(tmp>MAX_DIS) tmp = MAX_DIS;
				dis=distance[tmp];
				if(z>0) alt=altitude[0];
				if(z<0) alt=altitude[2];
				if(z==0) alt=altitude[1];
				if(x==0&&y==0) dir=directions[0];
				if(x==0&&y>0) dir=directions[1];
				if(x==0&&y<0) dir=directions[2];
				if(x>0&&y==0) dir=directions[3];
				if(x<0&&y==0) dir=directions[4];
				if(x>0&&y>0) dir=directions[5];
				if(x<0&&y>0) dir=directions[6];
				if(x>0&&y<0) dir=directions[7];
				if(x<0&&y<0) dir=directions[8];
				output = "『"+ob_list[i]->query("name")+"』似乎在"+dir+dis+"的"+alt+"。\n";				
				return output;
			}
		}
	}
	else
	// the checking of official and wizard is transferred to locate.c--mimicat 5.3.02
	/*if(wizardp(me) || me->query("class") == "official")*/
	{
		/*
		if (!wizardp(me) && me->query("combat_exp")<50000)
			{tell_object(this_player(),"你的经验还不足以确定他人的所在。\n");
				return"";
			}
		*/
			tmpobj = find_player(strr);
			if(!tmpobj) tmpobj = find_living(strr);
			if(!tmpobj) return "";
			ob = find_env(tmpobj);
			room = environment(me);
			if(ob)
			{
		        	sscanf(file_name(room), "/d/%s/%*s", domain1);
		        	sscanf(file_name(ob), "/d/%s/%*s", domain2);
				x0= (int)room->query("coor/x");
				y0= (int)room->query("coor/y");
				z0= (int)room->query("coor/z");
				x=(int)ob->query("coor/x")-x0;
				y=(int)ob->query("coor/y")-y0;
				z=(int)ob->query("coor/z")-z0;
				if(domain1!=domain2)//如果在同一个区域就省了
				{
					x=x-COOR_D->query_coor(domain1,"x")+COOR_D->query_coor(domain2,"x");
					y=y-COOR_D->query_coor(domain1,"y")+COOR_D->query_coor(domain2,"y");
					z=z-COOR_D->query_coor(domain1,"z")+COOR_D->query_coor(domain2,"z");
				}
				realdis=0;
				if(x<0)realdis-=x; else realdis+=x;
				if(y<0)realdis-=y; else realdis+=y;
				if(z<0)realdis-=z; else realdis+=z;
				tmp =(int)  realdis/50;
				if(tmp>MAX_DIS) tmp = MAX_DIS;
				dis=distance[tmp];
				if(z>0) alt=altitude[0];
				if(z<0) alt=altitude[2];
				if(z==0) alt=altitude[1];
				if(x==0&&y==0) dir=directions[0];
				if(x==0&&y>0) dir=directions[1];
				if(x==0&&y<0) dir=directions[2];
				if(x>0&&y==0) dir=directions[3];
				if(x<0&&y==0) dir=directions[4];
				if(x>0&&y>0) dir=directions[5];
				if(x<0&&y>0) dir=directions[6];
				if(x>0&&y<0) dir=directions[7];
				if(x<0&&y<0) dir=directions[8];
				output = "『"+tmpobj->query("name")+"』似乎在"+dir+dis+"的"+alt+"。\n";
				return output;
			}
		}
	return "";

}


int already_spreaded(string str,int hard) {
	object ob,ob1,*ob_list;
	int i;

	if(!str) {
		return 0;
	}

	ob_list = children(str);
	if(hard) {
		for(i=0; i<sizeof(ob_list); i++) {
			if(clonep(ob_list[i])) {
				ob1 = environment(ob_list[i]);
				destruct(ob_list[i]);
				if (objectp(ob1) && ob1->query("tasker"))	 {	// 去除task_npc
//						CHANNEL_D->do_sys_channel("sys", sprintf("smashing tasker %O.",ob1));
						ob1->self_destruct();
				} 										
			}
		}
		return 0;
	} else {
		for(i=0; i<sizeof(ob_list); i++) {
			if(clonep(ob_list[i])) {
				if(objectp(ob=find_env(ob_list[i]))) {
					return 1;
				} else {
					destruct(ob_list[i]);
				}
			}
		}
		return 0;
	}
}

object find_env(object ob) {
	while(ob) {
		if(ob->query("coor")) {
			return ob;
		} else {
			ob=environment(ob);
		}
	}
	return ob;
}

mapping *read_table(string file) {
	string *line, *field, *format;
	mapping *data;
	int i, rn, fn;

	line = explode(read_file(file), "\n");
	data = ({});
	for(i=0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !pointerp(field) ) {
			field = explode( line[i], ":" );
			continue;
		}
		if( !pointerp(format) ) {
			format = explode( line[i], ":" );
			continue;
		}
		break;
	}

	for( rn = 0, fn = 0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
		sscanf( line[i], format[fn], data[rn][field[fn]] );
		fn = (++fn) % sizeof(field);
		if( !fn ) ++rn;
	}
	return data;
}

void big_reward(object me, object who, object item)
{
	tell_object(me,"你真行！！\n");
}

void execute_accept_object(object me, object who, object item)
{
	who->accept_object(me,item);
}


void list_quests()
{
	int i = sizeof(quests);
	
	while(i--)
		write(sprintf("%O",quests[i]));
}

object *check_ppl_task(object ob){
	object *inv, *quest_item;
 	ob = this_player();
	inv = deep_inventory(ob);
	quest_item = filter_array(inv,(: $1->query("dynamic_quest") :));
	return quest_item;
}		


// +20% chance to lose one task if you fly with more than 8 tasks

void flying_risk(object ob){
	int count, chance;
	object *inv, *quest_item, item;
	inv = deep_inventory(ob);
	quest_item = filter_array(inv,(: $1->query("dynamic_quest") :));
	count = sizeof(quest_item);
	if (count <=8) 	return;
	
	chance = count*30 - 240;
	
	CHANNEL_D->do_sys_channel("sys", sprintf("losing task chance is %d.",chance));
			
	if (random(100)< chance) {
		item = quest_item[random(count)];
		tell_object(ob,WHT"\n风声呼呼，"+item->name()+NOR CYN"从你的身上不小心掉了出来，消失得无影无踪。\n\n"NOR);
		destruct(item);
	}
	return;
}	
		