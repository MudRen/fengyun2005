
inherit NPC;

void create()
{
	set_name("蒙古人", ({ "mongol"}) );
	set("gender", "男性" );
	set("age", 35);
	set("str", 10);
	set("long", @LONG
一个雄壮坚韧的蒙人。
LONG
);
	set("attitude", "peaceful");
        set("title", "异乡客");
        set("combat_exp", 20000);
        set_skill("unarmed", 50);
        set_skill("bloodystrike", random(20)+10);
        set_skill("force", 40);
	set_skill("iron-cloth", random(40)+10);
	
	map_skill("unarmed", "bloodystrike");
	
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
                "蒙古人突然颤栗道：故老相传，在大地边缘有一处比天还高的山峰，山
上不但有万古不化的冰雪，还有种比恶鬼更可怕的妖魔…\n",
        }) );

	setup();
	carry_object(__DIR__"obj/magcloth")->wear();
 
}
