
#include <ansi.h>

inherit NPC;


void create()
{
        set_name("杨铮", ({ "yang zheng","yang","zheng" }) );
        set("long",
                "一个瘦削、黝黑、沉静，还不到三十岁的汉子。\n");

        set("attitude", "friendly");
	set("age",32);
        set("str", 10);
	set("title", HIW"捕头"NOR);
	set("kar",10);
        set("combat_exp", 4000000+random(1000000));
        set("max_force",3000);
        set("force",3000);
        

	set_skill("unarmed",200);
	set_skill("sword",200);
	set_skill("libie-sword",200);
	set_skill("parry",1000);
	set_skill("dodge",500);
	set_skill("feixian-steps",200);

	map_skill("sword","libie-sword");
	map_skill("dodge","feixian-steps");

        setup();

        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}


void heart_beat()
{
	object di,yang,room,hook,ying,who;
	int rival,msg;
	
	::heart_beat();
	if (!this_object())	return;
		
	yang=this_object();
	room=environment();
	if (!room)	return;
		
	di=present("di qinglin",room);
	ying=present("ying wuwu",room);
	
	if(query("killed_di"))
	{
		who=ying->query("busy_object");
		call_out("leave_room",3,ying,who);
		delete("killed_di");
	}
	if(msg=query("leaving_msg"))
	{
	if(msg==3)
		message_vision(HIG"$N默默擦去离别钩上的血迹，疲惫不堪的嘴角突然露出了一丝微笑。\n"NOR,yang);
	if(msg==2)
		message_vision(HIG"$N喃喃自语道：“素文，案子结了，我终于可以回家了。”\n"NOR,yang);
	if(msg==1)
		{
		message_vision(HIG"斜阳似血，$N拖着疲惫的身影默默地离开麒麟阁。\n\n"NOR,yang);			
		destruct(yang);
		}
	add("leaving_msg",-1);
	}
	if(rival=query("begin_rival"))
	{
		if(rival==4)
		{
			command("say 莲姑是你杀的？\n");
			di->set("begin_rival",4);
		}
		else
		{
			if(rival==3)
				command("say 失劫的镖银也在你这里？\n");
			if(rival==2)
				command("hmm");
			if(rival==1)
				command("say 我就知道你一定会这样做的，因为你太骄傲，太不把别人放在眼里。\n");
			di->add("begin_rival",-1);
		}

	} 
	
	
	if (!query_temp("perform_libie"))
	if (objectp(di))
	if (yang->is_fighting(di))
	if (yang->query_busy())
	if (hook=present("leave hook",yang))
	if (hook->query("equipped") && hook->query("blood"))
	{
		set_temp("perform_libie",1);
		yang->start_call_out( (: call_other, __FILE__, "perform_libie" ,yang,di:), 2);
	}
}
	
void perform_libie(object yang, object di)
{
	message_vision(HIB"\n$N倏地欺近身来，身形猛然凝岳不动。\n\n离别钩交至右手，划向自己左臂。\n"HIR
"\n血光起，\n\n"HIB"$N左臂断落\n\n离别钩又斜斜飞起，直至$n咽喉。\n\n$n大惊之下，早已躲避不及。\n
"HIR"血光又起\n\n"HIB"$n直挺挺的倒落。。。\n"NOR,yang,di);
	yang->start_busy(1);
	di->die();
	delete_temp("perform_libie");
	return;
}

int do_rival(object di)
{
	if(!objectp(di)) return 0;
	set("begin_rival",4);
	return 1;
}

void die()
{
	int i;
	object di,ying,room,corpse,*inv;
	
	room=environment();
	di=present("di qinglin",room);
	di->set("yang_die",1);
	corpse=new("/d/libie/obj/yangcorpse1");
	corpse->move(room);
	inv=all_inventory(this_object());
	i=sizeof(inv);
	while(i--)
		inv[i]->move(corpse);
	
	message("vision",HIR"\n杨铮双目圆睁，不甘心的倒了下去。。。\n\n"NOR,room);
	destruct(this_object());
}

void leave_room(object ying,object who)
{	
	object yang,room;
	
	room=environment();
	yang=this_object();
	message_vision(HIW"$N给$n解开穴道。\n\n"NOR,yang,who);
	who->start_busy(1);
	who->set("libie/离别钩_杀死狄青麟",2);
	REWARD_D->riddle_set(who,"离别",4);
	set("leaving_msg",3);
}
