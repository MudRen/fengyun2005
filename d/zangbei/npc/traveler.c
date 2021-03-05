#include <ansi.h>
inherit SMART_NPC;

void create()
{
	set_name("大漠商旅",({"traveler","desert traveler"}));
	set("long", "
沙漠里既有烈日风暴，也有打劫的歹徒，所以行商之人大多成群结队，以求
互相照顾。他们负重而行，风尘仆仆。\n");
	set("age",30+random(20));
	set("attitude", "friendly");
	set("combat_exp", 1000000);
	set("group","traveler");
		
	set("chat_chance", 1);
        set("chat_msg", ({
                "旅人说：唉，可别遇上马匪才好。\n"
                "商人说：咱们结队而行，有强盗就跟他拼命。\n"
        }) );
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: auto_smart_fight(10) :),    
        }) );
	
	auto_npc_setup("guardian",100,100,1,"/obj/weapon/","fighter_w","cloudstaff",1);
		
	setup();
	set_skill("iron-cloth",150);
	carry_object("/obj/armor/cloth")->wear();
	carry_object(__DIR__"obj/towel")->wear();
}


