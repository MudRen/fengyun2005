inherit NPC;
 
void create()
{
        seteuid(getuid());
        set_name("打更的", ({"boater", "boat guard",}));
        set("long",
                "一个醉熏熏的打更的。\n");
        set("gender","男性");
        set("combat_exp", 500000);
        set_skill("unarmed", 100);
        set_skill("changquan",120);
        map_skill("unarmed","changquan");
        setup();
        carry_object("/obj/armor/cloth")->wear();
}