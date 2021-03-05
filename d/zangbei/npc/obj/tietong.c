#include <ansi.h>  
#include <combat.h>
inherit ITEM;
void create()
{
        set_name("铁筒", ({ "box" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
		set("long", @LONG
黝黑的铁筒，发射暗器的针筒，构造之精巧，竟似还在昔年名震天
下的『九天十地，天魔神针』之上。
LONG);
                set("material", "iron");
        }
        ::init_item();
}


void init()
{
	add_action("do_shoot","shoot");
}


int do_shoot(string arg)
{
	return notify_fail("你拨弄了几下，似乎找不到发射的机关。\n");
	
}
