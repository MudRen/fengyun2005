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
	set_name("大碗热茶", ({ "tea" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一碗热气腾腾的茶水，闻起来香气扑鼻。\n");
		set("unit", "碗");
		set("value", 5);
        set("liquid", ([
        "type": "water",
        "name": "茶水",
        "remaining": 8,
        "drunk_apply": 5,
        ]) );	
	}
	 ::init_item();
}

int finish_eat()
{
	set_name("豁碗", ({"bowl"}) );
	set("value", 10);
	set("long", "一只豁了一角的碗。\n");
	return 1;
}

	