
inherit NPC;

void create()
{
	set_name("獒犬", ({ "wolfdog" }) );
	set("race", "野兽");
	set("gender", "雄性");
	set("age", 20);
	set("long", "这是一只西域出产的凶猛无比的狼犬，皮糙肉厚，力大无比，
是西方神教为东山再起而作的努力之一。\n");
	
	set("str", 50);
	set("cor", 52);
	set("attitude", "friendly");

	set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
                "獒犬眼里的绿光使你不寒而颤．\n"
        }) );
	set("combat_exp", 2200000);
		
	set_temp("apply/attack", 250);
	set_temp("apply/dodge",200);
	set_temp("apply/move",320);
	set_temp("apply/damage",30);
	
	setup();
}
