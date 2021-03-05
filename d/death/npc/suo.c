// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

// 2009 FengYun
// Edit by hippo 2009.11
// 孝道 关联

inherit NPC;
#include <ansi.h>
int story();
int give_me_it(object me);
int give_me_it_zouzhe(object me);

int annie_drug()
{
	object me = this_player();

	if (REWARD_D->riddle_check(me,"天灵翡翠")==9){
		give_me_it(me);
		return 1;
	}
			
	if (REWARD_D->riddle_check(me,"天灵翡翠") == 5)
	{
		message_vision(query("name")+"微微一笑，点头道：梅二先生已知会过我了。\n",me);
		message_vision(query("name")+"道：你只消为我寻来"HIR"茵生草"NOR"和"HIB"两生花"NOR"，我便将明烟草给你。\n",me);
		REWARD_D->riddle_set(me,"天灵翡翠",6);
		return 1;
	}
	message_vision(query("name")+"微摇螓首：难为你找到这里，不过这草于我另有他用，不能给你。\n",me);
	return 1;
}


void create()
{
        set_name("缇萦", ({ "xiaonu", "nu" }) );
        set("gender", "女性" );
        set("long","
以孝道而闻名天下的缇萦。班固有诗赞：“三王德弥薄，惟后用肉刑。
太仓令有罪，就递长安城。自恨身无子，困急独茕茕。小女痛父言，
死者不可生。上书诣阙下，思古歌《鸡鸣》。忧心摧折裂，晨风扬激声。
圣汉孝文帝，恻然感至情。百男何愦愦，不如一缇萦。”\n");
        set("age", 24);
		set("per", 30);
		set("attitude","friendly");
        
        set("inquiry", ([
			//"孝道" : "身体发肤受之父母，养育之恩，有甚于天，不孝之人，鬼神难容。\n",
			//"xiao" : "身体发肤受之父母，养育之恩，有甚于天，不孝之人，鬼神难容。\n",
			"孝" : CYN"我情愿给官府收为奴婢，替父亲赎罪，但我的心愿是得到"YEL"孝女花"CYN"，献给我的父亲！\n",
			"xiao" : CYN"我情愿给官府收为奴婢，替父亲赎罪，但我的心愿是得到"YEL"孝女花"CYN"，献给我的父亲！\n",
			"孝道" : CYN"我情愿给官府收为奴婢，替父亲赎罪，但我的心愿是得到"YEL"孝女花"CYN"，献给我的父亲！\n",
			"墨" : HIC"书香门第总该有吧！\n",
			"孝女花" : CYN"孝女花由"YEL"六种花"CYN"以及"YEL"神石"CYN"同时还需要佛门无上法道，才能一气呵成。\n",
			"六种花" : CYN"这个六种花各有个的含义：\n
				"HIC"第一朵代表：顺利、心想事成、祝福、高贵。\n"CYN"
				"HIG"第二朵代表：愉快、幸福、纯洁、天真、和平、希望、美人、深埋心底的爱。\n"CYN"
				"HIW"第三朵代表: 永恒的爱与约定。\n"CYN"
				"HIY"第四朵代表: 呵护。\n"CYN"
				"HIB"第五朵代表: 因爱而有些忧郁。\n"CYN"
				"HIC"最后一朵得来不宜， 人间云：那是起死回生的圣物。\n"CYN"
				",
			"神石" : CYN"那是一颗能够使花屹立不倒、不再凋谢的神奇石头，据说是邪马台国贡品，现在可能流落到民间商贩手中了。\n",
			          	"明烟草" : 	(: annie_drug :),
          	"另有别用":	"action缇萦脸红了红，微笑不语。\n",
			"茵生草": "我当年移种明烟草的时候曾在同一处地方见过它。\n那草鲜红若血，叶瓣八分，你一见就可以认出来了。\n",
			"两生花": "这花素喜极险极峭之地，从东南到西北，各处悬崖都可能是它延生所在。\n",
			"移种": 			 (: story :),
			"同一处地方":  	(: story :),
			"地方":  		(: story :),
			"潭":	 "action缇萦微微笑了笑说：那是个很险峻的地方，很少有人去呢。\n",
			"潭边":  "action缇萦微微笑了笑说：那是个很险峻的地方，很少有人去呢。\n",
      ]) );
        set("combat_exp", 2200000);
        set_skill("xiaodao", 200);
        set("skill_public",1);
        set("chat_chance", 1);
    		set("chat_msg", ({
						"缇萦嘀嘀咕咕：身体发肤受之父母，养育之恩，有甚于天，不"YEL"孝"NOR"之人，鬼神难容。 \n",
			    	}) );   
		set_temp("apply/attack",200);
		set_temp("apply/dodge", 200);
		set_temp("apply/parry", 200);
        setup();
        carry_object("/obj/armor/ghost_cloth")->wear();
}


int is_ghost() { return 1; }

int story(){
		tell_object(this_player(),CYN"缇萦说：茵生草、两生花、明烟草，原来都是我在山里同一块地方见到的，都是稀世
的药材，家父东迁临淄，我便把两生花和明烟草移种到了东边的山上，原本还要回去
取那茵生草的，没想到家父为人陷害入狱，远赴长安，也就再也没有回去过。

缇萦幽幽地叹了口气：也不知茵生草是否还在那潭边，还有我那可爱的小乌龟，是
不是还在那翡翠池里。。。。\n"NOR);
		return 1;
}


int give_me_it(object me)
{
	object x;
	x=new(__DIR__"obj/grass");
	if (!x->move(me))
		x->move(environment(me));
	message_vision("缇萦微笑道：多谢。\n缇萦递给$N一株小草。\n",me);
	return 1;
}

int give_me_it_zouzhe(object me)
{
	object x;
	x=new(__DIR__"obj/zouzhe");
	if (!x->move(me))
		x->move(environment(me));
	message_vision("缇萦递给$N一本"HIW"奏折"NOR"。\n缇萦急道："CYN"“请速往！”\n"NOR,me);
	return 1;
}

int accept_object(object who, object ob)
{
	object me = who;
///////////////////////////////////////////孝道谜题//////////////////////////////////////////////////////	
	if (ob->query("name") == HIG"孝女花"NOR)
	{
		if (ob->query("lore"))
		{
			//message_vision("$N接过"+ ob->name() + "万分欣喜：“太好了，太好了，吾父有救矣。”\n",me);
			message_vision("缇萦一筹莫展道："CYN"“向皇上进言之事，还需得贵人相助。”\n"NOR,me);
			if (REWARD_D->riddle_check(me,"孝感苍天") == 1)
			{
				REWARD_D->riddle_set(me,"孝感苍天",2);
				return 0;
			}
		}
		//message_vision("$N急切地说：你尽然还有心情和小女子开玩笑！\n", me);			
		//message_vision("缇萦对$N微笑道：近日地府用度短缺，多谢捐赠。\n",me);
		return 0;
	}

	if (ob->query("name") == "素纸" && REWARD_D->riddle_check(me,"孝感苍天") == 3)
	{
		if (ob->query("lore"))
		{
			message_vision("缇萦接过"+ ob->name() + "说道：“麻烦再帮小女子取来"YEL"笔"NOR"、"HIC"墨"NOR"、"YEL"砚"NOR"。”\n",me);
			REWARD_D->riddle_set(me,"孝感苍天",4);
			return 1;
		}
		//message_vision("$N急切地说：你尽然还有心情和小女子开玩笑！\n", me);			
		//message_vision("缇萦对$N微笑道：近日地府用度短缺，多谢捐赠。\n",me);
		return 0;
	}

	if (REWARD_D->riddle_check(me,"孝感苍天") == 4)
	{
		if (ob->query("name") == "笔" || ob->query("name") == "墨" || ob->query("name") == "砚台")
		{
			string *material_names=({ "笔","墨","砚台" });
			string ob_name;
			int success, makeup_ok,i;
			object book;
			
			
			if (!REWARD_D->riddle_check(me,"孝感苍天")) {
					command("say 缇萦对$N微笑道：近日地府用度短缺，多谢捐赠。\n");
				return 1;
			}
			
			ob_name= ob->query("name");
			success=1;
			makeup_ok=0;
			for(i=0;i<3;i++)
			{
				if(ob_name==material_names[i])
				{
					if(me->query_temp("marks/death/xiaonv/"+ob_name))
					{
						command("say 这东西你不是给过我了。”\n");
						return 1;
					}
					me->set_temp("marks/death/xiaonv/"+ob_name,1);
					command("say 便是此物，多谢了。");
					makeup_ok=1;
				}
				success=success*me->query_temp("marks/death/xiaonv/"+material_names[i]);
			}
			if(!success) return makeup_ok; 
				
			me->delete_temp("marks/death/xiaonv/");	
			
			tell_object(me,"缇萦说："CYN"“都齐了，请稍等！”\n"NOR);
			give_me_it_zouzhe(me);
			REWARD_D->riddle_set(me,"孝感苍天",5);
	    return 1;
	  }
	}
	
	if (ob->query("name") == HIR"赦免令"NOR && REWARD_D->riddle_check(me,"孝感苍天") == 6)
	{
		if (ob->query("lore"))
		{
			message_vision("缇萦接过"+ ob->name() + "万分欣喜："CYN"“太好了，太好了，吾父有救矣。”\n"NOR,me);
			message_vision("缇萦贴近$n的右脸轻语道："CYN"“小女子无以为报，愿将孝道倾囊相授。”\n"NOR, ob, me);
			me->set("free_learn/xiaodao", 1);
			REWARD_D->riddle_done(me, "孝感苍天", 20, 1);
			return 1;
		}
		//message_vision("$N急切地说：你尽然还有心情和小女子开玩笑！\n", me);			
		//message_vision("缇萦对$N微笑道：近日地府用度短缺，多谢捐赠。\n",me);
		return 0;
	}

///////////////////////////////////////////以上孝道谜题//////////////////////////////////////////////////////	

	if (REWARD_D->riddle_check(me,"天灵翡翠") != 6 && REWARD_D->riddle_check(me,"天灵翡翠") != 7 && REWARD_D->riddle_check(me,"天灵翡翠") != 8 )
	{
		message_vision("缇萦对$N微笑道：近日地府用度短缺，多谢捐赠。\n",me);
		return 1;
	}

	if (REWARD_D->riddle_check(me,"天灵翡翠") == 6)
	{
		if (ob->query("name") == HIB"两生花"NOR && ob->query("real_flower") == 1)
		{
			REWARD_D->riddle_set(me,"天灵翡翠",7);
			message_vision("缇萦微笑道：便是此物，多谢了。\n",me);
			return 1;
		}
		else if (ob->query("name") == HIR"茵生草"NOR && ob->query("real_flower") == 2)
		{
			REWARD_D->riddle_set(me,"天灵翡翠",8);
			message_vision("缇萦微笑道：便是此物，多谢了。\n",me);
			return 1;
		}
		message_vision("缇萦对$N微笑道：近日地府用度短缺，多谢捐赠。\n",me);
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"天灵翡翠") == 7)
	{
		if (ob->query("name") == HIR"茵生草"NOR && ob->query("real_flower") == 2)
		{
			REWARD_D->riddle_set(me,"天灵翡翠",9);
			give_me_it(me);
			return 1;
		}
		message_vision("缇萦对$N微笑道：近日地府用度短缺，多谢捐赠。\n",me);
		return 1;
	}

	if (REWARD_D->riddle_check(me,"天灵翡翠") == 8)
	{
		if (ob->query("name") == HIB"两生花"NOR && ob->query("real_flower") == 1)
		{
			REWARD_D->riddle_set(me,"天灵翡翠",9);
			give_me_it(me);
			return 1;
		}
		message_vision("缇萦对$N微笑道：近日地府用度短缺，多谢捐赠。\n",me);
		return 1;
	}
	message_vision("缇萦对$N微笑道：出错了，你还不去报告巫师么？\n",me);
	return 1;
}

int recognize_apprentice(object ob)
{
     if(ob->query("free_learn/xiaodao"))
     		return 1;
		 return 0;
}

int prevent_learn(object me, string skill)
{
  	if (skill != "xiaodao")
  	{
      		command("shake");
      		command("say 我可只答应教你孝道啊。");
      		return 1;
  	}
  	return 0;
}

int prevent_shown(object me, string skill)
{
	if (me->query("free_learn/xiaodao")	&& skill == "xiaodao")
		return 0;
	
	return 1;
}