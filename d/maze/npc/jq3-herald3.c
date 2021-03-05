#include <ansi.h>
inherit MAZE_NPC;

void create()
{
//      string *name = ({HIC"长生",HIY"安乐",HIR"富贵",HIG"尊荣",CYN"显名",YEL"财利",GRN"喜欲"});
	string *name = ({"长生","安乐","富贵","尊荣","显名","财利","喜欲"});
        set_name(name[random(sizeof(name))]+"使", ({"jinqian herald","herald"}) );

        set("gender", "男性" );
        set("title","金钱帮 七使者之");
        set("age", 30+random(30));
	set("class","assassin");
        set("long", "金钱帮七大护法使者之一。\n");
        
        set("combat_exp", 7800000);
	set("pursuer",1);
        set("attitude", "aggressive");
        set("maze","jq3");
        set("experience",160);
	set("potential",90);
	set("money",300);
	set("toughness",150);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"喝道：什么人敢私闯黄金塔！\n",
        }) );
		
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(30) :),    
        }) );
	
	auto_npc_setup("liaoyin",250,200,1,"/obj/weapon/","random","random",2);
	setup();
    	carry_object("/obj/armor/cloth")->wear();    
}

int heal_up()
{
	if(environment() && !is_fighting() 
		&& query("startroom") 
		&& file_name(environment()) != query("startroom")) {
		return_home(query("startroom"));
		return 1;
	}
	return ::heal_up() + 1;
}