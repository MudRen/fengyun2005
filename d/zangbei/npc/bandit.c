#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("山寨喽罗",({"bandit"}));
	set("title",YEL"龙虎寨"NOR);

   	set("long","一个身穿黑衣，拿着明晃晃钢刀的小土匪。\n");
     	set("gender","男性");
    	set("age",32);
    	set("group","longhuzhai"); 	
 
    	set("combat_exp",2000000);  
    	set("attitude", "aggressive");
    	    	
    	set("death_msg",CYN"\n$N叫道：“早知道。。就不当土匪了。。”\n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
		10: "山寨喽罗叫道：“送上门的肥羊，弟兄们并肩上呀。”\n",
		15: "山寨喽罗叫道：“大王，大王在哪里？顶不住了。”\n",
        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
        
        set("inquiry", ([
        	"货物" : 	"货物么？早运走了！\n",
             	"大王" : 	"大王在寨子里歇息呢！\n",      
             	"寨子" : 	"你想入伙？功夫不到家！！！\n",
             	"龙虎寨" : 	"你想入伙？功夫不到家！！！\n",
             	"入伙" : 	"你想入伙？功夫不到家！！！\n",
   	]));
   	
    	set("chat_chance",1);
    	set("chat_msg",({
		"山寨喽罗叫道：“龙虎寨的大王在此，闲杂人等闪开了！”\n",
    	}) );    	    	
    	
	auto_npc_setup("wang",150,130,1,"/obj/weapon/","fighter_w","smallguy",1);
	
	setup();
    	carry_object("/obj/armor/cloth",([	"name": "黑布短靠",
    						"long": "一件黑布短靠。\n",
    						 ]))->wear();    
    
}


int accept_object(object who, object ob)
{

	if( ob->value() >= 10000) {
                        command( "say 哈哈，看在你孝顺的份上，就给你个方便吧。");
                        who->set_temp("wild4_pass", 1);
                        who->remove_all_killer();
                        return 1;
                } else {
                    	command("say 呸，你当大爷是叫花子？\n");
                        return 0;
                }
        return 0;
} 
