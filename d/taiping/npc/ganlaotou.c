#include <ansi.h>
inherit INQUIRY_MSG;
inherit SMART_NPC;

int ask_tie();
int paper();

void create()
{

	set_name("甘老头",({"gan laotou","gan"}));
    	set("long", "
他赤裸着上身，肋骨根根可数，那张脸亦是干尸一样，灰白的须发卷卷曲曲，也不
知是天生如此，还是因为经年累月伴着火炉，被火烘成这样。。\n");
	set("title", "千锤百炼");
	set("age",70);

	set("combat_exp", 9000000);
	set("class","yinshi");        	
	set("attitude","friendly");
		
	set("inquiry", ([
        		"韦七娘" : 	(: ask_tie :),
             	"wei qiniang" : (: ask_tie :),
              	"tie hen" : 	(: ask_tie :),
              	"铁恨" : 	(: ask_tie :),
              	"老蛔虫" : 	(: ask_tie :),
               	"谭氏兄弟" : 	(: ask_tie :),
                "宋大娘" : 	(: ask_tie :),
              	"老掌柜":	(: ask_tie :),
              	"血奴" : 	(: ask_tie :),
				"常笑":   	(: ask_tie :),
	 	])); 
	
	set("death_msg",CYN"\n$N大叫一声：“鹦鹉啊。。。” \n"NOR);
	set("chat_chance", 1);
    set("chat_msg", ({
                "甘老头似乎没有注意到你进来，锤子往刀上继续捶了几下，举起头来望一眼，转回
去，又举起铁锤捶下。\n",
        }) );
	
	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
        
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
		    (: auto_smart_fight(30) :),
        }) ); 		

	auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","pangu-hammer",2);
	
	set_skill("iron-cloth",200);

	setup();
	carry_object(__DIR__"obj/hammer")->wield();
	carry_object(__DIR__"obj/towel")->wear();
	carry_object("/obj/armor/cloth")->wear();
}


int ask_tie()  {
	
	message_vision("$N抬起头来看了看你，指了指自己的耳朵，摇摇头又继续打铁了。\n",this_object());
	this_player()->set("marks/parrot/甘老头",1);
	return 1;
}	

/*
int paper() {

	if (!this_player()->query("marks/parrot/甘老头的锁")) {
		message_vision("$N抬起头来看了看你，指了指自己的耳朵，摇摇头又继续打铁了。\n",this_object());
		return 1;
	}
	message_vision("$N道：“我只知道是有人叫我将纸送去鹦鹉偻，交给一个叫做"+this_player()->query("name")+"的人。”\n",this_object());
	message_vision("$N说：“我不识字，纸上写的什么我也不知道。”\n",this_object());
	return 1;
}

*/

