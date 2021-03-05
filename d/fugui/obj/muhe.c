inherit ITEM;
void create()
{
	set_name("木盒子", ({ "woodbox", "木盒子" }) );
	set_weight(500);        
	set_max_encumbrance(2000);	
	set("prep","on");        
	if( clonep() )                
		set_default_object(__FILE__);        
	else 
	{
		set("unit", "个");
		set("long", "这小木盒子满是灰尘，粘满了煤屑柴草，你似乎可以把它打开（ｏｐｅｎ）。\n");
		set("value", 100);
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
        if( !arg || arg != "woodbox" )
                return notify_fail("你要打开什么？\n");
	me = this_player();
	ob = this_object();
	message_vision("$N小心翼翼打开$n。\n", me, ob);
	ob->set("closed",0);
        return 1;
}

int is_closed()
{
	return ((int) this_object()->query("closed"));
}
