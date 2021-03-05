inherit NPC;
void create()
{
        set_name("力士", ({ "lishi","力士" }) );
        set("gender", "男性" );
        set("class", "bonze");
        set("str", 26);
        set("long", "面貌雄伟，作忿怒相，上半身赤裸，两脚张开，呈紧张状。\n");
        set("combat_exp", 26000);
        set("attitude", "friendly");
        
	set("no_shown",1);
        
        set_skill("unarmed", 500);
        set_skill("dodge", 60);
        setup();
        carry_object(__DIR__"obj/hat");
        carry_object(__DIR__"obj/staff");
}

