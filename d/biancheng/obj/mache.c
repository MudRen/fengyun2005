inherit ITEM;

void create()
{
        set_name("马车", ({ "mache" }) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "辆");
                set("long", "一辆八马并驰的黑漆大车，车上斜插着一面白绫三角旗：“关东万马堂。”\n");
                set("value", 1);
        }
}

