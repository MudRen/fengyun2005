#include <ansi.h>
#include <combat.h>
inherit NPC;
inherit F_MASTER;
int leave();

void create()
{
    set_name("定邦大师", ({"master dingbang", "master", "dingbang" }) );
    set("gender", "男性");
    set("long", "
定邦大师是兴国大师的师侄，主管禅寺外院，也负责收一些俗家弟子，
弘扬佛法。\n");
    	set("age", 74);
    	set("attitude", "peaceful");
    	set("class", "bonze");
    	set("apprentice_available", 3);

    	set("reward_npc", 1);
	set("difficulty", 5);
    	
    	set("combat_exp", 1200000);
    	set("score", 9000);
    	
    	set_skill("unarmed", 120);
    	set_skill("dabei-strike",120);
    	set_skill("force", 120);
    	set_skill("dodge", 120);
    	set_skill("literate", 100);
    	set_skill("chanting", 120);
    	set_skill("parry", 120);
    	set_skill("lotusforce", 120);
    	set_skill("buddhism", 100);
    	set_skill("nodust-steps",120);
    	set_skill("staff",120);
    	set_skill("cloudstaff",120);
    	set_skill("perception", 100);
    	set_skill("foreknowledge", 100);
	set_skill("move", 100);
	set_skill("magic", 100);
	set_skill("essencemagic", 100);
    	    	
    	map_skill("force", "lotusforce");
    	map_skill("dodge","nodust-steps");
    	map_skill("unarmed","dabei-strike");
    	map_skill("staff","cloudstaff");
    	map_skill("parry","cloudstaff");
    	map_skill("magic","essencemagic");
    	

 	set("guard_msg",HIW"$N喝道：阿弥陀佛,出家人与世无争，却也不任人欺侮，施主请了！！\n"NOR);
 	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.qianshouqianbian" :),
        }) );
         set("inquiry", ([
        	"leave" : (: leave :),
    	]));
 
    	create_family("兴国禅寺", 4, "大师");
		set("rank_nogen",1);
		set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
					
		set("ranks",({"小沙弥","小和尚","守山僧","布衣僧","麻衣僧","白衣僧","灰衣僧","黑衣僧",
		"护寺大师","护法罗汉","护国金刚","护寺神僧",YEL"护法圣僧"NOR,YEL"护国活佛"NOR,
		YEL"净土宗传人"NOR,HIY"净土宗宗主"NOR}));				
		
    	setup();
    	carry_object(__DIR__"obj/staff")->wield();
    	carry_object("/obj/armor/cloth")->wear();
}


void attempt_apprentice(object ob)
{
              
    	if (ob->query("once_menpai/bonze")&& ob->query("class")!="bonze") {
			command("shake");
			command("say 施主反复无常，没有向佛之心。\n");
			return;
		}
 		if(ob->query("marry") && !ob->query("jiebai")){
			message_vision("$N抬头看了看$n：这位施主六根未净，还是请回吧。\n", 
				this_object(), ob);
			return;
		}		
    	if (ob->query("gender")!="男性") {
    		message_vision("$N说：本寺不收女徒。\n",this_object());
    		return ;
    	}	
    	ob->set("class","bonze");
    	command("say 阿弥陀佛，善哉！善哉！");
    	command("recruit " + ob->query("id") );
}


int accept_fight(object me)
{
    	if( (string)me->query("class")=="bonze" )
        	command("say 阿弥陀佛！出家人戒逞强恶斗！老衲不敢违反清规。");
    	else
        	command("say 施主既然身负绝艺，老衲佩服便是，也不必较量了。");
       	return 0;
}


void init()
{	
	::init();
	add_action("do_killing", "kill");

}


int leave() {
	if (this_player()->query("class")!="bonze") return 0;
	message_vision(CYN"$N合掌道：阿弥陀佛，既是无缘，何必再留，以后也不要再回来了。\n"NOR, this_object(),this_player());
	message_vision(CYN"$N说：佛门的神通术和心法非弟子不能使用。\n"NOR,this_object(),this_player());
	return 1;
}

