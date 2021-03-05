//TIE@FY3
inherit ITEM;
void create()
{
        set_name("张志程", ({ "张志程", "zhicheng","zhangzhicheng" }) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "座");
                set("long", "一座腰悬无尘剑的张志程塑像。\n");
                set("value", 1);
        }
	::init_item();
}

int is_container() { return 1; }

