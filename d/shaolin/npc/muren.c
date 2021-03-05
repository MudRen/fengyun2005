// teacher.c

inherit NPC;

void create()
{
	set_name("木人", ({ "muren" }) );
	set("gender", "男性" );
	set("age", 22);
	set("int", 30);
	set("long",
		"少林寺木人，善使少林七十二绝技。\n"
		);
	set("attitude", "peaceful");
	set_skill("unarmed", 200);
	set_skill("force", 80);
	set("combat_exp", 90000);
	setup();
}
