inherit NPC;

void create()
{
	set_name("野熊", ({ "bear"}) );
	set("race", "野兽");
	set("gender", "雄性");
	set("age", 6);
	set("long", "这是一只皮糙肉厚的野熊，生性凶恶，力大无比。\n");
	
	set("str", 60);
	
	set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
               "野熊人立起来，发出震天的吼声。。。。",
        }) );
	
	set("combat_exp", 2000000);
	
	set_temp("apply/attack", 250);
	set_temp("apply/dodge",250);
	set_temp("apply/move",400);
	set_temp("apply/armor", 100);
	setup();
	carry_object(__DIR__"obj/palm");
}

