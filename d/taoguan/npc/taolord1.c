inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int leave();

void create()
	{
	    set_name( "清濯师太" , ({ "master qing", "master" }) );
	    set("nickname",WHT "心静如水" NOR);
	    set("gender", "女性");
	    set("age", 46);
	    set("long","
白云观主虽然修道，却不轻易收徒，清风、清漪师太是她出家前的丫头、清濯师太
原是被人遗弃在三清宫门前的孤儿，白云观主怜其身世便将她收留，这清濯也是秀
外慧中，不仅将三清道术学得炉火纯青，把观内的事务也安排的头头是道。近年来
丁白云少理俗务，这清濯师太成了三清观的内当家，隐隐便是丁白云的衣钵传人。
\n");
	
	    set("combat_exp", 3000000);
	    set("score", 20000);
	    set("reward_npc", 1);
	    set("difficulty", 10);
	    set("class", "taoist");
		
	    set("no_dodge_snow",1);
	    set("atman", 1400);
	    set("max_atman", 1400);
	    set("mana", 4000);
	    set("max_mana", 4000);
	    
	    set("inquiry", ([
	        "谷衣心法":  "谷衣心法是我三清宫为对抗邪魔外道所创的内功心法。\n",
	        "三清宫":   "我三清宫自张天师开山立派至今，世世代代皆以降妖伏魔为己任。\n",
	         "leave" : (: leave :),
		]) );
	
	    set("apprentice_available", 3);
	    set("chat_chance_combat", 80);
	    set("chat_msg_combat", ({
	        	(: cast_spell, "drainerbolt" :),
	    }) );
	
	    create_family("三清宫", 6, "主持");
	    set("rank_nogen",1);
		set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
		set("ranks",({"弟子","道童","道姑","小仙姑","仙姑","散人","玉清散人",
			"上清散人","太清散人","真人","玉清真人","上清真人",YEL"太清真人"NOR,
			YEL"玄女"NOR,YEL"道宗传人"NOR,HIY"道宗宗主"NOR}));

	    set("guard_msg",HIW"$N喝道：三清宫虽是女子，却也不容外人欺辱！\n"NOR);
	
	    set_skill("literate", 100);
	    set_skill("perception", 150);
	    set_skill("chanting",150);
	    
	    set_skill("foreknowledge", 100);
	    set_skill("force", 150);
	    set_skill("spells", 150);
	    set_skill("move", 150);
	    set_skill("unarmed", 150);
	    set_skill("sword", 150);
	    set_skill("tenderzhi", 150);
	    set_skill("parry", 150);
	    set_skill("dodge", 150);
	    set_skill("gouyee", 150);
	    set_skill("notracesnow", 150);
	    set_skill("snowshade-sword", 150);
	    set_skill("taoism", 150);
	    set_skill("scratmancy",150);
	    set_skill("scratching",150);
	    set_skill("necromancy",150);
	    
	    map_skill("spells", "necromancy");
	    map_skill("unarmed", "tenderzhi");
	    map_skill("parry", "snowshade-sword");
	    map_skill("sword", "snowshade-sword");
	    map_skill("move", "notracesnow");
	    map_skill("dodge", "notracesnow");
	    map_skill("force","gouyee");
	    map_skill("scratching","scratmancy");
	    			
	    set_temp("apply/dodge", 200);
	    set_temp("apply/armor", 200);
	
	    setup();
	    carry_object(__DIR__"obj/r_sword")->wield();
	    carry_object(__DIR__"obj/tcloth")->wear();
	    
}

void attempt_apprentice(object ob)
{
    	if( query("apprentice_available") ) {
        	if( find_call_out("do_recruit") != -1 )
            		command("say 慢著，一个一个来。");
        	else
            		call_out("do_recruit", 2, ob);
    	} else {
        	command("say 贫道今天已经收了三个弟子，不想再收徒了。");
    	}
}

void do_recruit(object ob)
{
    
    	if( (string)ob->query("gender") != "女性" )
		{
        	command("say 贫道是出家人，不便收男徒，施主还是请回吧。");
			return;
		}
    	
    	else if(ob->query("marry") && !ob->query("jiebai")) {
			message_vision("$N摇了摇头说：“这位姑娘已有家室，如何还能削发修行？\n",this_object(), ob);
			return;
     	}	  
    	             
        command("say 嗯... 想入我三清宫？也好....");
        command("recruit " + ob->query("id") );
        
}

int recruit_apprentice(object ob)
{
    	if( ::recruit_apprentice(ob) )
        	ob->set("class", "taoist");
    	
    	add("apprentice_availavble", -1);
}


void init()
{	
	object me = this_player();
	::init();
	 if( interactive(me = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
	add_action("do_killing", "kill");
}

void greeting(object me)
{
        object ob,*inv, ding;
        
        ob=this_object();
        if( !me || environment(me) != environment() ) return;
                        
        if (me->query("class")=="taoist" )        {
                
                inv = all_inventory(me);
                if  ( sizeof(inv) >= 15) 
                        return;
        
                if (present("ding",me)) return;
                
                message_vision(CYN"$N对$n说：“你跟随为师多年，今日传你一宝鼎，望你能光大师门。”\n"NOR,ob,me);
                ding= new("/obj/specials/ding/ding_baby");
                if (me->query("combat_exp")>5000000) {
                        ding->set("name",RED"红木宝鼎"NOR);
                        ding->set_max_encumbrance(300);
                } else if (me->query("combat_exp")>3000000) {
                   ding->set("name",YEL"黄木宝鼎"NOR);
                        ding->set_max_encumbrance(200);
                } else {
                        ding->set("name",HIC"青木宝鼎"NOR);
                        ding->set_max_encumbrance(100);
                }
                ding->move(me);
                message_vision("$N从怀里取出一口"+ding->name()+"递给$n。\n",ob,me);     
                return;
        }
                
} 

int leave() {
	if (this_player()->query("class")!="taoist") return 0;
	message_vision(CYN"$N道。三清奇术，概不外传，你若走了可不要后悔。\n"NOR, this_object(),this_player());
	return 1;
}
