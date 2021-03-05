
inherit ITEM;

void create()
{
	set_name("油皮袋", ({ "oilbag" , "油皮袋"}) );
	set_weight(500 + random(8000));
	set_max_encumbrance(40000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个防水的油皮袋，可以在水下使用。\n");
		set("value", 1);
		set("waterproof",1);
	}
}

int is_container() { return 1; }
