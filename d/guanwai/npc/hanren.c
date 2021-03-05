
inherit NPC;

void create()
{
	set_name("汉人", ({ "hanren"}) );
	set("gender", "男性" );
	set("age", 45);
	set("str", 10);
	set("long", 
"一个满面风尘、远离故乡的汉人。\n"
);
	set("attitude", "peaceful");
        set("title", "异乡客");
        set("combat_exp", 20000);
        set_skill("unarmed", 50);
        set_skill("bloodystrike", random(20)+10);
        set_skill("force", 40);
	map_skill("unarmed", "bloodystrike");
	set_skill("iron-cloth", 10);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
                "汉人擦擦满脸的尘土：快了，快了，做完这趟生意就可以回江南了……\n",
        }) );

	setup();
	carry_object(__DIR__"obj/magcloth")->wear();
 
}
