#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("黄衣卫统领", ({ "guard leader","leader" }) );
        set("gender", "男性" );
        set("age", 42);
		set("class","assassin");
        set("long", "这是一位金钱帮总舵的黄衣卫统领。\n");
        
        set("combat_exp", 1500000);
        set("attitude", "friendly");
        	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(30) :),
        }) );	
        set("chat_chance", 1);
        set("chat_msg", ({
                "黄衣统领喝道：没有帮主的口喻，谁都不准通过。\n",
        }) );
	
		auto_npc_setup("wang",150,150,0,"/obj/weapon/","fighter_w","lefthand-sword",1);
		set_skill("flame-strike",100);
		setup();
		
	    carry_object(__DIR__"obj/tangfu")->wear();
		carry_object("/obj/weapon/sword")->wield();
}
