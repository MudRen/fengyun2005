
inherit NPC;

void create()
{
        set_name("黄衣人", ({ "yellowman", "man"}) );
        set("gender", "男性" );
        set("age", 32);
        set("long", "这是一位身披黄衣的蒙面人\n");
        set("combat_exp", 150000);
        set("bellicosity", 30000 );
        set("attitude", "aggressive");
        
        set_skill("flying-dragon", 90);
	set_skill("dodge", 100);
	set_skill("unarmed", 20);
        set_skill("iron-cloth", 100);
        
        map_skill("unarmed", "flying-dragon");
		
	setup();
        carry_object("/obj/armor/cloth")->wear();
}

