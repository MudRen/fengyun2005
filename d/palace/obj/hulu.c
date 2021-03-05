
inherit ITEM;

void create()
{
	set_name("紫金葫芦", ({ "hulu" , "紫金葫芦"}) );
	set_weight(500+random(160000));
	set_max_encumbrance(80000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个可放好多东西的葫芦\n");
		set("value", 1);
	}
}

int is_container() { return 1; }
