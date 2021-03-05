#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
	set_name(RED"紫铜护心镜"NOR , ({ "copper plate", "plate" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	        set("unit", "块");
		set("long", "一块紫铜护心镜，上面赫然刻着个『三』字。\n");
		set("value", 700);
	        set("material", "copper");
	}
	::init_neck();
}
