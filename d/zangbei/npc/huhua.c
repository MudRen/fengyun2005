#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int estate();

void create()
{
    	set_name("秦护花",({"qin huhua","qin"}));
	set("title","鲁东");
   	set("long","
秦护花是鲁东最大世家的这一代主人，年纪已大得足够做他身旁少女的祖
父。但他身体还是保养得很好，精力还是很充沛，所以每年秋天，他都要
到这里来往一段日子。秦护花在武林的地位并不低，已可与当代任何门派
的掌门人分庭抗礼。\n");
   	
     	set("gender","男性");
     	set("group","khlr");
     	
    	set("age",62); 	 	
    	    	
    	set("combat_exp",4800000);  
    	set("attitude", "friendly");
    	
    	set("inquiry", ([
 
   		]));
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(30) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"秦护花笑道：“老夫聊发少年狂，左把酒，右抱姬，醉卧快活林。”\n",
    	}) );    	    	
    	
		auto_npc_setup("wang",200,180,0,"/obj/weapon/","fighter_w","xuanyuan-axe",1);
	
		setup();
    	carry_object("/obj/armor/cloth")->wear();
    	carry_object(__DIR__"obj/qaxe")->wield();
 
}

