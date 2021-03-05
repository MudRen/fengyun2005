#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name(HIW"白蚂蚁"NOR, ({ "white ant", "ant" }) );
        set("long","
一个穿着雪白衣裳的人，袖子又宽又长，就象是两只翅膀，人却又瘦
又小，长不满三尺半，宽不及一尺，若是放在秤上秤一秤，决不会比
一只兔子重多少。\n");
    	set("chat_chance",2);
		set("chat_msg",	({
				"白蚂蚁傲然的瞥了你一眼，负手而立，冷冷道：“当今天下，除了寥
寥几个门派的轻功身法还可入眼，其他的在我‘蹋雪无痕白蚂蚁’眼
里都是不值一提。”\n",
"白蚂蚁道：“除了轻功，老夫最喜欢试穿不同的衣服。听说，风云城
最近流行什么风云马褂，等我有空去搞一件。\n"
				})  );

        set("combat_exp", 400000);
	
		set_skill("dodge",150);
		set_skill("move",150);
		set_skill("unarmed",100);
		set_skill("shenji-steps",100);
		set_skill("nine-moon-steps",100);
		set_skill("nine-moon-claw",60);
		
		map_skill("unarmed","nine-moon-claw");
		map_skill("dodge","shenji-steps");
		map_skill("move","nine-moon-steps");
	
		set("perform_busy_u", "bat/dodge/shenji-steps/shenjimiaosuan");
	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );

		setup();
        carry_object("/obj/armor/cloth")->wear();
}

int accept_object(object who, object ob)
{	
	object jinlian;
	if (ob->query("name")=="秋风步法秘笈") 
	{
	 	REWARD_D->riddle_set( this_player(),"巧过蚂蚁/白蚂蚁",1);
	 	write("白蚂蚁不屑的翻了翻，但愈是往下看，愈是神色凝重，喟然长叹道：
＂秋风落叶＂果然名不虚传啊，天下第一果然不是吹的。”\n");
    		command("thank "+this_player()->query("id"));
		if (mapp (this_player()->query("riddle/巧过蚂蚁")))
		if (sizeof(this_player()->query("riddle/巧过蚂蚁"))==4)
			REWARD_D->riddle_done( this_player(),"巧过蚂蚁",50,1);    		
    	return 1;
	}
	if (ob->query("name")=="风云马褂") 
	{
		command("spank "+this_player()->query("id"));
	 	this_player()->set_temp("marks/whiteant",1);
	 	write("白蚂蚁嘻嘻笑道：“你了解我，你了解我。”\n");
    		return 1;
	}
	write("白蚂蚁冷冷道：“这种雕虫小技怎能入眼。”\n");
	return 0;
}
