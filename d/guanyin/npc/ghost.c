inherit NPC;
void create()
{
        set_name("人影", ({ "shadow" }) );
        set("gender", "男性" );
        set("age", 42);
	set("str",22);
        set("long","
面上满是痴呆迷惘之色，目中也早已失去了生命的光泽。
看来不但忘了自己的身世，简直也忘记了自己是个人了。\n");
	set("combat_exp", 20000);
        set("chat_chance", 1);
        set("chat_msg", ({
		"人影拿着扫把扫着地．．．．\n",
        }) );

        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/item/broom")->wield();

}
