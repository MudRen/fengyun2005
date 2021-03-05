#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("香蕉皮", ({ "banana skin", "xiang jiao pi" }) );
        set_weight(100);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "一张很奇特香蕉皮，似乎有很多层。香蕉皮外黄内滑。\n");
        set("unit", "个"); 
        set("value", 0);
    }
	::init_item();
}
void init()
{       
        object ob,carrier;

        ::init();
        carrier=environment();
       if (query("not_ready_yet")) return;
        if( interactive(ob = this_player()) )
        
         {
                remove_call_out("sliding");
                call_out("sliding", 1, ob);
        }

        add_action("do_drop","drop");
        
}

int sliding(object ob)
{
        if(environment(ob)!=environment()) return 0;
	if(ob==environment()) return 0;
	message_vision(HIY"$N忽然觉得有些不妥。。。似乎踩着了什么东西似的。\n"NOR,ob);
	message_vision(HIY"$N一下子跌了个嘴啃泥。。。真可怜哪。。。\n"NOR,ob);
	ob->start_busy(2);
	ob->receive_damage("sen", 100);
	return 1;
}

int do_drop(string arg)
{
	object skin;
	skin=present(arg,this_player());
	if(skin!=this_object()) return 0;
	tell_object(this_player(),"你趁人不注意，偷偷的将香蕉皮丢在了地上。。。\n");
	message("vision",this_player()->query("name")+"鬼鬼祟祟的将什么东西丢在了地上。\n",environment(this_player()),this_player());
    set("not_ready_yet",1);
	this_object()->move(environment(this_player()));
    set("not_ready_yet",0);
	return 1;
}
