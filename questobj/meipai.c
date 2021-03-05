#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(WHT"断梅笔"NOR, ({ "duanmei-bi" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "支");
            set("material", "wood");
            set("long", "岁寒三友之寒梅先生的信物，本是一枝断梅，据说乃是寒梅年青时与\n华山女子的定情之物，可惜情不再，梅已断。。\n");
          }

    ::init_item();
}
