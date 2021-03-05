inherit ITEM;

void create()
{
	set_name("玄武", ({ "玄武", "xuanwu" }) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "尊");
	    set("long", "一尊玄武的铜铸塑像，披发跣足，丰姿巍伟。\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

