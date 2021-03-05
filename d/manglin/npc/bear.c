
inherit NPC;

void create()
{
	set_name("白颈灰熊", ({ "bear", "big bear" }) );
	set("race", "野兽");
	set("gender", "雄性");
	set("age", 20);
	set("long", "这是一只凶猛无比的灰熊。\n");
	
	set("attitude", "aggressive");

	set("combat_exp", 900000);
	set("bellicosity", 3000 );
	set("agi", 10 );	
	set_temp("apply/attack", 100);
	set_temp("apply/armor", 20);
	set_temp("apply/damage", 100);
	setup();
}
