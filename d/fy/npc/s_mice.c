inherit NPC;

void create()
{
	set_name("小老鼠", ({ "mouse" }) );
    	set("race", "野兽");
        set("age", 1);
        set("long", "一只鼠头鼠脑的小老鼠。 \n");
        set("combat_exp",7000);
   	set("attitude", "aggressive");
        set_skill("dodge", 100);        
        set_temp("armor", 50);

    	setup();
}


