//  An example non-weapon type of weapon
#include <ansi.h>
#include <weapon.h>
inherit RING;
void create()
{
	set_name(HIB"青魔手"NOR, ({ "devil hand", "hand" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "只");
		set("long", "一只暗青色的手套，上面零零落落刻着一些文字。这手套的样子诡异，\n也实在难以判断是什么材质，透出一种难以名状的邪气。\n");
        	set("lore",1);
		set("value", 50);
		set("material", "steel");
	}
    	init_ring(18);
	
	set("real", 1);
	set("wield_msg", "$N从怀中摸出一个$n带在手上。\n");
	set("unwield_msg", "$N将手上的$n拿下来藏入怀中。\n");
        set("skill", ([
                  "name": "devil-spells",           // name of the skill
                  "exp_required": 2500000,  // minimum combat experience required
                  "sen_cost":     10,      // jing cost every time study this
                  "difficulty":   20,     // the base int to learn this skill
                  "max_skill":    59     // the maximum level you can learn
        ]) );


}
