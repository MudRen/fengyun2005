inherit NPC;

void create()
{
	set_name("大老鼠", ({ "mouse" }) );
    	set("race", "野兽");
        set("age", 1);
        set("long", "一只鼠头鼠脑的大老鼠。 \n");
        set("combat_exp",20000);
        set("attitude", "aggressive");        
        set_skill("dodge", 100);        
        set_temp("armor", 50);

    	setup();
}


