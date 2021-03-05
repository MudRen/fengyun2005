#include <ansi.h>
#include <combat.h>
inherit ITEM;

void create()
{
    set_name(MAG"五罗轻烟帕"NOR, ({ "handkerchief" }) );
	set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("material", "cloth");
		set("long", "一块约莫四尺见方的白缎手帕，四角上都绣著一朵红花。花红欲滴，每朵
花旁都衬著一张翠绿色的叶子，迎着微风，不住地抖动。\n");
		set("desc_ext","shaking 对方英语名字");
		}
   	::init_item();
}

void init()
{
	if(this_player()==environment())
	add_action("do_shake","shaking");
}

int do_shake(string arg)
{
	object ob;
	object me;
	string where;

	if (!arg) 
		return notify_fail("你想迷倒谁？\n"); 
	if (query("used")) 
		return notify_fail(this_object()->name()+"只能用一次。\n");
	me=this_player();
	
	if( environment(me)->query("no_fight") || environment(me)->query("no_magic") 
		|| environment(me)->query("no_spells"))
		return notify_fail("在这不可偷袭！\n");
		
	ob=present(arg,environment(me));
	if (!objectp(ob) || !living(ob)|| ob->query("race")=="元素" ) 
		return notify_fail(this_object()->name()+"只能对活的生物使用。\n");
	
	
	if (userp(me) && me!= ob)
	if (!COMBAT_D->legitimate_kill(me, ob)) {
		if (stringp(ob->query("NO_KILL")))
			return notify_fail(ob->query("NO_KILL"));
		if (stringp(ob->query("NO_PK")))
			return notify_fail(ob->query("NO_PK"));	
		else 
			return notify_fail("你无法攻击此人。\n");
	}
	
	
	if (ob!=me)
		message_vision(GRN"\n$N右手轻轻一扬，朝$n抖了抖手中的"+name()+GRN"，一丝若有若无的幽香拂面而过。。\n"NOR,me,ob);
        else {
        	message("vision",GRN"\n"+me->name()+GRN"右手轻轻一扬，朝自己抖了抖手中的"+name()+GRN"，一丝若有若无的幽香拂面而过。。\n"NOR,environment(me),me);
        	tell_object(me,GRN"\n你右手轻轻一扬，朝自己抖了抖手中的"+name()+GRN"，一丝若有若无的幽香拂面而过。。\n");
        }
        
    where=file_name(environment(ob));
    if (!userp(ob) && where[0..6]=="/d/cave") {
    	 message_vision(YEL"$N大笑道:这点雕虫小技也到我青龙会地盘上来卖弄,大爷见得多了！\n"NOR,ob);
    	 message_vision(HIR"\n$N对着$n大喝一声：下流的东西，不知羞耻...\n"NOR,ob,me);
    	 ob->kill_ob(me);
    } else {          
		if (ob == me || random( me->query("cps")+me->query("int")) > random (ob->query("cps"))+random(ob->query("int"))
	    	&& random(me->query("combat_exp")*2)> ob->query("combat_exp")
	    	&& !ob->query("big_boss")  && !ob->query("real_boss") &&!ob->query("boss"))		{
	        	if (ob!=me)
	        		message_vision(MAG "\n\n$N只觉得眼前五彩斑斓，身子微颤，转了几个圈子，倒在地上。。\n"NOR,ob);
				else {
					message("vision",MAG "\n\n"+me->name()+MAG"只觉得眼前五彩斑斓，身子微颤，转了几个圈子，倒在地上。。\n"NOR,environment(me),me);
					tell_object(me,MAG "\n\n你只觉得眼前五彩斑斓，身子微颤，转了几个圈子，倒在地上。。\n"NOR);
				}
				ob->unconcious();
			}else	{
		        message_vision(CYN"\n\n$N急忙以手遮鼻，屏住呼吸，不去闻那香气。。\n"NOR,ob);
		        message_vision(HIR"\n$N对着$n大喝一声：下流的东西，不知羞耻。。\n"NOR,ob,me);
				ob->kill_ob(me);
			}
		}
	set("used",1);
	if (me->query_busy()<3) me->start_busy(3);
	return 1;
}
