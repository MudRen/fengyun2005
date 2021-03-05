inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("拂尘的女子", ({ "housework girl" }) );
        set("gender", "女性");
        set("age", 25);
        set("long","一个神水宫的少女,正在打扫屋子。\n"); 
        set("attitude", "friendly");
        set("score", 2000);
        set("class", "huashan");
        
        set("combat_exp", 2500000);
        
        set("chat_chance_combat",100);     
        set("chat_msg_combat", ({
	     	(: auto_smart_fight(20) :),
     	}) ); 		

		auto_npc_setup("wang",150,140,0,"/obj/weapon/","fighter_w","tanzhi-shentong",1);
        setup();
        carry_object(__DIR__"obj/n_stone")->wield();
		carry_object("/obj/armor/cloth")->wear();
}