
inherit ITEM;
void create()
{
	set_name("铁轮盘", ({ "rusty device","device"}) );
	set("no_get", 1);
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "固定在观星台上的铁轮盘，如今早已爬满锈蚀，看不出当年曾作何用。\n");
		set("unit", "个");
		set("value", 0);
	}
	::init_item();
}

