inherit ITEM;

void create()
{
        set_name("铜碑", ({ "tong bei", "bei", "铜碑"}) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("prep", "behind");
                set("unit", "座");
                set("long", "铸造铜弥勒碑记\n");
                set("value", 1);
        }
}

int is_container() { return 1; }

