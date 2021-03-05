#include <ansi.h>
inherit NPC;


void create()
{
    	set_name("白发苍苍的老太婆",({"taipo"}));
   		set("long","白发苍苍的老太婆正佝偻着身子，蹒跚地走出来。\n");
     	set("gender","女性");
    	set("age",72);
    	set("per",10); 	
    	set("int",22);
    	set("cor",30);
    	set("cps",20);
    	
    	set("combat_exp",500000);  
    	set("attitude", "friendly");
    	
 		set("chat_chance",1);
    	set("chat_msg",({
		"白发苍苍的老太婆说：“这屋子已经有人租下了。。。。”\n",
    	}) );    	    	
    	    	
		setup();
    	carry_object("/obj/armor/cloth",([	"name": "粗布衣",
    						"long": "一件粗布衣。\n",
    						 ]))->wear();    
    
}
