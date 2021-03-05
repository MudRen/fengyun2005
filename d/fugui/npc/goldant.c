#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIY"金蚂蚁"NOR, ({ "gold ant", "ant" }) );
        set("long","
他身上穿着件金光闪闪的衣服，若不是脸上生着胡须，眼角有了皱纹，
无论谁都会将他看成个五六岁的小孩子。\n");
    	set("chat_chance",2);
	set("chat_msg",	({
		"金蚂蚁露出一种心弛神往的神色，喃喃道：“自古宝剑赠于英雄，想
我老金纵横天下多年，却连那把不死之剑都无法得到，实在是不甘心啊。”\n",
		"金蚂蚁喃喃道：“华山的老太婆子会用什么剑，只有我才配得上她的宝剑。”\n"
	})  );

        set("combat_exp", 1000000);
	
	set_skill("unarmed",100);
	set_skill("kongshoudao",100);
	set_skill("dodge",100);
	set_skill("parry",100);
	set_skill("ghosty-steps",100);
	
	map_skill("dodge","ghosty-steps");
	map_skill("unarmed","kongshoudao");
	
	set("chat_chance_combat",25);
	set("chat_msg_combat",	({
			(:perform_action,"unarmed.yaozhan":),
		}));
	
	setup();
        carry_object("/obj/armor/cloth")->wear();
}

int accept_object(object who, object ob)
{	
//	int combat_exp,pot,score;
	if (ob->query("name")==HIG "长生剑"NOR) 
	{
		REWARD_D->riddle_set( this_player(),"巧过蚂蚁/金蚂蚁",1);
		write("金蚂蚁仰天长笑道：“好好好，既然你送我如此重宝，怎能再拦着你呢？”\n");
		
		if (mapp (this_player()->query("riddle/巧过蚂蚁")))
		if (sizeof(this_player()->query("riddle/巧过蚂蚁"))==4)
			REWARD_D->riddle_done( this_player(),"巧过蚂蚁",50,1);
		return 1;		
	}
	if (ob->query("name")==HIG "凝碧剑"NOR) 
	{
		command("thank "+this_player()->query("id"));
		this_player()->set_temp("marks/goldant",1);
		write("金蚂蚁呵呵笑道：“你送我如此重宝，我就不再拦你了。”\n");
    		return 1;
	}
	write("金蚂蚁摇了摇头，嘿嘿一笑道：“这种破铜烂铁，随便找找都是一箩筐。”\n");
	return 0;
}


				