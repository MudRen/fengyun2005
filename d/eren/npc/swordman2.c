#include <ansi.h>
inherit SMART_NPC;

void create()
{
	set_name("杨平",({"yang ping","yang"}));
    	set("title","川中八义");
	set("long", "川中八义之首，风骨棱棱，气宇轩昂。\n");
	set("age",30+random(20));
	set("combat_exp", 4800000);
	
	set("reward_npc", 1);
    set("difficulty", 3);

	set("inquiry", ([
        	"燕南天" : "燕大侠是第一个敢闯入恶人谷的正道中人。\n",
        	"恶人谷" : "十大恶人散的散，死的死，恶人谷现在太平多了。\n",
      	]));
	
	
	set("chat_chance", 1);
    set("chat_msg", ({
        	"杨平道：“燕大侠武功虽高，还不足深佩，小弟最佩服的乃是他的干云
豪气，凛然大义，当真令我愧煞。”\n",
        }) );
	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
        	(: auto_smart_fight(20) :),    
       }) );
	
	auto_npc_setup("guardian",200,170,0,"obj/weapon/none","fighter_u","dragonstrike",1);
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object(__DIR__"obj/hat")->wear();
	
}
