#include <ansi.h>
inherit SMART_NPC;

int loan();

void create()
{
	set_name("塔公寺的喇嘛",({"tagong lama","lama"}));
	set("long", "塔公寺的老喇嘛，衣着比起附近寺庙里的喇嘛差多了，愁眉苦脸地望着塔林出神。\n");
	set("age",30+random(20));
	set("attitude", "friendly");
	set("combat_exp", 3500000);
		
	set("inquiry", ([
 		"香火":		(: loan() :),
 		"香火钱":	(: loan() :),
 		"朝圣":		(: loan() :),
		"转经":		"绕寺千转，自有所得！\n", 
		"司空掏星": "这猴精贼头狗脑的，我就知道他没安好心。\n",
   	]));
	
		set("chat_chance", 1);
        set("chat_msg", ({
		name()+"说：施主，布施点香火钱吧。\n",  
        }) );
		set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: auto_smart_fight(50) :),    
        }) );

	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","lianxin-blade",1);
	
	setup();
	carry_object(__DIR__"obj/lamacloth")->wear();
	carry_object(__DIR__"obj/nblade")->wield();
	
}


int loan(){
	object ob=this_object();
	
	message_vision(CYN"老喇嘛叹了口气说“这塔公寺年久失修，现在来朝圣的人是越来越少了。”\n"NOR,ob);
	message_vision(CYN"老喇嘛用希冀的眼光看着$N：“施主可愿捐些香火？”\n\n"NOR,this_player());
	return 1;
}



int accept_object(object who, object ob){
	
	who->add_temp("marks/tagong",ob->query("value"));
	
	if (who->query_temp("marks/tagong")<5000) {
		message_vision(CYN"老喇嘛脸上露出一丝失望，“嗯，多谢施主。”\n"NOR,this_object());
	} else if (who->query_temp("marks/tagong")<10000) {
		message_vision(CYN"老喇嘛双掌合十，低头垂目：“嗯，多谢施主。”\n"NOR,this_object());
	} else {
		message_vision(CYN"老喇嘛的眼里忽然放出光来，话音也有些颤抖：“佛祖一定会保佑施主的。
老衲这就去让人重修佛塔，再塑金身。”\n"NOR,this_object());
		tell_object(who,WHT"听了老喇嘛的话你才注意到，原来这里的塔林久经风雨，已经十分破旧了。\n"NOR);
		who->set_temp("zangbei/塔公寺施舍",1);
	}
	return 1;
} 