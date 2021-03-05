
inherit ITEM;
void create()
{
	set_name("断笛", ({ "broken flute","flute"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一把精致的木笛，在你手中的却只有折断的半截。\n");
		set("unit", "把");
		set("value", 0);
		set("real",1);
	}
	::init_item();
}

