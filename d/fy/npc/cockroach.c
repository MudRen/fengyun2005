inherit NPC;
void hide();
void create()
{
	if( random(2))
        set_name("大蟑螂", ({ "big cockroach","cockroach" }) );
	else
	set_name("小蟑螂", ({ "small cockroach","cockroach" }) );
        set("race", "昆虫");
        set("subrace","爬虫");
        set("age", 1);
        set("long", "一只非常恶心的蟑螂。 \n");

        set("combat_exp",7000);
        set("score", 200);
        set_skill("dodge", 100);
        set("arrive_msg", "飞快地爬了过来");
        set("leave_msg", "飞快地爬开了");
        
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
        message("vision", "蟑螂爬著爬著钻进墙边的裂缝了。\n", environment());
        call_out("disappear", 1);
}

void disappear()
{
        destruct(this_object());
}

