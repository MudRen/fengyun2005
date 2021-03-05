#include <ansi.h>
inherit MAZE_NPC;

void create()
{
    	set_name("龙啸云",({"long xiaoyun","long"}));
	set("title",HIR"活死人"NOR);
        set("nickname",HIY"兴云庄主"NOR);
        set("long",WHT"
龙啸云本已死，但谁能想到他又活了，准确的说不是活了，只是从地狱中被
召唤出来而已。\n"NOR);
     	set("gender","男性");
        set("combat_exp", 8000000);
	set("boss",1);
	
        set("attitude", "aggressive");
        set("zombie-killer",1);
        
        set("experience",1000);
	set("potential",1000);
	set("money",2000);
	set("toughness",300);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"喝道：什么人敢私闯黄金塔！\n",
        }) );

	set("officer-killer",1);		
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(100) :),    
        }) );
	
	auto_npc_setup("liaoyin",350,200,0,"/obj/weapon/","fighter_w","taiji",2);

	setup();
    	carry_object("/obj/armor/ghost_cloth")->wear();     
}