#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIY"三字经"NOR, ({ "szjing" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "cloth");
            set("long", "一本字迹不清的经文。\n");
          }

    ::init_item();
}
