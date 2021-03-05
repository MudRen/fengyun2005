
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("铁盒", ({ "box", "iron box"}) );
        set_weight(300);
        set_max_encumbrance(800);
        if (clonep())
           	set_default_object(__FILE__);
        else {
		set("unit", "个");
		set("long", "一个生满铁锈的铁盒。你可以试着把它打开(open)\n");
		set("no_drop", 1);
		set("value", 1);
        set("prep", "in");
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
	object		me, ob, item;
	int		kar;
	
	me = this_player();
	ob = this_object();
        if (me->is_ghost())
        	return notify_fail("鬼魂无法触动机关。\n");
        if( !arg || arg != "box" )
        	return notify_fail("你要打开什么？\n");
        if(ob->query_temp("marks/opened")) return 0;
		message_vision("$N小心地想要把$n打开．．．。\n", me, ob);
		kar = me->query_kar();
		if(random(kar) < 11) { 
		message_vision(HIR "只听到＂咯＂的一声，接着从$n里射出几只黑色的银针，正打在$N的脸上！\n"NOR, me, ob);
		me->receive_wound("kee",20);
		me->set_temp("last_damage_from","误触机关，中无影毒身亡。\n");
		me->apply_condition("no_shadow", 10);
		message_vision(HIR "$N中了针上的毒！\n"NOR, me);
	}
	else {
        	message_vision("$N终于把$n打开了。\n", me, ob);
            set("long", "一个锈迹斑斑的铁盒，盒盖已经被打开了。\n");
            switch (random(2)) {
                case 0:
                      item = new(__DIR__"jade");
                      item->move(ob);
                   	break; 
                case 1:
                      item = new(BOOKS"dodge_75");
                      item->move(ob);
                  	break;
                }
			ob->set_temp("marks/opened",1);
	}
        return 1;
}

