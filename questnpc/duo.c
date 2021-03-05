// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit QUESTNPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("吕迪", ({ "master lu", "master"}) );
        set("nickname", HIR "权法天王"NOR);
        set("title", "西方神教    宗主");
        set("gender", "男性" );
        set("age", 41);
	set("per", 30);
        set("agi",25);
        set("int",30);
	set("cor",40);
	set("attitude","friendly");
	set("max_force", 8000);
        set("force", 8000);
        set("force_factor", 50);
        set("long",
"没有人的脸上会发出这种青光的，除非他脸上戴着个青铜面具。这人的脸上就戴
着青铜面具，在星光下看来，显得更狰狞而怪异。他身上穿着的，却是件美丽的
绣花长袍，腰带上斜插着三柄弯刀。惨碧色的刀鞘上，缀满了明珠美玉。
\n"
	);
        set("combat_exp", 4000000);
        set("score", 20000);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.lianhuanbabu" :),
        	(: exert_function, "mihun" :)
        }) );
        set_skill("move", 150);
        set_skill("parry",150);
        set_skill("dodge", 150);
        set_skill("force", 100);
        set_skill("literate", 90);
	set_skill("unarmed",150);
	set_skill("demon-steps",150);
	set_skill("demon-force",100);
	set_skill("iron-cloth",100);
        map_skill("dodge", "demon-steps");
	map_skill("force", "demon-force");
        setup();
        //carry_object(__DIR__"obj/xiuhuacloth")->wear();
		//carry_object(__DIR__"obj/duopai");
		//carry_object(__DIR__"obj/duomianju")->wear();
}

