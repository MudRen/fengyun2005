#include <ansi.h>

inherit NPC;

void create()
{
        set_name("金牢狱卒", ({ "prison guard", "guard" }) );
        set("long", "这是青龙会五行大牢的金牢狱卒。\n");
        set("title","青龙会 守卫");
        set("attitude", "heroism");

	set("class","wudang");
        set("combat_exp", 2000000);

        set("chat_chance", 2);

        set("chat_msg", ({
        "金牢狱卒叹了口气道：十指连心，竟然这世上还有人能受得住这十指穿针之刑。。。\n",
        }) );



        set_skill("unarmed", 150);
        set_skill("sword", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("move", 150);
        set_skill("dragonstrike",150);
        set_skill("taiji-sword",150);
        set_skill("five-steps",140);
        
        map_skill("sword","taiji-sword");
        map_skill("parry","taiji-sword");
        map_skill("unarmed","dragonstrike");
        map_skill("dodge","five-steps");
        setup();

        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}

void init()
{
    object ob;

    ::init();
    if( interactive(ob = this_player()) && !is_fighting() ) 
    {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }
}

void greeting(object ob)
{   
	string where, location;
	if( !interactive(ob) || environment(ob) != environment() )
		return;
	if (!ob->query("vendetta/authority") ){
            message_vision("$N嘿嘿道：够胆量！私闯青龙会的地头，拿命来吧！\n", this_object() );
      		this_object()->kill_ob(ob);
      		ob->kill_ob(this_object());
	}
   	return;
}