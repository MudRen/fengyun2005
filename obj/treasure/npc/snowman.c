#include <ansi.h>
#include <combat.h>
inherit WALL;

void create()
{
	set_name(HIW"雪人"NOR, ({ "snow man" }) );
	set("title",HIY"圣诞节"NOR);
	set("nickname",WHT"一身洁白"NOR);
	set("race","元素");
	set("long",WHT"一个高大的"HIW"雪人"NOR+WHT"，肚子看上去鼓鼓的。\n"NOR);
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
  set_temp("buffup/backfire","all");
  set_temp("buffup/backfire_amount",random(30));
  //set_temp("damage_shield/amount",random(100));
  set_temp("buffup/backfire_msg",WHT"雪花飘散，瞬间$n就被雪掩埋了！\n"NOR);
  //set_temp("damage_shield/msg",WHT"雪花飘散，瞬间$n就被雪掩埋了！\n"NOR);


		set("drop/fixed_amount",1); //掉落1本书 不掉落最高卷轴
		set("drop/fixed_drop", ({
			BOOKS"class/cloud-dance_yegui_1",	
			BOOKS"class/cloud-dance_yegui_2",	
//			BOOKS"class/cloud-dance_yegui_3",	
			BOOKS"class/dragonstrike_zjbl_2",	
			BOOKS"class/dragonstrike_zjbl_3",	
//			BOOKS"class/dragonstrike_zjbl_4",
			BOOKS"class/dream-herb_huanmengluo_2",	
//			BOOKS"class/dream-herb_huanmengluo_3",	
//			BOOKS"class/essencemagic_team_drift_1",	
//			BOOKS"class/fengmo-staff_fengmo",	
			BOOKS"class/gouyee_heal_2",	
//			BOOKS"class/gouyee_heal_3",	
			BOOKS"class/iceheart_buffup_2",	
			BOOKS"class/iceheart_buffup_3",	
//			BOOKS"class/iceheart_buffup_4",	
			BOOKS"class/kwan-yin-spells_ma_2",	
			BOOKS"class/nine-moon-claw_weiwoduzun_2",	
//			BOOKS"class/nine-moon-claw_weiwoduzun_3",	
			BOOKS"class/qidaoforce_juxue_2",	
//			BOOKS"class/qidaoforce_juxue_3",
			BOOKS"class/xueyeqianzong_feline_2",	
//			BOOKS"class/xueyeqianzong_feline_3",	
//			BOOKS"class/xueyeqianzong_wolverine_3",	
			BOOKS"class/xuezhan-spear_liguang_2",	
//			BOOKS"class/xuezhan-spear_liguang_3",	
//			BOOKS"class/xuezhan-spear_liguang_4",	
			BOOKS"class/yijinjing_shield_2",	
//			BOOKS"class/yijinjing_shield_3",
			BOOKS"class/yue-spear_juechufengsheng_2",	
		}));
	
	set("drop/bg",0);
	// as a low lv boss, giant rock w never bg..
	set("drop/common",100);
	set("drop/rare",0);	// no rare drops.
	set("drop/amount",1);	// 掉落1个道具
	set("drop/common_drop",({
		"/d/xinjiang/obj/lotus.c",
		"/d/huashan/obj/amber.c",
		"/obj/treasure/obj/budda-tooth.c",
		"/obj/book/learn/magic_60.c",
		"/obj/book/learn/spells_100.c",
		"/obj/book/learn/iron-cloth_75.c",
		"/obj/book/axe_75.c",
		"/obj/book/blade_75.c",
		"/obj/book/hammer_75.c",
		"/obj/book/spear_75.c",
		"/obj/book/staff_75.c",
		"/obj/book/sword_75.c",
		"/obj/book/throwing_75.c",
		"/obj/book/unarmed_75.c",
		"/obj/book/whip_75.c",
	}) );
	set("drop/rare_drop",({
		"none",
	}) );
	
  set_temp("apply/armor",random(300));    // 护甲值 伤害=攻击-护甲
	//set("max_kee",100000);
	//set("max_gin",100000);
	//set("max_sen",100000);
	
	setup();
  call_out("self_destruct", 3600+random(3500)); //自动消灭时间 单位：秒
  //call_out("self_destruct", 10); //自动消灭时间 单位：秒
}

void init()
{
	add_action("do_killing", "kill");
	add_action("do_killing", "fight");
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
	object ob,snowball;
	object *itemx;
	int i;	

	if (random(2)) {
		ob = carry_object("/obj/money/gold");
		ob->set_amount(1+random(5));
	} else {
		ob = carry_object("/obj/money/silver");
		ob->set_amount(1+random(99));
	}
	snowball = new("/obj/treasure/npc/obj/snowball.c");
	if (snowball) snowball->move(this_object());	

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
			message_vision(HIW"$N"WHT"笑道：好了，就到这里，休息、休息一下。转眼间化为了雪堆！"NOR,this_object());
			destruct(this_object());
			return 1;
		}	
		message_vision(HIW"$N"WHT"叹了口气，站着给人打都没人要打，转眼间化为了雪堆。\n"NOR,this_object());
		destruct(this_object());
		return 1;
}

/*
int quest()
{
	string *area = ({ 	
		"huangshan", "huashan", "songshan", "palace", "laowu", 
		"resort", "qianfo", "qingping", "taoguan", "taoyuan", 
		"xinjiang","wanmei","eren",		
		"chuenyu", "taishan", "guanyin","wolfmount","qianjin",
		"biancheng", "zangbei","baiyun" ,"bat","changchun"});
		
	string *c_area =  ({"黄山","华山","嵩山","帝王谷","冰封小镇",
				"铁雪山庄","千佛山","清平山庄","三清山","桃源村",
				"新疆", "万梅山庄","恶人谷",
			    "黑松山","泰山","天枫山庄","狼山","千金楼", 
			    "边城", "藏北","白云岛","蝙蝠岛","长春岛",
			    });

	string arg, room_name, *files;
	int i,m,size;
	object room;
	object sm;
	object me = this_player();
	//mapping quest,*s_quest;

		m = random(sizeof(area));
		arg = "/d/"+area[m] +"/";
		files= get_dir(arg);

		for (int n=0;n<10+(random(10));n++){

		while(1)
		{
			i = random(sizeof(files));
			size = sizeof(files[i]);
			message_vision("file is "+ files[i] +"\n", me);
			if(files[i][(size-2)..size]==".c")
			{
				room_name = arg + files[i];
				room = find_object(room_name);
				if (!room)
					room = load_object(room_name);
				if (!room)	continue;
				if (!room->query("short")) 		continue;
				if (room->query("no_fly")) 		continue;
				if (room->query("no_fight")) 	continue;	
				if (room->query("underwater")) 	continue;
				break;
			}
		}
		sm = new("/obj/treasure/npc/snowman");
		sm->move(room);
		}
}
*/

/* Edit By Hippo 2009.10 */
