#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;
do_fight();
void create()
{
	set_name("小鱼儿", ({ "xiao yuer","yuer" }) );
	set("gender", "男性" );
        set("nickname",HIC"天下第一聪明人"NOR);
        set("title","恶人谷     小恶人");
        set("quality","good");
	set("age", 21);
	set("int", 100);
	set("per", 40);
	set("str", 52);
	set("dur", 30);
	set("cor", 50);
	set("long",
"他满头黑发也未梳，随随便便打了个结，但不知怎地，这又懒、又顽皮、又是满 
身刀疤的少年，身上却似有着奇异的魅力，强烈的魅力。尤其他那张脸，脸上虽 
有道刀疤，这刀疤却非但未使他难看，反使他这张脸看来更有种说不出的吸引力。 
这又懒、又顽皮、又满是刀疤的少年，给人的第一个印象，竟是个美少年，绝顶 
的美少年。\n"
		);
        set("force_factor", 40);
        set("max_gin", 3000);
        set("max_kee", 4100);
        set("max_sen", 3000);
	set("max_force",2000);
	set("force",2000);

        set("combat_exp", 6000000);
        set("score", 5200);
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
		"小鱼儿懒懒地一笑，撇了撇薄薄的嘴唇道：花无缺这个呆头鹅，得想个法子把 
他从移花宫主那找出来？ \n",
"小鱼儿眨眨眼，舔了舔嘴道：苏樱苏大小姐还将就称得上美人儿吧。\n",
		})	);  
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (:perform_action,"dodge.tianwaifeixian":),
        }) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}
