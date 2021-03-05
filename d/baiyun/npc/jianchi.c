inherit SMART_NPC;
#include <ansi.h>
void create()
{
    	set_name("剑痴" , ({ "jian chi","jian" }) );
    	set("long", "因剑而痴，为剑而痴。\n");
		set("attitude", "friendly");
    	set("age", 62);
        set("gender", "男性" );
        create_family("白云城",1, "剑客");
    	set("per",4);
    	set("combat_exp", 4000000);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(80) :),
	     		CYN"剑痴傻笑道：呵呵呵呵……哈哈哈哈……喔呼呼呼……啊嘿嘿嘿……\n"NOR,
        }) );


		set("chat_chance", 1);
        set("chat_msg", ({
        	"剑痴傻笑道：呵呵呵呵……哈哈哈哈……\n",
        	"剑痴傻笑道：喔呼呼呼……啊嘿嘿嘿……\n",
        
        }) );
    	auto_npc_setup("ouyang",200,180,0,"/obj/weapon/","fighter_w","feixian-sword",1);


		setup();
        carry_object(__DIR__"obj/mayi")->wear();
        carry_object(__DIR__"obj/chengyin")->wield();
}



/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
