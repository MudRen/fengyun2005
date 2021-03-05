
#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
    set_name(HIW"如意合欢白金戒"NOR, ({ "ring" }) );
    set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
            set("unit", "个");
            set("material", "gold");
			set("value", 2000000);
            set("long", "一个如意合欢白金戒，线条幽雅柔和，柔媚印象，实为送礼佳品\n");
			set("armor_prop/armor", 0);
	        set("wield_msg", "$N从怀中摸出一个$n戴在手指上。\n");
       		set("unwield_msg", "$N将手上的$n小心翼翼地藏入怀中。\n");
        }
        ::init_finger();
}

