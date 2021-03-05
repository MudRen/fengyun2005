#include <ansi.h>

inherit ITEM;
void create()
{
        set_name("素绢", ({ "silk sheet", "sheet"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("value", 0);
                                set("long",
"一张素绢，上面写着：
素文自知命不久矣，无他愿，但望过路的好心人能将素文与铮郎合体同葬”
生不同寝，死亦同冢"NOR);
        }
	::init_item();
}
