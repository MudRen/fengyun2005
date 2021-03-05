#include <ansi.h>
inherit MAZE_NPC;

void create()
{
        set_name("宣武堂卫士", ({ "guard"}) );
        set("gender", "男性" );
        set("title","金钱帮 ");
        set("age", 22);
        set("maze","jq1");
        set("target_name","金衣卫");
        set("class","official");
	set("long", "
宣武堂卫士是宣武堂内最高级别的禁卫，大多是上官金虹挑选出的出类拔萃之
辈，不仅手底功夫要狠，为人也要够狠才行。\n");
        
        set("combat_exp", 900000);
               
        set("attitude", "aggressive");
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "宣武堂卫士狞笑道：私闯武堂禁地者死！\n",
        }) );
	
		set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
	       	(: perform_action("spear.zonghengtianxia") :),    
        }) );
	
		auto_npc_setup("liaoyin",100,120,1,"/obj/weapon/","fighter_w","yue-spear",1);
		delete_skill("iron-cloth");
		setup();
		carry_object("/d/fy/npc/obj/tangfu")->wear();  
    	
}