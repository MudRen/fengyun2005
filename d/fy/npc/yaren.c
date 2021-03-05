
inherit NPC;

void create()
{
        set_name("风骚雅人", ({ "elegant man", "man"}) );
        set("gender", "男性" );
        set("age", 22);
        set("long", "这是一位小有才华的雅人，正在追求灵感。\n");
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("intellgent",1);
        
        set_skill("dagger", 100);
	set_skill("dodge", 100);   
        set_skill("iron-cloth", 200);
        set_skill("unarmed",100);
        set_skill("parry",100);
        
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "风骚雅人张了张口，又合上了。\n",
                "风骚雅人踱来踱去，似乎正在打腹稿。\n",
        }) );
	
	setup();
        carry_object(__DIR__"obj/fycloth")->wear();
        carry_object(__DIR__"obj/ironpen")->wield();
}

