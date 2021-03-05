
inherit NPC;

void create()
{
        set_name("波斯奴", ({ "bosi slave", "slave"}) );
        set("gender", "男性" );
        set("age", 32);
        set("long", "这是一位红发碧眼，高达六尺的番人。\n");
        set("combat_exp", 50000);
        set("bellicosity", 30000 );
        set("attitude", "aggressive");
        set_skill("blade", 90);
	set_skill("dodge", 100);
	set_skill("parry", 20);
        	
	setup();
	add_money("coin", 50);
        carry_object(__DIR__"obj/redcloth")->wear();
	carry_object(__DIR__"obj/roundblade")->wield();
}

