#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"考题" NOR, ({ "kaoti" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "张");
            set("material", "paper");
            set("long", "一张乡试的考题，考试的题目：天下英雄论");
          }

    ::init_item();
}
