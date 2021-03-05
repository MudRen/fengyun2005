inherit SMART_NPC;
#include <ansi.h>

void create()
{
	set_name("完颜铁", ({ "wanyan tie" }) );
	set("gender", "男性" );
        set("nickname", HIW"昆仑奴"NOR);
	set("age", 29);
	set("class","lama");

	set("long","好一条九尺开外的大汉．脸上横肉绷紧，全无表情，左耳上戴著个碗\n大的金环，秃顶闪闪发光。。\n");
	set("combat_exp", 3000000);
	set_skill("unarmed", 200);
	set_skill("move", 50);
	set_skill("force", 100);
	set_skill("parry", 200);
	set_skill("iron-cloth", 150);
	set_skill("bloodystrike", 200);
	set_skill("bolomiduo", 100);
	set_skill("jin-gang", 150);
	
	map_skill("unarmed", "bloodystrike");
	map_skill("force", "bolomiduo");
	map_skill("literate", "buddhism");
	map_skill("iron-cloth", "jin-gang");
	set("perform_busy_u", "lama/unarmed/bloodystrike/fofawubian");
	
		set("chat_chance_combat", 20);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
}
