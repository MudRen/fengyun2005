#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;


void create()
{
    set_name("捕快",({"yayi",}));
    set("title","太平镇");
    set("long","
太平镇的捕快其实并不是真正的官儿，只是常驻的驿吏，八百里方圆就这么
一个还算是官家的地方，所以无论是杀人越货的大案还是邻里吵架的鸡毛小
事，都归这儿的驿站官员管。\n");
  	set("gender","男性");
    	set("combat_exp",4500000);  
    	
    	
    	set("attitude", "friendly");
    	set("group","taiping");
    	set("inquiry", ([
               	"跳蚤" : 	"你领子上就有一只，正往你脖子里钻呢！",
   	]));
    	set("death_msg",CYN"\n$N说：你完了，等着杀头吧。。 \n"NOR);
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	     	10: 	"\n捕快叫道：来人啊，杀人啦！！！\n",
        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"捕快懒洋洋地说：这地方除了跳蚤，什么也没有。\n",
		"捕快从桌上拿起一杯水，一仰脖子喝了下去。\n",
    	}) );    	    	
    	
    	auto_npc_setup("wang",200,170,0,"/obj/weapon/","fighter_w","thunderwhip2",1);
	
	setup();
    	carry_object(__DIR__"obj/ychain")->wield();    
    	carry_object(__DIR__"obj/ycloth")->wear();  
    
    
}
