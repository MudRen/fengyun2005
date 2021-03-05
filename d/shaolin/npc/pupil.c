// TIE@FY3

inherit NPC;
void create()
{
        set_name("江湖中人", ({ "ren" }) );
        set("gender", (random(2)? "女性":"男性") );
        set("age", random(40)+10);
        set("long","一个正在对碑文入迷的人。\n");
		set("combat_exp", 50000);
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
                "江湖中人用头磕着碑石高叫道：怎么这么难学呀！\n",
        }) );

        set("attitude", "friendly");
        set("rank_info/respect", "施主");
        setup();
        carry_object("/obj/armor/cloth")->wear();

}
