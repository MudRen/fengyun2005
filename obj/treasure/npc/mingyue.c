inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();
string do_flee();

void create()	
{
    object weapon;

	set_name("明月心", ({ "mingyue xin","boss","mingyue"}) );
	set("gender", "女性" );
	set("nickname",BLU"本无心"NOR);
    set("title","高楼明月");
	set("class","legend");

	set("age",17);

	set("spawn_location","/d/biancheng/tas");

set("long","她的声音很好听，笑得更好看，她的态度很幽雅，装束很清淡。也许她并不能算是
个倾国倾城的绝色美人，可是她走进来的时候，就像是暮春的晚上，一片淡淡的月
光照进窗户，让人心里觉得有种说不出的美，说不出的恬静幸福。\n");
		set("agi", 70);
		set("per",40);
		set("gold", 40);
		set("real_boss",1);
		set("boss",1);	// immune to some rascal skill and ghostcurse.
						// busy resist but not immune.

        set("attitude","friendly");
    
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );

        set("combat_exp", 12000000);	// L140. CAP @ L110.
    
        set_skill("dodge", 400);
        set_skill("fall-steps", 300);
        set_skill("force", 200);
        set_skill("divineforce", 300);
        set_skill("sword", 200);
        set_skill("xiaohun-sword", 200);
        set_skill("parry",200);

		set_skill("iron-cloth",200);
        set_skill("spring-water",300);

        map_skill("iron-cloth", "spring-water");
        map_skill("force", "divineforce");
        map_skill("dodge", "fall-steps");
        map_skill("sword", "xiaohun-sword");
        map_skill("parry", "xiaohun-sword");
		
		set("max_kee",500000);
		set("max_gin",500000);
		set("max_sen",500000);
        
		setup();

		weapon=carry_object("/obj/weapon/sword");
		weapon->set_name(HIR"烛莹"NOR, ({ "dagger" }) );
		weapon->set("long"," ");
		weapon->set("value",0);
		weapon->set("nodrop_weapon",1);
		weapon->set("no_get",1);
		weapon->wield();


		weapon=carry_object("/obj/armor/cloth");
		weapon->set_name(CYN"淡青如水的长裙"NOR, ({ "cloth" }) );
		weapon->set("long","淡青如水的长裙(Cloth)。");
		weapon->set("value",0);
		weapon->set("no_get",1);
		weapon->wear();



	set("drop/bg",0);
	set("drop/common",100);
	set("drop/rare",0);	
	set("drop/amount",3);
	set("drop/common_drop",({
"/obj/generate/wrists_170_9.c",
"/obj/generate/surcoat_170_22.c",
"/obj/generate/surcoat_170_12.c",
"/obj/generate/neck_170_20.c",
"/obj/generate/head_170_10.c",
"/obj/generate/boots_170_21.c",
__DIR__"obj/myx_heart.c",
	}) );
	set("drop/rare_drop",({
"none",
	}) );

}


void die()
{
	object who = query_max_damage_dealer();
	object lotus;
	
	if (random(2)) {
		lotus = new(AREA_XINJIANG"obj/lotus");
		if (lotus) lotus->move(this_object());
	}

	if (!objectp(who))
		who = query_temp("last_damage_from");
		
	if (objectp(who))
		ANNIE_D->generate_drop_item(this_object(),who);
	::die();
	return;
}

int kill_ob(object who)
{
        ::kill_ob(who);
        smart_fight();
        return 1;
}



int hurting()
{
	message_vision(HIY"\n$N"HIY"吐出一口绵长的气息，脸色转瞬间变得红润。\n"NOR,this_object());
	receive_fulling("kee",query("max_kee")/3);
	receive_fulling("sen",query("max_sen")/3);
	receive_fulling("gin",query("max_gin")/3);
	set("annie/ec",time());
	return 1;

}

int hurting2()
{
	// heal here; 他>不<治疗gin/sen伤害.
	message_vision(HIY"\n$N"HIY"慢慢吐出一口长气，身上的伤势竟在转眼间尽数消失。\n"NOR,this_object());
	receive_fulling("kee",query("max_kee"));
	receive_fulling("gin",query("max_gin"));
	receive_fulling("sen",query("max_sen"));
	set("annie/ec2",time());
	return 1;

}

