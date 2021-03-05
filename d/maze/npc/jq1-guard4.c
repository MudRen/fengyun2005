#include <ansi.h>
inherit MAZE_NPC;

void create()
{
        set_name(HIY"金衣铁卫"NOR, ({ "jinqian tiewei","tiewei"}) );
        set("gender", "男性" );
        set("title","金钱帮 ");
        set("age", 22);
        set("class","official");
	set("long", "
金衣铁卫是金钱帮外堂禁卫，大多是上官金虹挑选出的出类拔萃之辈，
不仅手底功夫要狠，为人也要够狠才行。\n");
        
        set("combat_exp", 2000000);
                    
        set("chat_chance", 1);
        set("chat_msg", ({
                "金衣铁卫喝道：什么人！\n",
        }) );
	
		set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
	       	(: perform_action("spear.zonghengtianxia") :),    
        }) );
	
		auto_npc_setup("liaoyin",150,150,1,"/obj/weapon/","fighter_w","yue-spear",1);
		delete_skill("iron-cloth");
		setup();
		carry_object("/d/fy/npc/obj/tangfu")->wear();  
    	
}