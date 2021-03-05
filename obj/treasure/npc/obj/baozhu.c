#include <ansi.h>  
#include <combat.h>
inherit ITEM;
void create()
{
        set_name( HIR "爆竹" NOR, ({ "bao zhu" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
        set("long",YEL"古时在节日或喜庆日，用火烧竹，毕剥发声，以驱除山鬼\n瘟神，谓之：爆竹。\n"NOR);
                //set("material", "silver");
                set("no_split", 1);
                set("desc_ext","使用(use)");
                set("value",600);
        }
        ::init_item();
}

void init()
{
	add_action("do_shoot","use");
}

int do_shoot(string arg)
{
	object ob;
	object me;
	string where;
	//int dp;
	int damage;
	if (!arg) return notify_fail("你想炸什么？\n");
	if (query("used")) return notify_fail(this_object()->name()+"已经用完了。\n");
	me=this_player();
    	if ( me->query("combat_exp") < 100000 )
		return notify_fail("你经验太差了，没有办法掌握" + this_object()->name()+"的秘诀。\n");
    	if( environment(me)->query("no_fight") || environment(me)->query("no_magic") || environment(me)->query("no_spells"))
		return notify_fail("在这不可偷袭！\n");
    	ob=present(arg,environment(me));
    	if (!objectp(ob) || !living(ob)) 
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
	
	if (arg != "monster nian")
		return notify_fail("只能用作对付年兽。\n");
		
	if (ob->query("kee") < 8000000 || ob->query("gin") < 8000000 || ob->query("sen") < 8000000)
		return notify_fail("这只年兽已经胆怯了。\n");
		
    	message_vision(HIW"$N点燃了手中的"+this_object()->name()+HIW"顺势朝目标扔了过去。。。\n"NOR,me);
    	if (ob!=me)
    		message_vision(HIW"$N看着扔出的"+this_object()->name()+HIW"，爆裂后产生一道红光。。。。。\n",me,ob);
    	else {
    		message("vision",HIW""+me->name()+HIW"对着自己扔出的"+this_object()->name()+HIW"，爆裂后产生一道红光。。。。。\n"NOR,environment(me),me);
    		tell_object(me,HIW"你对着自己扔出的"+this_object()->name()+HIW"，爆裂后产生一道红光。。。。。\n"NOR);
    	}
    	    
    	where=file_name(environment(ob));
    	if (!userp(ob) && where[0..6]=="/d/cave") {
    		message_vision(YEL"$N大笑道:这点雕虫小技也到我青龙会地盘上来卖弄,大爷见得多了！\n"NOR,ob);
    		message_vision(YEL"$N听风辨形，居然在间不容发之际躲过了这漫天红叶！\n\n"NOR,ob);
    	} else {		
    		if (ob->query_skill("perception")/10>random(22) || ob->query("no_shot")) {
    			if (me!=ob) message_vision("$N听风辨形，居然在间不容发之际躲过了这漫天红叶！\n\n",ob);
    			else {
    				message("vision",me->name()+"听风辨形，居然在间不容发之际躲过了这漫天红叶！\n\n",environment(me),me);
    				tell_object(me,"你听风辨形，居然在间不容发之际躲过了这漫天红叶！\n\n");
    			}	
    		}else {
    			message_vision(HIR"红光"HIW"在$N"HIW"身上绽开。\n\n"NOR,ob);
    			//dp=COMBAT_D->skill_power(ob, SKILL_USAGE_DODGE);
    			damage=8975000;
    			//damage/=100;
    			if (damage<0) damage=0;
    			ob->receive_wound("kee",damage,me);    
    			ob->receive_wound("gin",damage,me);    
    			ob->receive_wound("sen",damage,me);    
		}	
    	}	
    	COMBAT_D->report_status(ob);                                         
    	if (ob!=me)	ob->kill_ob(me); 
    	set("used",1);
    	if (me->query_busy()<3) me->start_busy(3);
    	destruct(this_object());
    	return 1;
}