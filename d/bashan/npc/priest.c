

inherit NPC;
#include <ansi.h>
#include <combat.h>
void smart_fight();

void create()
{
	object armor,weapon;
	set_name("迦若", ({ "jia ruo","jia","ruo"}) );
	set("gender", "男性");
	set("title",YEL"上古楼兰 "NOR HIB"最高司祭"NOR);
	set("nickname",WHT"封神之人"NOR);
	set("age", 20+random(10));
	set("long","\n");
    set("combat_exp", 8000000);	
    set("score", 10000);
	set("fle",50);
	set("cor",40);
	set("cps",30);
	set("str",40);
	set("force_factor",180);
	set("per",40);

	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);

	set("max_kee",24000);
	set("max_gin",16000);
	set("max_sen",16000);

	set_skill("demon-blade",240);
	set_skill("blade",200);

	set_skill("demon-steps",200);
	set_skill("fall-steps",340);
	set_skill("anxiang-steps",200);
	set_skill("cloud-dance",200);
	set_skill("move",200);
	set_skill("dodge",200);

	set_skill("demon-force",200);

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
	set_skill("divineforce",200);	

	set_skill("qiuzhi-sword",250);
	set_skill("daimonsword",250);
	set_skill("zensword",250);
	set_skill("sword",200);

	map_skill("spells","kwan-yin-spells");
	map_skill("unarmed", "lingxi-zhi");
	map_skill("force", "divineforce");
	map_skill("dodge","cloud-dance");
	map_skill("move","anxiang-steps");
	map_skill("sword","daimonsword");
	map_skill("parry","qiuzhi-sword");
	
    	
        add_temp("apply/iron-cloth", 200);
	
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );

	setup();


	setup();
    armor=new("/obj/armor/cloth");
	armor->set_name("宽大的半旧长袍",({"cloth"}) );
	armor->move(this_object());
	armor->wear();

    carry_object(__DIR__"obj/chusword1")->wield();
    carry_object(__DIR__"obj/chusword2")->wield();

    set("reward_npc", 1);
	set("difficulty",7);
	set("resistance/kee",100);

}

object select_opponent() 	
{
	object * enemy;
	int i;
	enemy = query_enemy();
	if(!sizeof(enemy)) {
		return 0;
	}
	clean_up_enemy();
	if(!sizeof(enemy)) {
		return 0;
	}
	for(i=0; i<sizeof(enemy); i++)
		if (userp(enemy[i]))
			return enemy[i]; // focus user. ; annie 6.25.03
	return enemy[0];	// 从0杀起
}

int kill_ob(object who)
{
	int a = query_busy();

	if (base_name(who) == "/obj/npc/danei" || base_name(who) == "/obj/npc/danei_guard")
	{
		message_vision(HIW "$N扬了扬手，空气中点点星光闪烁，刹那间四周万籁俱寂．．．\n" NOR,this_object());
		who->die();
		return 1;
	}

	::kill_ob(who);
	smart_fight();
	return 1;
}

int bbqthem(object me, object obj) 
{
	int spells, busy_num,mod,magic;
	string id_enemy;
	
	spells = 750;        

	mod = COMBAT_D->can_busy(me, obj, "kwan-yin-spells");   
	
	obj->set_temp("last_damage_from",me);
	if(obj->is_ghost()) {
			obj->die();
			return 1;
	}
	if(obj->is_zombie()) {
			obj->die();
			return 1;
	}

	if(obj->query("combat_exp") /10 * mod >random(me->query("combat_exp")/100 * spells))
	{
		message_vision(CYN"$N连忙转过头去，不看$n。\n"NOR,obj,me);
		return 1;
	}

    magic = 4*random(400)+1;

	if(userp(obj))
	{
		tell_object(obj,HIW"你只觉得眼前白茫茫的一片，什么都看不到了。。。\n"NOR);
		obj->add_temp("block_msg/all",1);
		obj->start_busy(3 + random(2));
		message_vision(CYN"$N痛苦地捂住眼睛，直在地上打滚。\n"NOR,obj);
		obj->add_temp("block_msg/all",-1);
		obj->receive_damage("sen",magic,me);
		obj->set_temp("damaged_during_attack", 1);
		COMBAT_D->report_status(obj);
		obj->add_temp("block_msg/all",1);
		call_out ("recovers",10, obj);
	}
	else
	{
		obj->start_busy(3+random(2));
		message_vision(CYN"$N痛苦地捂住眼睛，直在地上打滚。\n"NOR,obj);
		obj->receive_damage("sen",magic,me);
		obj->set_temp("damaged_during_attack", 1);
		COMBAT_D->report_status(obj);
	}
	return 1;
}

