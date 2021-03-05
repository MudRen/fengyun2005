#include <ansi.h>
inherit SMART_NPC;

void create()
{
	set_name("藏翼子",({"zang yizi","zang"}));
    set("title","昆仑四鹫");
	set("long", "一个出家的道人，国字脸，通天鼻，双眉斜飞入鬓，一手昆仑剑法独步天下。\n");
	set("age",57);
	set("gender","男性");
	set("combat_exp", 6300000);
		
	set("reward_npc", 5);

	set("inquiry", ([
        	"燕南天" : "燕大侠是第一个敢闯入恶人谷的正道中人。\n",
        	"恶人谷" : "十大恶人散的散，死的死，恶人谷现在太平多了。\n",
      	]));
	
		
	set("chat_chance", 1);
        set("chat_msg", ({
        	"藏翼子叹道：“常听人言道燕南天武功之强强绝天下，贫道还不深信，
但今日一见……唉，唉……”\n",	
        }) );

	set("win_msg",CYN"藏翼子说：普天之下，也只有燕南天能挡得下我这一剑。\n"NOR);
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        	(: auto_smart_fight(30) :),    
       }) );
	
	auto_npc_setup("guardian",200,170,0,"/obj/weapon/","fighter_w","softsword",1);
	
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object(__DIR__"obj/zsword")->wield();
	
}


