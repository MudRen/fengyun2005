inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int leave();
void create()
{
	set_name("铁战", ({ "master tiezhan", "master"}) );
    	set("nickname", HIY "战狼盗"NOR);
	set("gender", "男性" );
	set("age", 34);

	set("reward_npc", 1);
	set("difficulty", 2);
	set("attitude","friendly");
	set("combat_exp", 400000);

	set("long","一个敞着衣襟，豪迈不羁的大汉；让人一见就觉得此人够义气。\n");

	create_family("狼山", 4, "大头领");
       	set("rank_nogen",1); 
    set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
	set("ranks",({ "小喽罗","大喽罗","迷狼盗","夜狼盗","战狼盗",
				"小头目","大头目","小头领","大头领","大盗","盗尊",
				"盗霸",RED"盗圣"NOR,RED"盗帅"NOR,RED"盗王"NOR,HIR"盗王之王"NOR}));
    	    	
  	set("class","wolfmount");
  
	set("guard_msg",HIW"$N对$n喝道：狼山子弟,同气连枝,不容外人欺侮！\n"NOR);
  
      	set("inquiry", ([
           	"leave" : (: leave :),
        ]) );
        
    	set_skill("hammer", 120);		// these two skills are hidden
    	set_skill("assassin-hammer",100);
    	
    	set_skill("literate", 100);
    	set_skill("move", 120);
		set_skill("dodge", 120);
    	set_skill("force", 140);
    	set_skill("parry", 120);
		set_skill("unarmed",120);
    	set_skill("summonwolf",150);
    	set_skill("wolf-strike",150);
    	set_skill("wolf-force",120);
    	set_skill("xueyeqianzong",120);
    	set_skill("perception", 100);
    	set_skill("foreknowledge",100);
    	set_skill("chanting",100);
    
    	map_skill("dodge", "xueyeqianzong");
    	map_skill("unarmed", "wolf-strike");
    	map_skill("hammer", "assassin-hammer");
    	map_skill("parry", "assassin-hammer");
    	map_skill("force", "wolf-force");
    	
    	set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.duanhou" :),
        }) );
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/pifeng")->wear();
    	carry_object(__DIR__"obj/stonehammer")->wield();  
}

void attempt_apprentice(object me)
{
      	if( (int)me->query_cps() >=10 )
    	{
    		command("say 我狼山又多了一个无畏无惧的热血儿郎，可喜可贺啊！\n");
        	command("recruit " + me->query("id") );
        	return;
    	}
    	else
    	{
		command("shake");
        	command("say 我看你遇事不够沉着，怎么能驾驭得了群狼，你还是走吧！\n");
    	}
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wolfmount");
}

int accept_fight(object me)
{
        if(me->query("class") == "wolfmount")
        {
            	if (me->query_skill("summonwolf",1) < 150)
            	{
            		command("say 你的唤狼术太差劲了，还比什么？（需150级）\n");
            		return 0;
            	}
            	command("say 好！赢了我，你就可以去找狼山中更高深的师傅了！\n");
        	return 1;
        }
        else
        {
        	command("say 开什么玩笑？老子从来不打架，要动手就玩真的！\n");
        	return 0;
        }
}

void win_enemy(object loser)
{
    	command("say 你就这点能耐啊？别跟别人说我是你师傅，丢人！丢人！\n");
}

void lose_enemy(object winner)
{
    	command("say 乖徒儿，不错不错。有前途！到山上找师爷师公学去吧。\n");
	winner->set_temp("marks/wolf_win_tiezhan",1);
}

void init()
{	
	::init();
	add_action("do_killing", "kill");

}


int leave() {
	if (this_player()->query("class")!="wolfmount") return 0;
	message_vision(CYN"$N不屑地看了你一眼。\n"NOR, this_object(),this_player());
	message_vision(CYN"$N说：想走可以，以后别指望咱狼山的独门特技。\n"NOR,this_object(),this_player());
	return 1;
}


int prevent_learn(object me, string skill)
{
  	if (skill == "hammer" || skill == "assassin-hammer")
  	{
      		return 1;
  	}
  	return 0;
}

int prevent_shown(object me, string skill)
{
	if (skill == "hammer" || skill == "assassin-hammer")
		return 1;
	
	return 0;
}