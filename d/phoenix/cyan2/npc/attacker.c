#include <ansi.h>
inherit __DIR__"in.c";

void create()
{
		object weapon;
        set_name("东瀛浪人", ({ "soldier" }) );
        set("attitude", "heroism");
        setup();

        weapon=carry_object("/obj/weapon/blade/pxblade");
        weapon->set_name("倭刀", ({ "no-dachi" }) );
		weapon->set("long"," ");
		weapon->set("no_get",1);
		weapon->set("value",0);
		weapon->wield();

}


void die(){
	destruct(this_object());
}