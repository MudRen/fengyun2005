// ; annie 07.2003
// dancing_faery@hotmail.com

inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int leave();
int look_stone();

void create()
{
	object weapon;
    set_name("薛音素", ({ "master xue", "master", "xue" }) );
    set("nickname", YEL"月神"NOR);
	set("gender", "女性");
    set("age",19);
    set("long",
"月色水波间，仿佛有层淡淡的烟雾升起，烟雾间仿佛有一条淡淡的人影。
云开，月现，月光淡淡的照下来，恰巧照在她的脸上。苍白的股，苍白如
月。\n"
        );

	set("combat_exp", 90000000);
    set("score", -10000);
    set("class", "moon");
    set("reward_npc", 1);
    set("difficulty", 10);

	set("no_fly",1);
	set("no_arrest",1);

	set("guard_msg",CYN"$N皱眉道：欺负我皓月宫的人，欺负上我这里来了？\n"NOR);

	set("inquiry",([
		"李坏": (: look_stone :),
    	]) );

    set("force", 3000);
    set("max_force", 3000);
    set("force_factor", 100);
    set("atman", 1400);
    set("max_atman", 1400);
    set("mana", 2000);
    set("max_mana", 2000);

    set("resistance/gin",70);
    set("resistance/kee",70);
    set("resistance/sen",70);
	
    set("inquiry", ([
		"李坏": (: look_stone :),
         ]) );

    set("apprentice_available", 1);

    create_family("皓月宫", 3, "宫主");
	set("title","皓月宫");

    set("rank_nogen",1);
    set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
		set("ranks",({ "小童","玉盘","婵娟","望舒","纤维","金波 ",
			               "玉弓","桂殿","团扇","玉桂","银台","五羊",
		YEL"素娥"NOR,YEL"太清门人"NOR,YEL"冰魄传人"NOR,HIY"蟾宗宗主"NOR}));

    set_skill("literate", 100);
	set_skill("starrain", 200);
	set_skill("force", 160);
	set_skill("chanting",160);
	set_skill("snowforce", 170);
	set_skill("blade", 250);
	set_skill("chillblade", 190);
	set_skill("throwing", 250);
	set_skill("parry", 160);
	set_skill("dodge", 200);
	set_skill("move", 170);
	set_skill("stormdance", 200);
	set_skill("perception",160);
	set_skill("foreknowledge",100);

	map_skill("throwing","starrain");
    map_skill("parry", "chillblade");
    map_skill("blade", "chillblade");
    map_skill("move", "stormdance");
    map_skill("dodge", "stormdance");
    map_skill("force", "snowforce");

    setup();

	weapon = carry_object("/obj/armor/cloth");
	weapon->set("name",WHT"飞雪沉纱"NOR);
	weapon->set("long","一件似有还无的素白纱衣。");
	weapon->wear();
	weapon=carry_object("/questnpc/obj/leaf");
    weapon->set_name(HIW"至刚白羽"NOR, ({ "white feather" }) );
	weapon->set("long","一簇洁白的羽毛，看似极其柔弱，其实坚硬无比。\n");
	weapon->set("base_unit","根");
	weapon->set("value",0);
	weapon->set_amount(909);
	weapon->set("volumn",909);
	weapon->wield();

}

void reset()
{
	set("apprentice_available", 1);
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) 
        {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。\n");
                else
                        call_out("do_recruit", 2, ob);
        } 
        else {
                command("flook");
        }
}

void do_recruit(object me)
{
	if( (string)me->query("class") != "moon" )
	{
		command("flook" );
	}
	else
	{
		if (REWARD_D->check_m_success(me,"两世恩怨") >0 && me->query("imbue/moon_xue"))
		{
			command("sigh");
			command("recruit " + me->query("id") );
			command("flook");
		}
		else
			command("flook" );
	}
}
		
int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "moon");
	add("apprentice_availavble", -1);
}


