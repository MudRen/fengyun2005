inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();
string do_flee();
	
void create()	
{
    object weapon;

	set_name("铁开诚", ({ "tie kaicheng","boss","tie"}) );
	set("gender", "男性" );
	set("class","fugui");
	set("title",RED"红旗镖局"NOR);
	set("nickname",BLU"九重天外卧龙深"NOR);
	set("age",30);
	set("long","这人穿着一件朴朴素素的布衣，白布袜，黑布鞋，方方正正的一张脸，怎
么看都是个有点笨笨的老实人。\n");

        set("gender", "男性" );
		set("agi",70);
		set("spawn_location","/d/fycycle/sroad7");

		set("gold",15);
		set("real_boss",1);
		set("boss",1);	// immune to some rascal skill and ghostcurse.
						// busy resist but not immune.

        set("attitude","friendly");
    
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );

        set("combat_exp", 3100000);	// L70. Cap @ L60.
    
        set_skill("sword", 400);
        set_skill("13-sword",250);	// for last hit.
        set_skill("softsword",250);	// for last hit.
		
        set_skill("dodge", 1);
        set_skill("shadowsteps",320);
		set_skill("perception", 200);
		set_skill("unarmed", 200);
		set_skill("parry", 200);
        set_skill("birdiestrike",160);	

		set_skill("force", 400);
        set_skill("skyforce",220);	

		set_skill("iron-cloth", 100);
        set_skill("henglian",100);	

        map_skill("sword", "13-sword");
        map_skill("dodge", "shadowsteps");
        map_skill("iron-cloth", "henglian");
        map_skill("force", "skyforce");
        map_skill("unarmed", "birdiestrike");
		
		set("max_kee",40000);
		set("max_gin",35000);
		set("max_sen",35000);
        
		setup();

		weapon=carry_object("/obj/armor/cloth");
		weapon->wear();
	
		set("drop/fixed_amount",1);
		set("drop/fixed_drop", ({		// L60 books
			BOOKS"class/cloud-dance_yegui_2",
			BOOKS"class/iceheart_buffup_3",
		}));
	
	set("drop/bg",0);
	set("drop/common",100);
	set("drop/rare",0);	
	set("drop/amount",3);
	set("drop/common_drop",({
"/obj/generate/wrists_70_4.c",
"/obj/generate/surcoat_70_17.c",
"/obj/generate/neck_70_5.c",
"/obj/generate/neck_70_15.c",
"/obj/generate/head_70_15.c",
"/obj/generate/boots_70_16.c",
	}) );
	set("drop/rare_drop",({
"none",
	}) );

}


int stone_done(object me, object caster){
	me->delete_temp("pfm/fg_sanchuan");
	return 1;
}

void unconcious()
{
	die();
}

void die()
{
	object *enemies,target,*sy_inv,things,me;
	int i,j;
	object who = query_max_damage_dealer();
	object lotus;
	
	if (random(2)) {
		lotus = new(AREA_XINJIANG"obj/lotus");
		if (lotus) lotus->move(this_object());
	}
	
	if (!objectp(who))
		who = query_temp("last_damage_from");
		
	enemies=query_enemy();
	me=this_object();

	if (enemies && sizeof(enemies))
	{
		target = select_opponent();

		things = new("/obj/weapon/sword");
		things->move(me);
		message_vision(HIR"\n$N的眼里突露愤恨之色，手腕一翻，一柄长剑赫然而现。\n"NOR,this_object());
		things->wield();

		set("kee",query("max_kee"));
		set("sen",query("max_sen"));
		set("gin",query("max_gin"));

		stop_busy();

		set("class","swordsman");

		"/daemon/class/swordsman/softsword/muyufeihong.c"->perform(me,target);
		stop_busy();

		"/daemon/class/swordsman/softsword/muyufeihong.c"->begin_perform(me,target);

		stop_busy();

		message_vision(HIC"\n剑势将竭却又未尽，转瞬间"NOR,this_object());

		things->set("name",HIC"长剑"NOR);

		"/daemon/class/swordsman/softsword/changtianluodian.c"->perform(me,target);
		
		stop_busy();

		things->set("name","长剑");
		stop_busy();

		message_vision(YEL"\n光华落下，"NOR,this_object());

		ccommand("perform 14sword "+target->query("id"));
		if (!is_busy())	// invisible?
			ccommand("perform 14sword");		// 无所谓了，总是hate最大的 :D
	
		target->set_temp("last_damage_from","被铁开诚临终一击打死了。");	// 一般总归打中至少一下了巴..
	}

	if (objectp(who))
		ANNIE_D->generate_drop_item(this_object(),who);

	::die();
}

void smart_fight()
{
	object ob;
	mapping buff;
	object target;
	string msg;
	object me = this_object();

	if (!random(3) && !is_busy()  && !ANNIE_D->check_buff(me,"ironup"))
	{
		message_vision(BMAG WHT"\n三串炸山轰\n"NOR,this_object());
		me->set_temp("pfm/fg_sanchuan",5);

		buff =
			([
				"caster":me,
				"who":	me,
				"type": "ironup",
				"att": "bless",
				"name": "横练·三串炸山轰",
				"buff1":"apply/iron-cloth",
				"buff1_c":120,
				"time":  30,	// 
				"buff_msg":WHT"$N全身衣襟忽然无风自动，却完全没有一丝声响！！\n" NOR,
				"warn_msg":"",
				"disa_type":3,
				"finish_function": (: stone_done :),
			]);
		ANNIE_D->buffup(buff);
		perform_busy(1);
	}

	if (!ANNIE_D->check_buff(me,"damagecurse"))
	{
		message_vision(BRED WHT"\n碎玉撼天破诀\n"NOR,this_object());

    	msg = YEL "$N沉气收心，缓缓地吐出一口长气，脸色变得如枯木般毫无表情。\n" NOR;

    	buff =
		([
			"caster":me,
			"who": me,
			"type":"damagecurse",
			"att":"bless",
			"name":"碎玉神罡·碎玉撼天破诀",
			"time": 300,
			"buff_msg": msg,
		]);
		ANNIE_D->buffup(buff);
		perform_busy(1);
	}

	if (is_busy())
		return;
	set("class","swordsman");
	ccommand("perform dodge.lianhuanjiao");
	set("class","fugui");
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

