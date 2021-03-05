// qinge.c

inherit NPC;

#include <ansi.h>
void create()
{
    set_name("秦歌", ({ "qin ge", "qin"}) );
	set("gender", "男性" );
	set("age", 25);
        set("title","山流 义侠");
	set("nickname",HIW "铁人"NOR);
	set("long",
"他颈上系着条红红的丝巾，眼睛灼灼有光，他长得就算不太英俊漂亮，就凭这种气
派，已足够让女人一队队的拜倒在他黑缎子的裤脚下。\n");
        set("chat_chance", 1);
        set("chat_msg", ({
            "秦歌豪爽地大笑起来：要赌就赌个爽快，否则还不如回家抱老婆去。\n",
	    "秦歌正色道：谁要想入山流，就得完全牺牲自己，就得要有下地狱的精神，
赴汤蹈火，也万死不辞！\n",
    }) );
        set("inquiry",  ([
                "山流" : "秦某人但得为了山流大业，就是再被砍千刀，流尽我血，也在所不辞！\n",
                "shanliu" : "秦某人但得为了山流大业，就是再被砍千刀，流尽我血，也在所不辞！\n",
                "血雨檄": "血雨檄中人皆称霸一方的黑道巨枭，不可小视。\n",
                "questnpc": "血雨檄中人皆称霸一方的黑道巨枭，不可小视。\n",
                "青龙令": "青龙令乃青龙会召集天下枭雄的凭信，若是得来，真可谓断其十指！\n",
	        "qinglong-ling": "青龙令乃青龙会召集天下枭雄的凭信，若是得来，真可谓断其十指！\n",
                ])                      );

	set("combat_exp", 20000000);
	set("attitude", "friendly");
	set("per",30);
	set("str", 40);
	set("force",1000);
	set("max_force",2000);
	set("force_factor",50);
	set_skill("dodge",100);
        set_skill("blade",200);
        set_skill("parry", 200);
	setup();
	carry_object("obj/armor/cloth")->wear();
}

int accept_object(object me,object ob)
{
	string org_attri;
	if (ob->query("id") != "qinglong-ling")
		return 0;
	if (me->query("organization/org_attribute") != "正")
	{
		message_vision("$N拱手道：这位"+RANK_D->query_respect(me)+"古道热肠，侠肝义胆令人钦佩，若是能入我正道，秦某当可与兄把酒论道，可惜可惜。。\n",this_object());
		QUESTNPC_D->quest_reward(me,ob,"正");
		return 1;
	}
	if (ob->query("killer") && ob->query("killer") == me)
	{
		message_vision("$N目光如炬，仔细看了下$n，击掌笑道：不错，不错！青龙授首，指日可待！\n",this_object(),ob);
		
	}else
	{
		message_vision("$N盯着$n，肃然道：这青龙令我且收下，但鹊巢鸠占之事岂是我正道所为，大丈夫当心胸坦荡，方能无愧于心。\n",this_object(),me);	
	}
	QUESTNPC_D->quest_reward(me,ob,"正");
	return 1;
}

