// dizi.c

#include <ansi.h>

inherit NPC;
void create()
{

    	set_name("蝙蝠岛弟子", ({ "dizi"}) );
	set("long", "这是一位蝙蝠岛专门担任保护之责的弟子。\n");
	set("attitude", "friendly");

	set("combat_exp", 500000+random(500000));
	set_skill("sword", 70+random(70));
	set_skill("parry", 70+random(70));
	set_skill("dodge", 70+random(70));
	set_skill("move", 70+random(70));

	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/weapon/sword")->wield();
}

void init()
{
 	::init();
 	if( interactive(this_player()) && !is_fighting() && !random(4)&& this_player()->query("class")!="bat") {
  		message_vision("\n$N忽然对$n大喝一声：什么人竟敢在此乱闯！看剑！\n",this_object(),this_player());
  		this_object()->kill_ob(this_player());
 	}
}
