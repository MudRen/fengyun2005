
inherit ITEM;

void create()
{
	set_name("大箱子", ({ "woodcase" , "大箱子"}) );
	set_weight(10000);
	set_max_encumbrance(80000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "口");
		set("prep", "under");
		set("long", "一个大箱子，木料很好，上面还包著黄铜。\n");
		set("value", 1);
	}
}

int is_container() { return 1; }


