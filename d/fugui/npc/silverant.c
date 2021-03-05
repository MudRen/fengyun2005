#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name(HIC"银蚂蚁"NOR, ({ "silver ant", "ant" }) );
        set("long","
他身上穿着件银光闪闪的衣服，脸上还带着个银面具，看来就象是个
用白银铸成的小妖怪，实在说不出的诡秘可怖。\n");
    	set("chat_chance",2);
		set("chat_msg",	({
				"
银蚂蚁抬头望了望天上的白云，长叹一声道：“二十多年了，当年山寨里的弟兄
被那厮害死，深仇如今还无法得报，人生若此，还有什么乐趣可言。”\n",
		"银蚂蚁狠狠道：“那厮的金刚不坏这么强，复仇不易啊，能从他那里偷点宝物，气死他也好。”\n"
		
		})  );

        set("combat_exp", 500000 + random (80000));

	set_skill("iron-cloth",100);
	set_skill("jin-gang",80);
	set_skill("unarmed",120);
	set_skill("bloodystrike",100);
	map_skill("iron-cloth","jin-gang");
	map_skill("unarmed","bloodystrike");
	
		set("perform_busy_u", "lama/unarmed/bloodystrike/fofawubian");
	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(50) :),
        }) );
        
	setup();
        carry_object("/obj/armor/cloth")->wear();
}

int accept_object(object who, object ob)
{	
	object jinlian;
	if (ob->query("name")==HIW"天竺佛珠"NOR ) 
	{
		REWARD_D->riddle_set(this_player(),"巧过蚂蚁/银蚂蚁",1);
		write("银蚂蚁怔了一下，喜泪纵横，不禁连声道：“杀不了那该死的葛伦秃驴，
杀了普松更好，让这老匹夫一辈子伤心痛苦！”\n");
  	  	command("thank "+this_player()->query("id"));
		if (mapp (this_player()->query("riddle/巧过蚂蚁")))
		if (sizeof(this_player()->query("riddle/巧过蚂蚁"))==4)
			REWARD_D->riddle_done( this_player(),"巧过蚂蚁",50,1);  	  	
  	  	return 1;
	}
	if (ob->query("name")=="舍利子") 
	{
		command("thank "+this_player()->query("id"));
		this_player()->set_temp("marks/silverant",1);
		write("银蚂蚁怔了一下，连声道：“拿到舍利子，让葛伦那秃驴哭吧！哈哈哈.....”\n");
  	  	return 1;
	}
	write("银蚂蚁缓缓摇了摇头。\n");
	return 0;
}		
