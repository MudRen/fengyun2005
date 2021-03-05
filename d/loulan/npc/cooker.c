inherit NPC;

void create()
{
        set_name("御厨", ({ "cooker" }) );
        set("gender", "男性" );
        set("age", 43);
        set("long", "一个本是紫禁城皇宫御膳房的大厨，后来被快活王抓到楼兰地宫做饭烧菜。\n");
        set("combat_exp", 1500000);
        set("attitude", "friendly");
        
        set_temp("apply/attack", 150);
	set_temp("apply/dodge",150);
        
        set("chat_chance", 1);
        set("chat_msg", ({
		"御厨汗流浃背地忙着烧清蒸鲈鱼，香味四溢。。。\n",
        }) );
        setup();
	carry_object("/obj/armor/cloth")->wear();
}
