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
	set_name("凉水", ({ "water" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一碗凉水。\n");
		set("unit", "碗");
		set("value", 100);
        set("liquid", ([
        "type": "water",
        "name": "凉水",
        "remaining": 8,
        "drunk_apply": 5,
        ]) );	
	}
	 ::init_item();
}

int finish_eat()
{
	set_name("破碗", ({"bowl"}) );
	set("value", 10);
	set("long", "一只破掉的碗。\n");
	return 1;
}

	