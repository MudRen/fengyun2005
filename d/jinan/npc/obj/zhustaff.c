
#include <ansi.h>
#include <weapon.h>

inherit STICK;

void create()
{
        set_name(HIG"打狗棍"NOR , ({ "doggie stick", "stick" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "根");
        set("long", GRN"一根绿油油，晶莹剔透的竹棒。\n"NOR);
        set("value", 1);
		set("no_give", 1);
		set("class","beggar");
		set("experience",3000000);
		set("material", "wood");
        	set("wield_msg", "$N抽出一根$n紧紧握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}
//	ITEM_D->setup_unique(this_object());  
    ::init_stick(35);
}
