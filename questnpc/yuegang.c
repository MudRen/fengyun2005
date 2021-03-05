#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;

void create()
{
	set_name("岳刚", ({ "yue gang", "yue" }) );
	set("gender", "男性" );
	set("vendetta_mark", "authority");
	set("age", 35);
	set("int", 41);
	set("per", 17);
	set("str", 50);
	set("dur", 50);
	set("cor", 30);
    create_family("朝廷命官", 1, "镇远大将军");
	set("long",
"岳刚是朝廷二品大员，一手家传中平枪法出神入化。\n"
		);
        set("force_factor", 20);
        set("max_gin", 3000);
        set("max_kee", 4800);
        set("max_sen", 2200);
		set("max_force",5000);
		set("force",5000);

        set("combat_exp", 4000000);
        set("score", 20000);
        set_skill("unarmed", 100);
        set_skill("spear", 130);
        set_skill("force", 90);
        set_skill("parry", 130);
        set_skill("literate", 80);
	set_skill("dodge", 150);

	set_skill("yue-strike", 90);
	set_skill("yue-spear", 120);
	set_skill("manjianghong", 60);
	
	map_skill("unarmed", "yue-strike");
        map_skill("spear","yue-spear");
        map_skill("force", "manjianghong");
        map_skill("parry", "yue-spear");
        
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action,"spear.qingheluo":),
        }) );
	setup();
	carry_object(__DIR__"obj/suozijia")->wear();
        carry_object(__DIR__"obj/feiyunspear")->wield();
}
/*
object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}


*/
