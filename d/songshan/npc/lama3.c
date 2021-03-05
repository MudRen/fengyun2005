inherit NPC;
#include <ansi.h>

int do_duel();

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
		
		set("inquiry", 	([
			"赶回西域":		(: do_duel :),
				
			]));
			
		set("no_busy",5);
	        	
		set("chat_chance", 1);
        set("chat_msg", ({
                "盘灯孚尔说：嘿嘿，其实恒河只是条小河，咱们兄弟总想若是能改成‘黄河三佛’
那可真有意思！\n",
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
		set_skill("perception",200);
		set_skill("nodust-steps",200);
		set_skill("dodge",200);
		map_skill("dodge","nodust-steps");		
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
	say("盘灯孚尔哈哈一笑说道：好说，好说。\n");

}

int	do_duel(){
	object me = this_player();
	
	if (is_fighting())
	{
		tell_object(me,"盘灯孚尔正忙着呢，没空搭理你。\n");
		return 1;
	}
		
	if (REWARD_D->check_m_success( me, "力斗三佛"))
	{
		command("say 是是，咱师兄弟这就动身，有生之年不回中原了。");
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"力斗三佛") == 1)
	{
		command("smile");
		command("say 老衲活了这么多年，还是第一次听到这个“赶”字。");
		command("say 中原之人气量忒也小点，连我一条小小的恒河都也容不下，难怪日益式微。");
		command("say 你既奉师命而来。。。。");
		
		message_vision(CYN"盘灯孚尔指了指就公塔说：老衲就在上面单打独斗，给你个交待。"YEL"
		
盘灯孚尔说罢，也不见他用力，竟然一晃就上了塔顶。\n\n"NOR, me);
		
		REWARD_D->riddle_set(me,"力斗三佛",2);
		destruct( this_object());
		
		return 1;
	}
	
		command("say 施主可与老衲塔顶相会，单打独斗，以决胜负。");
		
		return 1;
}
			
		
		
		
		
	
	