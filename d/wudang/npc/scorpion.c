#include <ansi.h>
inherit NPC;

int bite();

void create()
{
	set_name("七彩蝎子", ({ "scorpion" }) );
        set("race", "昆虫");
        set("subrace","爬虫");
        set("attitude", "aggressive");
        set("age", 1);
        set("long", "一只三寸长的大蝎子，模样十分凶恶。\n");

         
    	set("chat_chance_combat", 10);
    	set("chat_msg_combat", ({
		(: bite()  :),     
        }) );
    	    	     
		set("combat_exp",100000);
        set_skill("dodge", 200);
        set_temp("apply/attack",100);
        setup();
}



int bite(){
	object ob,*enemy, target;
	int i;
	
	ob=this_object();
	enemy=ob->query_enemy();
	if (!random(3)) target = enemy[random(sizeof(enemy))];
	if (target) {
		message_vision(HIM"七彩蝎子将尾巴一甩，啪地一声击向你。\n"NOR,target);
		tell_object(target,HIB"你哎呦一声，腿脖子上已是一道伤痕。\n"NOR);
		target->receive_wound("kee",target->query("max_kee")/20,ob);
		COMBAT_D->report_status(target);
		ob->start_busy(1);
	}
	return 1;
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}


void leave()
{
	message("vision","七彩蝎子悉悉簌簌地爬进了麦堆。\n", environment(),this_object() );
	destruct(this_object());
}
