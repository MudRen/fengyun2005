#include <ansi.h>
inherit NPC;

void create()
{
        set_name("宋长清", ({ "song" }) );
        set("gender", "男性");
        set("age", 30);
        set("long",
		"宋长清乃武当火工道人，身着灰色道袍。\n"
	);
        set("combat_exp", 10000);
        set("class", "taoist");
        create_family("武当派", 58, "弟子");

        set_skill("move", 10+random(40));
        set_skill("force", 10+random(40));
        set_skill("unarmed", 10+random(40));
        set_skill("sword", 10+random(40));
        set_skill("parry", 10+random(40));
        set_skill("dodge", 10+random(40));
        set_skill("taijiforce", 10+random(30));
        set_skill("taiji", 10+random(30));
        set_skill("three-sword", 10+random(30));
        set_skill("five-steps", 10+random(30));

        map_skill("force", "taijiforce");
        map_skill("sword", "three-sword");
        map_skill("parry", "three-sword");
        map_skill("unarmed", "taiji");
        map_skill("dodge", "five-steps");
        map_skill("move", "five-steps");
        
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "sword.nianzijue" :),
        }) );

        set_skill("changelaw", 10);
        setup();

        carry_object(__DIR__"obj/sword")->wield();
        carry_object(__DIR__"obj/cloth")->wear();

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

int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="武当派" ) {
                command("nod");
                command("say 进招吧。");
                return 1;
        }
        command("say 武当派不和别派的人过招。");
        return 0;
}

void greeting(object me)
{
    if( !me || environment(me) != environment() ) return;
	if( (string)me->query("family/family_name")!="武当派" ) {
		if( (string)me->name()!="彭长净" ) {
			say( YEL "宋长清说道：这位" + RANK_D->query_respect(me)
				+ "请留步，后院乃武当重地，不可随便进入。\n"NOR);
			} 
		else {
			message_vision( YEL "$N上上下下打量了$n几眼说道：彭师哥到哪里去了？\n"NOR, this_object(), me);
			message_vision( YEL "为什么脸色不好？若是身体不舒服，快到后院休息。\n"NOR, this_object(), me);
		}
	}
	else {
		say( YEL "宋长清说道：这位" + RANK_D->query_respect(me)
			+ "请后院休息，茶饭马上送到。\n"NOR);
	}
}
