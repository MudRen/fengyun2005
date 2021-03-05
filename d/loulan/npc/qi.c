#include <ansi.h>
inherit F_MASTER;
inherit SMART_NPC;
int leave();

void create()
{
	set_name("独孤伤", ({ "dugu shang","dugu" }) );
	set("gender", "男性" );
	set("long","
一个竹竿般瘦骨嶙峋的中年人，一件黑油油的皮衣像是蛇皮般裹在身上，
整个人也像是条毒蛇，每一分，每一寸都潜伏着不可测量的凶险，正是快
活王手下四使之气使，快活王手下第一高手。\n"
	);
        create_family("快活林", 2, "气使");
        set("attitude", "peaceful");
        set("rank_nogen",1);
        set("class","knight");
        
        set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
    	set("ranks",({"侍酒童","寻欢客","敛财客","药师","铁骑士","铁骑卫",
    			"铁骑统领","铁骑使","酒使","色使","财使","气使",
    			RED"快活右使"NOR,RED"快活左使"NOR,RED"一字并肩王"NOR,HIR"快活王"NOR}));
	
		set("reward_npc", 1);
		set("difficulty", 2);
    	
    	set("perform_busy_d", "knight/dodge/windy-steps/fengliu");
    	set("perform_weapon_attack", "knight/axe/xuanyuan-axe/guifushengong");
    	set("skill_type_w", "axe/xuanyuan-axe");
	
		set("chat_chance_combat", 30);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
    	
		set("age", 45);
        set("per", 4);
                
        set("combat_exp", 1500000);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "独孤伤冷哼一声，斜斜瞥了你一眼。\n",
        }) );
        
        set("inquiry", ([
    
    	]));
        
        set_skill("foreknowledge",100);
        set_skill("unarmed", 150);
        set_skill("force", 150);
        set_skill("longlife-force", 150);
        set_skill("axe", 200);
        set_skill("xuanyuan-axe", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("move", 150);
        set_skill("literate",100);
        set_skill("chanting",100);
        set_skill("windy-steps", 150);
        set_skill("hanshan-strike", 140);
        set_skill("perception", 120);
        set_skill("dream-herb",100);
        set_skill("herb",100);
        
        map_skill("herb","dream-herb");
        map_skill("dodge", "windy-steps");
        map_skill("unarmed", "hanshan-strike");
        map_skill("force", "longlife-force");
        map_skill("axe", "xuanyuan-axe");
        map_skill("parry", "xuanyuan-axe");
        
        setup();
  		carry_object("/obj/weapon/axe_l")->wield();
        carry_object(__DIR__"obj/foxcloth")->wear();
}

void attempt_apprentice(object me)
{
	command("smile");
    command("recruit " + me->query("id") );
	return;
}

void recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
    	ob->set("class", "knight");
}

int accept_fight(object me)
{
        object ob;
        ob = this_object();
	
	if (me->query("class")!= "knight" && me->query_temp("marks/knight_win_dugu")) {
		command("say 今天老夫身体欠佳，不打了，你请进吧。");
		return 0;
	}
		
	if(me->query("family/family_name") == query("family/family_name") &&
	   	me->query("family/master_id") == query("id"))
        {
        	if (ob->is_busy() || ob->is_fighting()) {
        		command("say 慢着，我先解决这个小子再说！");
        		return 0;
        	}
        	if (me->query_skill("windy-steps",1)< 150) {
        		command("say 你的身法太差，王爷见了还说我教徒无方，不成。");
        		tell_object(me,"（需150级急风三十六式）\n");
        		return 0;
        	}
        		
        	full_me();
        	message_vision(CYN"独孤伤吸了口气，浑身骨节喀喀作响。\n"NOR,ob);
        	command("say 好，你赢了我，你就可以去跟王爷学习了！\n");
        	me->set_temp("marks/fight_dugu",1);
        	return 1;
        }
        else
        {
        	command("say 无知小辈！关夫子门前卖大刀，让老夫教训你一下也好！\n");
			me->set_temp("marks/fight_dugu",1);
			return 1;
        }
}

void win_enemy(object loser)
{
    	command("say 不成器的庸才！\n");
}

void lose_enemy(object winner)
{
    	object owner;
    	mapping all;
    	
    	if (objectp(winner))
    	if (objectp(owner = winner->query("possessed")))
    		winner = owner;
    		
    	command("say 哎，老了。。\n");
    	if (winner->query_temp("marks/fight_dugu"))
    	{
    		winner->set_temp("marks/knight_win_dugu",1);
    		if (!REWARD_D->check_m_success(winner,"酒色财气"))
    		{
    			REWARD_D->riddle_set(winner, "酒色财气/qi", 1);
    			tell_object(winner, WHT"你完成了『酒色财气』中的“气”\n"NOR);
    		}
    		 		
    		all = winner->query("riddle/酒色财气");
			if (mapp(all) && sizeof(all) == 4)
				REWARD_D->riddle_done(winner,"酒色财气",50,1);	
    	}
}

