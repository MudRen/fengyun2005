
inherit ITEM;

void create()
{
	set_name("细麻线", ({ "string" , "xi xiang"}) );
	set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "一条长长的细麻线。\n");
		set("value", 50);
	}
    ::init_item();
}



