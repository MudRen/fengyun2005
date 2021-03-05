#include <armor.h>
#include <ansi.h>
inherit WRISTS;

void create() {
	set_name(HIG"缀满梅花的纱巾"NOR, ({ "ribbon"}) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一条缀满梅花的纱巾，上面斑斑点点溅着几点鲜红的血迹。\n");
		set("unit", "条");
		set("value", 0);
		set("wear_msg", "$N轻轻地把一条$n系在手腕上。\n");
		set("unwield_msg", "$N轻轻地把$n从手腕上解了下来。\n");
	}
	::init_wrists();
}

