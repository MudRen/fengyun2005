#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

void create()
{
    	set_name("李马虎",({"li mahu","li","mahu"}));
	set("title","杂货铺老板");
   	set("long","
他姓李，别人都叫他李马虎。是个很乐观的中年人，
圆圆的脸，无论看到谁都是笑眯眯的。\n");
     	set("gender","男性");
    	set("age",32);
    	
    	set("combat_exp",2800000);  
    	set("attitude", "friendly");
    	    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
			10: name()+"叫道：“来人啊，强盗打劫店铺啦！”\n",
        ]) ); 
           	
    	set("chat_chance",1);
    	set("chat_msg",({
		"李马虎笑眯眯地道：“女人用鸡蛋清洗脸，越洗越年轻的。”\n",
    	}) );    	    	
    	
    	
	auto_npc_setup("wang",160,150,0,"/obj/weapon/","fighter_w","taiji",1);
	
	setup();
    	carry_object("/obj/armor/cloth")->wear();    
    
}
