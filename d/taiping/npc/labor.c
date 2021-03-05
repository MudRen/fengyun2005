#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("马夫",({"labor",}));
    	set("long","
驿站里的马夫，地位虽然低微，却是关系到驿站声誉的差使。近来安子
豪与内地的小潘做起了骆驼队生意，所以他也兼管起养骆驼来。只要给
他三两银子，就可以平安迅速地将你载回中原。\n");
  	set("gender","男性");
    	
    	set("combat_exp",1500000);  
    	set("attitude", "friendly");
    	
    	set_skill("fork",200);
    	set_skill("parry",200);
    	set_skill("dodge",200);
    	
    	set("inquiry", ([
                "饲料整理" : 	"拿把钉耙把那堆饲料整理（ｃｌｅａｎ）一下吧。\n\n",
				"饲料" : 	"拿把钉耙把那堆饲料整理（ｃｌｅａｎ）一下吧。\n\n",
				"整理饲料":	"拿把钉耙把那堆饲料整理（ｃｌｅａｎ）一下吧。\n",
				"沙漠": "雇了我的骆驼队，过沙漠又快又安全。\n",
				"desert": "雇了我的骆驼队，过沙漠又快又安全。\n",
				"camel": "雇了我的骆驼队，过沙漠又快又安全。\n",
				"骆驼": "雇了我的骆驼队，过沙漠又快又安全。\n",
				"骆驼队": "雇了我的骆驼队，过沙漠又快又安全。\n",
				"小潘":	"小潘据说在关内管骆驼，具体我也不是太清楚。\n",
        ]));
    	
    	
    	set("death_msg",CYN"\n$N说：你完了，等着杀头吧。。 \n"NOR);
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	     	10: 	"\n马夫叫道：来人啊，杀人啦！！！\n",
        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
    		
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
    		"马夫手忙脚乱地打扫着马房，嘴里不情不愿地嘟囔着。\n",
    		"马夫说：“谁能帮我把这些饲料整理一下呢？”\n",
    		"“～～～～咴～～～～咴～～～～”\n",
    		
    	}) );    	    	
    	
    	
	setup();
    	carry_object(__DIR__"obj/ycloth")->wear();      
    	carry_object(AREA_TAIPING"obj/brokenrake")->wield();
}

int accept_object(object who, object item){
	object ob;
	object room;
	
	ob = this_object();
	room = find_object(AREA_QUICKSAND"yizhan");
	
	if (!room || !room->query("route_clear")) {
		message_vision("
马夫唉声叹气地说：“最近路上不太平，我跟中原那头失了联系，
这骆驼队的生意也做不成了。。”\n",this_object());
		return 1;
	}
	if ((item->query("value")<300 && !who->query("石观音/desert_route"))
		|| item->query("value")<300) {
		message_vision("
马夫为难地摇摇头：“这点钱，就是买骆驼草都不够啊！”\n",ob);
		return 0;
	}
	if (who->is_busy()) {
		message_vision("马夫说：“客官似乎还有事儿没了吧？”\n",ob);
		return 0;
	}
		
	message_vision("马夫满脸堆笑地说：“客官，咱们这就上路。”\n",ob);
	message_vision("
马夫从后面牵出一头又大又壮的骆驼，$N一纵身骑了上去。\n",who);
	message_vision("$N高声吆喝：“骆驼队出发喽！”\n",ob);
	who->set_temp("ride","骆驼");
	who->start_busy(16);
	environment()->go_out_1(who, 0);
	return 1;
}
