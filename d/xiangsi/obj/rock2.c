// annie 07.2003
// dancing_faery@hotmail.com
inherit ITEM;

void create()
{
	set_name("虎踞石", ({ "虎踞石" , "大石","rock"}) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","behind");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "一块形如猛虎，正对着石梁作势欲扑的奇石。\n");

		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }
