
inherit ITEM;
void create()
{
	set_name("窥天镜", ({ "rusty telescope","telescope"}) );
	set("no_get", 1);
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "架在观星台上的铜制的窥天长镜，如今早已爬满锈蚀。\n");
		set("unit", "把");
		set("value", 0);
	}
	::init_item();
}

