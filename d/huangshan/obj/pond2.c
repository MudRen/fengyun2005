inherit ITEM;

void create()
{
        set_name("青池", ({ "青池", "青","qing" }) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "水色为青的池潭\n");
                set("value", 1);
        }
	::init_item();
}

int is_container() { return 1; }

