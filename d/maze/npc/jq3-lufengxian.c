#include <ansi.h>
inherit MAZE_NPC;

void create()
{
    	set_name("吕凤先",({"lu fengxian","lu"}));
		set("title",HIR"活死人"NOR);
        set("nickname",HIC"银戟温侯"NOR);
        set("long",WHT"昔日的银戟温侯已死，现在的吕凤先却似乎更加强大。\n"NOR);
     	set("gender","男性");
    	set("class","fugui");
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
	
		auto_npc_setup("liaoyin",350,250,0,"/obj/weapon/","fighter_w","xuezhan-spear2",2);

		setup();
    	carry_object("/obj/armor/cloth")->wear();     
    	carry_object(__DIR__"obj/silver_spear")->wield();
}
