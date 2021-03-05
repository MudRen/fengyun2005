// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("蒙面客", ({ "figure"}) );
        set("nickname", HIR "刀不留人"NOR);
        set("gender", "男性" );
        set("age", 41);
		set("per", 30);
		set("attitude","friendly");
		set("bellicosity",30000);
        set("figure_friend",1);
        
        set("long",
"这人的脸上戴着黑布面具，在星光下看来，显得狰狞而怪异。令人瞩目的是他的
腰带上斜插着一柄弯刀，刀鞘上缀满了明珠美玉。
\n"
	);
        set("combat_exp", 4500000);
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                (: perform_action, "blade.tiandirenmo" :),
        }) );

        set_skill("move", 200);
        set_skill("parry",200);
        set_skill("dodge", 200);
        set_skill("force", 200);
        set_skill("unarmed",200);
		set_skill("demon-steps",150);
		set_skill("demon-force",200);
		set_skill("blade",200);
		set_skill("parry",200);
		set_skill("demon-blade",150);
		set_skill("dragonstrike",180);
	
	map_skill("unarmed","dragonstrike");
	map_skill("parry","demon-blade");
	map_skill("blade","demon-blade");
        map_skill("dodge", "demon-steps");
        map_skill("move","demon-steps");
	map_skill("force", "demon-force");
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/weapon/sword_katana")->wield();
		
}

void init()
{
        object ob;

        ::init();
        add_action("do_get","get");
        if( interactive(ob = this_player())) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{   
	if( !interactive(ob) || environment(ob) != environment() ){
		return;
	}
	if (!ob->query("figure_friend")){
            message_vision("$N叫道：杀！\n", this_object() );
      		this_object()->kill_ob(ob);
      		ob->kill_ob(this_object());
	}
      	return;
}

int do_get(string arg)
{
if(!arg) return 0;
message_vision("$N笑道：没有这么便宜的事吧？\n",this_object(),this_player());
if (!this_player()->is_busy()) this_player()->start_busy(1);
return 1;
}