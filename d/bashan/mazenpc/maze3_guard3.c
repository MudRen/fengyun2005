#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
	set_name("阿修罗部众", ({ "disciple" }) );
	set("title",YEL"大光明教"NOR);
	set("nickname",HIR"妙手 妙手 妙妙手"NOR);
	set("gender", "女性" );

	set("attitude", "aggressive");
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: auto_smart_fight(50) :),
	}) );

	set("combat_exp", 9000000);
	set("death_msg",CYN"\n$N低声道：生亦何欢，死亦何惧？莫若归去，莫若归去……\n"NOR);

	set_skill("parry",200);
	set_skill("dodge",200);
	set_skill("unarmed",200);
	set_skill("fengyu-piaoxiang",320);
	map_skill("dodge","fengyu-piaoxiang");
		
	set_skill("kaleidostrike",240);
	map_skill("unarmed","kaleidostrike");
	
	set("perform_unarmed_attack","demon/unarmed/kaleidostrike/xukongyeyue");      

	setup();

	weapon=carry_object("/obj/armor/hat");
	weapon->set_name(HIR"隋煬之钗"NOR, ({ "hairpin"}) );
	weapon->set("long","一枚火红的玉钗。\n");
	weapon->set("value",0);
	weapon->wear();

	carry_object(__DIR__"obj/wolfclaw")->wield();

}

