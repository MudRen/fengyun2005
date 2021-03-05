inherit ITEM;
void create()
{
    set_name( "头发", ({ "hair"  }) );
    set("unit", "根");
    set("value",0);
    set("long","一根又细又长的头发，显然是女子的。\n");
    set("medman",1);
    set_weight(5);
	::init_item();
}
