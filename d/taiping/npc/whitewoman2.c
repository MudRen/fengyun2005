#include <ansi.h>
#include <command.h>

inherit SMART_NPC;

void create()
{

	set_name("白衣妇人",({"white cloth woman","woman"}));
    	set("title",WHT"李家庄"NOR);
    	set("long", "
白衣妇人的年纪已不轻，却应了那句老话 ——年已花信，风韵犹存。她们的身材
也很窈窕，很动人。\n");
	set("age",40);
	set("combat_exp", 8000000);
        set("gender","女性");	

		set("group","lidaniang");
			
	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
        }) );

	
	auto_npc_setup("xuebin",250,200,1,"/obj/weapon/","fighter_w","smallguy",1);
	set("gender","女性");	
	setup();
	carry_object(__DIR__"obj/whitecloth")->wear();
}
