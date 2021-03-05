inherit SMART_NPC;
#include <ansi.h>
void  smart_fight( object who);
int kill_him();

void create()
{
        set_name("山道人", ({ "taoist shan","shan" }) );
        set("nickname",HIY "狂杖" NOR);
        set("title","三清供奉");
        set("gender", "男性");
        set("age", 60);
        set("long",
"山道人是丁氏兄妹从南疆请来的三清宫四供奉之一，手持一柄暗青色
的法杖。\n"
);
        set("attitude", "friendly");
        set("combat_exp", 800000);
        set("score", 2000);

        set("class", "beggar");
        set("reward_npc", 1);
		set("difficulty", 2);

        set("inquiry", ([
                "谷衣心法": "谷衣心法是我茅山派为对抗邪魔外道所创的内功心法。\n",
		         "内奸" : "action"CYN"“内奸？”山道人一脸疑惑地看着你：“谁告诉你宫里有内奸？”\n"NOR,
                "三清道宗":  (: kill_him :),

        ]) );
		
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(40) :),
        }) );
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        
        auto_npc_setup("wang",100,100,0,"/obj/weapon/","fighter_w","dagou-stick",1);
        setup();
        
        carry_object(__DIR__"obj/s_staff")->wield();
		carry_object(__DIR__"obj/s_cloth")->wear();
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
		me->start_busy(2);
		return 1;
	}
	else
	{
		if (!me->query_temp("annie/demon_san"))
		{
			me->set_temp("annie/demon_san",1);
			command("say 有趣，有趣。你怎么会知道这件事？");
			command("say 既然如此，我就告诉你一个秘密。");
			command("say "+me->query("annie/demon_puzzle_san")+"\n");
		}
		else
		{
			command("say 哦？你认为我就是偷书的人？");
			command("say 且不管是或不是，已经留不得你了！");
			this_object()->kill_ob(me);
			me->kill_ob(this_object());
			me->perform_busy(2);
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

	if (!me->query_temp("annie/demon_san") || REWARD_D->riddle_check(me,"无字天书") != 4)
	{
		::die();
		return;
	}
	this_object()->full_me();
//	"/cmds/imm/full"->main(this_object(),"");
	if (me->query("annie/demon_puzzle") == 3)
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

