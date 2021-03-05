
inherit ITEM;

void create()
{
	set_name("雕像", ({ "xiang" , "diao xiang", "diao"}) );
	set_weight(50000);
	set_max_encumbrance(8000);
	set("no_get", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "天文家僧一行的雕像\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }


