//tieflag.c
inherit ITEM;
void create()
{
    set_name("铁血大旗", ({ "flag" }) );
    set_weight(10000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "面");
            set("value", 0);
            set("material", "cloth");
            set("long", "一面用鲜血染成的旗帜，是铁血大旗门掌门信物。\n");
          }

    ::init_item();
}
