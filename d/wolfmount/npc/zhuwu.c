inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
	set_name("朱五太爷", ({ "master zhuwu", "master", "zhuwu" }) );
	set("gender", "男性" );
	set("age", 75);

    set("per", 40);
	set("attitude","heroism");
	set("apprentice_available", 5);
	set("long",		"
他全身都已冰冷僵硬，脸上的肌肉也已因萎缩而扭曲．一张本来很庄
严的脸，已变得说不出的邪恶可怖。\n"
		);
		
	create_family("狼山", 3, "山主");
	set("rank_nogen",1); 
	    set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
	set("ranks",({ "小喽罗","大喽罗","迷狼盗","夜狼盗","战狼盗",
				"小头目","大头目","小头领","大头领","大盗","盗尊",
				"盗霸",RED"盗圣"NOR,RED"盗帅"NOR,RED"盗王"NOR,HIR"盗王之王"NOR}));
				
	set("class", "wolfmount");
	
	set("inquiry", ([
		"他人":		"此人姓温、名良玉，自称为太阳使者！\n",
		"仇":		"此人姓温、名良玉，自称为太阳使者！\n",
		"报仇":		"此人姓温、名良玉，自称为太阳使者！\n",
	]));
			
	set("combat_exp", 20000000);
	set("difficulty", 40);
	set("reward_npc", 1);
	
	set_skill("parry", 190);
	set_skill("unarmed", 200);
	set_skill("foreknowledge",170);
	set_skill("move", 180);
	set_skill("perception",180);
	
	set_skill("hammer", 300);
	set_skill("assassin-hammer", 180);
	set_skill("cursism", 200);
	set_skill("force", 160);
	set_skill("wolf-force",170);
	set_skill("wolf-curse",200);
	set_skill("dodge", 160);
	set_skill("xueyeqianzong", 160);
	set_skill("literate",100);
	set_skill("wolf-strike", 200);
	set_skill("summonwolf", 270);
	set_skill("chanting",100);
	
	map_skill("dodge","xueyeqianzong");
	map_skill("unarmed","wolf-strike");
	map_skill("parry","assassin-hammer");
	map_skill("hammer","assassin-hammer");
	map_skill("force","wolf-force");
	map_skill("cursism","wolf-curse");
	
	setup();
	carry_object(__DIR__"obj/graycloth")->wear();
	carry_object(__DIR__"obj/juque");
	carry_object(__DIR__"obj/rockhammer")->wield();
}

int is_ghost()
{ 
	return 1; 
}

void init(){	
	::init();
	add_action("do_kill","kill");
}

int do_kill(string arg)
{
	object me,ob;
	object player, victim;
    	string id,id_class;
	me = this_player();
	if(arg == "master zhuwu" || arg == "master" )
	{
		if ( ob=present("wanyan tie",environment(this_object())) )
		{
			message_vision("$N对$n大喝一声：＂你不够斤两跟我主动手，让我先宰了你！\n",ob,me);
			ob->kill_ob(me);
			return 1;
		}
		else if ( ob=present("wanyan gang",environment(this_object())) )
		{
			message_vision("$N对$n大喝一声：＂你不够斤两跟我主动手，让我先宰了你！\n",ob,me);
			ob->kill_ob(me);
			return 1;
		}
		else 
		{
			return 0;
		}
	}
	player = this_player();
    if(!arg || arg == "") return 0;
    	victim = present(arg, environment(player));
	if(!objectp(victim))
		return notify_fail("这里没有这个人。\n");
    	if(living(victim))
    	{
        	id_class=victim->query("class");
        	id=victim->query("id");
       		if(id_class == "wolfmount"&& userp(victim)&&player!=victim)
        	{
			message_vision(HIW"$N对$n喝道：老子的徒弟也是你能杀的？\n"NOR, this_object(),player);
			this_object()->kill_ob(player);
			player->kill_ob(this_object());
            		if (!player->is_busy()) player->start_busy(2);
			return 0;
        	} 
    	}
    	return 0;
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
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } 
        else 
        {
                command("say 狼山弟子，贵精不贵多，今天不能再收了。");
        }
}

void do_recruit(object me){
	
		if( (string)me->query("class") != "wolfmount" )
        {
            command("say 我只收狼山子弟，你还是另谋高就吧！\n");
        }
        else if(!me->query("marks/杀太阳使者") && !REWARD_D->check_m_success(me,"狼山锄奸"))
        {				// 杀了 sun legate, 或者 解了 riddle 都可以拜
        	switch ( random(2) )
			{
		  		case 0:
					command("say 狼山已落入他人之手，我如何收你？\n");
			//		me->set_temp("marks/拜朱五太爷",1);
				break;
				case 1:
		  	//		me->set_temp("marks/拜朱五太爷",1);
		  			command("say 我冤魂不灭，就是等着有人为我报了仇，再传他一身武功。\n");
		  			break;
			}
		} else  {
		 		if (me->query_skill("assassin-hammer",1) < 150)
            	{
            		command("say 你帮我报了大仇，！\n");
            		command("say 不过你的搏浪七杀功力尚浅，学武不能好大喜功，多练上一阵再来拜我。\n");
            		tell_object( me, "（需150级搏浪七杀）\n");
            		return;
            	}
		
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