int bbqthem2(object me, object obj) 
{
	int spells, busy_num,mod,magic;
	string id_enemy;
	
	spells = 750;        

	mod = COMBAT_D->can_busy(me, obj, "kwan-yin-spells");   
	
	obj->set_temp("last_damage_from",me);
	if(obj->is_ghost()) {
			obj->die();
			return 1;
	}
	if(obj->is_zombie()) {
			obj->die();
			return 1;
	}

	if(obj->query("combat_exp") /10 * mod >random(me->query("combat_exp")/100 * spells))
	{
		message_vision(CYN"$N避闪身形，连退数尺，躲开幽旋的噬人阴风。\n"NOR,obj,me);
		return 1;
	}

    magic = 4*random(800)+1;
	message_vision(HIB BLK"$N顶门上升起一阵白雾，目光呆滞，像是全部生机都被抽走一样。\n"NOR,obj);
	obj->receive_wound("gin",magic,me);
	obj->set_temp("damaged_during_attack", 1);
	COMBAT_D->report_status(obj);

	return 1;
}


int recovers(object obj)
{
	if (obj->query_temp("block_msg/all")>=1)
	    	obj->add_temp("block_msg/all", -1);
	tell_object(obj, HIG"慢慢慢慢的，你的眼睛开始可以分辨周围的事物了。\n" NOR);
	return 1;
}	

void smart_fight()
{
	int i,max_busy=99;
	object *enemy,target,sword,me=this_object();
	string action;
	object env, *inv;

	env = environment(me);
	inv = all_inventory(env);
	enemy = me->query_enemy();

	if (is_busy())
		return;

	i = random(2);
	switch (i)
	{
	case 0:
		// 七光御阵
		message_vision(HIY"\n$N双手作托莲台印，喃喃而念：聚七霞之光，明兮天华，金轮映辉，破冥逐暗，化为无日天煌．．．\n" NOR,this_object());
		message_vision(HIW"．．．只见$N双手一瞬间发出比太阳还要耀眼的光芒！！！\n\n" NOR,this_object());

		if (sizeof(enemy))
	        for(i=0; i<sizeof(enemy); i++)
				bbqthem(me, enemy[i]);
		
		perform_busy(3);
		break;
	case 1:
		// 返空离魂
		message_vision(HIB"\n$N一指按在眉间，阴声吟唱：罡风卷日，幽月华升，鬼幕天张，万魂集焰，黑炎盈穹，冥火湮灭．．．\n"NOR,this_object());
		message_vision(WHT"．．．刹时间仿佛地狱临世，无数幽暗的光影环绕飞旋，憧憧鬼幕中传来阵阵哀号！！！\n\n" NOR,this_object());

		if (sizeof(enemy))
	        for(i=0; i<sizeof(enemy); i++)
				bbqthem2(me, enemy[i]);

		perform_busy(3);
		break;
	}

	return;
}


void die()
{
	object me=this_object(),owner,enemy,paper,*sy_inv,things,env=environment(me),soul;
	int j;
	if (!query_temp("last_damage_from"))
	{
		sy_inv = all_inventory(this_object());
		for(j=0;j<sizeof(sy_inv);j++){
			things = sy_inv[j];
			destruct(things);
		}
		delete("reward_npc");
		::die();
		return;
	}
    if(objectp(enemy=query_temp("last_damage_from")))
        if(owner=enemy->query("possessed"))
			enemy = owner;
	::die();
	return;
}

	
void switch_defense(int i)
{
	if (i == 1)
	{
		add("resistance/gin",100);
		add("resistance/sen",100);
		add("resistance/kee",-100);
		set_temp("shield_force/type","atman");
		set_temp("shield_force/ratio",10000);
		set_temp("shield_force/msg",
			BLU"$N"BLU"招式在$n"BLU"身边气泡上划出一溜深蓝色的星火，消失无踪。\n"NOR);
		message_vision(HIB"\n$N"HIB"左手指间闪出一星幽蓝的火，在空中虚划而过．．．\n"HIW"一个绛紫色的气泡顿在$N"HIW"身后出现，越变越大，渐渐笼住$N"HIW"全身。\n"NOR,this_object());
	}
	else
	{
		add("resistance/kee",100);
		add("resistance/gin",-100);
		add("resistance/sen",-100);
		delete_temp("shield_force");
	}
}


void heart_beat()
{
	if (is_fighting())
	{
		set("atman",10000);
		add("counter",1);
		if (query("counter") >= 30)
		{
			set("counter",0);
			switch_defense(1-query("def_type"));
			set("def_type",1-query("def_type"));
		}
	}
	::heart_beat();
}
	
mapping ob_hit(object attacker, object victim,int damage)
{
	mapping data = ([]);
	if (!victim->is_busy())
		return 0;
	victim->stop_busy();
	data["msg"] = CYN"$n白袍鼓动，借$N一击之力向后轻飘飘的退了开去。\n"NOR;
	return data;
}

/*
update here;ask ke about silencer;call mingyue->delete_temp(inquiry_time);ask ke about silencer;updatep /d/bashan/npc/;clone /d/bashan/npc/chu;call chu->ccommand(kill fighter);call chu->ccommand(kill fighter 2);
update here;clone /d/bashan/npc/yawnboy;clone /d/bashan/npc/yawngirl;updatep /d/bashan/npc/;clone /d/bashan/npc/chu;call chu->ccommand(kill justdoit);call chu->ccommand(kill sinny);
*/

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/


