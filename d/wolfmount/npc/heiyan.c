#include <ansi.h>
inherit NPC;

void create()
{
    set_name("黑眼狼", ({"heiyan wolf","heiyan"}) );
        set("gender", "男性" );
        set("nickname", HIB"夜狼"NOR);
        set("long", "黑衣、黑鞋、黑巾蒙面，在夜色下眼睛诡异地闪着绿色的光。。\n");
 	set("attitude", "friendly");
/*	set("max_gin", 1000);
	set("max_kee", 1000);
	set("max_sen", 1000); */
    set("age", 35);
    	set("agi", 10);
        set("combat_exp", 1000000);
    set_temp("apply/damage", 50);
    set_temp("apply/armor", 50);

        create_family("狼山", 1, "第四代弟子");
        set_skill("staff", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("move", 150);
        set("chat_chance", 1);
        set("chat_msg", ({
        "黑眼狼仰天长嚎：狼山武功甲天下，夜狼武功甲狼山！\n",
        }) );

        setup();
        carry_object(__DIR__"obj/langyabang")->wield();
        carry_object(__DIR__"obj/blkcloth")->wear();
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
	if( !ob || environment(ob) != environment() )
		return;
	if (ob->query("class") != "wolfmount")
	{
        	message_vision("$N冷冷的看着你：“想上狼山，你没有机会了。”\n", this_object() );
      		this_object()->kill_ob(ob);
      		ob->kill_ob(this_object());
	}
      	return;
}