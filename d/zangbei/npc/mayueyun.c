#include <ansi.h>
inherit SMART_NPC;

int estate();

void create()
{
    	set_name("马月云",({"ma yueyun","ma"}));
    	set("title","温柔贤惠");
   	set("long","
马方中的太太很贤慧、菜烧得很好，所以马方中一天比一天发福，到了中
年后，已是个不大不小的胖子。马太太无论说什么，马方中都千依百顾。
村子里的老太太，小媳妇们，都在羡慕马太太。一定是上辈子积了德，所
以才嫁到这样一位好丈夫。\n");
   	
     	set("gender","女性");
     	set("group","ma");
     	
    	set("age",32); 	 	
    	
    	set("marry_name","马方中");
    	set("marry","ma fangzhong");
    	
    	set("combat_exp",500000);  
    	set("attitude", "friendly");
    	
    	set("inquiry", ([
 		"*":	"我很少出门，你问的这些我都不知道呀。\n",
   		]));

    	set("chat_chance",1);
    	set("chat_msg",({
		"马月云看了看身边的一双儿女，心满意足地笑着。\n",
    	}) );    	    	
    	
		
		setup();
    	carry_object("/obj/armor/cloth",([	"name": "青布裙",
    						"long": "一条家常穿的布裙。\n",
    						 ]))->wear();    
 
}

