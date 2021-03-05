#include <ansi.h>
inherit MAZE_NPC;

void create()
{
        set_name("铁雪奇侠", ({ "prisoner"}) );
        set("gender", "女性" );
        set("title",WHT"行尸走肉"NOR);
        set("age", 52);
	set("class","assassin");
        set("long", "
曾几何时，他们还是江湖上头可断、血可流，志不可没的铮铮汉子，可是地牢中
多年的折磨和药物的毒害，已经把他们变成了没有神志、没有正邪的嗜血狂人。\n");
        set("maze","jq2");
        set("combat_exp", 3600000);
		if (!random(10))	set("attitude", "aggressive");
        
		set("target_name","行尸走肉");
        
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"嘶哑地喊道：死，死，死！\n",
        }) );
		
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(15) :),    
        }) );
	
	auto_npc_setup("liaoyin",200,150,1,"/obj/weapon/","fighter_w","diesword",1);
	setup();
    	carry_object("/obj/armor/cloth",([	"name": "破旧不堪的囚衣",
						"long": "一件破旧不堪的囚衣，已经看不出原来的颜色和质地了。\n",
					 ]))->wear();    
}
