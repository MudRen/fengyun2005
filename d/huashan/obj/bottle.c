
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("小玉瓶", ({ "bottle", "jade bottle"}) );
    set_weight(800);
    set_max_encumbrance(100);
    if (clonep())
    	set_default_object(__FILE__);
    else {
		set("unit", "个");
		set("long", "一个白中透出绿色的小玉瓶，瓶盖紧闭。\n");
		set("value", 1);
        	set("prep", "in");
    		set("value", 1);
    		set("is_closed", 1);
    }
	::init_item();
}

int is_container() {return 1;}

void init()
{
   	add_action("do_open","open");
}

int do_open(string arg)
{
	object me, ob, item;
	
	me = this_player();
	ob = this_object();
    	if( !arg || (arg != "bottle" && arg != "玉瓶") ) {
    		return notify_fail("你要打开什么？\n");
    	}
    	if(!query("is_closed")) {
    		return 0;
	}
	message_vision("$N小心翼翼地把$n盖旋转开．．．一阵药香飘出。\n", me, ob);
	item = new("/d/wolfmount/npc/obj/ginyao");
	if(objectp(item)){
		item->move(ob);
		item->set("base_value",0);
	} 
    	set("long", "一个白中透出绿色的小玉瓶，瓶盖已经被打开。\n");
	set("is_closed",0);
    	return 1;
}

