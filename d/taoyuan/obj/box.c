
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("铁盒", ({"iron box", "box"}) );
    set_weight(300);
    set_max_encumbrance(800);
	set("unit", "个");
	set("long", "一个生满铁锈的铁盒。你可以试着把它打开(open)\n");
	set("closed", 1);
	set("poison", 2);
	set("value", 200);
    ::init_item();
}

int is_container() {return 1;}

void init()
{
	if(this_player()==environment())
		 add_action("do_open","open");
		 add_action("do_close","close");
}

int do_close(string arg)
{
	object		me, ob;

	me = this_player();
	ob = this_object();
        if( !arg || arg != "box" )
                return notify_fail("你要关上什么？\n");
       	message_vision("$N把$n盖关上了。\n", me, ob);
	ob->set("closed",1);
	return 1;
}

int do_open(string arg)
{
	object		me, ob;
	int		kar;
	
    if( !arg || arg != "box" && arg != "iron box")
        return notify_fail("你要打开什么？\n");
	me = this_player();
	ob = this_object();
	if(!query("closed")){
		return notify_fail("铁盒已经被打开了。\n");
	}
	message_vision("$N小心地想要把$n打开．．．。\n", me, ob);
	kar = me->query("kar");
	if( kar < 29 && query("poison")) { 
		message_vision(HIR "只听到＂咯＂的一声，接着从$n里射出几只蓝色的银针，正打在$N的脸上！\n"NOR, me, ob);
		me->apply_condition("no_shadow", 10);
		message_vision(HIR "$N中了针上的毒！\n"NOR, me);
		add("poison", -1);
	}else {
		ob->set("closed",0);
       	message_vision("$N终于把$n打开了。\n", me, ob);
	}
        return 1;
}

int is_closed()
{
	return ((int) this_object()->query("closed"));
}
