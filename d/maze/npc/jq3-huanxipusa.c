inherit MAZE_NPC;
#include <ansi.h>

void create()
{
	set_name("大欢喜女菩萨", ({ "huanxi bodhisattva", "bodhisattva","pusa" }) );
	set("gender", "女性" );
	set("title", HIR"欢喜教 女主持"NOR);
        set("age", 39);
	
        set("long","
这简直就不是人，而是一座山，肉山。她眼睛并不小，现在却被脸上的肥肉挤成
了一条线，她脖子本来也许并不短，现在却已被一叠叠的肥肉填满了。 \n"
		);
	set("inquiry", ([
		"葛伦": "葛伦那老家伙，哼，总有一天欢喜教会一统藏北。\n",
	]) );
        set("combat_exp", 8000000);

        set("attitude", "aggressive");
        set("zombie-killer",1);
        
        set("experience",250);
	set("potential",60);
	set("money",250);
	set("toughness",150);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"喝道：什么人敢私闯黄金塔！\n",
        }) );
		
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(100) :),    
        }) );
	
	auto_npc_setup("liaoyin",300,250,1,"/obj/weapon/","fighter_w","kwan-yin-spells",2);
	setup();
    	carry_object("/obj/armor/cloth")->wear();    
}