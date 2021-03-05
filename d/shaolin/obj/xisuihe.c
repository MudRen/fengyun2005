#include <ansi.h>
inherit ITEM;
void create()
{
//      object book;
        set_name("经盒", ({ "xisuihe"}) );
        set_weight(300);
        set_max_encumbrance(80000);
	set("unit", "个");
	set("long", "一个用上好红木作的木盒，上面用梵文写着[洗髓]二子。\n");
	set("closed", 1);
	set("value", 0);
	set("xisui", 1);
}

int is_container() {return 1;}

void init()
{
	if(this_player()==environment())
		 add_action("do_open","open");
}

int do_open(string arg)
{
	object	book, me, ob;
     if( !arg || arg != query("id") )
                return notify_fail("你要打开什么？\n");
	me = this_player();
	ob = this_object();
	if (me->query("force_factor")<60)
		return notify_fail("你费尽九牛二虎之力，盒盖纹丝不动。\n");
	message_vision("$N“嘎吱”一声，将$n打开。。。\n", me, ob);
	if (ob->query("xisui")) {
		message_vision(HIR"洗髓经！！！$N的眼睛一下子红了.\n"NOR,me);
		message_vision("$N一伸手,小心翼翼地将洗髓经取出藏在怀里.\n"NOR,me);
		seteuid(getuid());
		book=new(BOOKS"skill/xisui_100");
		book->move(me);	
		ob->set("xisui",0);    
	} else
		message_vision("盒子里空空的什么也没有,唉,白忙乎了.\n",me);
	ob->set("closed",0);
	me->perform_busy(1);
        return 1;
}

int is_closed()
{
	return ((int) this_object()->query("closed"));
}