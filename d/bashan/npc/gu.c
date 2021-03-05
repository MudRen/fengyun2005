// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
        set_name("顾剪秋", ({ "gu jianqiu","gu","jianqiu" }) );
        set("title",CYN"巴山剑客"NOR);
        set("nickname",CYN"夜雨飞葭"NOR);
        set("gender", "男性" );

		set("age",47);

        set("long","二十年前，人们提到他时称他为“巴山小顾”，而今天这个称呼\n已变为“巴山顾先生”，顾道人江湖声望可见一斑。\n");

		set("skill_public",1);

	set("chat_chance",6);
	set("chat_msg", ({
		"顾剪秋放声大笑，豪气不减当年。\n",
	}) );

            set("inquiry",([
 		"九月初九"  :"action顾剪秋哈哈一笑道：九月初九，那不是风云三开张的纪念日吗？\n",
    		"顾云飞"  :"风飞与云飞负有重任在身啊。\n",
 		"顾风飞"  :"风飞与云飞负有重任在身啊。\n",
 		"顾雷飞"  :"疑？你方才来的时候没有见到他们两个？\n",
 		"顾电飞"  :"疑？你方才来的时候没有见到他们两个？\n",
 		"重任"  :"action顾剪秋摇了摇头道：不可说，不可说。\n",
           ]) );


    set("reward_npc", 1);
	set("difficulty",7);

        set("combat_exp", 10000000);

		set_temp("busy_immune",1);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: ccommand("perform luoxiang") :),
             }) );


        set_skill("sword", 300);
        set_skill("advanced-parry", 200);
        set_skill("unarmed", 180);
        set_skill("gaunforce", 190);
        set_skill("venusfinger", 170);
		set_skill("perception",200);
        set_skill("literate", 140);
        set_skill("chanting", 190);
        set_skill("dodge", 200);
        set_skill("move", 160);
        set_skill("parry", 200);
        set_skill("windsword", 220);
        set_skill("nodust-steps", 190);
        set_skill("iron-cloth", 170);

        map_skill("unarmed", "venusfinger");
        map_skill("force", "gaunforce");
        map_skill("sword", "windsword");
        map_skill("parry", "windsword");
        map_skill("dodge", "nodust-steps");
        map_skill("move", "nodust-steps");

		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name(HIG"细柳"NOR, ({ "sword"}) );
		weapon->set("long"," ");
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("青绣长袍", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}
