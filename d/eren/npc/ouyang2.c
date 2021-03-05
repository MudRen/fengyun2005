#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

void create()
{
	set_name("欧阳当",({"ouyang dang", "dang"}));
	set("title","豆腐二胖");
	set("long", "此人又高又胖。园脸，肥颈，笑眯得起来的眼睛，慢条斯理的说话。\n");
	set("age",43);
	set("attitude", "friendly");
	set("combat_exp", 9800000);
	
	set("reward_npc",20);
	
	set("inquiry", ([
        	"小烟" : "村里的小孩，昨天还在这儿买豆腐来着。",
        	 "欧阳豆腐铺" : "嘿嘿，咱兄弟开的豆腐铺。",
              "哈哈酒楼": "哈哈酒楼当然是哈哈儿开的喽，他现在不行喽。",
              "哈哈儿": "哈哈酒楼当然是哈哈儿开的喽，他现在不行喽。",
   			  "豆腐":	"小店专卖豆腐，远近闻名。\n",
   			  	
   	]));
	
	set("chat_chance", 1);
    set("chat_msg", ({
			"欧阳当笑了笑：什么陈婆豆腐麻辣豆腐，不上我的眼。\n",
        	
        }) );
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: auto_smart_fight(30) :),    
        }) );
	
	auto_npc_setup("guardian",300,200,0,"/obj/weapon/","fighter_w","kwan-yin-spells",2);
	
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/armor/ribbon",([	"name": "粗布手巾",
    						"long": "一条粗布手巾。\n",
    						"value": 2,
    						 ]))->wear();   
}
