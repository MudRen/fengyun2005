#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;
do_fight();
void create()
{
	set_name("俞佩玉", ({ "yu peiyu","yu" }) );
	set("gender", "男性" );
        set("nickname",HIY"天下第一美男子"NOR);
        set("title","无极门     少门主");
        set("quality","good");
	set("age", 21);
	set("int", 29);
	set("per", 30);
	set("str", 32);
	set("dur", 30);
	set("cor", 50);
	set("long",
"这少年实在是太完美了,如果说还有什么遗憾的话,就是左脸上有道淡淡的疤痕。\n"
		);
        set("force_factor", 40);
        set("max_gin", 3000);
        set("max_kee", 4100);
        set("max_sen", 3000);
		set("max_force",2000);
		set("force",2000);

        set("combat_exp", 1500000);
        set("score", 1200);
        set_skill("unarmed", 80);
        set_skill("sword", 110);
        set_skill("force", 70);
        set_skill("parry", 110);
        set_skill("literate", 80);
	set_skill("dodge", 140);

        set_skill("feixian-sword", 180);
	set_skill("yiqiforce", 60);
        set_skill("feixian-steps",180);
	
//	map_skill("unarmed", "meihua-shou");
        map_skill("sword","feixian-sword");
        map_skill("force", "yiqiforce");
        map_skill("parry", "feixian-sword");
		map_skill("dodge","feixian-steps");
		set("chat_chance",10);
		set("chat_msg",	({
		"俞佩玉痴痴地望着远方，口中只是不断道：「要忍耐……莫忘了，忍耐…」 \n"
		})	);  
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (:perform_action,"dodge.tianwaifeixian":),
        }) );
	setup();
    carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}
