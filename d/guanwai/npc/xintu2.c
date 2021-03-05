
inherit NPC;

void create()
{
	set_name("马鲁", ({ "xintu"}) );
	set("gender", "男性" );
	set("age", 55);
	set("str", 10);
	set("long", @LONG
一个装束华丽但已很破旧的藏人，达赖活佛的虔诚信徒。
LONG
);
	set("attitude", "peaceful");
        set("title", "朝圣信徒");
        set("combat_exp", 10000);
        set_skill("unarmed", 70);
        set_skill("bloodystrike", random(50)+10);
        set_skill("force", 50);
	set_skill("iron-cloth", random(50)+100);
	map_skill("unarmed", "bloodystrike");
    
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
                "\n马鲁面向布达拉宫，三步一拜，五步一叩，执着而神圣地往前跪行着。\n",
        }) );

	setup();
        carry_object(__DIR__"obj/hada")->wear();
 
}
