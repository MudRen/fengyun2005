inherit ITEM;
#include <ansi.h>

void create()
{
    set_name(HIM"紫水晶"NOR , ({ "purple crystal","crystal"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "粒");
        set("long", "一粒散发出幽幽紫光的水晶石。\n");
        set("value", 400);
        set("lore",1);
	}
	::init_item();
}


void init()
{
  if(this_player()==environment())
  add_action("do_combine","combine");
}

int do_combine()
{
	int i,red=0,blue=0,yellow=0,green=0;
	object jade,me, *inv;
	object redi,bluei,yellowi,greeni;
	me = this_player();
	inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++)
                {
			if(inv[i]->query("name") == HIY"黄水晶"NOR) {yellow = 1; yellowi = inv[i];}
                        if(inv[i]->query("name") == HIG"绿水晶"NOR) {green = 1; greeni = inv[i];}
                        if(inv[i]->query("name") == HIR"红水晶"NOR) {red = 1; redi = inv[i];}
                        if(inv[i]->query("name") == HIB"蓝水晶"NOR) {blue = 1;  bluei = inv[i];}
		}
	if( yellow && blue && red && green )
	{
			destruct(redi);
	        destruct(yellowi);
	        destruct(greeni);
	        destruct(bluei);
			jade = new(BOOKS"skill/fanwen_50");
			jade->move(me);
			message_vision(HIY"$N手里的五块水晶石忽然聚集在一起，放出夺目的光华。。。。\n"NOR,this_player());
		
			REWARD_D->riddle_done( this_player(),"五色水晶", 50, 1);
			destruct(this_object());
	
	}
	else 
		message_vision("$N把手里的几块水晶石摆弄了几下．\n",this_player());
	return 1;
}

