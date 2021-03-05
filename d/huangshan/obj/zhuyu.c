#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( "茱萸果", ({ "zhu yu", "茱萸果" }) );
    set_weight(10);
    if( clonep() )
            set_default_object(__FILE__);
    else {
        set("unit", "个");
        set("long", "朱红色的果子圆润可爱。\n");
    	set("value", 1000);    
    }
	::init_item();
}
