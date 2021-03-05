#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIM"紫晶宝石"NOR, ({ "stone" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "枚");
            set("material", "stone");
            set("jile",1);
            set("value", 500);
            set("long", "一枚紫莹莹的宝石，外行人实在看不出什么名堂。\n");
            set("thief_obj",1);
          }
	::init_item();
}
