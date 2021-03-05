#include <weapon.h>

inherit THROWING;
#include <ansi.h>
void create()
{
	set_name(RED"五"BLU"花"HIG"神箭"NOR, ({ "5flower arrow" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一把三寸长的短箭，上边镂着一些奇怪的花纹．\n");
		set("unit", "堆");
		set("base_unit", "把");
		set("base_weight", 1);
		set("base_value", 10);
		set("wield_msg","$N不知从哪里突然间拽出一把$n握在手里．\n");
		set("volumn",15);
	}
    set_amount(15);
	::init_throwing(10);
}