int hurting3()
{
	int i,j;
	object *enemy;
	string msg;
	object me = this_object();
	enemy = query_enemy();
	if (!enemy || !sizeof(enemy))
		return 1;
	msg=HIW"\n明月心骤而出手。\n\n袖起处，整座小楼中亮若白昼，风闪过，无数点银芒交织，仿若千月星痕！\n\n"NOR;
	message_vision(msg,me);
	j=0;
	add_temp("apply/damage",730);
	add_temp("apply/attack",420);
	for(i=1;i<=12;i++)
	{
		stop_busy();
		COMBAT_D->do_attack(me,enemy[j],TYPE_PERFORM,WHT"一点点寒星闪动，飞袭向$n！"NOR);
		if (j==sizeof(enemy)-1) j=0;
		else j++;
	}
	add_temp("apply/damage",-730);
	add_temp("apply/attack",-420);
	return 1;
}


void smart_fight()
{
	object ob;
	mapping buff;
	object me = this_object();
	int i;
	object ghost;
	object target;

	ccommand("exert npc_hurtless");
//		25 mins
	if (!random(3) && time()>query("annie/ec2")+1500 && query("kee") < query("max_kee")/3)
	{
		message_vision(BBLU HIW"\n六脉顺气\n"NOR,this_object());
		message_vision(HIG"\n$N"HIG"双手合十，低声吟咏．．．\n\n"NOR,this_object());
		perform_busy(10);
		// delay 20,争取在这段时间里挂掉他吧
		call_out("hurting2",20);
	}

	if (is_busy())
		return;

//		5 mins
	if (!random(3) && time()>query("annie/ec")+300 && (
		query("kee") < query("max_kee")/3*2
		|| query("sen")< query("max_sen")/3*2
		|| query("gin")< query("max_gin")/3*2)
		)
	{
		message_vision(BBLU HIW"\n引溯回元\n"NOR,this_object());
		message_vision(HIG"\n$N"HIG"飘身闪退，合守魂印运转内息，吐气渐变悠长．．．\n\n"NOR,this_object());
		perform_busy(10);
		// delay 20,争取在这段时间里挂掉他吧
		call_out("hurting",20);
	}

	if (is_busy())
		return;

	if (!random(3))
		if (ccommand("perform force.check_gspm"))
			ccommand("perform force.guishenpomie");

	if (is_busy())
		return;

	switch (random(5))
	{
	case 0:
	case 1:
		if (time()>query("annie/ex")+8)
		{
			set("annie/ex",time());
			target = select_opponent();

			message_vision(BGRN WHT"\n花氲灵击\n"NOR,this_object());
			message_vision(BCYN WHT"\n灯光下只见一个纤弱轻巧的人影闪了一闪，小阁楼间刹时布满香气。\n"NOR,this_object());

			add_temp("apply/attack",720);
			add_temp("apply/damage",150);

			COMBAT_D->do_attack(this_object(),target,TYPE_PERFORM,CYN"一阵淡淡的烟雾卷着清香向$n袭去．．．"NOR,"伤害！
"CYN"$n一脸痴迷，神情如醉．．．"NOR);
			if (target->query_temp("damaged_during_attack"))
				target->add("force",target->query("force")>250?-250:-target->query("force"));
			add_temp("apply/damage",-150);
			add_temp("apply/attack",-720);
		}
		break;
	case 2:		
		if (time()>query("annie/exxx")+ 10)		// hmm, 我是不是该安静地逃开，还是傻傻地留下来？
		{
			set("annie/exxx",time());
			message_vision(BMAG HIW"\n千月星痕\n"NOR,this_object());
			message_vision(HIW"\n明月心神色荧洁，双手微笼袖中，小楼内的灯光闪动，似乎也暗了几分。\n"NOR,this_object());
			perform_busy(4);
			call_out("hurting3",8);
		}
	}

	return;
}


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

