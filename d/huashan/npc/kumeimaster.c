
#include <ansi.h>
inherit F_MASTER;
inherit NPC;
int force_convert();
int leave();
void create()

{
    set_name("枯梅大师", ({ "master kumei", "kumei","master"}));
    set("long", "
这是一个白发苍苍的老妇，一张干枯瘦削的脸上满是伤疤，耳朵缺了半个，
眼睛也少了一只，剩下的一只眼睛半开半合，开合之间，精光暴射，无论谁也
不敢逼视。她身子很瘦小，但却有种说不出来的威严，无论谁人只要瞧上她 
一眼，连说话的声音都会压低些。
\n"
        );
    	set("nickname", HIW "铁仙姑"NOR);
    	set("gender", "女性");

    	set("class","huashan");
    	create_family("华山派", 16, "掌门");
    	set("rank_nogen",1);
    	set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
		set("ranks",({"女童","小侠","少侠","女侠","梅使","兰使",
					"竹使","菊使","朝阳女侠","落雁仙女","莲华仙子",
					"五云仙姬",CYN"玉女"NOR,CYN"剑圣"NOR,CYN"剑宗传人
					"NOR,HIC"剑宗宗主"NOR}));
    	
    	set("reward_npc", 1);
    	set("difficulty", 5);
    
    	set("age", 59);
    	set("per", 3);
    
    	set("combat_exp", 3200000);
    	set("attitude", "friendly");
	set("guard_msg","$N喝道：贫尼的徒弟，容不得阁下来管教！\n\n");

    	set_skill("unarmed", 150);
    	set_skill("zhaixin-claw",150);
    	set_skill("move", 150);
    	set_skill("dodge", 150);
    	set_skill("parry", 150);
    	set_skill("literate", 100);
    	set_skill("chanting",100);
    	set_skill("force", 150);
	set_skill("sword", 200);
	set_skill("anxiang-steps", 150);
	set_skill("tanzhi-shentong", 150);
	set_skill("throwing", 200);
	set_skill("hanmei-force", 150);
	set_skill("qingfeng-sword", 150);
	set_skill("perception", 100);
	set_skill("foreknowledge", 100);
	
	
	map_skill("force", "hanmei-force");
	map_skill("move", "anxiang-steps");
	map_skill("parry", "tanzhi-shentong");
	map_skill("sword", "qingfeng-sword");
	map_skill("dodge", "anxiang-steps");
	map_skill("unarmed", "zhaixin-claw");
	map_skill("throwing", "tanzhi-shentong");
	map_skill("sword", "qingfeng-sword");
	
	set("inquiry", ([
		"leave" : (: leave :),
	]));

	set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
        (: exert_function, "chill" :),
    }) );
	
   	setup();
	carry_object("/obj/weapon/sword")->wield();
	carry_object("/obj/armor/cloth", 
                ([      "name"  :       HIB "蓝缎袍"NOR,
                        "long"  :       0 ])
                )->wear();
}


void attempt_apprentice(object ob)
{
    	if (ob->query("gender")=="男性") {
    		command("say 华山只收女子为徒。\n");
    		return;
    	}	
    	if (ob->query_skill("sword",1) < 15) {
        	 command("say  你对剑术所知甚少，竟然想来拜我！（需15级基本剑术） ");
			return;
    	}
    	if ((int)ob->query_skill("move",1) < 15 ) {
        	command("say 阁下的身法似乎不能学武啊！（需15级基本轻功）");
		return;
    	}
    	command("recruit " + ob->query("id"));
}

void init()
{	
	::init();
	add_action("do_killing", "kill");

}

int leave() {
	if (this_player()->query("class")!="huashan") return 0;
	message_vision(CYN"$N冷笑一声，“华山竟然有这样的弟子。“\n"NOR, this_object());
	message_vision(CYN"$N说：寒梅心法和摘心手的秘诀你得留下。\n"NOR,this_object());
	return 1;
}