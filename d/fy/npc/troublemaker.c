inherit NPC;

void create()
{
        set_name("裸体男人", ({ "naked man","man" }) );
        set("title","赤身裸体");  
        set("gender", "男性" );
        set("age", 28);
        set("per", 30);
        set("long","这是一位正在洗澡的裸体男人，体格健壮，浑身的肌肉线条清晰，仿佛猎豹一般。\n");

        set("combat_exp", 1200000);
        set("score", 50);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("meihua-shou", 10);
        set_skill("fall-steps", 10);

        map_skill("unarmed", "meihua-shou");
        map_skill("dodge", "fall-steps");
		setup();
}

