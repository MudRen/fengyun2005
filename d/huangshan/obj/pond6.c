inherit ITEM;

void create()
{
        set_name("翡翠池", ({ "翡翠池", "翡翠","feicui" }) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "水色为翡翠的池潭\n");
                set("value", 1);
        }
	::init_item();
}

int is_container() { return 1; }

