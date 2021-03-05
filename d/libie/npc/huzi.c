#include <ansi.h>
inherit NPC;

void create()
{       set_name("小虎子", ({ "xiao huzi", "huzi" }) );
        set("long",  "
他是一个年纪很轻的捕快，但已经浑身是血，奄奄一息了，不过似乎还
可以救治（ｈｅａｌ），你真希望他在咽气之前能告诉你谁是凶手。\n");

	set("attitude", "heroism");
	set("age", 17);
	set("gin", -1);
        set("kee", -1);
        set("sen", -1);
        set("eff_gin", 1);
        set("eff_kee", 1);
        set("eff_sen", 1);
        set("title", "捕快");
        set("disable_type", HIR "<昏迷不醒>"NOR);
        set("combat_exp", random(10000));

        set_skill("unarmed", 70+random(100));
        set_skill("staff", 70+random(100));
        set_skill("parry", 70+random(100));
        set_skill("dodge", 70+random(100));
        set_skill("move", 100+random(100));

        set_temp("apply/attack", 70);
	set_temp("apply/dodge", 70);
	set_temp("apply/parry", 70);
        set_temp("apply/damage", random(100));
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);
        set("chat_chance", 1);

        setup();
	this_object()->disable_player(" <昏迷不醒>");
	this_object()->set_temp("is_unconcious",1);
	set_temp("block_msg/all", 1);
	COMBAT_D->announce(this_object(), "unconcious");

}

void init()
{
    	::init();
    	call_out("die", 60, this_object());
}
 

void heart_beat()
{
	object ob,me,room;
	
	room=environment();
	ob = this_object();
	me=ob->query("救人者");
	if(living(ob))
	if(present(me,room))
	{	
		if(!me->query_temp("libie/离别钩_救小虎子"))
        	{
               		me->set_temp("libie/离别钩_救小虎子", 1);
                	message("vision",RED"\n浑身浴血的小虎子哇的喷出一大口鲜血，大喝道：郑大哥快走。。 大哥快走啊！\n言罢小虎子又昏了过去。\n"NOR, me);
        		ob->disable_player(" <昏迷不醒>");
        		ob->set_temp("is_unconcious",1);
        	}
        	else
        	{
                        message_vision(RED"小虎子悠悠醒转，又吐出口淤血，似乎清醒了些。\n"NOR,me);
                        me->delete_temp("libie/离别钩_救小虎子");
                        if (REWARD_D->riddle_check(me,"离别")<2)
                        	message_vision(RED"小虎子紧握住$N的手叫道：你、你、你杀了我郑大哥，我跟你拼了！
话音未落，便又倒了下去。\n"NOR,me);
						else
						{
							tell_object(me, RED"小虎子紧握住你的手挣扎道：正约、正约。。除三！\n"NOR);
			                me->set("libie/huzi",1);	// perma here so ppl won't have to keep using lotus
			            }	
			        	ob->die();
        	}
	}
	else 
		ob->unconcious();
	::heart_beat();
}
