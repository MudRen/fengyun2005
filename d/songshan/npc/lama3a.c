inherit NPC;
#include <ansi.h>

void check_fight();

void create()
{
		set_name("盘灯孚尔", ({ "pan deng"}) );
		set("gender", "男性" );
		set("title",HIY"恒河三佛"NOR);
		set("age", 70+random(10));
		set("class","lama");        
		set("long",
			"天竺高僧，此次聚众到少林寺,妄图一统武林。\n"
			);
		set("class","lama");
	    set("combat_exp", 4500000);
	    set("score", 900);
	    set("reward_npc", 1);
		set("difficulty",5);
		
		set("NO_KILL","师傅让你来赶人，可不叫你来杀人。\n");	
		set("no_busy",5);
	        	
		set("chat_chance", 0);
    	set("chat_msg", ({
    		(: check_fight()	:),	            
        }) );
        
		set_skill("iron-cloth", 200);
	  	set_skill("unarmed", 200);
		set_skill("dragonstrike", 200);
		set_skill("force", 200);
		set_skill("dragonstrike", 200);
		set_skill("spells",200);
		set_skill("parry",200);
		set_skill("kwan-yin-spells",200);
		set_skill("jin-gang",150);
		set_skill("perception",180);
		
		map_skill("iron-cloth","jin-gang");
		map_skill("spells","kwan-yin-spells");
		map_skill("unarmed", "dragonstrike");
		map_skill("force", "bolomiduo");
    	
/*        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );*/

		setup();
        carry_object(__DIR__"obj/lamacloth1")->wear();
        carry_object(__DIR__"obj/ring1")->wear();
        
}

void win_enemy(object loser)
{
		object room;
		
		if (!loser || environment(loser) != environment())
				return;
				
		command( "say 小子，要和咱恒河三佛斗智斗勇，你还差远了。");
		
		if (!room = find_object("/d/songshan/talin"))
			room = load_object("/d/songshan/talin");
		
		message_vision(YEL"\n$N一脚把$n从塔顶踢了下去。\n"NOR, this_object(), loser);
		
		set("chat_chance",0);
		loser->move(room);
//		loser->unconcious();
		message_vision(YEL"扑通一声，$N扎手扎脚地从就功塔顶栽了下来。\n"NOR, loser	);
		
		return;
		
}

int accept_fight(object me)
{
       	command("say 不急，一个个来。");
   		return 0;
}

void lose_enemy(object winner)
{
		object fo1, fo2, fo3;
		
		if (!winner)	return;
			
		set("chat_chance",0);
				
		fo1 = present("jin bo");		
		if (fo1) {
			message_vision(CYN"\n$N说：作弊、作弊、肯定有巫师帮忙！\n\n"NOR, fo1);	
		}
		
		fo2 = present("bo luo");
		if (fo2) {
			message_vision(CYN"$N干笑几声说：青山不改，绿水长流，咱们后会有期！\n\n"NOR, fo2);
		}
		
		message_vision(YEL"盘灯孚尔脸色铁青，一语不发。\n"NOR, winner);
		set("chat_chance",0);
		
		REWARD_D->riddle_done( winner, "力斗三佛", 50, 1);
		
		return;		
}


void die()
{
		object fo1, fo2, fo3;
		object killer;
		
		if (!objectp(killer= query_temp("last_damage_from")))
		{
			::die();
			return;
		}
		
		set("chat_chance",0);
				
		fo1 = present("jin bo");		
		if (fo1) {
			message_vision(CYN"$N惊叫道：大师兄、大师兄！一失脚从塔顶上掉了下去。\n"NOR, fo1);	
			
			destruct(fo1);
		}
		
		fo2 = present("bo luo");
		if (fo2) {
			message_vision(CYN"$N干笑几声说：青山不改，绿水长流，咱们后会有期！\n"NOR, fo2);
			destruct(fo2);
		}
				
		REWARD_D->riddle_done( killer, "力斗三佛", 50, 1);
		destruct(this_object());				
}



void 	check_fight()	{
		
		object *inv, ob;
		int i;
		
		inv= all_inventory(environment());
		for (i=0;i<sizeof(inv);i++){
			if (userp(inv[i]))
			{
				ob = inv[i];
				ob->fight_ob(this_object());
				this_object()->fight_ob(ob);
				return;
			}
		}
		
		set("chat_chance", 0);
		return;
}


void init(){
		object ob;
		if (interactive(ob=this_player()))
		{
			call_out("greetings", 1, ob);		
		}	
		::init();
}		
		
		
void greetings(object ob){
	
		object fo1, fo2, fo3;
		
		if (!ob || environment(ob)!= environment())	return;
			
		fo3 = this_object();
		fo1 = present("bo luo");
		fo2 = present("jin bo");
		
		if (!fo1 || !fo2) {
			command("say hmm, something is wrong");
			return;
		}
					
		command("say 看来中原武人不仅狂妄，还蠢得很，真的和咱们三兄弟"WHT"单打独斗"CYN"来了。");
		message_vision(CYN"

伯罗各答说：以多胜少，胜之不武，咱兄弟也不都上，就一个个地和你过招。

金伯胜夷说：这个叫做车轱辘战，小子你命苦啊！

盘灯孚尔说：废话少说，做了便是！\n\n"NOR, ob);

		fo1->set("chat_chance", 100);
}		
		
	
	