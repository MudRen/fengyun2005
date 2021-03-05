#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
        set_name( MAG "紫枚瑰" NOR, ({ "purple flower", "flower" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "神秘迷人的紫玫瑰。\n");
                set("unit", "朵");
                set("value", 6);
                set("material", "plant");
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N轻轻地把一朵$n戴在头上。\n");
                set("unwield_msg", "$N轻轻地把$n从头上除了下来。\n");

                set("female_only", 1);

        }
        ::init_head();
		call_out("wither",600);
}
void wither()
{
	if (query("delivery"))
	{
		set("name","枯萎的"+name());
		set("long","这原来是一朵"+query("long")+"不过现在已经枯萎了。\n");
		delete("delivery");
	}
}