#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("红木大柜", ({ "mugui"}) );
        set_weight(300);
        set_max_encumbrance(80000);
	set("unit", "个");
	set("long", "一个用上好红木作的木柜。\n");
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
        if( !arg || arg != "mugui" ) return 0;
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
