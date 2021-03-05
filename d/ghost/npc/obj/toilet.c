#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("金漆马桶", ({ "toilet", "金漆马桶"}) );
        set_weight(300);
        set("no_get", 1);
        set("no_shown", 1);
        set_max_encumbrance(800000);
	set("unit", "个");
	set("long", "一个女孩子用的金漆马桶。\n");
	set("closed", 1);
	set("value", 2000);
        set("objects", ([
                AREA_GHOST"npc/butterfly": 1,
        ]));

	::init_item();
}

int is_container() {return 1;}

void init()
{
	 add_action("do_open","open");
	 add_action("do_close","close");
}

int do_close(string arg)
{
	object		me, ob;

	me = this_player();
	ob = this_object();
        if( !arg || arg != "toilet" )
                return notify_fail("你要关上什么？\n");
       	message_vision("$N把$n盖关上了。\n", me, ob);
	ob->set("closed",1);
	return 1;
}

int do_open(string arg)
{
	object		me, ob;
	int		kar;
	
        if( !arg || arg != "toilet" )
                return notify_fail("你要打开什么？\n");
	me = this_player();
	ob = this_object();
	ob->set("closed",0);
       	message_vision("$N将$n盖打开。\n", me, ob);
        return 1;
}

int is_closed()
{
	return ((int) this_object()->query("closed"));
}
