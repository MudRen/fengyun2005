inherit NPC;

void create()
{
	set_name("棕熊", ({ "bear", "big bear" }) );
	set("race", "野兽");
	set("gender", "雄性");
	set("age", 20);
	set("long", "这是一只凶猛无比的长白山棕熊。\n");
	
	set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 2000000);
	
	set_temp("apply/attack", 400);
	set_temp("apply/armor", 100);
	set_temp("apply/dodge",300);
	set_temp("apply/damage", 300);
	setup();
	carry_object(__DIR__"obj/palm");
}
