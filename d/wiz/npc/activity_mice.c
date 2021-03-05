#define RESET_TIMES 8
#include <ansi.h>
inherit NPC;
int last_reset_time=RESET_TIMES;
//int time_period(int timep, object me);
//int wait_period(int timep, object me);

void create()
{
	set_name(HIM"鼹鼠"NOR, ({ "job mouse" }) );
    	set("race", "野兽");
        set("age", 1);
        set("title", HIY"得力助手"NOR);
        set("nickname",WHT"聪慧灵物"NOR);
        set("per",100);
        set("long","
一只漂亮聪明的大老鼠，负责打理WIZ日常工作，活动期间总是特别繁忙。\n");
        set("combat_exp",200000);
        set("NO_KILL","鼹鼠这么惹人喜爱的样子你怎么忍心下手。\n");      
        set_skill("dodge", 200);        
        set_temp("armor", 200);

    	setup();
}

void reset(){
	if (environment() && last_reset_time>=RESET_TIMES) {
		string *area = ({ 	
			"huangshan", "huashan", "songshan", "palace", "laowu", 
			"resort", "qianfo", "qingping", "taoguan","fy","chenxiang",
			"xinjiang","wanmei","eren","fugui","guanwai","jinan",
			"wudang","taiping",
			"chuenyu", "taishan", "guanyin","wolfmount","qianjin",
			"biancheng", "zangbei","baiyun" ,"bat","changchun"});
			
		string *c_area =  ({"黄山","华山","嵩山","帝王谷","冰封小镇",
					"铁雪山庄","千佛山","清平山庄","三清山","风云城","沉香镇",
					"新疆", "万梅山庄","恶人谷","富贵山庄","关外","济南",
					"武当山","太平镇",
				    "黑松山","泰山","天枫山庄","狼山","千金楼", 
				    "边城", "藏北","白云岛","蝙蝠岛","长春岛",
				    });
	
		string arg, arg1, room_name, *files;
		int num,i,m,size;
		object room;
		object sm;
		object me = this_player();
		
		num=18+random(9)+random(9);
	
		for (int n=0;n<num;n++) {
			
			m = random(sizeof(area));
			arg1 = "/d/"+area[m] +"/";
			arg = arg1+"*.c";
			files= get_dir(arg);
	
			
	
			while(1)
			{
				i = random(sizeof(files));
				size = sizeof(files[i]);
				//message_vision("file is "+ files[i] +"\n", me);
				//if(files[i][(size-2)..size]==".c")
				//{
					room_name = arg1 + files[i];
					room = find_object(room_name);
					if (!room)
						room = load_object(room_name);
					if (!room)	continue;
					if (!room->query("short")) 		continue;
					if (room->query("no_fly")) 		continue;
					if (room->query("no_fight")) 	continue;	
					if (room->query("underwater")) 	continue;
					break;
				//}
			}
			sm = new("/obj/treasure/npc/monsternian");
			sm->move(room);
			//message_vision("monsternian move to /d/"+ area[m] +"/"+ files[i]+"\n", me);
			//command("chat [1;31msnowman move to /d/"+ area[m] +"/"+ files[i]+"[0;32m");
		}
		last_reset_time=0;
		command("chat [1;37m眼若铜铃，来去如风的[1;33m年兽[1;37m出现在[1;39m风云村内。[0;32m");
	} else {
		last_reset_time++;
	}
	log_file("HIPPO_DEBUG", sprintf("刷新时间和数值记录：%s,%d\n",ctime(time()),last_reset_time));
}