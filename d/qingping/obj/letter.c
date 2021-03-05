//XXDER
inherit ITEM;
void create()
{
        set_name("信", ({ "letter", "信"}) );
	set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
                set("long", "一封密封了的信。\n");
                set("value", 100);
        }
}
