inherit ITEM;

void create()
{
	set_name("武士", ({ "knight", "武士" }) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "尊");
	    set("long", "一个勇猛威烈，气势夺人，擎旗捧剑的武士雕像。\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

