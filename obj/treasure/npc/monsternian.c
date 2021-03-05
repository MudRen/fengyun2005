#include <ansi.h>
#include <combat.h>
inherit NPC;

void create()
{
	set_name(HIY"年兽"NOR, ({ "monster nian" }) );
	set("title",HIR"民间传说"NOR);
	set("nickname",YEL"形若狮子而独角"NOR);
	set("race","野兽");
	set("long",YEL"在太古时期，有一种凶猛的怪兽，散居在深山密林中，人们管它们叫“年”。\n"NOR);
	set("combat_exp",1);
	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);
	set("no_fight",1);
	set("no_beg",1);
	set("no_steal",1);
	set("busy_immune",4);
	set("no_heal",1);
	set("real_boss",1); //和杀BOSS一样，在全频道公告。
	    

  //给玩家一点小小的麻烦，杜绝NEW ID攻击。
  //set_temp("damage_shield/type","kee");
  //set_temp("buffup/backfire","all");
  //set_temp("buffup/backfire_amount",random(30));
  //set_temp("buffup/backfire_msg",BRED+YEL"鳞片飞散，逼得$n喘不过气来！\n"NOR);


		set("drop/fixed_amount",2); //掉落1本书 不掉落最高卷轴
		set("drop/fixed_drop", ({
		BOOKS"class/cloud-dance_yegui_1",	
		BOOKS"class/cloud-dance_yegui_2",	
//	BOOKS"class/cloud-dance_yegui_3",	
		BOOKS"class/dragonstrike_zjbl_2",	
		BOOKS"class/dragonstrike_zjbl_3",	
//	BOOKS"class/dragonstrike_zjbl_4",
		BOOKS"class/dream-herb_huanmengluo_2",	
//	BOOKS"class/dream-herb_huanmengluo_3",	
//	BOOKS"class/essencemagic_team_drift_1",	
//	BOOKS"class/fengmo-staff_fengmo",	
		BOOKS"class/gouyee_heal_2",	
//	BOOKS"class/gouyee_heal_3",	
		BOOKS"class/iceheart_buffup_2",	
		BOOKS"class/iceheart_buffup_3",	
//	BOOKS"class/iceheart_buffup_4",	
		BOOKS"class/kwan-yin-spells_ma_2",	
		BOOKS"class/nine-moon-claw_weiwoduzun_2",	
//	BOOKS"class/nine-moon-claw_weiwoduzun_3",	
		BOOKS"class/qidaoforce_juxue_2",	
//	BOOKS"class/qidaoforce_juxue_3",
		BOOKS"class/xueyeqianzong_feline_2",	
//	BOOKS"class/xueyeqianzong_feline_3",	
//	BOOKS"class/xueyeqianzong_wolverine_3",	
		BOOKS"class/xuezhan-spear_liguang_2",	
//	BOOKS"class/xuezhan-spear_liguang_3",	
//	BOOKS"class/xuezhan-spear_liguang_4",	
		BOOKS"class/yijinjing_shield_2",	
//	BOOKS"class/yijinjing_shield_3",
		BOOKS"class/yue-spear_juechufengsheng_2",	
		BOOKS"learn/magic_60",
		BOOKS"learn/spells_100",
		BOOKS"learn/iron-cloth_75",
		BOOKS"axe_75",
		BOOKS"blade_75",
		BOOKS"hammer_75",
		BOOKS"spear_75",
		BOOKS"staff_75",
		BOOKS"sword_75",
		BOOKS"throwing_75",
		BOOKS"unarmed_75",
		BOOKS"whip_75",
		}));
	
	set("drop/bg",0);
	// as a low lv boss, giant rock w never bg..
	set("drop/common",100);
	set("drop/rare",0);	// no rare drops.
	set("drop/amount",3);	// 掉落1个道具
	set("drop/common_drop",({
		"/d/xinjiang/obj/lotus.c",
		"/d/huashan/obj/amber.c",
		"/obj/treasure/obj/budda-tooth.c",
		"/obj/generate/wrists_25_1.c",
		"/obj/generate/surcoat_25_2.c",
		"/obj/generate/neck_25_12.c",
		"/obj/generate/head_25_12.c",
		"/obj/generate/boots_25_13.c",
		"/obj/generate/surcoat_25_14.c",
		"/obj/generate/neck_25_2.c",
		"/obj/generate/head_25_2.c",
		"/obj/generate/cloth3_25_12.c",
		"/obj/generate/cloth1_25_2.c",
		"/obj/generate/boots_25_3.c",
		"/obj/generate/surcoat_40_3.c",
		"/obj/generate/surcoat_40_15.c",
		"/obj/generate/head_40_3.c",
		"/obj/generate/head_40_13.c",
		"/obj/generate/cloth1_40_13.c",
		"/obj/generate/wrists_40_2.c",
		"/obj/generate/neck_40_3.c",
		"/obj/generate/neck_40_13.c",
		"/obj/generate/cloth3_40_3.c",
		"/obj/generate/boots_40_4.c",
		"/obj/generate/boots_40_14.c",
		"/obj/generate/surcoat_55_4.c",
		"/obj/generate/surcoat_55_16.c",
		"/obj/generate/neck_55_4.c",
		"/obj/generate/head_55_4.c",
		"/obj/generate/head_55_14.c",
		"/obj/generate/wrists_55_3.c",
		"/obj/generate/neck_55_14.c",
		"/obj/generate/cloth2_55_4.c",
		"/obj/generate/cloth2_55_14.c",
		"/obj/generate/boots_55_5.c",
		"/obj/generate/boots_55_15.c",
		"/obj/generate/wrists_70_4.c",
		"/obj/generate/surcoat_70_17.c",
		"/obj/generate/neck_70_5.c",
		"/obj/generate/neck_70_15.c",
		"/obj/generate/head_70_15.c",
		"/obj/generate/boots_70_16.c",
		"/obj/generate/surcoat_70_5.c",
		"/obj/generate/head_70_5.c",
		"/obj/generate/cloth3_70_15.c",
		"/obj/generate/cloth1_70_5.c",
		"/obj/generate/boots_70_6.c",
		"/obj/generate/wrists_90_5.c",
		"/obj/generate/neck_90_6.c",
		"/obj/generate/neck_90_16.c",
		"/obj/generate/head_90_6.c",
		"/obj/generate/head_90_16.c",
		"/obj/generate/boots_90_7.c",
		"/obj/generate/surcoat_90_6.c",
		"/obj/generate/surcoat_90_18.c",
		"/obj/generate/cloth3_90_6.c",
		"/obj/generate/cloth1_90_16.c",
		"/obj/generate/boots_90_17.c",
	}) );
	set("drop/rare_drop",({
		"none",
	}) );
	
  set_temp("apply/armor",random(300));    // 护甲值 伤害=攻击-护甲
	set("max_kee",9000000);
	set("max_gin",9000000);
	set("max_sen",9000000);
	
	setup();
  call_out("self_destruct", 3600+random(3500)); //自动消灭时间 单位：秒
}

