inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();
string do_flee();

void create()	
{
    object weapon;

	set_name("苦瓜大师", ({ "kugua","boss"}) );
	set("gender", "男性" );
	set("nickname",BLU"妙手素斋"NOR);
    set("title","兴国寺挂搭和尚");
	set("class","bonze");
set("long","苦瓜大师是当年天下第一名捕金九龄的师兄，却不像金九龄对名声权欲那
般在意。真正能入得了大师法眼的，或许只有锅盆瓢铲，而苦瓜和尚最出
名的，也就是那一手妙绝天下的素斋了吧。\n");

		set("spawn_location","/d/qianfo/zt2");
        set("gender", "男性" );
		set("agi",70);
		set("gold",30);
		set("real_boss",1);
		set("boss",1);	// immune to some rascal skill and ghostcurse.
						// busy resist but not immune.

        set("attitude","friendly");
    
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );

        set("combat_exp", 6100000);	// L125. CAP @ L95.
    
        set_skill("force", 400);
        set_skill("lotusforce",250);
        set_skill("magic", 200);
        set_skill("essencemagic",400);		//	random (700) + 700 sen damage per light_sense... 
        set_skill("unarmed", 200);
        set_skill("luohan-quan",300);	// 不，还是不要enable这个了..	 // 不，还是enable吧:p
        set_skill("dodge", 200);
        set_skill("fall-steps",200);	// 不，还是不要enable这个了..	 // 不，还是enable吧:p
		set_skill("parry",200);
		
		
        map_skill("dodge", "fall-steps");
        map_skill("unarmed", "luohan-quan");
        map_skill("force", "lotusforce");
        map_skill("magic", "essencemagic");
		
		set("max_kee",80000);
		set("max_gin",70000);
		set("max_sen",70000);
        
		setup();

		weapon=carry_object("/obj/armor/cloth");
		weapon->set_name(YEL"莲洁僧衣"NOR, ({ "cloth" }) );
		weapon->set("long","莲洁僧衣(Cloth)。");
		weapon->set("value",0);
		weapon->wear();
	
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
"/obj/generate/surcoat_110_7.c",
"/obj/generate/head_110_7.c",
"/obj/generate/head_110_17.c",
"/obj/generate/cloth2_110_17.c",
"/obj/generate/boots_110_18.c",
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

int hurting()
{
	message_vision(HIY"\n$N"HIY"慢慢吐出一口长气，身上的伤势竟在转眼间尽数消失。\n"NOR,this_object());
	full_me();
	set("annie/ec",time());
	return 1;
}


void dist(object ghost)
{
	if (!ghost)
		return;
	message_vision(BLU"$N在空中打了个旋儿，形体渐渐消散无影．．．\n"NOR,ghost);
	destruct(ghost);
	return;
}

void smart_fight()
{
	object ob;
	mapping buff;
	object *enemy;
	int i;

	set("atman",query("max_atman")*2);

	// 召唤天王
	if (!present("天王",environment()) && time()>query("annie/sh")+30)
	{
		message_vision(BMAG YEL"\n召唤天王\n"NOR,this_object());
		message_vision(CYN"\n$N沉声喝道：护法天王何在？\n．．．天空中隆隆雷声响起，一个天王应召而来！\n\n"NOR,this_object());
		ob = new("/d/qianfo/npc/tianwang"+(1+random(4)));
//		ob->delete("no_shown");
		ob->set("name","天王");
		ob->set("combat_exp",5000000+random(1000000));
		"/feature/nada"->reset_npc(ob);
		ob->full_me();
		ob->move(environment());
		set("annie/sh",time());

		enemy=query_enemy();
		i = sizeof(enemy);
		while(i--) {
			if( enemy[i] && living(enemy[i]) ) {
				ob->kill_ob(enemy[i]);
				enemy[i]->kill_ob(ob);
			}
		}
		ob->set("possessed",this_object());
		call_out("dist",60,ob);
	}
//	ccommand("conjure shade_sense");
	
	// 回复体力
	if (!random(3) && time()>query("annie/ec")+ 600 && 
		(query("kee") < query("max_kee")/3
		|| query("sen")< query("max_sen")/3
		|| query("gin")< query("max_gin")/3))
	{
		message_vision(BBLU HIW"\n六脉顺气\n"NOR,this_object());
		message_vision(HIG"\n$N"HIG"双手合十，低声吟咏．．．\n\n"NOR,this_object());
		perform_busy(10);
		// delay 20,争取在这段时间里挂掉他吧
		call_out("hurting",20);
	}

	if (random(3))	ccommand("conjure light_sense");
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

