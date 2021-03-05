// XXDER@FY3
inherit NPC;
void create()
{
	set_name("胡不愁" , ({ "buchou", "hu buchou", "hu" }) );
	set("long", "只见他头大身短，额角开阔，面上纵然未笑，也带着几分笑意。\n");
	set("attitude", "friendly");

	set("age", 19);
        set("gender", "男性" );
        create_family("清平山庄", 1, "弟子");

	set("combat_exp", 350000);

	set_skill("dodge", 50+random(50));
        set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("qingpingsword", 100);
        set_skill("force", 60);
        set_skill("qingpingforce", 55);
        set_skill("chaos-steps", 100);
        set_skill("parry",50);
        
        map_skill("sword", "qingpingsword");
        map_skill("force", "qingpingforce");
        map_skill("dodge", "chaos-steps");
        map_skill("parry","qingpingsword");
        
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "sword.fengzijue" :),
        }) );

	setup();
	carry_object(__DIR__"obj/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}
