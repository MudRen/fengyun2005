#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIW"冰魄寒霜剑"NOR, ({ "ice sword","sword" }) );
        set_weight(50);
        if( clonep() )
            set_default_object(__FILE__);
        else 
        {
            set("unit", "把");
            set("long", "一把晶莹醍透的宝剑，通体洁白，竟是由万年玄冰制成。\n");
            set("material", "ice");
        	set("wield_msg", "寒光一闪，一把$n赫然擎在$N手中，四下顿时如入冰窟。。\n");
        	set("unwield_msg", "$N手一扬，$n已插在背后。\n");
        }
        ::init_sword(30);
//      call_out("check_status",1);
}

/*
int check_status()
{
	object me;
	me=environment();
    	if(	objectp(me) && living(me)
    		&& !userp(me)) {
        	call_out("check_status",10+random(20));
		return 1;
	}
	call_out("dissolve",1);
	return 1;
}

//	This sword can't be used by players, otherwise it could cause serious perma-frozen bug.--- silencer
mixed hit_ob(object me,object victim)
{	string msg;

    	if(!userp(me) && !random(5)&&(!victim->query_temp("is_unconcious")))
	{
		msg=HIW"$n忽然觉得全身如坠入冰窟，竟一动都不能动了！！\n"NOR;
       		victim->set_temp("disable_inputs",1);
	        victim->set("disable_type",HIW "<冻僵中>"NOR);
		victim->set_temp("is_unconcious",1);
		call_out("remove_frozen",10,victim);
		return msg;
	}
	return 0;
}

int dissolve()
{
	object holder,room;
	
	if(!objectp(holder=environment())) {
		destruct(this_object());
		return 1;
	}
	
	if(userp(holder))
		room=environment(holder);
	else room=holder;
	message("vision",this_object()->query("name")+"渐渐的化成了一滩冰水。\n",room);
	destruct(this_object());
//	message("vision"," i am dead or i am not。\n",room);
	return 1;
}
	
void remove_frozen(object me)
{
	me->delete("disable_type");
    	me->delete_temp("disable_inputs");
    	me->delete_temp("is_unconcious");
    	if(!me->is_ghost())
        message_vision(HIR "\n\n$N发出一声怒吼，双臂一振，将周身凝聚的冰块震得粉碎！！\n\n"NOR, me);
}
*/