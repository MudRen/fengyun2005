#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("榴莲", ({ "durian", "liu lian" }) );
        set_weight(11000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "一颗巨大的榴莲，上面满是硬刺，少说有二十多斤。\n");
        set("unit", "个"); 
        set("value", 10);
        set("material", "wood");
        set("wield_msg", "$N拿出一颗巨大的，上面满是硬刺的$n，握在手中。\n");
        set("unequip_msg", "$N放下手中的$n。\n");
    	set("opened", 1);
    	set("durian_remain", 3);
    }    
        ::init_hammer(15);
}

void init () {
    if(this_player()==environment()) {
		add_action("do_eat", "eat");
		add_action("do_cut", "cut");
	}
}

int do_eat(string arg)
{
    object durian, me;
    
    me = this_player();    
    if (!arg || arg != "durian" && arg != "榴莲" && arg != "liu lian") return 0; 	
   	if(query("opened")) {
   		tell_object(me, "这东西满是硬刺，怎么下嘴啊？\n");
   		message("vision", me->name() + "抱着大榴莲就想咬，可榴莲的长满刺的硬壳让她无从下嘴。\n", 
   				environment(me), me);
    } else {
		message_vision("$N屏着呼吸，切下一片榴莲果肉细细品尝。。。\n", me);
    	tell_object(me, "甜甜的，有种特殊的味道，还不错啊。\n");
     	me->add("food", 2);
    	add("durian_remain", -1); 
    	if(query("durian_remain") == 0) {
    		destruct(this_object());
    	}
    }
    return 1;
}

int do_cut(string arg)
{
	object durian, me, weapon, obj;
	
	if (!arg || arg != "durian" && arg != "榴莲" && arg != "liu lian") {
		write("你要砍开什么？\n");
		return 1;
	}
	me = this_player();
	weapon = me->query_temp("weapon");
	if(!weapon) {
    	write("你手上没有合适的锐器，用手是开不开榴莲的。\n");
   	} else {
		if(weapon->query("flag") & 4) {	 
			if(query("opened")) {
				message("vision", me->name() + "挥动手中的" + weapon->name() + 
						"砍开了大榴莲。\n", environment(me), me);
				message_vision("一阵奇臭的怪味扑鼻而来。。。。。 \n", me);
				set("long", "被砍开的榴莲，露出里面黄色的瓤，散发着一阵奇臭的怪味。\n");
				set_name("打开的榴莲", ({"durian", "opened durian"}));
				set("wield_msg", "$N一颗上面满是硬刺的$n，握在手中。\n");
        		set("unequip_msg", "$N放下手中的$n。\n");
				set("opened", 0);
			} else {
				tell_object(me, "笨蛋！榴莲已经打开了。\n");
			}	
		} else {
			write("用这个是没办法开榴莲的，换一个试试。\n");
		}
	}
	return 1;
}