void init()
{
	add_action("do_killing", "kill");
	add_action("do_killing", "fight");
	add_action("do_killing", "steal");
}

int do_killing(object me)
{
	if (this_object()->is_fighting() || this_object()->is_busy()) {
          message_vision(CYN"$N热情的说道：后面的请排队，不要拥挤，不要拥挤。。。\n"NOR, this_object());
        	return 1;
        }
   return 0;
}

void kill_ob(object ob)
{
        if(is_fighting()) {
                ob->remove_enemy(this_object());
                ob->remove_killer(this_object());
                tell_object(ob,CYN"$N热情的说道：后面的请排队，不要拥挤，不要拥挤。。。\n"NOR);
                return ;
        }
        ::kill_ob(ob);
}


void die()
{
	object who = query_max_damage_dealer();
	object ob;
	object *itemx;
	int i,n;

	if (random(100)>=80) {
		ob = carry_object("/obj/money/gold");
		ob->set_amount(1+random(2));
	} else {
		ob = carry_object("/obj/money/silver");
		ob->set_amount(1+random(99));
		}
		//snowball = new("/obj/treasure/npc/obj/snowball.c");
		//if (snowball) snowball->move(this_object());

  switch (random(4)) {
                case 0: 		ob = carry_object("/obj/medicine/party/pill_chunjuan");
														ob->set_amount(1);
														break;
                case 1: 		ob = carry_object("/obj/medicine/party/pill_niangao");
														ob->set_amount(1);
														break;
                case 2: 		ob = carry_object("/obj/medicine/party/pill_tangyuan");
														ob->set_amount(1);
														break;
                case 3: 		ob = carry_object("/obj/medicine/party/pill_shuijiao");
														ob->set_amount(1);
														break;
                default:		
  }
	if (!objectp(who))
		who = query_temp("last_damage_from");
	
	if (objectp(who))
	{
		ANNIE_D->generate_drop_item(this_object(),who);
		itemx=all_inventory(this_object());
		for (i=0;i<sizeof(itemx) ;i++ )
			itemx[i]->move();
	}
	
	::die();
	return;
}

int self_destruct(){
	
		if (is_fighting() || is_busy()) {
			call_out("self_destruct",1);
			message_vision(HIY"$N"YEL"笑道：好了，就到这里，休息、休息一下。瞬间消失在林间深处！"NOR,this_object());
			destruct(this_object());
			return 1;
		}	
		message_vision(HIY"$N"YEL"叹了口气，站着给人打都没人要打，化为雾气消失在空中。\n"NOR,this_object());
		destruct(this_object());
		return 1;
}

/* Edit By Hippo 2009.10 */
