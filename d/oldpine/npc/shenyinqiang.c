#include <ansi.h>
inherit SMART_NPC;

void create()
{
        set_name( "沈银枪", ({ "shen yinqiang", "shen" }) );
		set("long", "冠绝江湖的『宝马银枪』，一手捋须，一手持一柄银白色的长枪。\n");
		set("attitude", "friendly");
		set("title", HIY "宝马银枪"NOR);
		set("age", 57);
        set("gender", "男性" );
		set("per", 60);
		set("combat_exp", 2900000);
		set("class","fugui");
        set("reward_npc", 1);
		set("difficulty", 3);
        
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(70) :),
     	}) ); 		

		auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","xuezhan-spear3",1);
		setup();
        carry_object("obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/silver_spear")->wield();
//        add_money("gold", random(5));
}
