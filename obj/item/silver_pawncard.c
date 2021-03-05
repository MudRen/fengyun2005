
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("当铺银卡", ({ "silver pawncard","card" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long","
小小的卡片上盖着风云当铺的印记，激活了后，可
将可当物品的数量增加到１５。");
                set("value", 1000000);
				set("destination","none");
				set("material", "paper");
				set("desc_ext","激活（activate silver pawncard）");
        }
        ::init_item();
}


void init()
{
   	add_action("do_activate","activate");
}
    
    
int do_activate(string arg)
{
    	object me = this_player();
		
		if (!arg)	return 0;
			
		if (present(arg, me)!= this_object())
			return 0;
		
		if (REWARD_D->check_m_success(me,"当铺银卡")) {
			tell_object(me,"你已经拥有当铺银卡了！\n");
			return 1;
		}
		
			
		tell_object(me, "你激活了当铺银卡，你可以在当铺里储存１５件物品了。\n\n")	;	
		
		CHANNEL_D->do_sys_channel(
			"info",sprintf("%s成为风云当铺银卡的拥有者啦！",me->name(1)));
        
        REWARD_D->riddle_done(me,"当铺银卡",10,1);
        me->set("marks/pawn_expansion",5);
        destruct(this_object());
    	return 1;
}

