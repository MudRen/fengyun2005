inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIY"描金箱子"NOR, ({ "gold box", "box","描金箱子" }) );
	set_weight(5000);        
	set_max_encumbrance(2000);	
	set("prep","on");        
	if( clonep() )                
		set_default_object(__FILE__);        
	else 
	{
		set("unit", "个");
		set("long", "这个描金箱子雕龙画壁，镶金嵌玉，似乎可以打开（ｏｐｅｎ）。\n");
		set("value", 5000);
		set("closed", 1);
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
		 add_action("do_open","open");
}
int do_open(string arg)
{
	object	me, ob;
        if( !arg || arg != "gold box"&& arg != "box"&& arg != "描金箱子" )
                return notify_fail("你要打开什么？\n");
	me = this_player();
	ob = this_object();
	message_vision("$N轻轻打开$n。\n", me, ob);
	ob->set("closed",0);
        return 1;
}

int is_closed()
{
	return ((int) this_object()->query("closed"));
}
