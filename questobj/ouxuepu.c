#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIR"呕血谱"NOR, ({ "ouxue-pu" }) );
    set_weight(50);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "册");
            set("material", "stone");
            set("long", HIR"相传一代棋圣刘仲甫在骊山与一乡下老媪对弈一百二十着，被杀得大败，登时呕血
数升，流传下这千古名局。\n"NOR);
          }

    ::init_item();
}
