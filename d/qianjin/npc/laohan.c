// beggar.c

inherit NPC;

void create()
{
        set_name("老汉", ({ "laohan" }) );
        set("gender", "男性" );
        set("age", 53);
        set("long", "一个正在风烛残年中挣扎的老汉。\n");
        set("combat_exp", 30000);
        set("str", 27);
        
	set("attitude", "friendly");
        
        
        set("chat_chance", 5);
        set("chat_msg", ({
		"老汉停下来，将地上的垃圾捡了起来。\n",

        }) );
        set("inquiry", ([
                "湖上八娇" : "哦，她们都住在荷花荡上\n",
		"湖上月" : "她？她最爱吃生烧扒翅了．\n",
		"yue" : "她？她最爱吃生烧扒翅了．\n",
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
}
