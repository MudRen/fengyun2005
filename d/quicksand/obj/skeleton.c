
inherit ITEM;

void create()
{
	set_name("一具枯乾的骸骨", ({ "skeleton" , "骸骨"}) );
	set_weight(400000);
	set_max_encumbrance(500000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "具");
		set("long", "一具枯乾的骸骨。\n");
		set("value", 1);
	}
}

int is_container() { return 1; }


