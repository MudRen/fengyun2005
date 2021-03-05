inherit NPC;
void hide();
void create()
{
	if( random(2))
        set_name("小老鼠", ({ "mouse" }) );
	else
    set_name("尖嘴老鼠", ({ "mouse" }) );
        set("race", "野兽");
        set("age", 1);
        set("long", "一只饿得瘦骨嶙峋，皮包骨头，可怜巴巴的老鼠。 \n");

        set("combat_exp",7000);
        set("score", 200);
        set("force", 200);
         set("max_force", 200);
        set_skill("dodge", 100);
        set("arrive_msg", "飞快地蹿了过来");
        set("leave_msg", "偷偷地溜走了");
        set("limbs", ({ "头部", "身体"}) );
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
       message("vision", "老鼠摇摇尾巴，大摇大摆地一下子蹦进王动的大床上去了。\n", environment());
        call_out("disappear", 1);
}

void disappear()
{
        destruct(this_object());
}

