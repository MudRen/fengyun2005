#include <ansi.h>
#include <armor.h>
inherit SURCOAT;
//霞雲彩綾 真虹紗羽 疏雨云河 坠月玄纱
void create()
{
        set_name(CYN"竹叶符衣"NOR, ({ "surcoat" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "bamboo");
                set("unit", "件");
                set("long","一件竹叶编织成的衣服，叶上隐有符文浮现。\n");
        }
        ::init_surcoat();
}

