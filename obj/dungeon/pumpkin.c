#include <ansi.h>
inherit NPC;

void create()
{
        set_name("南瓜精", ({ "pumpkin gnome","gnome" }) );
        set("race", "野兽");
        set("age", 0);
        set("long", "一个圆圆的，硬邦邦的大南瓜\n");
        set("limbs", ({ "挂藤", "左侧", "右侧" }) );
        set("verbs", ({ "bite" }) );
        set_skill("dodge", 1000);
		set("combat_exp", 3000);
    	set("chat_chance",100);
    	set("chat_msg",({
		(: random_move() :),
    	}) );  
		set("arrive_msg", "摇摇晃晃地滚了过来。");
		set("leave_msg", "骨碌骨碌地滚开了。");
        setup();
}


void die()
{
	object ob=new("/d/death/npc/obj/pumpkin");
	int n;
	object owner;
	
	owner = query("ol");
	
	if (owner)
	{
		owner->add_temp("annie_quest/halloween_done",1);
		if (owner->query_temp("annie_quest/halloween")
			-owner->query_temp("annie_quest/halloween_done")>0) {
			n = owner->query_temp("annie_quest/halloween")- owner->query_temp("annie_quest/halloween_done");			
			owner->set("quest/short", CYN"消灭所有南瓜精，还剩下"+ n +"个"NOR);
		
		}
		else {
			owner->set("quest/short", CYN"回去向郭大妈报告结果(end)"NOR);
			owner->set("quest/duration",300);
			owner->set("quest_time",time());
		}
	}

	ob->set("value",0);
	ob->move(environment());
	message_vision(YEL"\n南瓜精呼噜噜一阵怪叫，被打回了大南瓜。\n"NOR, this_object());
	destruct(this_object());
	return;
}