void init()
{
	::init();
	add_action("do_killing", "kill");
}

int leave()
{
    if (this_player()->query("class")!="moon") return 0;
	message_vision(CYN"$N淡淡的扫了$n一眼。\n"NOR, this_object(),this_player());
	message_vision(CYN"$N说：既然你一心要走，我也不想勉强。\n"NOR,this_object(),this_player());
	message_vision(CYN"$N说：只是门中各艺的精髓，你是都无法再用的了。\n"NOR,this_object(),this_player());
    return 1;
}

int look_stone()
{
	object me;
	me=this_player();
	if (REWARD_D->check_m_success(me,"两世恩怨") >0)
	{
		ccommand("say ……。");
		return 1;
	}
	if (REWARD_D->riddle_check(me,"两世恩怨") == 10 )
	{
	ccommand("emote 闻讯惨然一笑：……李坏，李坏，我们终于要再见了么？");
	ccommand("emote 闭上双眼慢慢地叹了口气。");
	ccommand("nod");
	REWARD_D->riddle_set(me,"两世恩怨",11);
	return 1;
	}

	if (random(2))
	{
		message_vision("$N低声叹息：你说为什么，心上就会依依切切的挂着他呢……\n"NOR,this_object(),this_player());
	}
	else
	{
		message_vision("$N望着远方的晴空，幽幽道：不知他现在可好，是不是还喜欢\n在初雪的日子里唱歌……\n"NOR,this_object(),this_player());
	}
    return 1;
}


int accept_object(object me, object obj)
{
	if (obj->query("name") == "小纸袋" && obj->query("real") == 3)
	{
		if (REWARD_D->riddle_check(me,"两世恩怨") == 2 && me->query_temp("annie/xiangsi_master") == 4)
		{
			ccommand("say 难为你了，竟还把它找了出来。");
			ccommand("say 只是这些日子我又想了很多……还是都随缘而定，天意要让我与他\n为敌，逃得了一时，也逃不了一世的。");
			ccommand("say 我不想再去改变什么……该怎样的，就怎样吧。");
			REWARD_D->riddle_set(me,"两世恩怨",3);
			return 0;
		}

	}
	command("smile");
	command("shake");
	return 0;
}

/*

薛音素目前共学过十二种技能：

  基本刀法 (blade)                         - 出神入化 150/    0
＊冰镜七诀 (chillblade)                    - 出神入化 150/    0
  纵跃闪躲之术 (dodge)                     - 深不可测 200/    0
  内功心法 (force)                         - 一代宗师 180/    0
  读书识字 (literate)                      - 豁然贯通 150/    0
  基本轻功 (move)                          - 深不可测 200/    0
  拆招卸力之法 (parry)                     - 登峰造极 170/    0
  听风辨器之术 (perception)                - 深不可测 300/    0
＊冷雪心经 (snowforce)                     - 出神入化 140/    0
＊寒星雨觞 (starrain)                      - 深不可测 200/    0
＊天岚凝舞 (stormdance)                    - 深不可测 200/    0
  暗器使用 (throwing)                      - 深不可测 300/    0

以下是你目前使用中的特殊技能。
——————————————————————————————————
  刀法 (blade)            ： 冰镜七诀         有效等级：300     
  闪躲术 (dodge)          ： 天岚凝舞         有效等级：570     
  内功 (force)            ： 冷雪心经         有效等级：300     
  读写 (literate)         ： 无               有效等级： 75     
  轻功 (move)             ： 天岚凝舞         有效等级：570     
  招架 (parry)            ： 冰镜七诀         有效等级：310     
  听风术 (perception)     ： 无               有效等级：300     
  暗器 (throwing)         ： 寒星雨觞         有效等级：390     
 
有效等级 = 基本技能/2 + 特殊技能*武功系数
亮绿色或红色的数字表示来自于武器、Perform、或Advanced-skill的修正值。
 
——————————————————————————————————

*/
/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/
