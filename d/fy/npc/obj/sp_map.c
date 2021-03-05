#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("原始丛林旅行者指南", ({ "hitch hiker's guide","guide"}) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
				set("oops",1);
                set("long", "这就是你现在最最需要的原始丛林旅行者指南！友情提醒：请带上你的毛巾。");
                set("value", 3000);
				set("desc_ext","丛林探险");
        }
        ::init_item();
}


