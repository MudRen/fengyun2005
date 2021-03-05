
#include <ansi.h>

inherit NPC;


void create()
{
        set_name("狄青麟", ({ "di qinglin","di","qinglin" }) );
        set("long","
一身雪白的衣裳，一尘不染；一张苍白清秀的脸上，总是带着冷冷淡淡的
的表情。这就是视功名富贵如尘土、却把名马美人视如生命的狄小侯爷。\n");

        set("attitude", "friendly");
        set("reward_npc", 1);
	set("difficulty", 20);
	set("age",27);
        set("title", HIY"世袭一等侯"NOR);

        set("combat_exp", 3000000+random(1000000));
        set("max_force",2000);
        set("force",2000);
        
        set_skill("unarmed",200);
    	set_skill("dagger",200);
    	set_skill("xinyue-dagger",150);
	set_skill("parry",200);
	set_skill("dodge",200);
	set_skill("fall-steps",200);
    	map_skill("dagger","xinyue-dagger");
	map_skill("dodge","fall-steps");
	map_skill("parry", "xinyue-dagger");

        setup();

        carry_object(__DIR__"obj/shirt")->wear();
        carry_object(__DIR__"obj/thinblade")->wield();
//        carry_object(__DIR__"obj/letter2");
}

void init()
{
		if( !query_heart_beat(this_object()) ) set_heart_beat(1);
//		::init();
}

void heart_beat()
{
	object di,yang,room,ying, weapon;
	int rival;
	
	::heart_beat();
	di=this_object();
	if (!di)	return;
		
	room=environment();
	if (!room)	return;
	
	yang=present("yang zheng",room);
	if(query("yang_die"))
	{
		ying=present("ying wuwu",room);
		di->start_call_out( (: call_other, di, "kill_ying" ,di,ying:), 3);
		delete("yang_die");
	}
	if(rival=query("begin_rival"))
	{
		if((rival==4)||(rival==3))
		{
			command("nod");
			say("\n");
		}
		if(rival==2){
			say("\n");
			command("say 只要你能打败我，镖银就是你的，我的命也是你的，你都可以带走。\n");
		}
		if(rival==1)
		{
			di->kill_ob(yang);
			yang->kill_ob(di);
			call_out("do_busy",5,di);
			delete("begin_rival");
		}

		yang->add("begin_rival",-1);
	} 
	
	
	if (objectp(yang))
	if (di->is_fighting(yang))
	if (random(3)==1&&!yang->query_busy()&&query("do_busy"))
	{
		message_vision(HIR"\n$N刀尖一转，刺在了$n左臂的曲池穴上，$n只觉左半身发麻，动也不能动了。\n"NOR,di,yang);
		yang->start_busy(200);
		weapon = yang->query_temp("weapon");
		if (objectp(weapon) && !weapon->query("blood"))
			message_vision(CYN"\n$N淡淡地说道：这钩本是不祥之物，你既然用了它，就注定一世痛苦。\n\n"NOR, di);
	}
}

int do_busy(object di)
{
	di->set("do_busy",1);
	return 1;
}

int kill_ying(object di,object ying)
{
	object room,who;
	
	room=environment();

	if(objectp(ying))
	{
		message_vision(YEL"$N信步走到$n身后，什么话也没说，突然反手一刀，由$n
背后刺入$p的心脏。\n\n"NOR,di,ying);
		who=ying->query("busy_object");
		if (environment(who)!= environment(this_object()))	return 0;
		message_vision(YEL"$N露出一种古怪恐惧的眼神，倒在$n身旁，用尽最后一丝内力，
为$n解开穴道。\n"NOR,ying,who);
		who->start_busy(1);
		ying->die();
		call_out("kill_who",3,di,who);
		return 1;
	}
	return 0;
}

int kill_who(object di, object who)
{
	message_vision(HIY"$N对$n微笑道：“我说过，只要能够胜过我，什么你都可以拿去。”\n"NOR,di,who);
	di->kill_ob(who);
	who->kill_ob(di);
	return 1;
}
	
void die()
{
	object yang,room,me,yangcorpse,ying;
	
	room=environment();
	
	yang=present("yang zheng",room);
	ying=present("ying wuwu",room);
	if(objectp(yang))
	{
		yang->set("killed_di",1);
		ying->set("sad_leave",1);
	}
	else
		if(me=room->query("结局人物"))
	{
		me->set("libie/离别钩_杀死狄青麟",1);
		REWARD_D->riddle_set(me,"离别",4);
		
	}
	::die();
}


int return_home(object home)
{
	home=environment();
	if(!present("yang zheng",home))
	{
		destruct(this_object());
		home->delete("结局人物");
	}
	return 1;
}