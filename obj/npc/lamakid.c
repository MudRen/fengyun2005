// beggar.c

#include <ansi.h>

inherit NPC;
string desc();

void create()
{
        int i,amun;
        string *order = ({"赵","钱","孙","李","周","吴","郑","王","冯","陈","褚","卫","蒋"});
		string *orderr = ({"包包", "宝宝","小小", "毛毛", "囡囡"});
        set_name( order[random(13)] + orderr[random(5)], ({ "kid", "small kid" }) );
		set("title", "聪慧小童");
		set("gender", "男性" );
		set("age", random(5)+4);
		set("int", 26);
		set("long",	(: desc :));
        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :)
        }) );

		set("attitude", "peaceful");
		set("combat_exp", 2000);
        set_skill("unarmed", 1+random(10));
        set_skill("taiji", 10+random(10));
        map_skill("unarmed", "taiji");
		setup();
		carry_object("/obj/armor/cloth")->wear();
}

string desc(){
	
	object me = this_player();
	object owner;
	owner = query("lama_owner");
	
	if (!owner || owner!= me)	
		return "一个聪明伶俐的小孩，正在地上蹦蹦跳跳地玩耍。\n";
		
	return "一个满脸肃穆的小孩，虽然衣衫陈旧，却有一般高贵的气质。\n";
}




int accept_object(object me, object obj)
{
    object room, owner;
    if (me != query("starter"))	return 0;
    	
    if (REWARD_D->riddle_check(me,"灵童转世") == 4)
	if (obj->name() == "黑木禅杖") {
		owner = query("lama_owner");
		if (!owner)
		{		
			message_vision(CYN"小童双掌合十道：以尔之力，千劫测度，不能得知。\n"NOR, me);
			REWARD_D->riddle_set(me,"灵童转世", 999);	// failed
			me->set("timer/lingtong", time());		
			room = find_object("/d/resort/lake2");
        	room ->ending(me, 0);
        	return 1;
		}		
		message_vision(CYN"小童双掌合十道：
		
慈因积善，誓救众生，

手中金锡，振开地狱之门。

掌上明珠，光摄大千世界。

大悲大愿，大圣大慈。
	
说罢：向$N微微一笑。\n"NOR, me);					;
		
		REWARD_D->riddle_set(me,"灵童转世", 6);
        room = find_object("/d/resort/lake2");
        room ->ending(me, 1);
        return 1;
	}
	return 0;
}

