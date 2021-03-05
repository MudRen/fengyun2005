//XXDER 菩提庵乃是神水宫的接引处麽 突见一条白影，就像是一片雪花般

//飘过来。

//    夜凉如水，自山的那一边吹过来的晚风，轻柔得就如同天鹅的羽毛，淡淡的星光照在她

//身上。她轻盈的身子彷佛溶於这温柔的秋夜中。

inherit NPC;
int leave();

#include <ansi.h>
void create()
{
    	set_name("宫南燕", ({ "gong nanyan","gong"}) );  
    	set("gender", "女性");
    	set("class", "shenshui");
    	set("age", 21);
    	set("long","
她是个很美丽的少女，穿着雪白的衣服，乌黑的长发和雪白的衣袂同
时在风中飘扬，看来是那麽超群绝俗。");
    	
    	set("attitude", "peaceful");
    	set("class", "shenshui");
    	set("apprentice_available", 5);
    
    	
    	set("reward_npc", 1);
    	set("difficulty", 5);
    	
    	set("chat_chance_combat", 50);
    	set("chat_msg_combat", ({
        	(: perform_action, "dodge.lianhuanbu" :),
    	}) );
    
    	set("combat_exp", 5000000);
    	set("score", random(90000));
    	
    
    	set_skill("unarmed", 140);
    	set_skill("sword", 150);
    	set_skill("force", 150);
    	set_skill("parry", 120);
    	set_skill("dodge", 120);
    	set_skill("literate",140);
    	set_skill("move",120);
    	set_skill("charm",140);
    	set_skill("move",120);
    	set_skill("nine-moon-spirit", 120);	
    	set_skill("nine-moon-steps", 150);
    	set_skill("nine-moon-claw", 120);
    	set_skill("nine-moon-force", 150);
    	set_skill("nine-moon-sword", 150);

    	map_skill("dodge", "nine-moon-steps");
    	map_skill("unarmed", "nine-moon-claw");
    	map_skill("force", "nine-moon-force");
    	map_skill("sword", "nine-moon-sword");
    	map_skill("move","nine-moon-steps");
    
    	set_temp("nine-moon-force_poison", 340);
    	set_temp("damage_shield/type","kee");
	set_temp("damage_shield/amount",180);
	set_temp("damage_shield/msg",MAG"$n似乎沾上了$N周围的毒雾，手脚开始不灵便起来。\n"NOR);
	
    	set_temp("apply/dodge", 100);
    	set_temp("apply/attack", 100);

    	setup();
    	carry_object(__DIR__"obj/white_cloth")->wear();
}

/*
void reset()
{
    delete_temp("learned");
    set("apprentice_available", 5);
}

void attempt_apprentice(object ob)
{
    if( query("apprentice_available") ) {
        if( find_call_out("do_recruit") != -1 )
            command("say 慢著，一个一个来。");
        else
            call_out("do_recruit", 2, ob);
    } else {
        command("say 本使者今天已经收了五个弟子，不想再收徒了。");
    }
}

void do_recruit(object ob)
{
    	object girl;

   	if( ((int)ob->query("cor") < 10) || ((int)ob->query("cps") < 10)
        	|| ((int)ob->query("int") < 10)
        	||      ((int)ob->query("con") < 10)) {
        	command("say 入神水九阴要靠缘份，依我看" +
                	RANK_D->query_respect(ob) + "和九阴今生无缘。");
        	return;
    	}
    	if( (string)ob->query("gender") != "女性" )
    	{
		command("shake");
		command("say 神水宫的武功，非女子不能修炼到至高境界。");

	} else {
        	command("smile");
        	command("say 很好，很好，很好。");
        	command("recruit " + ob->query("id") );
		tell_object(ob, HIY"\n你只听一个细微的声音传了过来：你既已入我神水，当知神水密径。\n"NOR);
   		tell_object(ob, HIY"我神水弟子可在蒲团上坐定，青衣大师伯当发动机关，送你至神水密道。\n"NOR);
   		message("vision", ob->name()+ "似乎在侧耳聆听什么，却什么也听不到。\n",
   				environment(ob), ob);
   	}
}

int recruit_apprentice(object ob)
{
    	if( ::recruit_apprentice(ob) )
        	ob->set("class", "shenshui");
    	add("apprentice_availavble", -1);
}

void init()
{	
	::init();
	add_action("do_killing", "kill");
}

int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
        if(!objectp(victim))
		return notify_fail("这里没有这个人。\n");
    if(living(victim))
    {
        id_class=victim->query("class");
        id=victim->query("id");
       	if(id_class == "shenshui"&& userp(victim)&&player!=victim)
        {
message_vision(HIW"$N对著$n喝道：" + RANK_D->query_rude(player) 
						+ "竟敢杀" + RANK_D->query_self_rude(this_object()) 
						+ "的徒弟，去死吧。\n"NOR, this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}


int leave() {
	if (this_player()->query("class")!="shenshui") return 0;
	message_vision(CYN"$N冷笑了一声。\n"NOR, this_object(),this_player());
	message_vision(CYN"$N说：想走可以，但从此不能在江湖上使用九阴神功。\n"NOR,this_object(),this_player());
	return 1;
}

*/