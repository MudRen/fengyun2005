#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("经书盒", ({ "jingshuhe"}) );
        set_weight(300);
        set_max_encumbrance(80000);
	set("unit", "个");
	set("long", "一个用上好红木作的木盒，刚好可以放经书。\n");
	set("closed", 1);
	set("value", 200);
}

int is_container() {return 1;}

void init()
{
	if(this_player()==environment())
		 add_action("do_open","open");
}
int do_open(string arg)
{
	object		me, ob;
        if( !arg || arg != query("id") )
                return notify_fail("你要打开什么？\n");
	me = this_player();
	ob = this_object();
	message_vision("$N“嘎吱”一声，将$n打开了。。。\n", me, ob);
		ob->set("closed",0);
        return 1;
}

int is_closed()
{
	return ((int) this_object()->query("closed"));
}
