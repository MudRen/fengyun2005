

inherit NPC;
void create()
{
        set_name("白袍妇", ({ "woman" }) );
        set("gender", "女性" );
        set("age", 48);
        set("str", 58);

        set("long","这人云鬓不整，未洗铅华，四十多岁的年纪，五尺多高的身材，
容貌虽憔悴，但依稀仍可见少年时的风华。
\n");
        set("combat_exp", 120000);
        
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("flying-dragon", 70);
        set_skill("zuixian-steps", 100);
	
        map_skill("unarmed", "flying-dragon");
        map_skill("dodge", "zuixian-steps");

        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
        }) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
}
