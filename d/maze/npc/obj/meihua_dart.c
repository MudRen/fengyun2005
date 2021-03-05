#include <ansi.h>
#include <weapon.h>
inherit THROWING;

void create() {
	set_name(HIR"血梅花"NOR, ({ "blood blossom","blossom" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"一朵白色的梅花，每片花瓣上有一滴红色的血渍，骇人异常。。\n");
		set("unit", "堆");
		set("base_unit", "枚");
		set("base_weight", 40);
		set("base_value", 0);
		set("volumn",200);
	}
	set_amount(500);
	::init_throwing(20);
}
