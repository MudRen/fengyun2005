#include <ansi.h>
#include <command.h>

inherit SMART_NPC;

void create()
{

	set_name("白衣大汉",({"white cloth man","man"}));
    	set("title",WHT"李家庄"NOR);
    	set("long", "
白衣大汉一手掌灯，一手握刀，追巡在庄内。雪白的衣衫之上鲜血斑驳，刀与灯辉
映，刀光中闪着血光。他们的眼瞳亦仿如噬血，四下搜索，似乎意犹未尽。\n");
	set("age",40);
	set("combat_exp", 8000000);
        	
	set_skill("iron-cloth",150);
	set_skill("xisui",100);
	map_skill("iron-cloth","xisui");
	
	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
        }) );
	
	
	auto_npc_setup("xuebin",250,200,1,"/obj/weapon/","fighter_w","smallguy",1);
	setup();
	carry_object(__DIR__"obj/whitecloth")->wear();
}
