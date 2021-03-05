#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(RED"侠义无双令"NOR, ({ "xiayiling" }) );
    set_weight(100);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "块");
            set("material", "iron");
            set("long", "这是『无垢山庄』的至宝，看上去非金非玉，质地坚硬无比，令中隐然有红光浮现，\n凡是执此令者，有如无垢山庄庄主亲至，天下武林，莫敢不从。\n");
          }

    ::init_item();
}
