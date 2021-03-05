#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;
do_fight();
void create()
{
	set_name("林还玉", ({ "lin huanyu", "lin" }) );
	set("gender", "男性" );
	set("nickname",HIW"玉面公子"NOR);
        set("title","铁雪山庄 掌门弟子");
        set("quality","good");
	set("age", 21);
	set("int", 35);
	set("per", 35);
	set("str", 30);
	set("dur", 30);
	set("cor", 50);
	set("long",
"铁雪山庄的四大弟子，无一不是江湖上的一流高手，林还玉风流倜傥，拳剑双绝，不知道倾倒了多少红颜。\n"
		);
        set("force_factor", 90);
        set("max_gin", 3500);
        set("max_kee", 4800);
        set("max_sen", 3200);
		set("max_force",4000);
		set("force",4000);

        set("combat_exp", 8000000);
        set("score", 2000);
        set_skill("unarmed", 90);
        set_skill("sword", 130);
        set_skill("force", 80);
        set_skill("parry", 130);
        set_skill("literate", 90);
	set_skill("dodge", 130);

	set_skill("meihua-shou", 90);
    set_skill("diesword", 180);
	set_skill("qidaoforce", 90);
    set_skill("fall-steps",160);
	
	map_skill("unarmed", "meihua-shou");
        map_skill("sword","diesword");
        map_skill("force", "qidaoforce");
        map_skill("parry", "diesword");
		map_skill("dodge","fall-steps");
        
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: do_fight :),
        }) );
	setup();
	carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object(__DIR__"obj/diewusword")->wield();
}

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


do_fight()
{	
	command("perform dodge.luoyeqiufeng");
    command("perform caidiekuangwu");
}

	
	
