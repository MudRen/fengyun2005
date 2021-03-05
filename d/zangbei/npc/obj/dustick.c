#include <ansi.h>
#include <weapon.h>

inherit STICK;

void create()
{
        set_name(WHT"玉杖"NOR , ({ "jade stick", "stick" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "根");
        set("long", "一根洁白，晶莹剔透的宝杖，不象是兵器，更像一件饰物。\n"NOR);
        set("value", 100);
		set("class","beggar");
		set("agility",24);
		set("material", "jade");
        	set("wield_msg", "$N抽出一根$n紧紧握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}
	::init_stick(20);
}
