#include <ansi.h>
inherit SMART_NPC;
int helpme();

void create()
{
    	set_name("赤裸少女",({"naked girl","girl"}));
    	set("long","
她还是个孩子，根本就没有发育成熟，就已被摧残了。现在她睡着，只因为她
已被折磨得太久，已哭得太疲倦。她雪白的身子蜷曲在紫缎被褥上，更显得娇
弱无助，楚楚动人。\n");
    	set("gender","女性");
    	set("age",12);
    	set("no_arrest",1);
    	set("per",40);
    	set("force",2000);
    	set("max_force",2000);
    	set("combat_exp",500000);  
    	set("attitude", "friendly");
    
	   	set("nb_chat_chance", 100);
	    set("nb_chat_msg_combat", ([
	    		100: (: helpme() :),
		]) ); 
    	
    	set("death_msg",CYN"\n$N惨然一笑：“这也是我的解脱吧。”\n"NOR);  
    	set("chat_chance",1);
    	set("chat_msg",({
			"赤裸少女翻了个身，脸上犹自带着未干的泪痕。\n",	
    	}) );
    	setup();    
}


int helpme() {
	object me, longwang, *enemy, player;
	int i,n;
	
	longwang=present("long wang",environment(this_object()));
	if (!longwang) return 1;
	if (longwang->is_fighting()) return 1;
	
	if (query("kee")>=query("max_kee")*4/5)
		message_vision(CYN"$N叹了口气说：原来你也是和龙王一伙的坏人。\n"NOR,this_object());
	
	enemy=query_enemy();
	n= random(sizeof(enemy));
	player= enemy[n];
	
	if (!player->query_temp("taiping/longwang_kill")) {
		message_vision(CYN"$N狞笑着说：“老子的女人，还轮不到你来出手吧。\n"NOR,longwang);
		for (i=0;i<sizeof(enemy);i++) {
			enemy[i]->kill_ob(longwang);
			longwang->kill_ob(enemy[i]);
		}
		this_object()->remove_all_killer();
	} else 	{
		if (!random(5)) message_vision(WHT"$N一拍大腿说： Ｓ＆Ｍ？原来兄弟喜欢这个调调儿！\n"NOR,longwang);
	}
	return 1;

}
	
	
void die(){

	object player,longwang;
	int i;
	player=this_object()->query_temp("last_damage_from");
	longwang=present("long wang",environment(this_object()));
	if (player && longwang)
	if (!longwang->is_fighting() && !player->query_temp("taiping/longwang_kill")) {
		message_vision("$N狂笑道：杀了老子的女人，你还想跑？\n",longwang);	
		player->kill_ob(longwang);
		longwang->kill_ob(player);
	}
	if (longwang) message_vision(CYN"海龙王点了点头。\n"NOR,this_object());
	::die();
}	