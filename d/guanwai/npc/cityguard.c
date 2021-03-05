
inherit SMART_NPC;

void create()
{
	set_name("城卫", ({ "city guard", "guard" }) );
	set("gender", "男性" );
	set("age", 25);
	set("long", @LONG
一个藏僧，乃大昭寺年轻一代中的佼佼者，有万夫不当之勇。
LONG
);
	set("attitude", "heroism");
        set("combat_exp", 8000000);
	set("group","cityguard");

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
        }) );
    
    	auto_npc_setup("wang",250,200,0,"/obj/weapon/","fighter_w","kwan-yin-spells",1);
	setup();

	carry_object(__DIR__"obj/3staff")->wield();
        carry_object(__DIR__"obj/redcloth")->wear();
}
