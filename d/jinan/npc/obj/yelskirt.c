// cloth.c
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
    	set_name(YEL"鹅黄色长裙"NOR, ({ "long skirt","skirt" }) );
    	set_weight(300);
		if( clonep() )
			set_default_object(__FILE__);
		else {
		set("unit", "件");
	        set("long", "一件鹅黄色长裙，素雅中微微又有点俏皮可爱。\n");
	        set("value", 40);
			set("material", "cloth");
	        set("armor_prop/armor", 1);
		set("female_only", 1);
	}
	::init_cloth();
}
