// annie. 07.2003
// dancing_faery@hotmail.com

inherit ITEM;

void create()
{
	set_name("古藤", ({ "vine", "古藤" }) );
	set_weight(50000);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","inside");
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "片");
	    set("long", "茂密的古藤覆盖了整片的崖壁。\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }
