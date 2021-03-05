#include <ansi.h>
inherit MAZE_NPC;

void create()
{
    	set_name("五毒童子",({"nefarious kid","kid"}));
	set("title",HIR"活死人"NOR);
        set("nickname",HIB"五毒教主"NOR);
        set("long",WHT"
五毒童子昔年在人间为恶诸多，早已为李寻欢一刀毙命，但现在又出现在你的
面前。他身形矮小如幼童，身上穿着条短裙，露出一双小腿，他的头也很小，
眼睛却亮如明灯，充满了怨毒。\n"NOR);
     	set("gender","男性");
    	
     	set("age",12);
        set("combat_exp", 8000000);
	set("boss",1);
	set("zombie-killer",1);
	
        set("attitude", "aggressive");
        
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
	
	auto_npc_setup("liaoyin",300,250,1,"/obj/weapon/","fighter_w","herb",1);

	setup();
    	carry_object("/obj/armor/skirt",([	"name": "短裙",
					"long": "一条色彩艳丽的短裙。\n",
					 ]))->wear();     
}
