inherit NPC;

void create()
{
	set_name("老鼠精", ({ "mouse" }) );
    	set("race", "野兽");
        set("altitude","aggressive");
        set("age", 1);
        set("long", "这只老鼠看来有年头了，浑身毛儿雪白，两只眼睛闪着绿光。 \n");
        set("combat_exp",50000);
        set("attitude", "aggressive");      
        set_skill("dodge", 100);        
        set_temp("armor", 50);

    	setup();
}


void die(){
       	object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner = me->query("possessed")) {
		me = owner;
	} 
        if (objectp(me))
		QUESTS_D->special_reward(me,"金狮大厨");
    	   
    	::die();
}