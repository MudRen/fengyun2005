// worker.c

inherit NPC;

void create()
{
        set_name("裸体女人", ({ "naked girl", "girl" }) );
        set("title", "一丝不挂");
        set("gender", "女性" );
        set("age", 29);
        set("long", "正在水中嬉笑玩打的漂亮女人，两腮桃红，酥胸起伏有致，两点嫣红仿
佛灿烂桃花般盛开着。。。\n");
        set("combat_exp", 17000);
        set("attitude", "friendly");
        
        set_skill("unarmed", 10);
        set_skill("parry", 25);
	set_skill("dodge", 100);
	set_skill("throwing", 50);
	
	setup();
}

