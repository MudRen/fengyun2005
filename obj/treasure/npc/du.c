inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();
string do_flee();

void create()	
{
    	object weapon;

		set_name("杜桐轩", ({ "du tongxuan","boss", "du" }) );
		set("gender", "男性" );
		set("nickname",BLU"翰林学士"NOR);
    	set("title","权倾京城 南霸");
		set("class","official");
set("long","这人施施地站在烟水亭顶上，很高，很瘦，穿著极考究，态度极斯文，年
纪虽不甚大，两翼却已斑白，一张清瘤瘦削的脸上，仿佛带著三分病容，
却又带著七分威严，令人绝不敢对他有丝毫轻视。\n");

		set("spawn_location","/d/jinan/pavtop");

        set("gender", "男性" );
    	set("agi", 70);
    	set("gold", 40);
		set("real_boss",1);
		set("boss",1);	// immune to some rascal skill and ghostcurse.
						// busy resist but not immune.

        set("attitude","friendly");
    
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );

        set("combat_exp", 8600000);	// L125. CAP @ L110.
    
        set_skill("unarmed", 400);
        set_skill("changquan",400);
		set_skill("perception",500);
		set_skill("dodge",300);
		set_skill("puti-steps",400);
		
		map_skill("dodge","puti-steps");
        map_skill("unarmed", "changquan");
		
		set("max_kee",150000);
		set("max_gin",150000);
		set("max_sen",150000);
        
		setup();

		weapon=carry_object("/obj/armor/cloth");
		weapon->set_name(HIB"宝蓝色的长衫"NOR, ({ "cloth" }) );
		weapon->set("long","宝蓝色的长衫(Cloth)。");
		weapon->set("value",0);
		weapon->wear();

		set_temp("apply/attack",230);	// 这家伙的命中实在是太·糟·糕·了！！！

	
	set("drop/fixed_amount",1);
	set("drop/fixed_drop", ({		// L80-90 books
			BOOKS"class/cloud-dance_yegui_2",
			BOOKS"class/dragonstrike_zjbl_3",
			BOOKS"class/iceheart_buffup_3",
			BOOKS"class/xueyeqianzong_wolverine_3",
			BOOKS"class/nine-moon-claw_weiwoduzun_2",
			BOOKS"class/yijinjing_shield_2",
			BOOKS"class/yue-spear_juechufengsheng_2",
	}));
	set("drop/bg",0);
	set("drop/common",100);
	set("drop/rare",0);	
	set("drop/amount",3);
	set("drop/common_drop",({
"/obj/generate/surcoat_130_8.c",
"/obj/generate/surcoat_130_20.c",
"/obj/generate/neck_130_18.c",
"/obj/generate/head_130_8.c",
"/obj/generate/cloth3_130_18.c",
"/obj/generate/cloth1_130_8.c",
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
	// heal here; 他 不 治疗gin/sen伤害.
	message_vision(HIY"\n$N"HIY"吐出一口绵长的气息，脸色转瞬间变得红润。\n"NOR,this_object());
	receive_fulling("kee",query("max_kee")/3);
	receive_fulling("sen",query("max_sen")/3);
	receive_fulling("gin",query("max_gin")/3);
	set("annie/ec",time());
	return 1;

}

void smart_fight()
{
	object ob, me;
	mapping buff;
	object *enemy;
	int i;
	
	me = this_object();
	
	// All str down please ....., sq's game now
	enemy=query_enemy();
	if (!random(3))
	{
		message_vision(BCYN WHT"\n寂寂长空\n"NOR,this_object());
		message_vision(CYN"\n忽祢间长空廖廖，高天冥冥，世间一片空寂。远远的，有大雁飞过的声音．．．\n\n"NOR,this_object());
		for (i=0;i<sizeof(enemy);i++) {
			if (objectp(ob = enemy[i])) {
				if (ANNIE_D->check_buff(ob,"strup"))	continue;
				buff =
				([
					"caster":this_object(),
					"who":ob,
					"type":"strup",
					"att":"curse",
					"name":"天魔无相·寂寂长空",
					"buff1":"apply/strength",
					"buff1_c":-20-random(50),
					"time":60,
					"buff_msg":CYN"$N"CYN"突觉意态萧然，一时间竟下不了重手，力道渐软。\n"NOR,
				]);
				ANNIE_D->buffup(buff);
			}
		}	
	}
	
	if (!random(3) && time()>query("annie/ec")+ 220 && 
		(query("kee")<query("max_kee")/3 || query("sen")< query("max_sen")/3
		|| query("gin")< query("max_gin")/3))	// 4min/cast.
	{
		message_vision(BBLU HIW"\n引溯回元\n"NOR,this_object());
		message_vision(HIG"\n$N"HIG"飘身闪退，合守魂印运转内息，吐气渐变悠长．．．\n\n"NOR,this_object());
		perform_busy(10);
		// delay 20,争取在这段时间里挂掉他吧
		call_out("hurting",20);
	}

	set("force",query("max_force")*2);
	
	// about 4k dmg/5 hits	enough time to heal
	if (me->query_temp("xxx/1")+ 30 < time()) {
		ccommand("perform yuhuan");	
		me->set_temp("xxx/1", time());
		me->stop_busy();
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

