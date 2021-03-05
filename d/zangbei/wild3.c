inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "草原");
        set("long", @LONG
西部草原，辽阔而静寂。望山跑死马。朝着一片缓缓起伏的绿色平坡走，许久，
它仍然在天边诱人地等待。上了高处，前面又是伸向白云处的草原。远处的雪峰倒
映在蓝天白云下，近处，一排排高大的白杨树，象哨兵似傲然地聳立，连绵数十里。
(拦路土匪需交１两黄金放行。)
LONG
        );
        set("long_night",@LONG
草原的夜是寂寞的，辽远清冷的高空，挂起无数的星点，在下面，夜行人的灯
笼摇摇摆摆，象是沼地中的鬼火跳舞，在道路两旁，全是黑沉沉的白杨树林，在前
面，无边的草原在风中瑟瑟作响，呜咽似地呻吟，令赶路的人毛骨悚然。(拦路土匪
需交１两黄金放行。)
LONG
        );
        
        set("exits", ([ 
		"southeast" : __DIR__"wild2",
		"west" : __DIR__"wild4",
		"south" : __DIR__"woods1",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1600);
        set("coor/y",710);
        set("coor/z",0);
        set("no_lu_letter",1);
	set("map","zbwest");
	setup();
	
}


void reset() {
	object badguy,*inv,room,boss/*,village*/;
	int count,i;
	mixed current_time;
	string *boss_name=({"baimian langzhong","tu laohu","one eye"});
	string boss1;
	
	::reset();
	
	room=this_object();
	current_time=NATURE_D->get_current_time();

//	in the morning, first reset disappear	
	inv=all_inventory();
	for (i=0;i<sizeof(inv);i++) {
		if (inv[i]->query("group")=="longhuzhai") {
			if (current_time[5]<1080 && current_time[5]>360) {
				if (inv[i]->query("id")=="bandit" && !userp(inv[i])) {
					inv[i]->ccommand("say 天晓也，扯呼。");
					message_vision("$N一头钻进南边的树林里消失了。\n",inv[i]);
					destruct (inv[i]);
				} else {
					room=find_object(AREA_ZANGBEI"village");
					if (!room) destruct (inv[i]);
					else {
						inv[i]->move(room);
						message_vision("$N从山寨外面走了进来。\n",inv[i]);
					}
				}
				
			} else count++;
		}
	}

//	in the evening, first reset appears
	if (current_time[5]>1080 || current_time[5]<360) {
		if (count<2) {
			for (i=0;i<3;i++)	{
				badguy=new(__DIR__"npc/bandit");
				badguy->set("attitude", "friendly");
				badguy->move(room);
			}
			message_vision("只听刷拉拉一阵响，路旁的树林里窜出了几个土匪。\n",badguy);
			badguy->ccommand("say 月黑风高夜，杀人放火天。");
		}	
		if (!present(boss_name[0],room) && !present(boss_name[1],room)
			&& !present(boss_name[2],room))
		for (i=0;i<6;i++) {
			boss1=boss_name[random(sizeof(boss_name))];
			boss=find_real_living(boss1);
			if (boss && !boss->is_fighting()) {
				badguy=present("bandit",room);
				message_vision(CYN"$N诚惶诚恐地说：大王也来了。\n"NOR,badguy);
				message_vision(CYN"$N一边往外走一边说，“我去看看孩儿们生意做的怎样。”\n"NOR,boss);
				boss->move(room);
				boss->set("attitude","friendly");
				boss->ccommand("pat bandit");
				return;
			}
		}	
	}
	return;
}


int valid_leave(object obj, string dir){
	int i;
	object *inv/*,*bandit*/;
	
	if(dir == "west"){
		if (obj->query_temp("wild4_pass") || obj->query("combat_exp")<1000000) return 1;
		inv = all_inventory(this_object());
		for (i=0;i<sizeof(inv);i++) {
			if (inv[i]->query("group")=="longhuzhai") 
				return notify_fail(inv[i]->name()+"说：“此山是我开，此树是我栽，要打此路过，留下买路钱！”\n");
		}
		
	}	
	return 1;
}