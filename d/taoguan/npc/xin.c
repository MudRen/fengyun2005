// ; annie 07.2003
// dancing_faery@hotmail.com
// 
// 八部众之夜叉王 千魂集焰 辛望 
// EXP 8M KEE 40K GIN/SEN 24K RESIST/ALL 60
// STR 40 DMG 25 ATTACK 46K DODGE 45K PARRY 150K
// PETMASTER

// A/D/P：远低于标准8M，PARRY数值高，此人不可TK。
// 宠物群：6M EXP，完全BUFF之后50-81K ATTACK,32K D/P.

inherit NPC;
#include <ansi.h>
#include <combat.h>
void clear_room();

void create()
{
	object armor,weapon;
	set_name("辛望", ({ "xin wang","xin"}) );
	set("gender", "男性" );
	set("title",YEL"大光明教 "NOR CYN"夜叉王"NOR);
	set("nickname",RED"千魂集焰"NOR);
	set("age", 60+random(10));
	set("attitude","friendly");

	set("long",
		"此人乌衣白发，几络长须，手持纸剑，身披道袍，看起来一派\n道骨仙风。\n"
		);
	set("class","demon");
    set("combat_exp", 8000000);	
    set("score", 10000);
	set("fle",50);
	set("cor",40);
	set("cps",30);
	set("str",20);
	set("per",20);
	set("force",2500);
	set("max_force",2500);
	set("force_factor",64);
	set("atman",1500);
	set("max_atman",1500);
	set("mana",1500);
	set("max_mana",1500);

	set("no_fly",1);
	set("no_arrest",1);

	set("group","demon");
		
	set("resistance/gin",60);
	set("resistance/kee",60);
	set("resistance/sen",60);

	set("max_kee",40000);
	set("max_gin",24000);
	set("max_sen",24000);
	
	set_skill("daimonsword",160);
	set_skill("sky-sword",250);
	set_skill("sword",200);

	set_skill("demon-steps",200);
	set_skill("fall-steps",200);
	set_skill("anxiang-steps",200);
	set_skill("cloud-dance",200);
	set_skill("move",200);
	set_skill("dodge",200);

    set_skill("perception",200);

	set_skill("meihua-shou",210);
  	set_skill("unarmed", 300);
	set_skill("force", 200);

	set_skill("lingxi-zhi", 170);
	set_skill("spells",200);
	set_skill("parry",200);
	set_skill("kwan-yin-spells",200);
	set_skill("five-steps",180);
	set_skill("move",200);
	set_skill("dodge",200);
	
	map_skill("spells","kwan-yin-spells");
	map_skill("unarmed", "lingxi-zhi");
	map_skill("force", "bolomiduo");
    	map_skill("dodge","fall-steps");
    	map_skill("move","anxiang-steps");
    	map_skill("sword","daimonsword");
    	map_skill("parry","sky-sword");
    	
        add_temp("apply/iron-cloth", 200);

	set("NO_KILL","尽管辛望就站在你面前四尺之处，但这短短的四尺距离你就是无法跨越。\n");
	
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
//               (: smart_fight() :),
        }) );

		set("chat_chance",0);
		set("chat_msg", ({
	             (: clear_room() :),	// ; to kickout jiasi/(pet) player
        }) );

	setup();

	carry_object(__DIR__"obj/taopao")->wear();
	carry_object(__DIR__"obj/papersword")->wield();
	carry_object(__DIR__"obj/paper3");

    set("reward_npc", 1);
	set("difficulty",7);

}

void init()
{
	object me;
	::init();
	me = this_player();
	if (userp(me) && environment(me)->query("short") == "三清密室" && !is_fighting())
	{
		remove_call_out("do_greeting");
		call_out("do_greeting",1,me,environment(this_object()));
	}
}


void do_killob(object me,object room)
{
	if (!me || environment(me) != room)
		return;
	message_vision(CYN"\n$N笑道：怪不得你能杀了马空群，果然有几分本事。不过，一切也就到此\n为止了。——放心吧，你的尸体资质上佳，我是不会浪费的。\n"NOR,this_object(),me);

	call_out("do_m_killob",1,me,room);

	return;
}

void do_m_killob(object me,object room)
{
	if (!me || environment(me) != room)
		return;
	message_vision(CYN"\n$N口中念念有辞，双手急遽地在空中挥舞，陡然大喝道：起！\n"NOR,this_object(),me);
	call_out("do_n_killob",2+random(2),me,room);
}

