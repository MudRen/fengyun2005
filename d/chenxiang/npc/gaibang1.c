// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
//inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("赵能", ({ "zhao neng","zhao"}) );
        set("title", "丐帮六袋弟子");
        set("gender", "男性" );
        set("age", 34);
		set("attitude","friendly");
		set("class","beggar");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.xianglongwuhui" :)
        }) );
        set("combat_exp", 350000);
        set_skill("move", 100);
        set_skill("parry",100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("literate", 80);
		set_skill("unarmed",100);
		set_skill("doggiesteps",60);
		set_skill("dragonstrike",60);
		set_skill("huntunforce",60);
		set_skill("begging",120);
		map_skill("dodge", "doggiesteps");
		map_skill("force", "huntunforce");
		map_skill("unarmed", "dragonstrike");
        setup();
        carry_object(__DIR__"obj/6bagcloth")->wear();

}
