#include <weapon.h>
inherit STAFF;

void create() {
	set_name("细细的钓鱼竿", ({ "fishpole" }) );
	set_weight(2000);
	set_max_encumbrance(1);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一根细细的钓鱼竿。\n");
		set("value", 300);
		set("material", "wood");
		set("wield_msg", "$N把$n紧紧地握在手中。\n");
		set("unwield_msg", "$N松开了手中的$n。\n");
	}
    ::init_staff(10);
}


void init()
{
        add_action("do_use", "fishing");
}

int do_use(string arg)
{
        tell_object(this_player(),"你掏出一个" + this_object()->name() + "。\n");
        environment(this_player())->fish_notify(this_object(), 0);

        return 1;
}

int is_container() { return 1; }