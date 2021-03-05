inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void smart_fight();
void smart_busy();
void smart_attack();

int leave();
void create()
{
        set_name("王动", ({ "master wang", "master", "wang" }) );
        set("long","
他长得本不算难看，只不过显得面黄肌瘦，连说话都是有气无力的样
子，象是已饿了好几天。直挺挺躺在床上，但并没有睡着，眼睛反而
睁得很大。\n");
        set("nickname", HIR"一飞冲天 鹰中王"NOR);
        set("gender", "男性" );
        
        set("apprentice_available", 10);
        set("class","fugui");
        set("reward_npc", 1);
	set("difficulty", 20);
        
        set("age", 36);
        set("int", 40);
        set("agi", 100);
        
        set("combat_exp", 8000000);
		set("attitude","heroism");
        
        create_family("富贵山庄", 7, "庄主");
        set("rank_nogen",1);
        set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
		set("ranks",({ "小懒虫","懒虫","大懒虫","小懒鬼","懒鬼","大懒鬼",
                "小懒侠","大懒侠","义士","义侠","枪豪","枪霸",CYN"枪王"NOR,
                CYN"枪神"NOR,CYN"九洲枪神"NOR,HIC"欢乐英雄"NOR}));
							                
        set("chat_chance", 2);
        set("chat_msg", ({
                "王动喃喃自语：郭大路那犟牛到底跑到哪里去了？\n",
        }) );
        set("inquiry",  ([
				"郭大路" : "哎...那头犟牛.....\n",
				"红娘子" : "哎....\n",
				"竹叶青":	"等我找到了，一定请你来喝！\n",
                "leave": (: leave :),
        ])                      );
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        	(: smart_fight() :),    
        }) );

	
        set_skill("move", 220);
        set_skill("foreknowledge", 190);
        set_skill("parry", 180);
        set_skill("dodge", 180);
        set_skill("iron-cloth", 180);
        set_skill("spear", 350);
        
        set_skill("chanting", 100);
        
        set_skill("perception",100);
        set_skill("henglian", 180);
        set_skill("force", 160);
		set_skill("unarmed", 160);
		set_skill("literate", 100);
        
        set_skill("skyforce",160);
        set_skill("xuezhan-spear",250);
        set_skill("hawk-steps",160);
        set_skill("eagle-claw",160);
        
        map_skill("force", "skyforce");
	map_skill("parry","xuezhan-spear");
	map_skill("iron-cloth","henglian");
        map_skill("spear","xuezhan-spear");
        map_skill("dodge","hawk-steps");
        map_skill("move","hawk-steps"); 
        map_skill("unarmed","eagle-claw");     	
        
        set_temp("apply/iron-cloth",110);
        set_temp("apply/dodge",200);
        set_temp("apply/attack",100);
        set_temp("apply/haste",400);      
     	
     	setup();
        carry_object(__DIR__"obj/oldcloth")->wear();
        carry_object(__DIR__"obj/spear");
}

void attempt_apprentice(object ob)
{
        if( find_call_out("do_recruit") != -1 )
             command("say 慢著，一个一个来。");
        else
            call_out("do_recruit", 2, ob);
}

void do_recruit(object me)
{
		if(me->query("gender") != "男性" )
        {
          	command("say 我只收男弟子，你还是另谋高就吧！");
          	return 0;
        }
        if ( me->query_skill("hawk-steps",1)< 130)
        {
        	command("say 你的鲲鹏步法太差了（需130），我王动怎么会有你这样的徒弟呢！");
        	return 0;
        }
        
        if (!REWARD_D->check_m_success(me,"义救林太平"))
        {
        	command("sigh");
			command("say 如今我大难当头，这倒也罢了，可却拖累了我那林兄弟，
身中奇毒，至今尚在昏迷之中，生死难料，哪能再连累小兄弟你啊。");
			return 0;
		}
		
        if(!me->query_temp("marks/金链子"))	{
          	command("say 大路不见了，还是等知道了大路的消息再谈此事吧.\n");
		  	return 0;
		}
	 
	   	command("say 你帮我了却心头大事，我就收你为徒吧！\n");
        command("recruit " + me->query("id") );
	  
}
		
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "fugui");
}

void killed_enemy(object who)
{
        command("say 何必自寻死路呢？\n");
}

int accept_fight(object me)
{
	command("say 想打架？留着的力气帮我打扫一下院子吧！");
	command("sleep");
	return 0;
}

void init()
{
	::init();
	add_action("do_killing", "kill");
}

int do_killing(string arg)
{	
	object player, victim, weapon;
	string name;
	if(!arg) return 0;
	player = this_player();
	if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
	{
		name = victim->name();
		if( name == "王动")
		{
			if (weapon = present("silver spear", this_object())) {
				message_vision("$N皱皱眉头。\n", this_object());
                		message_vision("$N不知从哪里摸出一只亮银枪。\n", this_object());
                		weapon->wield();
                		call_out("do_unwie", 3);
                		}
			return 0;
		}
		return 0;
	}
	return 0;		
}

int do_unwie()
{
        if( !this_object()->is_fighting())
        {
                command("unwield spear");
                message_vision("$N揉揉眼、打个哈欠，立刻躺倒在床上。。。。\n", this_object());
                return 1;
        }
        else
                call_out("do_unwie", 3);
}

int accept_object(object me, object ob)
{
	if(ob->query("name") == HIY"金链子"NOR)
	{
		command("touch " + me->query("id"));
		command("say 终于知道大路的消息了！\n");
		command("say 这位" + RANK_D->query_respect(me)+ "，大恩不言谢，以后你就是我富贵山庄的人了.\n");
		me->set_temp("marks/金链子",1);
		return 1;
    }
	else
	    tell_object(me,"王动说道：这不是我想要的。\n");
        return 0;      
}


int leave() {
	if (this_player()->query("class")!="fugui") return 0;
	message_vision(CYN"$N笑笑，“这儿太穷，留不住人了。“\n"NOR, this_object());
	message_vision(CYN"$N说：人各有志，我不勉强，只是我的横练心诀你大概没机会体会了。\n"NOR,this_object());
	return 1;
}

smart_fight()
{
	int i;
	object *enemy;
	enemy = this_object()->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			if (!enemy[i]->is_busy()
				&& enemy[i]->query("combat_exp")<this_object()->query("combat_exp")) {
				this_object()->smart_busy();
			}
			{
				this_object()->smart_attack();
			} 
		}
	}
}

smart_busy() {
	this_object()->perform_action("dodge.yingjichangkong");
}
smart_attack() {
	this_object()->perform_action("spear.bafangfengyu");	
}
