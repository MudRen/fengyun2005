inherit NPC;
void hide();
void create()
{
	if( random(2))
        	set_name("黑头蟋蟀", ({ "cricket" }) );
	else
    		set_name("青头蛐蛐", ({ "cricket" }) );
        set("race", "昆虫");
        set("subrace","爬虫");
        set("age", 1);
        set("long", "一只蹦蹦跳跳的蟋蟀。 \n");

        set("combat_exp",7000);
        set("score", 200);
        set("force", 200);
         set("max_force", 200);
        set_skill("dodge", 100);
        set("arrive_msg", "飞快地跳了过来");
        set("leave_msg", "飞快地跳走了");
        
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
        message("vision", "蟋蟀蹦着蹦着蹿进墙边的草丛中去了。\n", environment());
        call_out("disappear", 1);
}

void disappear()
{
        destruct(this_object());
}

