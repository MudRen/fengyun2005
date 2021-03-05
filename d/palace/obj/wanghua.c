
inherit ITEM;

void create()
{
	set_name("忘魂花", ({ "wanghua" , "忘魂花"}) );
	set_weight(5);
	set_max_encumbrance(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("prep", "on");
		set("long", "一棵碧绿的草\n");
		set("value", 1);
	}
}

int is_container() { return 1; }
