// 熟悉各地描述的工作	--- By silencer@fy4. workgroup


inherit NPC;
inherit F_VENDOR;
#include <ansi.h>

void create()
{
    set_name("徐万里", ({ "xu wanli", "xu" }) );
	set("gender", "男性" );
	set("age", 61);
	set("title", CYN "足不出户"NOR);
	set("long","
徐万里据说是徐霞客的第十五代玄孙，取了个威风的名字，学其曾祖游历四地，
老来在警世书局里开了个铺子经销各地的图经地志，同时雇些年轻学徒到各地
继续登录风土人情。\n");
	set("combat_exp", 150000);
	set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ([
		"obj/item/map_scroll": 100,
	]) );
	
	set("inquiry", ([
	       	"job": 	 	"这儿正缺人手，从我这儿买张卷轴给我，我给你指点指点。\n",
	       	"工作": 	"这儿正缺人手，从我这儿买张卷轴给我，我给你指点指点。\n",
	       	"图经地志": 	"这儿的图经地志还不完善，从我这儿买张卷轴给我，我给你指点指点。\n",
	       	"地图": 	"这儿的图经地志还不完善，从我这儿买张卷轴给我，我给你指点指点。\n",
	       	"map": 		"这儿的图经地志还不完善，从我这儿买张卷轴给我，我给你指点指点。\n",
	       	"风土人情": 	"想去游历游历？从我这儿买张卷轴给我，我给你指点指点。\n",
         ]) );
		
	set_skill("unarmed",150);
	set_skill("dodge",150);
	set_skill("parry",150);
	setup();
	carry_object(__DIR__"obj/fycloth")->wear();
}

void init(){
	add_action("do_vendor_list","list");
	::init();
}

int accept_object(object who, object item) {
	
	int amount;
	string *area = ({ 	
		"huangshan", "huashan", "songshan", "palace", "laowu", 
		"resort", "qianfo", "qingping", "taoguan", "taoyuan", 
		"xinjiang","wanmei",
		
		"chuenyu", "taishan", "guanyin","wolfmount","qianjin" });
	
	string *c_area =  ({"黄山","华山","嵩山","帝王谷","老屋",
				"铁雪山庄","千佛山","清平山庄","三清山","桃源村",
				"新疆", "万梅山庄",
			    "黑松山","泰山","天枫山庄","狼山","千金楼", 
			    "白云岛","长春岛"});
	string arg, room_name, *files;
	int i, n, m, size, reward, exp;
	object room, silver;
	
	if (item->query("id")!= "scroll" || item->query("usage")!="map")
		return 0;
	
	if (!item->query("room_desc"))	{
		if (item->query("destination")=="none") {
			
			if (who->query("timer/xu_map") + 30 > time()) {
				message_vision(CYN"
徐万里说：我不是刚给你交待过么？怎么还在这儿？\n"NOR, who);
				return 0;
			}
						
			if (who->query("combat_exp")> 100000 
				|| QUESTS_D->verify_quest(who,"绘地图"))
				m = random(sizeof(area));
			else
				m = random(12);
				
			arg = "/d/"+area[m] +"/";
			files= get_dir(arg);
	    	    	n = 6;
	    	    	
	    	    	while(n--) {
	    	    		i = random(sizeof(files));
	    	        	size = sizeof(files[i]);
//	    	        	message_vision("file is "+ files[i] +"\n", who);
	        		if(files[i][(size-2)..size]==".c") {
	  	        		room_name = arg + files[i];
	  	        		room = find_object(room_name);
	  	        		if (!room)
	  	        			room = load_object(room_name);
	  	        		if (!room)	continue;
	  	        		if (!room->query("short")) continue;
	  	        		break;
	  	        	}
	  	        }	
			
			// Very Bad Luck, I can't find any room.
			if (!room) {
				message_vision(CYN"
徐万里接过卷轴，拿起毛笔刚要落笔，不小心手一抖一团墨汁洒在卷轴上，
徐万里一笑说：抱歉抱歉，这张卷轴没法用了，你还有新的么？\n"NOR,who);
				return 1;
			}
					  	        			
	  	        message_vision(CYN"
徐万里接过卷轴，拿起毛笔在上面写了几个字又递回给$N说：你可去轴上的地
点考察一番，记录下风土人情后再回来给我。\n"NOR, who);
			item->set("map_owner", who);
			item->set("destination", room_name);
			item->set("room_name", room->query("short"));
			item->set("area", c_area[m]);
			who->set("timer/xu_map", time());
			return notify_fail("");
		} else
			{
			message_vision(CYN"
徐万里说：“我不是已经把具体地点写在卷轴上了么？”\n"NOR, who);
			return 0;
		}
	} else {
		if (item->query("map_owner")!= who) {
			message_vision(CYN"
徐万里说：“我好像没和阁下打过交道吧？\n"NOR, who);
			return 0;
		}
		message_vision(CYN"
徐万里说：“好！好！太谢谢你了！\n"NOR, who);
		// Giving reward
		
		if ( QUESTS_D->verify_quest(who,"绘地图")){
			amount = 20;
			QUESTS_D->special_reward(who,"绘地图");
		} else 
			amount = 12;
		
		silver = new("obj/money/silver");
		silver ->set_amount(amount);
		if (!silver->move(who)) 
			destruct(silver);
		tell_object(who, WHT"你得到了"+ chinese_number(amount)+ "两银子！！\n"NOR);	
		
		return 1;		
	}	
}



void reset()
{
	set("vendor_goods", ([
		"obj/item/map_scroll": 100,
	]) );
}
		
