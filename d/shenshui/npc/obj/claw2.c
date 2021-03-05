//  An example non-weapon type of weapon
#include <ansi.h>
#include <weapon.h>
inherit RING;
void create()
{
	set_name(WHT"带吸盘的大触手"NOR, ({ "claw", "hand" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "只");
		set("long", "一只从深海海底的千年章鱼身上砍下的触手，上面有无数细小的吸盘。\n");
        	set("lore",1);
		set("value", 50000);
		set("experience",3000000);
		set("material", "steel");
		set("owner",1);
	}
    	init_ring(30);
	set("wield_msg", "$N从怀中摸出一个$n带在手上。\n");
	set("unwield_msg", "$N将手上的$n拿下来藏入怀中。\n");
	       
}

int query_autoload() { return 1; }

