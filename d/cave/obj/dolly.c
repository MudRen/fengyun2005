
inherit ITEM;

void create()
{
    set_name("小土车", ({ "dolly" , "小土车"}) );
	set_weight(500);
    set_max_encumbrance(20000);
	set("no_get", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "辆");
        set("long", "一辆破旧坏损的小土车，木头轮子烂了一半，歪倒在路旁。\n");
		set("value", 1);
	}
}

int is_container() { return 1; }


