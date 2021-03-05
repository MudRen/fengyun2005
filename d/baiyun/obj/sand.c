inherit ITEM;

void create()
{
    set_name("沙子", ({ "sand","shazi"}) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "片");
        set("long", "一片黄灿灿的沙子。你似乎可以在里面搜索（ｓｅａｒｃｈ）。\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }
