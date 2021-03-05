// mind_beast.c

inherit NPC;

void create()
{
	set_name("雪蹄胭脂马", ({ "red horse", "horse" }) );
	set("race", "家畜");
	set("gender", "雄性");
	set("age", 3);
	set("long", "这是一只蹄宽腿壮，一人多高的千里马。\n");
	
	set("attitude", "peaceful");
	
        set("chat_chance", 1);
        set("chat_msg", ({
		"雪蹄胭脂马＂咴～～咴咴＂地嘶叫了几声\n",
        }) );
	set("combat_exp", 20000);
	set_temp("apply/attack", 60);
	set_temp("apply/armor", 40);
	set_temp("apply/dodge",40);
	setup();
	carry_object(__DIR__"obj/maan")->wear();
}
