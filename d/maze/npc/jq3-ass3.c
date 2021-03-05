#include <ansi.h>
inherit MAZE_NPC;

void create()
{
//      string *name = ({HIC"青龙"NOR,HIW"白虎"NOR,HIR"朱雀"NOR,HIB"玄武"NOR});
	string *name = ({"青龙","白虎","朱雀","玄武"});
        set_name(name[random(sizeof(name))], ({"jinqian assassin","assassin"}) );

       set("gender", "男性" );
        set("title","金钱帮 "HIB"四杀手之"NOR);
        set("age", 30+random(30));
	set("class","assassin");
        set("long", "金钱帮四大杀手之一。\n");
        set("maze","jq3");
        set("combat_exp", 6400000);

        set("attitude", "aggressive");
        
        set("experience",180);
	set("potential",70);
	set("money",200);
	set("toughness",150);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"喝道：什么人敢私闯黄金塔！\n",
        }) );
		
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(20) :),    
        }) );
	
	auto_npc_setup("liaoyin",250,200,1,"/obj/weapon/","random","random",1);
	setup();
    	carry_object("/obj/armor/cloth")->wear();    
}