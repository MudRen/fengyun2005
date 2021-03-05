
inherit ITEM;

void create()
{
	set_name("凝露池", ({ "dew pond" , "pond", "凝露池", "池"}) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一片天然的石凹，边上砌起了一圈白玉石栏，约有两尺深浅，三坪宽长。\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }
