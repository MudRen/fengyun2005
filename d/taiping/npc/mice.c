inherit NPC;
void hide();
void create()
{
	if( random(2))   set_name("白老鼠", ({ "mouse" }) );
		else	set_name("灰老鼠", ({ "mouse" }) );
        set("race", "野兽");
        set("age", 1);
        set("long", "一只身儿倍圆的大老鼠。 \n");

        set("combat_exp",10000);
        
        set("force", 200);
        set("max_force", 200);
        set_skill("dodge", 100);
        
        set("arrive_msg", "从草堆里钻了出来");
        set("leave_msg", "一溜烟地跑掉了");
        set("limbs", ({ "头部", "身体","前爪","后爪","尾巴"}) );
        set("verbs", ({ "bite" }) );
        set_temp("armor", 50);

    	set("chat_chance", 25);
    	set("chat_msg", ({
        	(: random_move :),
            	(: hide :)
    	}) );

        setup();
}


void hide()
{
        if( !environment() ) return;
        message("vision", "老鼠跑着跑着就不见了。\n", environment());
        call_out("disappear", 1);
}

void disappear()
{
        destruct(this_object());
}

