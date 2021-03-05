// annie. 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit NPC;
void create() {
    	set_name("瘦小的黑影", ({ "shadow"}));
    	set("long", "暗洞中一片漆黑，你看不清这个人的面貌。\n"
        );
    	set("gender", "女性");
    	set("class","huashan");
    	set("age", 59);

		set("no_arrest",1);
		set("no_fly",1);

		set("chat_chance", 1);
        set("chat_msg", ({
                "黑影转了一圈，似乎无比焦急。\n",
                "黑影恨声道：这丫头又到哪里去了？\n",
                }) );
   
    	set("combat_exp", 4000000);
    	set("attitude", "friendly");
    	set_skill("unarmed", 200);
    	set_skill("zhaixin-claw",200);
    	set_skill("move", 200);
    	set_skill("dodge", 200);
    	set_skill("parry", 200);
		map_skill("unarmed", "zhaixin-claw");
    	setup();
    	carry_object("/obj/armor/cloth", 
               ([      "name"  :       HIB "蓝缎袍"NOR,
                        "long"  :       0 ])
        )->wear();
}



int kill_ob(object who)
{
	object me;
	::kill_ob(who);
	delete("timer");
	if (!is_busy())
	{
		ccommand("qusi "+who->query("id"));
		ccommand("perform zhaixin");
		if (who->query("kee") < 0)
			ccommand("die2 "+who->query("id"));
		else
			ccommand("fake");
	}

	return 1;
}


