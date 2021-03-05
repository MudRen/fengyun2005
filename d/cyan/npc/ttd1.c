// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
int leave();

void create()
{
	object weapon;
        set_name("水离", ({ "shui li","shui","li" }) );
        set("title","明霞山 侍女"NOR);
		set("nickname",HIG"舞秋月，佾江风，也是疏狂也任真"NOR);
        set("gender", "女性" );
		set("class","berserker");

		set("group","couple");

		set("age",21);
		set("str",24);
		set("force_factor",150);


        set("combat_exp", 4700000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: ccommand("perform fengsiyunqi") :),
             }) );


        set_skill("blade", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("spring-blade", 200);
        set_skill("13-sword", 150);

        map_skill("blade", "spring-blade");
        map_skill("parry", "spring-blade");
        map_skill("dodge", "13-sword");

		setup();

        weapon=carry_object("/obj/weapon/blade");
        weapon->set_name("细长弯刀", ({ "blade" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name(CYN"莲花百褶裙"NOR, ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}
