//Xxder@fy3
inherit ITEM;
void create()
{
	set_name("草编蚂蚱", ({ "insect" }) );
	set_weight(150);
        set_max_encumbrance(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个用草编的蚂蚱\n");
		set("value", 2);
	}
}
int is_container() { return 1; }
