inherit ITEM;

void create()
{
        set_name("韦驮像", ({ "weituo", "韦驮像","韦驮","护法韦驮","护法韦驮像" }) );
        set_weight(500);
        set_max_encumbrance(8000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "尊");
                set("long", "一尊护法韦驮像，高大威猛。\n");
                set("value", 1);
        }
}

int is_container() { return 1; }

