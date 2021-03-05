#include <ansi.h>
inherit __DIR__"in.c";

void create()
{
	object weapon;
        set_name("武当弟子", ({ "dizi"}) );
        set("long","随着各派尊长到明霞山参加饮血平寇大会的无不是百里挑一的精英，\n他们的武学造诣在江湖中通常已鲜有人及。\n");
        set("attitude", "heroism");

		set("death_msg",CYN"\n$N挣扎道：师兄．．．．\n"NOR);
	set("no_heal",1);

        setup();
        weapon=carry_object("/obj/weapon/sword");

		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("灰色长衫", ({ "cloth" }) );
		weapon->set("long"," ");
		weapon->set("no_get",1);
		weapon->set("value",0);
		weapon->wear();


}


