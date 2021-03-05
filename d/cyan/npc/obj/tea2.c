//

inherit ITEM;
inherit F_LIQUID;
void init()
{
        if(environment()==this_player())
        add_action("do_drink", "drink");
}

void create()
{
	set_name("淡茶", ({ "tea" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "淡得与凉水没什么两样的一碗茶。\n");
		set("unit", "碗");
		set("value", 300);
        set("liquid", ([
        "type": "water",
        "name": "淡得毫无味道的茶",
        "remaining": 8,
        "drunk_apply": 5,
        ]) );	
	}
	 ::init_item();
}

int finish_eat()
{
	set_name("缺了一角的碗", ({"bowl"}) );
	set("value", 10);
	set("long", "一只缺了一角的碗。\n");
	return 1;
}

	