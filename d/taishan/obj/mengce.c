#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"天宗盟册"NOR, ({ "meng ce", "ce"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "卷");
                set("value", 0);
                set("long",
"一卷丝帛卷轴，卷首端端正正写着【天宗盟册】四个字。\n"NOR);
        }
	::init_item();
}

