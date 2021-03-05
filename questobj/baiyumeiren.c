#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(WHT"白玉美人"NOR, ({ "yumeiren" }) );
    set_weight(50);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "尊");
            set("material", "stone");
            set("long", WHT"一个妙手雕成，晶莹而滑润的白玉美人，看来仿佛九天仙子，不食
人间烟火，盗帅楚留香因为觉得象极了苏蓉蓉，尤其是那同样温婉
清澈的一泓秋水，踏月京城，盗得送与了蓉儿．\n"NOR);
          }

    ::init_item();
}
