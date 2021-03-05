#include <ansi.h>
#include <command.h>

inherit SMART_NPC;

void create()
{

		set_name("白衣青年人",({"young man","man"}));
    	set("long", "一个高高瘦瘦的青年人，乃是武三爷手下的干将。\n");
		set("age",20);
		set("combat_exp", 3000000);
        
        set("sanye",1);
        
        
		set("max_kee", 6000);
		set("max_gin", 6000);
		set("max_sen", 6000);
        	
		set("inquiry", ([
        	"号令":	"我可不是这儿能下命令的人。\n",
        	"mission":	"我可不是这儿能下命令的人。\n",
        	"三爷":	"三爷就是武三爷，明天这太平镇的一切就都是三爷的了。\n",
   		]));        	
		
		
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(30) :),
        }) );
	
		set("chat_chance",1);
    	set("chat_msg",({
				"白衣青年人摩拳擦掌，似乎很不耐烦的样子！\n",
    	}) );   
	
		auto_npc_setup("xuebin",170,170,1,"/obj/weapon/","random","random",1);
		setup();
		carry_object(__DIR__"obj/whitecloth")->wear();
}
