// TIE@FY3
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIG"方丈手谕"NOR,({ "shouyu" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "纸");
                set("material", "paper");
                set("long", "这是一张空白的方丈专用手谕笺。\n");
        }
	::init_item();
}
