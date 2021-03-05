// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
int jice();

void create()
{
	object weapon;
        set_name("灰衣人", ({ "figure" }) );

        set("gender", "男性" );
		set("age",47);

        set("long","这人神情威猛，骨髓极大，但却很瘦，头发花白，一张瘦棱棱的脸上长\n着对三角眼，眼中凶光四射，他一直站得远远地，注视着神秘客。\n");

        set("combat_exp", 10000000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: ccommand("perform tianwaifeixian") :),
             }) );

        set_skill("sword", 240);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("feixiansword", 200);
        set_skill("13-sword", 220);

        map_skill("sword", "feixiansword");
        map_skill("parry", "feixiansword");
        map_skill("dodge", "13-sword");

		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name(MAG"噬魂剑"NOR, ({ "sword" }) );
		weapon->set("long"," ");
		weapon->set("value",0);
		weapon->wield();

		set("no_kill",1);

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("半旧的六品官袍", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}
