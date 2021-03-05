#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(GRN"残松图"NOR, ({ "cansong-tu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "幅");
            set("material", "stone");
            set("long", "这是西方神教孤松先生的信物，画已残破不堪，而画中孤松也寥落衰败。\n");
          }

    ::init_item();
}
