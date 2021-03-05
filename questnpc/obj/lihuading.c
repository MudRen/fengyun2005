#include <ansi.h>  
#include <combat.h>
inherit ITEM;
void create()
{
        set_name( HIW "天绝地灭透骨针" NOR, ({ "needle box","box" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long","一个金光灿灿的小圆筒\n");
                set("material", "silver");
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
	string where;
	int dp;
	int damage;
	if (!arg) return notify_fail("你要打谁？\n");
//	if (query("used")) return notify_fail(this_object()->name()+"只能用一次\n");
	me=this_player();
	if(userp(me))
		return notify_fail("你不知道使用的方法，无法发射。\n");
    if ( me->query("combat_exp") < 50000 )
		return notify_fail("你经验太差了，没有办法掌握" + this_object()->name()+"的发射秘诀。\n");
    if( environment(me)->query("no_fight") ||
        environment(me)->query("no_magic") ||
        environment(me)->query("no_spells") 
	)
	return notify_fail("在这不可偷袭！\n");
    ob=present(arg,environment(me));
    if (!objectp(ob) || !living(ob)) return notify_fail(this_object()->name()+"只能对活的生物使用\n");
    if (!me->is_fighting(ob)) message_vision("$N阴笑一声，从怀里摸出一件东西．．\n",me);
    message_vision("$N对着$n举起了手中的"+this_object()->name()+"...\n",me,ob);
    message_vision(RED "从匣子中闪电般射出一片银光．．．...\n" NOR,me);
/*    
    where=file_name(environment(ob));
    if (!userp(ob) && where[0..6]=="/d/cave") {
    	message_vision(YEL"$N大笑道:这点雕虫小技也到我青龙会地盘上来卖弄,大爷见得多了！\n"NOR,ob);
    	message_vision(YEL"$N听风辨形，居然在间不容发之际躲过了这漫天针雨！\n"NOR,ob);
    } else {		
*/
    if (ob->query_skill("perception")/10>random(32)) 
    	message_vision("$N听风辨形，居然在间不容发之际躲过了这漫天针雨！\n",ob);
    else {
    message_vision("银光打在$N身上，一闪就消失了。\n",ob);
    ob->receive_damage("kee", 0, me);
	dp=COMBAT_D->skill_power(ob, SKILL_USAGE_DODGE);
    damage=800000-dp/3;
    damage/=100;
    if (damage<0) damage=0;
    ob->receive_wound("kee",damage,me);    
    ob->receive_wound("gin",damage,me);    
    ob->receive_wound("sen",damage,me);    
	}	
//    }	
    COMBAT_D->report_status(ob);                                         
    ob->kill_ob(me); 
  //  set("used",1);
//     me->start_busy(3);
    return 1;
}
