inherit NPC;
#include <ansi.h>
inherit F_MASTER;
void smart_fight();

int your_score = 0;
void create()
{
    	set_name("西门吹雪", ({ "master ximen", "ximen", "master" }) );
    	set("title", "万梅庄主");
    	set("gender", "男性");
     	set("nickname", RED "剑神" NOR );
    	set("age", 34);
    	set("reward_npc", 1);
    	set("difficulty", 30);
    	set("class","fighter");
    	set("long","西门吹雪乃是当代绝顶高手之一，剑法已经到达了『无剑』的境界。\n"); 
    
    	set("attitude", "peaceful");
    	set("combat_exp", 20000000);
    	
    	set("score_cost",20000);
		set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );
        
    	set("chat_chance", 1);
    	set("chat_msg", ({
        	"西门吹雪怒骂道：陆小凤，你就是逃到幽灵山庄，我也要杀了你！！\n",
        }) );

    	set("inquiry", ([
        	"拜师": "我向来有个规矩，凡是想拜我为师的，得接我三招不死，
你想试试(accept test)？\n",
        	"apprentice": "我向来有个规矩，凡是想拜我为师的，得接我三招不死，
你想试试(accept test)？\n"

        ]) );

    	create_family("万梅山庄", 1, "庄主");
    	set("ranks",({ "弟子","领班","小管家","管家","大管家", "总管","大总管","副庄主" }));
    	set("rank_nogen",1);

    	set_skill("force", 180);
    	set_skill("unarmed", 160);
    	set_skill("sword", 200);
    	set_skill("parry", 160);
    	set_skill("dodge", 160);
    	set_skill("move", 160);
    	set_skill("doomforce", 150);
    	set_skill("doomstrike",200);
    	set_skill("doomsteps", 200);
    	set_skill("doomsword",150);
    	set_skill("perception",150);

    	map_skill("force", "doomforce");
    	map_skill("unarmed", "doomstrike");
    	map_skill("sword", "doomsword");
    	map_skill("dodge", "doomsteps");
    	map_skill("move", "doomsteps");
    	map_skill("parry","doomsword");


    	setup();

    	carry_object(__DIR__"obj/xuejian")->wield();
    	carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
    	::init();
    	add_action("do_accept", "accept");
}

int do_accept(string arg)
{
    	mapping guild;
    	int extra;	
    	int mgin,mkee,msen;
    
    	if( arg== "test" )    {
		if(this_player()->query("family/master_id") == this_object()->query("id")){
            		say("\n西门吹雪拍拍你的头道：你已经证明你是一个可造之才了！\n");
            		return 1;
		}
		if (this_object()->is_busy()) {
			tell_object(this_player(),"西门吹雪正忙着呢，没空理你。\n");
			return 1;
		}
			
		if (this_object()->is_fighting()) {
			command("say 先让我收拾了这个碍手碍脚的家伙。");
			return 1;
		}
		mgin=(int)query("max_gin");
	    	mkee=(int)query("max_kee");
	    	msen=(int)query("max_sen");
	    	set("eff_kee",mkee);
	    	set("eff_gin",mgin);
	    	set("eff_sen",msen);
	    	set("gin",mgin);
	    	set("kee",mkee);
	    	set("sen",msen);
		extra=100;
		
        	say("\n西门吹雪点了点头，说道：很好，这是第一招....\n\n");
        	this_object()->add_temp("apply/attack", extra*5);	
		this_object()->add_temp("apply/damage",extra*2);
        	COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
        	this_object()->add_temp("apply/attack", -extra*5);	
		this_object()->add_temp("apply/damage",-extra*2);                    
               	if( (int)this_player()->query("kee") < 0 || !present(this_player(), environment())) {
                        say("西门吹雪叹了口气，说道：连第一招都撑不过，真是自不量力....\n");
            		return 1;
        	}
        	
        	say("\n西门吹雪说道：这是第二招....\n\n");
        	this_object()->add_temp("apply/attack", extra*5);	
		this_object()->add_temp("apply/damage",extra*4);
        	COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
        	this_object()->add_temp("apply/attack", -extra*5);	
		this_object()->add_temp("apply/damage",-extra*4);                      
        	if( (int)this_player()->query("kee") < 0  || !present(this_player(), environment())) {
                        say("西门吹雪「哼」地一声，说道：便是有这许多不怕死的家伙....\n");
            		return 1;
        	}
        	
        	say("\n西门吹雪说道：第三招来了....\n\n");
        	this_object()->add_temp("apply/attack", extra*5);	
		this_object()->add_temp("apply/damage",extra*4);
        	COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
        	this_object()->add_temp("apply/attack", -extra*5);	
		this_object()->add_temp("apply/damage",-extra*4);                      
        	if( (int)this_player()->query("kee") < 0 || !present(this_player(), environment())) {
                        say("西门吹雪叹道：可惜，难道我一身武功竟无传人....\n");
            		return 1;
        	}
        		        
        	say("\n西门吹雪哈哈大笑，说道：今日终於觅得一个可造之才！\n\n");
        	say("\n不过高手寂寞，所以我不想收任何人。。。。\n");
        //	your_score = this_player()->query("score");
        //	command("recruit " + this_player()->query("id") );
        	return 1;
    }
    return 0;
}
/*
void recruit_apprentice(object ob)
{
    	if( ::recruit_apprentice(ob) )
        	ob->set("class", "fighter");
    	ob->add("betrayer",-1);
    	if(ob->query("betrayer") < 0) ob->set("betrayer",0);
}*/

void killed_enemy(object who)
{
    	command("say 狂妄之徒，死不足惜！\n");
}

void die()
{
    	object killer;
    	if(objectp(killer = query_temp("last_damage_from"))){
    		if (killer->query("marks/won_lu")) killer->set("marks/kill_ximen", 1);
    	}
    	::die();
}

smart_fight()
{
	int i;
	object *enemy, who;
	who = this_object();
	enemy = this_object()->query_enemy();
	i = sizeof(enemy);
	if (i>2 && enemy[1]->is_zombie()&& random(3)>0) {
		who->perform_action("sword.zombie-wp1");
		return;
	}
	if (!random(5))
		who->perform_action("sword.hunranyijian"); 
	return;
}  

