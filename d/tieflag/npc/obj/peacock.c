#include <ansi.h>  
#include <combat.h>
inherit ITEM;
void create()
{
        set_name(GRN"孔雀翎"NOR, ({ "peacock tail","peacock" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long","这是一个金黄的圆筒，看起来很平凡，但这是天下最神秘的暗器。\n");
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
	if (!arg) return notify_fail("你要打谁？\n");
    	if (query("used")) return notify_fail(this_object()->name()+"只能用一次。\n");
	me=this_player();
    
    if (me->query_busy())
    	return notify_fail("你现在正忙。\n");
    	
   	if ( me->query("combat_exp") < 50000 )
		return notify_fail("你经验太差了，没有办法掌握" + this_object()->name()+"的发射秘诀。\n");
   
   	if( environment(me)->query("no_fight") ||
        	environment(me)->query("no_magic") ||
        	environment(me)->query("no_spells"))
			return notify_fail("在这不可偷袭！\n");
    	ob=present(arg,environment(me));
   
   	if (!objectp(ob) || !living(ob)) return notify_fail(this_object()->name()+"只能对活的生物使用。\n");
    
   	if (ob==me)
		return notify_fail("射自己？\n");
		
    if (userp(me))
	if (!COMBAT_D->legitimate_kill(me, ob)) {
		if (stringp(ob->query("NO_KILL")))
			return notify_fail(ob->query("NO_KILL"));
		if (stringp(ob->query("NO_PK")))
			return notify_fail(ob->query("NO_PK"));	
		else 
			return notify_fail("你无法攻击此人。\n");
	}
    
   	if (!me->is_fighting(ob)) 
    		message_vision("$N阴笑一声，从怀里摸出一件东西．．\n",me);
    	message_vision("$N对着$n举起了手中的"+this_object()->name()+"...\n",me,ob);
    	message_vision(HIC "从圆筒中放出一片光芒，辉煌灿烂，就如那美丽的孔雀翎毛...\n"NOR,me);
    	if (ob->query_skill("perception")/10>random(5) || ob->query("no_shot")) 
    		message_vision("$N听风辨形，居然在间不容发之际躲过了这漫天针雨！\n",ob);
    	else {
		    message_vision("光芒打在$N身上，一闪就消失了。\n",ob);
		    ob->receive_damage("kee", 0, me);
			dp = COMBAT_D->skill_power(ob, SKILL_USAGE_DODGE);
		    damage=200000-dp;
		    damage/=100;
		    if (damage<0) damage=0;
		    ob->receive_wound("kee",damage,me);    
		    ob->receive_wound("gin",damage,me);    
		    ob->receive_wound("sen",damage,me);    
    	}
    	COMBAT_D->report_status(ob);                                         
    	ob->kill_ob(me); 
    	set("used",1);
    	me->start_busy(3);
    	return 1;
}
