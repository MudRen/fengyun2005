inherit SMART_NPC;
#include <ansi.h>
int kill_him();

void create()
{
        set_name("林道人", ({ "taoist lin" }) );
        set("nickname",HIG "快鞭" NOR);
        set("gender", "男性");
        set("title","三清供奉");
        set("age", 65);
        set("long",
"林道人是丁氏兄妹从南疆请来的三清宫四供奉之一。\n"
);
	set("attitude", "friendly");
        set("combat_exp", 550000);
        set("score", 2000);

        set("class", "yinshi");

    	set("reward_npc", 1);
		set("difficulty", 1);

        set("inquiry", ([
                "谷衣心法": 
"谷衣心法是我茅山派为对抗邪魔外道所创的内功心法。\n",
		         "内奸" : "action"CYN"“内奸？”林道人捻捻小胡子，摇头道：“你想必是弄错了吧。”\n"NOR,
                "三清道宗":  (: kill_him :),
        ]) );
		
		set("perform_weapon_attack", "palace/whip/thunderwhip/tianleiyiji");
	
		set("chat_chance_combat", 30);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );

		set_skill("flame-strike",100);
        set_skill("move", 100);
        set_skill("force", 100);
        set_skill("spells", 100);
        set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("gouyee", 100);
		set_skill("whip",100);
		set_skill("thunderwhip",100);
		set_skill("zuixian-steps",160);
        set_skill("cursism", 100);
        set_skill("necromancy", 100);    

        map_skill("spells", "necromancy");
        map_skill("force", "gouyee");
        map_skill("whip","thunderwhip");
        map_skill("dodge","zuixian-steps");
        map_skill("parry","thunderwhip");
        map_skill("move","zuixian-steps");
        map_skill("unarmed","flame-strike");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup();

        add_money("coin", 30);
        carry_object(__DIR__"obj/l_whip")->wield();
	carry_object(__DIR__"obj/l_cloth")->wear();
}


int kill_him()
{
	object me;
	me = this_player();
	if (!me->query("annie/demon_puzzle") || REWARD_D->riddle_check(me,"无字天书") != 4)
	{
		message_vision(CYN"$N冷冷的看了$n一眼，从鼻孔里哼了一声。\n",this_object(),me);
		command("say 你管的也太多了吧！\n");
		this_object()->kill_ob(me);
		me->kill_ob(this_object());
		me->perform_busy(2);
		return 1;
	}
	else
	{
		if (!me->query_temp("annie/demon_lin"))
		{
			me->set_temp("annie/demon_lin",1);
			command("say 有趣，有趣。你怎么会知道这件事？");
			command("say 既然如此，我就告诉你一个秘密。");
			command("say "+me->query("annie/demon_puzzle_lin")+"\n");
		}
		else
		{
			command("say 哦？你认为我就是偷书的人？\n");
			command("say 且不管是或不是，已经留不得你了！\n");
			this_object()->kill_ob(me);
			me->kill_ob(this_object());
			me->start_busy(2);
		}
	}
	return 1;
}

void die()
{
	object me, owner;
    if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed"))
			me = owner;
	if (!me)
	{
		::die();
		return;
	}

	if (!me->query_temp("annie/demon_lin") || REWARD_D->riddle_check(me,"无字天书") != 4)
	{
		::die();
		return;
	}
	this_object()->full_me();
//	"/cmds/imm/full"->main(this_object(),"");
	if (me->query("annie/demon_puzzle") == 1)
	{
		message_vision(CYN"\n$N在垂死之际忽然挣扎而起，扭曲着脸对$n说：\n",this_object(),me);
		message_vision("好……好吧，我就……就告诉你，那本书现在就在……就在……太清殿门……\n\n",this_object(),me);
		message_vision(RED"一把飞刀突然从暗处飞出，迅疾的插入了$N的咽喉。\n\n"NOR,this_object(),me);
		message_vision(HIY"$N的眼珠死鱼般的突了出来，喉中咯咯作响，死命的瞪着$n背后。\n$N忽然用双手拔下飞刀，只见一道血泉标出，$N厉叫道：三……弟……\n\n"NOR,this_object(),me);
		REWARD_D->riddle_set(me,"无字天书",5);
		REWARD_D->riddle_done(me,"三清锄奸",50,1);
	}
	else
	{
		message_vision(CYN"$N在垂死之际忽然挣扎而起，扭曲的脸贴近$n的耳朵，悄声说了一句话。\n",this_object(),me);
		tell_object(me,name()+"告诉你：你错了，书不是我偷的。\n");
		message_vision("$n脸色大变，而$N已经在狂笑声中倒了下去。\n\n"NOR,this_object(),me);
		// failed,penalty: clean marks,从头做起
		REWARD_D->riddle_clear(me,"无字天书");
		me->add("annie/demon_xin_failed",1);
	}
	::die();
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

