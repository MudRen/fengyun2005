// girlfi.c

#include <ansi.h>

inherit SMART_NPC;

void create()
{
        set_name("莲风儿", ({ "fenger" }) );

        set("gender", "女性");
        set("age", 20);
        set("long",
                "她国色天香　娇丽无伦　温柔娴静　秀绝人寰\n"
                "她姿容绝美　世所罕见　从她身旁你闻到一股幽香。\n");
        set("attitude", "peaceful");
        set("class", "swordsman");
        set("combat_exp", 4400000);

        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(40) :),
        }) );
    	    	
    	auto_npc_setup("wang",200,180,0,"/obj/weapon/","fighter_w","shadowsteps",1);
        setup();
        carry_object(__DIR__"obj/skirt")->wear();
        carry_object(__DIR__"obj/boot")->wear();

}


void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "莲风儿说：这位" + RANK_D->query_respect(ob)
                                + "，你来陪我吗？\n");
                        break;
                case 1:
                        say( "莲风儿呆呆的出神，似乎没有察觉你进来。\n");
                        break;
        }
}
