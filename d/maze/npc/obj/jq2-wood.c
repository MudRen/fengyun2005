#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(GRN"无间木"NOR, ({"wood vessel","vessel"}) );
	set_weight(500);
	set_max_encumbrance(500);	
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("unit", "口");
                set("long", "
一块碧绿的檀木小鼎，隐隐散发着芳香，你可以把合适的药草放在鼎中
炼制（lian）。\n\n");
		set("value", 1);
		set("no_drop",1);
		set("no_sell",1);
		set("no_give",1);
		set("prep","in");
	}
        ::init_item();
}


void init()
{
	if(this_player()==environment())
		 add_action("do_lian","lian");
}

int do_lian(string lian)
{
	object	me, *inv, *ob;
        int     i, n;
	string  *ob_name = ({GRN"损心草"NOR,MAG"摧肝花"NOR,BLU"离魂叶"NOR,HIR"七绝枝"NOR });
	        
        ob = allocate(4);
        me = this_player();
        inv = all_inventory(me);
                
        if (me->is_busy())
        	return notify_fail("你现在正忙。\n");
                	
        for (i=0; i<4; i++) {
        	n = sizeof (inv);
        	while (n--) {
        		if (inv[n]->query("name") == ob_name[i] && inv[n]->query("wujian")) 
        			ob[i] = inv[n];
         	}
         	if (!objectp(ob[i])) {
        		tell_object(me, "你缺少"+ob_name[i]+"。\n");
        		return 1;
        	}
        }
        
        if (environment(me)->query("short")!= "无间堂")
        	return notify_fail("无间木鼎只有在无间堂的炉鼎旁方能使用。\n"); 
        
        
        message_vision(HIC"
$N将损心草、摧肝花、离魂叶、七绝枝一一投入无间木鼎。

突然，整个无间木鼎变得晶莹透彻，一股香烟自鼎中袅袅而起，仿佛
识得$N一般，窜入$N的口鼻之中。 

\n"NOR, me);
	tell_object(me, YEL"
你顿觉浑身仿佛脱胎换骨一般，任督二脉畅然无阻，三花会顶，丹田之中充溢 
着氤氲之气，而眉间的绿意也悄然褪去。。。 

你不禁坐下抱膝吐呐。\n\n"NOR,me);

	me->start_busy(100);
	destruct(ob[0]);
	destruct(ob[1]);
	destruct(ob[2]);
	destruct(ob[3]);

	
	environment(me)->event3(me, 0);
	destruct(this_object());

	return 1;
}