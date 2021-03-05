#include <ansi.h>
#include <command.h>
inherit SMART_NPC;

void create()
{

	set_name("谭天豹",({"tan tianbao","tan"}));
    	set("title",YEL"谭门三霸天 老三"NOR);
    	set("long", "
谭门三霸天当然姓谭。也许他们并不是北派谭腿的嫡系，可是他们自己要这么说，
就没有人敢怀疑，也没有人否认。拼了十三年命，经过了大小两百多次浴血苦战，
“谭门三霸天”确实已在江湖中稳稳站住了脚，想推倒他们的人，大多数已被他
们一脚踢死。。\n");

	set("age",40);
	set("combat_exp", 7500000);
	set("class","swordsman");        	
	set("attitude","friendly");
		
	set("reward_npc",5);
	
	set("death_msg",CYN"\n$N说：老大会为我报仇的。啊啊啊。。。 \n"NOR);		   
	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	     	10: 	"谭天豹说：“你还是快溜吧，老大回来你哭都来不及了。”\n",
        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) ); 		

	auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","shadowsteps+lingxi",1);
		
	setup();
	carry_object(__DIR__"obj/hat")->wear();
	carry_object(__DIR__"obj/lan_cloth3")->wear();
	if (!random(20)) carry_object(__DIR__"obj/redstone");
}



	
	