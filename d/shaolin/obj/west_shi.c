inherit ITEM;
void create()
{
	set_name("西石坊", ({ "shifang" , "西石坊"}) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个高大的石刻牌坊。\n");
		set("value", 1);
	}
}

int is_container() { return 1; }


