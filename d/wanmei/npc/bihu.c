inherit NPC;
void create()
{
    	set_name("壁虎", ({ "bihu" }) );
        set("race", "野兽");
        set("age", 1);
        set("gender", "雌性");
    	set("combat_exp", 3000);
        set("attitude","peaceful");
 
        set_temp("apply/dodge", 100);
	
        setup();
}
