#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
        string *flower_name=({ "桃金娘","风信子","白头翁","水仙花"}) ;
        set_name(flower_name[random(sizeof(flower_name))], ({"flower"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "绚烂开放的鲜花。\n");
                set("unit", "朵");
                set("value", 10);
                set("material", "plant");
                set("armor_prop/armor", 0);
                set("wear_msg", "$N轻轻地把一朵$n戴在头上。\n");
                set("unwield_msg", "$N轻轻地把$n从头上除了下来。\n");
                set("female_only", 1);
		
        }
        	::init_head();

}


