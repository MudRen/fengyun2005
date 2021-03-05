#include <armor.h>
inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name(HIR"金红散花衣"NOR, ({ "huaqun" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", @LONG
京城有名的锦华阁大师傅用了七七四十九天绣成的裙子，裙子由金、红两种
丝线织成，下摆绣了许多梅花花瓣，犹如天女散花一般。江湖中传说这裙子
隐藏了一门绝世武功，从此江湖中为此展开了一场争夺之战。阿飞在一机缘
巧合中得到了这裙子，他把裙子送给了林仙儿，作为定情之用。
LONG);
		set("material", "cloth");
		set("armor_prop/armor", 3);
		set("armor_prop/intelligence",2);
	}
	::init_cloth();
}
/*
void init()
{
	set("dynamic_quest", (
			"owner_name" : "/d/qianjin/npc/lin",
			"fin_func" : "execute_accept_object",
			"file_name" : "/questobj/huaqun",
			])
		);

}
*/