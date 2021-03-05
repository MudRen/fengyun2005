#include <combat.h>
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"五花神弓"NOR, ({ "iron-bow" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把由万年玄铁锻就的五花神弓，传说中的五花神箭只有和这把\n神弓配合（install）才尽显神奇威力。 \n");
		set("installed", 0);
	}
}

void init()
{
	if(this_player()==environment())
	add_action("do_install","install");
	add_action("do_shoot","shoot");
}

int do_install()
{
	int i,arrower=0;
	int arrow_num;
	object me, *inv;
	object arrow;
	me = this_player();
		
	inv = all_inventory(me);
    for(i=0; i<sizeof(inv); i++)
        {
		if(inv[i]->query("name") == RED"五"BLU"花"HIG"神箭"NOR) 
		{
			arrower = 1; 
			arrow = inv[i];
			arrow_num = arrow->query_amount();
		}
        }
	if( arrower )
	{
	    destruct(arrow);
        message_vision(CYN "$N在"+this_object()->name()+CYN"上搭上一支五花神箭。\n"NOR,this_player());
		set("installed",arrow_num);
		return 1;
	}
	else 
		{
			if (query("installed")>0)
				tell_object(me,"所有的箭都安上了。\n");
			else
				message_vision("$N试着拉了拉"+this_object()->name()+"，但是没有箭。\n",this_player());
		}
	return 1;
}

int do_shoot(string arg)
{
	object ob;
	object me;
	int dpme,dpob;
	int damage;
	int after_shoot;
	if (!arg) return notify_fail("你要射谁？\n");
	
	if (query("nouse"))  
		return notify_fail(name()+"已经断了，没用啦。\n");
	
	if ((int) query("installed") <= 0)  
		return notify_fail(this_object()->name()+"不安装箭是没有办法发射的。\n");
	me = this_player();
//	if (me->is_busy()) return notify_fail("你现在忙得很，没机会开弓！\n");
	if (time()<query("delay")+6) return notify_fail("弓弦刚收回，尚未再次拉开。\n");
   	if ( me->query_str() < 30 )
        	return notify_fail("你手无缚鸡之力，何以能拉开这" + this_object()->name()+"。\n");
	if( environment(me)->query("no_fight") ||environment(me)->query("no_magic") || 	environment(me)->query("no_spells"))
		return notify_fail("在这不可偷袭！\n");
	ob=present(arg,environment(me));
	if (!objectp(ob) || !living(ob)) 
		return notify_fail(this_object()->name()+"只能对活的生物使用。\n");
	
	if (ob==me)
		return notify_fail("射自己？你的手臂不够长。\n");

	if (userp(me))
	if (!COMBAT_D->legitimate_kill(me, ob)) {
		if (stringp(ob->query("NO_KILL")))
			return notify_fail(ob->query("NO_KILL"));
		if (stringp(ob->query("NO_PK")))
			return notify_fail(ob->query("NO_PK"));	
		else 
			return notify_fail("你无法攻击此人。\n");
	}		
    
    add("used",1);
            		
    message_vision(CYN"\n$N长笑声中，奋起神力，将"+this_object()->name()+CYN"拉至满月。。。\n\n",me);
    message_vision(CYN"\n$N大喝一声："+RED"五～"BLU"花～"HIG"神～箭～～"NOR+"．．．\n",me);
    
    if (query("used") > random(5)+3) {
	    message_vision(WHT"\n"+query("name")+"啪地一声断了。\n"NOR,me);
	    set("nouse",1);
	    set("name",YEL"断了的五花神弓"NOR);
	 	return 1;
	 }
	    
    message_vision(HIR"\n从"+this_object()->name()+HIR"中射出一片箭光，箭头幻化五花，闪电般飞向$N。。。\n\n",ob);
	
	dpob=COMBAT_D->skill_power(ob, SKILL_USAGE_DODGE);
	dpme=COMBAT_D->skill_power(me, SKILL_USAGE_DODGE);
	
	damage= 200*me->query("agi")/ob->query("agi");;
	if (damage > 5000) damage = 5000;
    damage=damage*2;  //add by ldb 方便守经楼 
	if( random(me->query("combat_exp")) > (int)ob->query("combat_exp")/5 )
	{
        	message_vision(HIR"$N只觉得眼前箭光闪烁，一时之间竟无从躲闪。\n"NOR,ob);
        	message_vision(HIR"\n箭光闪电般射入$N的身体．．．\n" NOR,ob);
			ob->receive_wound("kee",damage,me);
			COMBAT_D->report_status(ob);
			me->perform_busy(5);
	}
	else
	{
		message_vision(HIR"漫天箭雨中，$N似乎看到一丝破绽．．．\n"NOR,ob);
		message_vision(HIW"$N就地一滚，险险躲过"+RED"五"BLU"花"HIG"神箭"HIW+"的袭击．．．\n"NOR,ob);
		me->perform_busy(3);
	}
	ob->kill_ob(me);
	after_shoot = query("installed")>0? query("installed") - 1:0 ;
	set("installed",after_shoot);
	set("delay",time());
	return 1;
}



