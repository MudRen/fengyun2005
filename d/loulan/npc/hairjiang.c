inherit NPC;

void create()
{
        set_name("梳头老师傅", ({ "hair oldman" }) );
        set("gender", "男性" );
        set("age", 63);
        set("long", "一个在关外小有名气的梳头师傅，长年劳累背已经驮的很厉害。\n");
        set("combat_exp", 400000);
               
	set("attitude", "friendly"); 
        set("chat_chance", 1);
        set("chat_msg", ({
		"梳头老师傅眯着双眼，轻轻地给白飞飞梳理着云鬓秀发。\n",
        }) );
        set("inquiry", ([
                "梳头" : "嗯，你头发看上去不错，等这边事好了我帮你梳梳。\n",
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
}
