
inherit NPC;

void create()
{
        set_name("镖师", ({ "biao shi"}) );
        set("gender", "男性" );
        set("age", 32);
        set("long", "这是一位高达六尺的镖师。\n");
        set("combat_exp", 70000);
        set("attitude", "friendly");
        
        set_skill("hammer", 100);
	set_skill("dodge", 100);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "镖师又将手中的石锁一口气连举了七八十下。\n",
                "镖师望了望自己粗壮的胳膊，又捏了两下，脸上露出得意之色。\n",
        }) );
	
	setup();
        carry_object(__DIR__"obj/jinzhuang")->wear();
	carry_object(__DIR__"obj/stonehammer")->wield();
}

