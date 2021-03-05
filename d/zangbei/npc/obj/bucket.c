// waterskin.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("水桶", ({ "bucket"}) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个大水桶。\n");
		set("unit", "个");
		set("value", 20);
		set("max_liquid", 20);
	}
	::init_item();
}
