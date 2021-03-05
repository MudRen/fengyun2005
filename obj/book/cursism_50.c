#include <armor.h>

inherit CLOTH;
#include <ansi.h>

void create()
{
        set_name(HIR"人皮袈裟"NOR, ({"jiasha"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
        	set("long","一件人皮缝制的大红袈裟，上面密密麻麻绣了很多蝇头小字。\n");
                set("material", "cloth");
                set("skill", ([
                        "name":         "cursism",               
                        "exp_required": 100000,                              
                       	"sen_cost":     2,        
                    	"difficulty":   20,          
                        "max_skill":    49                              
                ]) );
                set("unit", "件");
                set("value", 100);
                set("armor_prop/armor", 20);

        }
        ::init_cloth();
}

