#include <ansi.h>
inherit NPC;

void create()
{
    object weapon;
    set_name("背后灵", ({ "ghost" }) );

    set("long","一个从山崖上摔下而死的冤魂。\n他正紧紧的粘在你背后．．．\n");

    set("age", 35);
    set("reward_npc", 1);
    set("difficulty", 1);

    set("real_ph",1);
    set("no_arrest",1);

    set("chat_chance", 1);
    set("chat_msg", ({
		"背后灵喃喃道：两生花．．．不要去摘两生花．．．\n",
		"背后灵骤然双眼圆睁，指着你的头顶尖叫：鬼，鬼，有鬼啊！\n",
      }) );

    set("combat_exp", 2400000);
    set("score", 200);

    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
		(: ccommand("perform hanmeiluo") :),
//		(: smart_fight() :),              
    }) );

    set_skill("move", 200);
    set_skill("parry", 160);
    set_skill("dodge", 150);
    set_skill("unarmed",200);
    set_skill("luoriquan",180);
    set_skill("fengyu-piaoxiang",200);

    set_skill("qiuzhi-sword",100);
    set_skill("sword",160);

    map_skill("sword","qiuzhi-sword");
    map_skill("unarmed","luoriquan");
    map_skill("dodge","fengyu-piaoxiang");
    map_skill("move","fengyu-piaoxiang");
    map_skill("parry","qiuzhi-sword");    

    setup();
    weapon = new("/d/tieflag/obj/lovering");
    weapon->set_name(CYN"虚无魂气"NOR, ({ "ghosty aura","sword" }));
    weapon->set("skill_type","sword");
    weapon->set("value",0);
    weapon->set("unit","把");
    weapon->set("long","一丝虚无飘渺的魂魄．．．\n");
    weapon->move(this_object());
    weapon->wield();

    weapon = new("/obj/armor/cloth");
    weapon->set_name(HIR BLK"残破布衣"NOR, ({ "cloth" }));
    weapon->move(this_object());
    weapon->wear();
}

int is_ghost() { return 1; }

