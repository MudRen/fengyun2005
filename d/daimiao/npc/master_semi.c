inherit SMART_NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("神秘人", ({ "master shadow", "master"}) );
        set("gender", "男性" );
        set("age", 64);
        set("per", 3);
        set("group", "demon");
        set("vendetta_mark","demon");
        set("attitude","friendly");
		set("class","demon");
    
        set("combat_exp", 10000000);
        set("score", 200000);
        
        set("long","此人身著魔教中彰显地位的镏金长袍，\n却以一顶低低的斗笠掩住面目．．．\n");
    
        create_family("魔教", 1, "执令使");
        set("rank_nogen",1);
        set("ranks",({"教徒","副堂主","堂主","副坛主","坛主",
                      "副舵主","舵主","护法","大护法",
                      "长老","大长老","副帮主"}));
        set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,15000000 }));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: auto_smart_fight(90) :),
        }) );
        
        set_skill("whip", 300);
        set_skill("dragonwhip", 200);
        set_skill("unarmed", 190);
        set_skill("divineforce", 190);
        set_skill("spicyclaw", 170);
		set_skill("perception",160);
		set_skill("magic",160);
		set_skill("sheolmagic",170);
        set_skill("literate", 100);
        set_skill("chanting", 190);
        set_skill("dodge", 180);
        set_skill("move", 170);
        set_skill("parry", 190);

        map_skill("unarmed", "spicyclaw");
        map_skill("force", "divineforce");
        map_skill("whip", "dragonwhip");
        map_skill("magic", "sheolmagic");

        setup();
        carry_object(__DIR__"obj/semiwhip")->wield();
        carry_object(__DIR__"obj/semicloth")->wear();

}


void attempt_apprentice(object me)
{
	if (me->query("gender") == "女性")
	{
		ccommand("shake");
		ccommand("say 老夫只收男徒。");
		return;
	}
	if (me->query("class") != "demon")
	{
	ccommand("emote 从斗笠下瞥了你一眼。");
	ccommand("say 要入我教，你先要证明你的忠心。");
	ccommand("say 去把＂那东西＂找来，我就上报教主，收你入教。");
	REWARD_D->riddle_set(me,"拜入魔教",1);
	}
	else
	{
		ccommand("shake");
		ccommand("say 你既已入教中，便安心呆下就是。");
	}
	return;
}


int accept_object(object me, object obj)
{
	if (random(100)+1)			// Not possible in fy2005
	{
		ccommand("shake");
		return 0;
	}
	if (REWARD_D->riddle_check(me,"拜入魔教") != 1)
	{
		ccommand("shake");
		return 0;
	}
	REWARD_D->riddle_set(me,"拜入魔教",2);
	ccommand("emote 自斗笠下发出低低的笑声。");
	ccommand("say 好，你可以入教。");
	ccommand("recruit "+me->query("id"));
	return 1;
}
