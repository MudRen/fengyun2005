// beggar.c

inherit NPC;

void create()
{
        set_name("花匠", ({ "huajiang" }) );
        set("gender", "男性" );
        set("age", 33);
        set("long", "一个正在辛勤浇灌名贵花园的花匠。\n");
        set("combat_exp", 45000);
        set("str", 27);
        
	set("attitude", "friendly");
        ;
        set("chat_chance", 1);
        set("chat_msg", ({
		"花匠拎起花壶，小心地往异品牡丹上浇水\n",
                (: random_move :)
        }) );
        set("inquiry", ([
                "湖上八娇" : "哦，她们都住在荷花荡上\n",
		"湖上雪" : "她？她最爱吃生烧扒翅了．\n",
		"xue" : "唉！她真的好命苦，连自己的亲生哥哥都不能见！\n",
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
}
