// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
        set_name("神秘客", ({ "figure","figure jiang" }) );

        set("gender", "男性" );
		set("age",47);

        set("long","一个头带斗笠，低低遮住面容的人，浑身散发着强烈的杀气。\n");

        set("combat_exp", 10000000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: ccommand("perform fentianzhan") :),
             }) );


            set("inquiry",([
 		"九月初九"  :"action神秘客一语不发，理都不理$n一下。\n",
 		"顾道人"  :"action神秘客一语不发，理都不理$n一下。\n",
 		"顾剪秋"  :"action神秘客一语不发，理都不理$n一下。\n",
           ]) );

        set_skill("blade", 240);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("beilongblade", 200);
        set_skill("13-sword", 220);

        map_skill("blade", "beilongblade");
        map_skill("parry", "beilongblade");
        map_skill("dodge", "13-sword");

		setup();

        weapon=carry_object("/obj/weapon/blade/pxblade");
        weapon->set_name(HIB"寸尺刀"NOR, ({ "blade" }) );
		weapon->set("long"," ");
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("青灰衣", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

        weapon=carry_object("/obj/armor/hat");
        weapon->set_name("大斗笠", ({ "hat" }) );
		weapon->set("value",0);
		weapon->wear();

}

void die()
{
	stop_busy();
	ccommand("perform fenqin");
	::die();
}
