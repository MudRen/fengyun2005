inherit NPC;
#include <ansi.h>

int init_quest();

void create()
{
        set_name("张恩", ({ "zhang", "zhang en"}) );
        set("title", HIW "丐帮分舵舵主"NOR);
        set("gender", "男性" );
        set("class","beggar");
        set("age", 34);
		set("attitude","friendly");
        set("long","丐帮遍布大江南北，张恩能力出众，被分配管理此分舵。\n");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.xianglongwuhui" :)
        }) );
        set("combat_exp", 1000000);
        
       	set("inquiry", ([
	        "飞鸽传信":	(: init_quest :),
	        "协助":		(: init_quest :),
	        "保护":		(: init_quest :),
	     	"袁姬":		(: init_quest :),
	     	"局中局":	(: init_quest :),
	     	"yuanji":	(: init_quest :),
	     	"qingbo":	(: init_quest :),
	     	"清波公子":	(: init_quest :),
	    	"骗局":		"胡说八道什么，难道你贪生怕死不敢做了么？\n", 		
	     	"米公公":	"听说此人是宫中高手，千万不要正面与他冲突。\n",
	     	"南宫灵":	"南宫灵是我们丐帮现任帮主。\n",
	     	"失败":		"胡说，我丐帮办事，从来没有失败的！\n",
	     ]));
        
        
        set_skill("move", 100);
        set_skill("parry",120);
        set_skill("dodge", 120);
        set_skill("force", 180);
        set_skill("unarmed",150);
		set_skill("doggiesteps",200);
		set_skill("dragonstrike",150);
		set_skill("huntunforce",120);
        
        map_skill("dodge", "doggiesteps");
        map_skill("move","doggiesteps");
		map_skill("force", "huntunforce");
		map_skill("unarmed", "dragonstrike");

        setup();
        carry_object(__DIR__"obj/7bagcloth")->wear();

}


int	init_quest() {
	object me = this_player();
	object ob = this_object();
	object room, t1, t2, t3;
	
	if (REWARD_D->check_m_success(me,"魂断鹊桥")|| F_LEVEL->get_level(me->query("combat_exp"))< 61)
	{
		command("shake");
		command("sigh");
		tell_object(me,"（解此谜题至少需要等级61）\n");
		return 1;
	}
	
	if (me->query("class") == "beggar" && me->query_skill("begging",1)<150)
	{
		command("shake");
		command("sigh");
		tell_object(me,"（丐帮弟子解此谜题需150级乞讨之术）\n");
		return 1;	
	} 
	
	if (REWARD_D->riddle_check(me,"魂断鹊桥")== 1)
	{
		command("say 飞鸽？传信？似乎没有这件事啊？");
		command("?");
		command("say 不过总舵来人，正好我这儿有一件棘手之事。\n");
	}
	
	if (REWARD_D->riddle_check(me,"魂断鹊桥")<=2)
	{		
		command("say 这沉香小镇上有一对青梅竹马的情侣，袁姬和清波公子。自小
定了终身，恩恩爱爱。没料到天不遂人愿，数年前清波公子之父得罪了朝廷
显贵，杀头的杀头，坐牢的坐牢，唯清波公子一人幸免。这袁姬到也情深意
重，并不因此而背约。\n");

		command("say 谁又料想祸不单行，前几日宫里的米公公替皇上来选秀女，竟
然挑中了袁姬！皇上的旨意，谁又敢违抗！清波公子一介书生，又有什么办
法？这袁姬一个弱女子，却宁死不从，米公公一时也无法可施。\n");

		command("say 昨天，帮里的眼线来报，米公公的手下为了断了袁姬的希望，
请了黑道上的杀手，不日便将刺杀清波公子。想我丐帮，怎能容得此等伤天
害理之事。只是我手下多是沉香人氏，易引人注目。\n");

		command("consider");

		command("say 若你愿相助，可速去清波公子处暗中"YEL"保护！"CYN"\n");
		REWARD_D->riddle_set(me,"魂断鹊桥",2);
		
		if (REWARD_D->riddle_check(me,"局中局")==1)
			tell_object(me, WHT"\n你觉得这一切似乎是那么的熟悉，难道，又回到了从前？\n"NOR);
		return 1;
		
	}
	
	if (REWARD_D->riddle_check(me,"魂断鹊桥")==3)
	{
		message_vision(CYN"$N跌足叹道：任务未毕，你怎么竟然回来了！错了！错了！\n"NOR,ob);
		message_vision(YEL"话音未落，屋外蓬蓬蓬冲进一个弟子拜倒：禀舵主，清波公子他。被暗杀了！\n"NOR, me);
		command("say 这、这、这。。。");
		command("slap "+ me->query("id"));
		REWARD_D->riddle_set(me,"魂断鹊桥",4);
		
		if (REWARD_D->riddle_check(me,"局中局")==1)
			tell_object(WHT"\n（。。。。。。。。。。）\n");
		
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"魂断鹊桥")==4)
	{
		command("say 天意，天意！事已至此，也无法挽回了！");
		REWARD_D->riddle_set(me,"魂断鹊桥",5);
		return 1;
	}
	
	t1 = present("zhao neng");
	t2 = present("li feng");
	t3 = present("dai yin");
	
	if (REWARD_D->riddle_check(me,"魂断鹊桥")==5)
	{
		if (!t1 || !t2 || !t3)
		{
			command("say 天意，天意！事已至此，也无法挽回了！");
			return 1;
		}
		
		command("say 只是，袁姬还在米公公手中。。。");
		message_vision(CYN"$N一拍桌子：干脆，杀进去把袁姑娘抢出来！\n"NOR, t1);
		message_vision(CYN"$N摇摇头：米公公武功深不可测，此计万万不可。\n"NOR,t2);
		message_vision(YEL"\n$N忽然凑到$n身旁，悄悄地在$n耳边说了几句话。\n"NOR, t3, ob);
		
		REWARD_D->riddle_set(me,"魂断鹊桥",6);
		return 1;
	}

	if (REWARD_D->riddle_check(me,"魂断鹊桥")==6)
	{
		message_vision(YEL"$N长身而起，击掌道，“此计甚妙！”\n"NOR,ob);
		
		tell_object(me, CYN"
张恩道：当务之急，乃是救出袁姑娘，戴兄弟有一瞒天过海之计，你可速与他商量。\n"NOR);
		REWARD_D->riddle_set(me,"魂断鹊桥",7);
		
		
		if (REWARD_D->riddle_check(me,"局中局")==1)
			tell_object(me,WHT"\n（这、这是个"YEL"骗局"WHT"，快告诉张恩！）\n"NOR);
			
		return 1;
	}
	if (REWARD_D->riddle_check(me,"魂断鹊桥")>=7	)
	{
		command("say 怎么还在这里耽搁！");
		return 1;
	}
}
	
		
int accept_object(object me, object ob)
{
		if (ob->query("name")=="麻沸散" && ob->query("real")
			&& REWARD_D->riddle_check(me,"魂断鹊桥")==10)
		{
			tell_object(me,CYN"张恩说：好，如今万事俱备，我已遣人暗中通知袁姑娘，
你速速前去，把麻沸散交给袁姑娘。\n"NOR);
			ob->set("real",2);
		}
		return 0;
}		
			
			
	
	
	
	
	
	