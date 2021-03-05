#include <ansi.h>  
#include <combat.h>
inherit ITEM;
void create()
{
        set_name( HIW "暴雨梨花针" NOR, ({ "needle box","box" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
		set("long", @LONG
这银匣子七寸长，叁寸厚，制作得极为精致，匣子的
一旁排列着叁行极细的针孔，每行九孔。

匣子上面刻着四行小篆：

出必见血
空回不祥
急中之急
暗器之王

右边不知什么人新近刻上了下面几行：

驰骋江湖横纵，
怎奈风翻云涌。
暴雨落梨花，
魂去林寒露重。
谁送、谁送、
生死功名一梦。

似乎是一首《如梦令》。
LONG);
                set("material", "silver");
                set("no_split", 1);
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
	if (query("used")) return notify_fail(this_object()->name()+"已经用完了。\n");
	me=this_player();
    	if ( me->query("combat_exp") < 50000 )
		return notify_fail("你经验太差了，没有办法掌握" + this_object()->name()+"的发射秘诀。\n");
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
	
    	message_vision(BLU"$N阴笑一声，从怀里摸出一件东西。。\n"NOR,me);
    	if (ob!=me)
    		message_vision(HIW"$N对着$n举起了手中的暴雨梨花针，从匣子中闪电般射出一片银光。。。。。\n",me,ob);
    	else {
    		message("vision",HIW""+me->name()+HIW"对着自己举起了手中的暴雨梨花针，从匣子中闪电般射出一片银光。。。。。\n"NOR,environment(me),me);
    		tell_object(me,HIW"你对着自己举起了手中的暴雨梨花针，从匣子中闪电般射出一片银光。。。。。\n"NOR);
    	}
    	    
    	where=file_name(environment(ob));
    	if (!userp(ob) && where[0..6]=="/d/cave") {
    		message_vision(YEL"$N大笑道:这点雕虫小技也到我青龙会地盘上来卖弄,大爷见得多了！\n"NOR,ob);
    		message_vision(YEL"$N听风辨形，居然在间不容发之际躲过了这漫天针雨！\n\n"NOR,ob);
    	} else {		
    		if (ob->query_skill("perception")/10>random(22) || ob->query("no_shot")) {
    			if (me!=ob) message_vision("$N听风辨形，居然在间不容发之际躲过了这漫天针雨！\n\n",ob);
    			else {
    				message("vision",me->name()+"听风辨形，居然在间不容发之际躲过了这漫天针雨！\n\n",environment(me),me);
    				tell_object(me,"你听风辨形，居然在间不容发之际躲过了这漫天针雨！\n\n");
    			}	
    		}else {
    			message_vision(HIR"银光打在$N身上，一闪就消失了。\n\n"NOR,ob);
    			dp=COMBAT_D->skill_power(ob, SKILL_USAGE_DODGE);
    		        damage=300000-dp; 
    			damage/=100;
    			damage=damage*2;  //add by ldb 方便守经楼 
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
    	return 1;
}
