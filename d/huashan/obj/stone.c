inherit ITEM;

void create()
{
	set_name("青石", ({"stone", "qing shi"}) );
	set_weight(50000);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","on");
	if( clonep() )
  	  set_default_object(__FILE__);
	else {
	    set("unit", "块");
	    set("long", "一块白玉般的岩石，就像是个孤独的巨人矗立在月光下。若石上没有花。岩 
石上只有一株碧绿的草，比花更美，比翡翠还绿。 
\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

