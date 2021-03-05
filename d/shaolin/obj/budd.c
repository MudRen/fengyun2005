inherit ITEM;

void create()
{
        set_name("弥勒佛", ({ "fe", "弥勒佛" }) );
        set_weight(500);
        set_max_encumbrance(8000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "尊");
                set("long", "一尊泥塑弥勒佛像，笑容可掬，普渡着天下苍生。\n");
                set("value", 1);
        }
}

int is_container() { return 1; }

