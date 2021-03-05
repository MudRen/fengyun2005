// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
        set_name("林默", ({ "lin mo","lin","mo" }) );
        set("title",YEL"金狮镳局"NOR);
		set("nickname",BLU"少林寺下山弟子"NOR);
        set("gender", "男性" );

		set("age",37);

        set("combat_exp", 3100000);

		set_temp("no_busy",2);

        set_skill("force", 160);
        set_skill("unarmed", 200);
        set_skill("iron-cloth", 150);
        set_skill("xisui", 140);
        set_skill("yizhichan", 170);
        set_skill("dodge", 160);
        set_skill("stormdance", 110);
        
        map_skill("dodge","stormdance");
        map_skill("unarmed","yizhichan");
        map_skill("iron-cloth","xisui");

		setup();

        weapon=carry_object(__DIR__"obj/necklace");
		weapon->wear();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("灰色镳衣", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}