void do_n_killob(object me,object room)
{
	object guard;
	if (!me || environment(me) != room)
		return;
	message_vision(HIB"\n一道淡蓝飞快的顺着地上的符图流动，整个符图开始发出耀眼的光芒。\n\n"HIW"刹那间光华大盛，狂风骤起，几道灵息在阵中凝结成形！\n\n"NOR,this_object(),me);

	delete("NO_KILL");

	set("chat_chance",100);			// 開始監測意外終止狀況 ; annie 6.27.03

	me->set_temp("annie/demon_xin_2",0);	// 如果失败，从头再来。
	delete("NO_KILL");
	guard = new(__DIR__"tiger");
	guard->move(room);
	guard->kill_ob(me);
	me->kill_ob(guard);
	guard = new(__DIR__"dragon");
	guard->move(room);
	guard->kill_ob(me);
	me->kill_ob(guard);
	guard = new(__DIR__"turtle");
	guard->move(room);
	guard->kill_ob(me);
	me->kill_ob(guard);
	guard = new(__DIR__"phoenix");
	guard->move(room);
	guard->kill_ob(me);
	message_vision(CYN"\n$N哈哈大笑道：成了，终于成了，失传三百年的四相转生之阵，终于成了！\n\n"NOR,this_object(),me);
	me->kill_ob(guard);
	kill_ob(me);
	me->kill_ob(this_object());

}

void do_greeting(object me,object room)
{
	if (!me || environment(me) != room)
		return;
	call_out("do_killob",1+random(2),me,room);
}

void clear_room()	// ; annie 6.27.03 處理假死的問題
{
	object room,me;
	object *olist;
	int i;
	me = this_object();
	room = environment(me);
	olist = all_inventory(room);

	set("NO_KILL","尽管辛望就站在你面前四尺之处，但这短短的四尺距离你就是无法跨越。\n");

	for(i=0; i<sizeof(olist); i++)
	{
		if (olist[i] == me)
			continue;
		if (!olist[i]->query("max_kee"))	// item? character? ... forgot what' the function for ><" ; annie 6.27.03
			continue;
		if (!userp(olist[i]) && olist[i]->query("title") == WHT"四灵之"NOR)
		{
			destruct(olist[i]);
			continue;
		}
		message_vision(CYN"\n辛望冷哼一声，抛出一张土黄色的符纸贴在$N身上。\n$N的轮廓慢慢的模糊消失了．．．\n\n"NOR,olist[i]);
		olist[i]->move(load_object("/d/taoguan/taoguan"));
		message_vision(CYN"\n大门前的空气忽然开始阵阵波动，一个模糊的轮廓慢慢的从虚空中显现出来．．．\n\n"NOR,olist[i]);
	}

	set("chat_chance",0);
	return;
}

void kill_ob(object who)
{
	object me=who,here=environment(who),*inv=all_inventory(here);
	int i;
	::kill_ob(who);
	for (i=0;i<sizeof(inv) ; i++)
		if (!userp(inv[i]) && inv[i]->query("title") == WHT"四灵之"NOR)
			if (!inv[i]->is_fighting(me))
			{
				inv[i]->kill_ob(me);
				me->kill_ob(inv[i]);
			}
}


void die()
{
	object room,me;
	object *olist;
	object owner,enemy,paper,*sy_inv,things;
	int i,j=0;
	me = this_object();
	room = environment(me);
	olist = all_inventory(room);

	for(i=0; i<sizeof(olist); i++)
		if (olist[i]->query("title") == WHT"四灵之"NOR)
			j = 1;
	if (j)											// 如若還有四靈活著,IMMORTAL.; annie 6.27
		this_object()->full_me();
//		"/cmds/imm/full"->main(this_object(),"");
	else
	{
		if (!query_temp("last_damage_from"))
		{
			sy_inv = all_inventory(this_object());
			for(j=0;j<sizeof(sy_inv);j++){
				things = sy_inv[j];
				destruct(things);
			}
			::die();
			return;
		}

		if(objectp(enemy=query_temp("last_damage_from")))
			if(owner=enemy->query("possessed"))
				enemy = owner;
				
		if (environment(me)->query("short") != "三清密室")
		{
			set("reward_npc", 0);
			sy_inv = all_inventory(this_object());
			for(j=0;j<sizeof(sy_inv);j++){
				things = sy_inv[j];
				destruct(things);
			}
			::die();
			return;
		}

		message_vision(CYN"\n$N的嘴角沁出鲜血，眼里突然流露出一种说不出来的讥诮之色。\n"WHT"——白凤公主虽然已经叛出魔教，魔教仍不能容她毁在外人手里。\n所以我来，是为了报仇。\n尽管这一次我失败了，可是总有一天我们会成功的。\n\n"NOR,me,enemy);
//		REWARD_D->riddle_done(enemy,"仇恨",100,1);
		enemy->set("annie/demon_killed_xin",1);	// 
		environment()->pushout();
		::die();
	}
	return;
}

