
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("当铺金卡", ({ "golden pawncard","card" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long","
小小的卡片上盖着风云当铺的印记，激活了后，可
将可当物品的数量增加到２０。不过，只有银卡的
拥有者才能使用此卡。");
                set("value", 3000000);
				set("destination","none");
				set("material", "paper");
				set("desc_ext","激活（activate golden pawncard）");
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

		if (!arg)		return 0;
		if (present(arg, me)!= this_object())
			return 0;
		
		
		if (!REWARD_D->check_m_success(me,"当铺银卡")) {
			tell_object(me,"只有当铺银卡的拥有者才能够激活金卡！\n");
			return 1;
		}
		
		if (REWARD_D->check_m_success(me,"当铺金卡")) {
			tell_object(me,"你已经拥有当铺金卡了！\n");
			return 1;
		}
		
			
		tell_object(me, "你激活了当铺金卡，你可以在当铺里储存２０件物品了。\n\n")	;	
		
		CHANNEL_D->do_sys_channel(
			"info",sprintf("%s成为风云当铺金卡的拥有者啦！",me->name(1)));
        
        REWARD_D->riddle_done(me,"当铺金卡",10,1);
        me->set("marks/pawn_expansion",10);
        destruct(this_object());
    	return 1;
}

