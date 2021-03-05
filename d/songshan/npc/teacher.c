// teacher.c
#include <ansi.h>
inherit NPC;
int quest();

void create()
{
		set_name("梦焕", ({ "meng huan", "huan" }) );
        create_family("少林寺", 20, "弟子");
		set("title", "笔下生花");
		set("class", "shaolin");
        set("vendetta_mark","shaolin");
		set("int",5);
        set("skill_public",1);
		set("gender", "男性" );
		set("age", 57);
        set("chat_chance", 2);
        set("inquiry", ([
        	"经书":	(: quest() :),
        	"多事之秋": "少林寺正值多事之秋，藏经阁"YEL"经书被盗"CYN"\n",
        	"经书被盗": "少林寺经书被盗，你若有心相助可速去见方丈。\n",	
        	"见方丈": "少林寺经书被盗，你若有心相助可速去见方丈。\n",	
        	"守经楼": "少林寺经书被盗，你若有心相助可速去见方丈。\n",	
        ]));	
        
        set("chat_msg", ({
                "梦焕嘀咕道：＂不知道是谁偷了本寺的经书？＂\n",
        }) );
		set("long","
梦焕原姓孟，年轻时中过秀才，曾经是滁县的父母官，在任期间曾屡破疑案，
可惜为奸佞所忌，仕途坎坷，终于看破红尘，出家为僧。梦焕精通读书识字，
你若有心可向他请教（apprentice）。\n");
				
		set("attitude", "peaceful");
		set_skill("literate", 150);
		setup();
		carry_object("/obj/armor/cloth")->wear();
}


void attempt_apprentice(object ob)
{
    	command("say 小僧无德无能，何敢收徒。");
		command("say 不过，若是施主想学读书识字，小僧倒可与施主共勉。\n");
		return; 	
}

int quest() {
		object ob = this_player();
		
		command ("say 少林寺正值多事之秋，藏经阁"YEL"经书被盗"CYN"，小僧受方丈之嘱下山探访。");
		if (!REWARD_D->check_m_success(ob,"多事之秋") && !REWARD_D->riddle_check(ob,"多事之秋"))
			REWARD_D->riddle_set(ob,"多事之秋",1);
        return 1;
}


int recognize_apprentice(object ob)
{
	if(ob->query("free_learn/literate"))
		return 1;
    else {
		if(REWARD_D->check_m_success(ob,"守经楼")) 
		{
			command ("say 好，好，你为本寺立了大功，如果你愿学读书，小僧当竭力相助。\n");
			ob->set("free_learn/literate", 1);
			return 1;
		}
        	command ("say 少林寺正值多事之秋，藏经阁"YEL"经书被盗"CYN"，小僧受方丈之嘱下山探访，
此事未了，小僧实在无暇顾及诗书之事。");
			if (!REWARD_D->check_m_success(ob,"多事之秋") && !REWARD_D->riddle_check(ob,"多事之秋"))
				REWARD_D->riddle_set(ob,"多事之秋",1);
        	return 0;
	}
}
