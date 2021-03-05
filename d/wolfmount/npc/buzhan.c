inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("卜战", ({ "master buzhan", "master" }) );
        set("nickname", HIW"战狼王"NOR);
        set("long","他闪着光的脸虽然枯瘦腊黄，却带着种说不出的慑人气概。\n");
        set("gender", "男性" );
        set("apprentice_available", 5);
        
        set("age", 46);
        set("spi", 25);
        set("per", 40);
		set("attitude","heroism");
        set("combat_exp", 2200000);
               
        set("guard_msg",HIW"$N对$n喝道：狼山子弟,同气连枝,不容外人欺侮！\n"NOR);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "卜战一手紧紧握着旱烟枪：俺那帮好孩儿死得真惨，谁杀了那天杀星常\n无意，老夫必倾囊以授。\n",
        }) );
        
        create_family("狼山", 3, "大头领");
        set("rank_nogen",1); 
		    set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
	set("ranks",({ "小喽罗","大喽罗","迷狼盗","夜狼盗","战狼盗",
				"小头目","大头目","小头领","大头领","大盗","盗尊",
				"盗霸",RED"盗圣"NOR,RED"盗帅"NOR,RED"盗王"NOR,HIR"盗王之王"NOR}));
        set("class", "wolfmount");
        
        set("reward_npc", 1);
		set("difficulty", 2);
        
        set_skill("move", 150);
        set_skill("unarmed", 150);
        set_skill("perception", 150);    
        set_skill("foreknowledge",150);
        set_skill("parry", 150);
        set_skill("xueyeqianzong", 150);
        set_skill("wolf-strike", 160);
        set_skill("assassin-hammer", 160);
        set_skill("literate",100);
        set_skill("dodge", 150);
        set_skill("force", 150);
        set_skill("chanting",100);
    	
    	set_skill("summonwolf", 200);
        set_skill("hammer",200);
		set_skill("wolf-force",160);
	
		
		map_skill("dodge","xueyeqianzong");
		map_skill("unarmed","wolf-strike");
		map_skill("parry","assassin-hammer");
		map_skill("hammer","assassin-hammer");
		map_skill("force","wolf-force");
     	map_skill("cursism", "wolf-curse");	
     	
     	setup();
     	carry_object(__DIR__"obj/silkcloth")->wear();
	carry_object(__DIR__"obj/hanyan")->wield();
       	carry_object(BOOKS"skill/wolf-curse_50");

}

void reset()
{
	set("apprentice_available", 5);
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) 
        {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。\n");
                else
                        call_out("do_recruit", 2, ob);
        } 
        else {
                command("say 老夫已经收够了弟子，不能再收了。\n");
        }
}

void do_recruit(object me)
{
	if( (string)me->query("class") != "wolfmount" )
        {
        	command("say 我只收本门弟子，你还是另谋高就吧！\n");
        }
        else if(!me->query_temp("marks/wolf_win_tiezhan"))
        {
        	switch ( random(2) )
		{
		  	case 0:
				command("say 好个不忠不孝的家伙，竟然没有和铁战打招呼就跑来我这\n里，不收！\n");
				break;
			case 1:
		  		command("say 学武要循序渐进，你还是打好基础再来吧。\n");
		  		break;
		}
	}
	else if (!me->query_temp("marks/wolf_killed_wuyi"))
	{
                command("shake");
                command("say 不杀掉常无意那匹夫，老夫绝不收徒！\n");
	}
	else
	{
		command("say 你帮我报了大仇，我就收你为徒吧！\n");
		command("recruit " + me->query("id") );
	}
}
		
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wolfmount");
        add("apprentice_availavble", -1);
}

void init()
{	
	::init();
	add_action("do_killing", "kill");
}
