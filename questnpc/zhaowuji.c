#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;
do_fight();
void create()
{
	set_name("赵无忌", ({ "zhao wuji","zhao" }) );
	set("gender", "男性" );
        set("nickname",HIW"白玉老虎"NOR);
        set("title","大风堂     少堂主");
        set("quality","good");
	set("age", 29);
	set("int", 59);
	set("per", 30);
	set("str", 32);
	set("dur", 30);
	set("cor", 50);
	set("long",
"他原本是个很英俊的少年，但现在他的嘴唇已乾裂，泌出血丝，甚至连皮 
肤都已经乾裂。眼眶已凹下去，健康红润的脸色，已变得像是张白纸。\n"
		);
        set("force_factor", 40);
        set("max_gin", 3000);
        set("max_kee", 4100);
        set("max_sen", 3000);
	set("max_force",2000);
	set("force",2000);

        set("combat_exp", 5000000);
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
	
        map_skill("sword","feixian-sword");
     map_skill("force", "yiqiforce");
        map_skill("parry", "feixian-sword");
		map_skill("dodge","feixian-steps");
		set("chat_chance",10);
		set("chat_msg",	({
		"赵无忌凝望着天空，一字一字道：我还没有倒下去，我还活着，因为我还有仇恨。\n"
		})	);  
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (:perform_action,"dodge.tianwaifeixian":),
        }) );
	setup();
    carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}
