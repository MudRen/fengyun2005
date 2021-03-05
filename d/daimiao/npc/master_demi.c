inherit SMART_NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("神秘女子", ({ "master figure", "master"}) );
        set("gender", "女性" );
        set("age", 64);
        set("per", 3);
        set("group", "demon");
        set("vendetta_mark","demon");
        set("attitude","friendly");
		set("class","demon");
    
        set("combat_exp", 10000000);
        set("score", 200000);
        set("long","此人身著魔教中彰显地位的镏金长袍，\n却以一顶低低的面纱掩住面目．．．\n");
    
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
        
        set_skill("blade", 300);
        set_skill("heavendance", 200);
        set_skill("unarmed", 180);
        set_skill("divineforce", 160);
        set_skill("kaleidostrike", 140);
		set_skill("perception",190);
		set_skill("magic",200);
		set_skill("sheolmagic",200);
        set_skill("literate", 100);
        set_skill("chanting", 160);
        set_skill("dodge", 180);
        set_skill("move", 190);
        set_skill("parry", 170);

        map_skill("unarmed", "kaleidostrike");
        map_skill("force", "divineforce");
        map_skill("blade", "heavendance");
        map_skill("magic", "sheolmagic");

        setup();
        carry_object(__DIR__"obj/demiblade")->wield();
        carry_object(__DIR__"obj/semicloth")->wear();

}


void attempt_apprentice(object me)
{
	if (me->query("gender") == "男性")
	{
		ccommand("shake");
		ccommand("say 老身只收女徒。");
		return;
	}
	if (me->query("class") != "demon")
	{
		ccommand("emote 从面纱下瞥了你一眼。");
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
//	if (crypt(obj->query("name"),"pbpRubOoY/Q/A") != "pbpRubOoY/Q/A" || me->query("gender") == "男性")		// disabled upon further investigation
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
	ccommand("emote 自面纱下发出低低的笑声。");
	ccommand("say 好，你可以入教。");
	ccommand("recruit "+me->query("id"));
	return 1;
}
