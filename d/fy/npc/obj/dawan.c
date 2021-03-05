
inherit ITEM;

void create()
{
	set_name("大碗", ({ "dawan", "wan" }) );
	set_weight(700);
   set_max_encumbrance(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个豁角的大碗。\n");
		set("unit", "个");
		set("value", 50);
	}

	::init_item();
}
int is_container() { return 1; }


// 凝輕·dancing_faery@hotmail.com

