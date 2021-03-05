#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
    	set_name(YEL"黄毛巾"NOR, ({ "yellow towel","towel" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
        set("long", "一条汗迹斑斑的黄毛巾。\n");
		set("value", 7000);
		set("material", "cloth");
		set("armor_prop/armor", 5);
	}
    ::init_head();
}
