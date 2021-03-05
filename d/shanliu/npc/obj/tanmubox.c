#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(YEL"檀木盒"NOR, ({ "tanmubox"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("value", 0);
                set("long",
"一个很平常的檀木盒，没有上锁，似乎轻轻一用力就可以打开盖子。 \n"NOR);
        }
	::init_item();
}
void init()
{
	if(this_player()==environment())
	{
		add_action("do_open","open");
	}
}

int do_open(string arg)
{
	object	me, ob;
    if(  arg != "tanmubox")
        return 0;
	me = this_player();
	ob = this_object();
	message_vision("$N将$n打开\n", me, ob);
	message_vision("只见盒子里分文皆无，就有一张纸签： 
这是一张破旧的纸签，上面潦草地写道： 
        若无诚信，何以济世？\n ",me);
	set("open",1);
	set("long","一个打开的檀木盒,盒子里分文皆无，就有一张纸签： 
这是一张破旧的纸签，上面潦草地写道： 
        若无诚信，何以济世？ 
\n");
	if (me==query("送东西人"))
	{
		me->set("山流/失败",time());
		me->delete("入山流/取回盟册");
		me->delete("入山流/治愈麻风");
		me->delete_temp("入山流/送东西");
	}
	remove_action("do_open","open");
    return 1;
}

