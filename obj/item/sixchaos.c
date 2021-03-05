#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(BLK"六阴拘魂阵"NOR, ({ "six-chaos hall" }) );
        set_weight(100);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "久已失传的奇门阵法，不知是何人布下。\n");
		set("no_reset",1);
		set("no_get",1);
		set("value",100);
		set("unit","个");
    }
	::init_item();
}

void init()
{       
        object ob,carrier;


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
	object room;
	room=find_object("/d/dark_fy/fysquare");
	if (!room)
		room=load_object("/d/dark_fy/fysquare");
    if(environment(ob)!=environment()) return 0;
	if(ob==environment()) return 0;
	message_vision(HIY"\n一道耀眼的黄色光芒突然笼罩住$N．．．\n\n"NOR,ob);
	ob->add_temp("block_msg/all",1);
	ob->move(room);
	ob->add_temp("block_msg/all",-1);
	tell_object(ob,HIY"黄色光芒渐渐退去，你似乎不曾移动过，然而．．．\n\n"NOR);
	return 1;
}

int do_drop(string arg)
{
	object skin;
	skin=present(arg,this_player());
	if(skin!=this_object()) return 0;
    set("not_ready_yet",1);
	this_object()->move(environment(this_player()));
    set("not_ready_yet",0);
	return 1;
}
