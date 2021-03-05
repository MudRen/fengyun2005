// mind_beast.c

inherit NPC;

void create()
{
	set_name("木马", ({ "wood horse", "horse" }) );
	set("race", "野兽");
	set("gender", "雄性");
	set("age", 3);
	set("long", "这是一只木马。\n");
	

	set("max_kee", 600);
	set("max_gin", 600);
	set("max_sen", 900);
	set("attitude", "peaceful");
	set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
	set("verbs", ({ "bite", "hoof"}) );
		set("combat_exp", 20000);
	set_temp("apply/attack", 60);
	set_temp("apply/armor", 40);
	set_temp("apply/dodge",40);
	setup();
}
