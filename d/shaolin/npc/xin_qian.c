// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
int kill_him();

void create()
{
        set_name("心鉴", ({ "master jian","master", "jian"}) );
        set("gender", "男性" );
        set("age",62);
		create_family("少林寺", 17, "长老");
        set("long", "少林寺七大高手之一。\n");
		set("vendetta_mark","shaolin");
        set("combat_exp", 6000000);
        set("attitude", "friendly");
        
        set("chat_chance", 2);
        set("chat_msg", ({
//                name()+"说道：藏经阁丢书，老夫自愿在此面壁十年。\n",	// 老夫？...>_< 我还老夫人哩
                name()+"说道：藏经阁丢书，老衲自愿在此面壁十年。\n",
        }) );
        
        
	    set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
     	}) ); 		

		auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","yiyangzhi2",1);   
		setup();
		carry_object(__DIR__"obj/monk_cloth")->wear();
}

void init()
{
	::init();
	if (environment(this_object())->query("short") == "六祖殿" && !is_fighting() && !is_busy()) {
		command("say 你来有什么事吗？\n");
		call_out("do_kick",2+random(3),this_player());
	}
}

int do_kick(object me)
{
	object room;
	if(me && environment(me) == environment() && !me->is_fighting()
		&& !me->is_busy())
	{
		command("say 没有事你可以走了。。\n");
		message_vision("$N袍袖一挥，一股大力将$n送出屋外。\n",this_object(),me);
		room = 	load_object(AREA_SHAOLIN"liuzu");
		if(room) me->move(room);
	        message_vision("$N从西边的屋子中飞了出来，重重地摔在地下！\n",me);
		me->receive_damage("kee",50,this_object());
	}
	return 1;
}


/*
int kill_him()
{
	object me;
	me = this_player();
	if(!me->query("m_success/勇保经书") || is_fighting())
	{
		message_vision(CYN"心鉴说道：那偷书贼屡屡得手，老衲难咎其职，自愿在此面壁十年。\n"NOR,me);
		return 1;
	}
	delete("vendetta_mark");

	me->set_temp("annie/demon_gao_askqian",1);

	message_vision(CYN"心鉴喝道：你便是那偷书盗贼，莫道那天我不曾见你！\n"NOR,me);
	message_vision(CYN"心鉴喝道：竟敢在少林放肆，自速其死，老衲不再轻饶！\n"NOR,me);
	message_vision(CYN"心鉴袍袖一振，真气鼓动，大喝道：贼人，且看我降魔手段！\n"NOR,me);
	set("combat_exp",3000000);
    set("chat_chance_combat", 100);
	map_skill("unarmed", "dabei-strike");
	set("chat_msg_combat", ({
            (: perform_action, "unarmed.qianshouqianbian" :),
        }) );
	kill_ob(me);
	me->kill_ob(this_object());
	return 1;
}

void killed_enemy(object who)
{
    command("heng");
    command("say 我佛云雷霆手段，菩萨心肠，今日你须怨不得我！");
	remove_killer(who);
	who->remove_killer(this_object());
	if (!is_fighting())
	{
		set("vendetta_mark","shaolin");
		set("chat_chance_combat", 10);
		set("chat_msg_combat", ({
				(: perform_action, "unarmed.qiankun" :),
		}) );
		set("combat_exp", random(600000)+600000);
	}
}

void unconcious()
{
	::die();
}

void die()
{
	int i;
	object killer, owner;
	object room;
	room = environment();
	if(objectp(killer = query_temp("last_damage_from")))
	{
		if(owner=killer->query("possessed"))
			killer = owner;

		if(!killer->query("m_success/勇保经书") || room->query("short") != "六祖殿" || !killer->query_temp("annie/demon_gao_askqian"))
		{
			// rob的?
			set("vendetta_mark","shaolin");
			::die();
			return ;
		}

		message_vision(HIR"\n$N目睚俱裂，大喝道：好，好！\n$N长身而起，集全身功力向$n扑去！\n"NOR,this_object(),killer);

		killer->set("annie/demon_gao",1);

		if (random(killer->query_skill("move",1)) > 100)
		{
			message_vision("$n身随意转，闪在一旁，$N毕生功力击于墙上，竟将墙壁轰出一个大洞！\n\n",this_object(),killer);
		}
		else
		{
			message_vision(CYN"$n闪躲不及，被$N毕生功力所聚的一掌印在胸口，顿时如断线风筝般飞出！\n$n飞到六丈开外，猛然撞在墙上，竟将墙壁撞出一个大洞！\n"NOR,this_object(),killer);
			killer->receive_wound("kee",(400-random(killer->query_skill("parry",1)))*20,this_object());
			COMBAT_D->report_status(killer);
		}
        room->opengate();
	}
	::die();
}
*/