
inherit ITEM;
void create()
{
	set_name("白玉晗蝉", ({ "jade cicada","cicada"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一枚玲珑剔透的白玉晗蝉，是世间难得一见的珍品。\n");
		set("unit", "枚");
		set("value", 3333);
	}
	::init_item();
}

