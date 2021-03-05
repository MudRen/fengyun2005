#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

void create()
{
	set_name("欧阳丁",({"ouyang ding","ding"}));
	set("long", "此人又高又胖。园脸，肥颈，笑眯得起来的眼睛，慢条斯理的说话。\n");
	set("title","豆腐大胖");
	set("age",45);
	set("attitude", "friendly");
	set("combat_exp", 9500000);
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
		"欧阳丁说：我这个豆腐，乃是刘安的八公山豆腐的独门真传，入口即化，入口即化啊。\n",
        	
        }) );
		set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: auto_smart_fight(100) :),    
        }) );
	
	auto_npc_setup("guardian",300,200,0,"/obj/weapon/","fighter_w","jin-gang",2);
	
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/armor/ribbon",([	"name": "蓝布手巾",
    						"long": "一条蓝布手巾。\n",
    						 "value": 2,
    						 ]))->wear();    
	carry_object("/obj/weapon/staff",([	"name": "豆腐杆",
    						"long": "一根豆腐杆。\n",
    						 "value": 2,
    						 ]))->wield();    
    
}

