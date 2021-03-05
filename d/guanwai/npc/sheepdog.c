inherit NPC;

void create()
{
	set_name("牧羊犬", ({ "shepherd dog", "dog" }) );
	set("race", "野兽");
	set("gender", "雄性");
	set("age", 20);
	set("long", "这是一只西藏产的牧羊犬，正忠实地看护着羊群。\n");
	
	set("agi",60);
	
	set("attitude", "friendly");

	set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
                "牧羊犬汪汪地叫了几声，警惕地向四周看了几眼。\n"
        }) );
	set("combat_exp", 2000000);
		
	set_temp("apply/attack", 300);
	set_temp("apply/dodge",280);
	set_temp("apply/move",320);
	set_temp("apply/damage",50);
	set_temp("apply/armor", 120);

	setup();
}
