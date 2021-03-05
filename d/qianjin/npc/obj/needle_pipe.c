#include <ansi.h>  
#include <combat.h>
inherit ITEM;
void create()
{
        set_name(GRN"漆黑的铜管"NOR, ({ "needle pipe"}) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long","这是一个小小的黑色圆筒。\n"	);
                set("material", "gold");
                
        }

        ::init_item();

}
void init()
{
	add_action("do_shoot","shoot");
}

int do_shoot(string arg)
{
	object ob;
	object me;
	int dp;
	int damage;
	
	if (!arg) return 
		notify_fail("你要打谁？\n");
    	
    	if (query("used")) 
    		return notify_fail(this_object()->name()+"只能用一次。\n");
	
	me=this_player();
    	if (userp(me))
    		return notify_fail(this_object()->name()+"已经用完了。\n");
    	    	
    	ob=present(arg,environment(me));
    	if (!objectp(ob) || !living(ob)) 
    		return notify_fail(this_object()->name()+"只能对活的生物使用。\n");
      		
    	message_vision("牛毛般的针雨打在$N身上。\n",ob);
    	damage = 2000;
    	ob->receive_wound("kee",damage,me);    
    	ob->receive_wound("gin",damage,me);    
    	ob->receive_wound("sen",damage,me);    
    	COMBAT_D->report_status(ob);                                             	
    	return 1;
}
