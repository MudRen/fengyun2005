//	Used by /d/fy/npc/mapseller
// 	熟悉各地描述的工作	--- By silencer@fy4. workgroup

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("四海金卡", ({ "golden card","card" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long","
小小的卡片上盖着风云南宫钱庄的印记，据说激活了后，
就能够在大部分的店铺里直接通过钱庄转账交易。
也可通过set e_money 1或0 来转换付钱方式。");
                set("value", 100000);
				set("destination","none");
				set("material", "paper");
				set("desc_ext","激活（activate）");
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

		if (!arg || (arg!="golden card" && arg!="card"))	{
			tell_object(me,"格式：activate golden card\n");
			return 1;
		}
		
		if (REWARD_D->check_m_success(me,"四海金卡")) {
			tell_object(me,"你已经拥有四海金卡了！\n");
			return 1;
		}
		
			
		tell_object(me, "
你激活了南宫钱庄的漫游账号，从现在开始，你可以通过控制
set e_money 1	:通过转帐来进行交易
unset e_money	:用身边现金进行交易\n\n")	;	
		
		CHANNEL_D->do_sys_channel(
			"info",sprintf("%s成为南宫联号钱庄四海金卡的拥有者啦！",me->name(1)));
        
        REWARD_D->riddle_done(me,"四海金卡",10,1);
        destruct(this_object());
    	return 1;
}

