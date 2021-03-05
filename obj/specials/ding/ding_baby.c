inherit ITEM;
#define MAX_CARRY 29
#include <ansi.h>

void create()
{
        set_name(YEL"随身小香炉"NOR, ({ "ding" }) );
	set_weight(500);
	set("no_drop",1);
	set("no_give",1);
	set("no_get",1);
	set("small_ding",1);
	set_max_encumbrance(50);	
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("unit", "口");
                set("long", CYN"一只六寸来高的小鼎，设计精巧，既可以用来炼制宝物，又可以用来存放
一些符咒法纸等物，需要时可以飞快地取出。（ｇｒａｂ）。\n\n"NOR);
		set("value", 1);
		set("prep","on");
	}
        ::init_item();
}


int is_container() 
{ 
	return 1; 
}

void init()
{
	if(this_player()==environment())
		 add_action("do_grab","grab");
}


int do_grab(string arg)
{
	object	me, ob,*inv;
        if( !arg )
                return notify_fail("你要从小香炉里拿什么东西？\n");
	if (!ob=present(arg,this_object()))
		return notify_fail("小香炉里有这样东西么?\n");
	if (!ob->query("fast_grab"))
		return notify_fail("这样东西不够轻便,没法一下子抓出来。\n");
	me = this_player();
	inv = all_inventory(this_player());
	if(sizeof(inv) >= MAX_CARRY) 
		return notify_fail("你身上已经带着太多东西了。\n");
	message_vision("$N一伸手，飞快地从小香炉里抓出$n。\n", me, ob);
	ob->move(me);
        return 1;
}

