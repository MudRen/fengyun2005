// taolord.c
// last modified by annie,6.28.03

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int leave();
int nec_book();

void create()
	{
	    set_name( "丁白云" , ({ "master ding", "master" }) );
	    set("nickname",HIB "晴空白云" NOR);
	    set("gender", "女性");
	    set("age", 66);
	    set("long",
	        "丁白云是丁乘风的师妹，也是丁乘风的亲妹妹。\n");
	
	    set("combat_exp", 20000000);
	    set("score", 200000);
	    set("reward_npc", 1);
	    set("difficulty", 40);
	    set("class", "taoist");
		
	    set("no_dodge_snow",1);
	    set("atman", 1400);
	    set("max_atman", 1400);
	    set("mana", 4000);
	    set("max_mana", 4000);
	    
	    set("inquiry", ([
		        "谷衣心法": "谷衣心法是我三清宫为对抗邪魔外道所创的内功心法。\n",
		        "三清宫":   "我三清宫自张天师开山立派至今，世世代代皆以降妖伏魔为己任。\n",
		         "leave" : (: leave :),
		         "内奸" : 	"却不知道这内奸是什么人．．．\n",
			 	"三清道宗":	(: nec_book :),
			 	"无字天书":	(: nec_book :),
	        ]) );
	
	    set("apprentice_available", 10);
	    set("chat_chance_combat", 80);
	    set("chat_msg_combat", ({
	        (: cast_spell, "drainerbolt" :),
//	        (: cast_spell, "invocation" :),
	    }) );
	
	    create_family("三清宫", 5, "女主持");
	    set("rank_nogen",1);
		set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
		set("ranks",({"弟子","道童","道姑","小仙姑","仙姑","散人","玉清散人",
			"上清散人","太清散人","真人","玉清真人","上清真人",YEL"太清真人"NOR,
			YEL"玄女"NOR,YEL"道宗传人"NOR,HIY"道宗宗主"NOR}));
			
	    set("guard_msg",HIW"$N喝道：三清宫虽是女子，却也不容外人欺辱！\n"NOR);
	
	    
	    set_skill("perception", 190);
	    set_skill("literate", 150);
	    set_skill("spells", 220);
	    set_skill("chanting",180);
	    
	    set_skill("foreknowledge",100);
	    set_skill("force", 160);
	    set_skill("move", 160);
	    set_skill("unarmed", 160);
	    set_skill("parry", 160);
	    set_skill("dodge", 160);
	    
	    set_skill("sword", 200);
	    set_skill("tenderzhi", 160);
	    set_skill("gouyee", 150);
	    set_skill("notracesnow", 180);
	    set_skill("snowshade-sword", 200);
	    set_skill("taoism", 220);
	    set_skill("necromancy", 200);
	    set_skill("scratmancy",200);
	    set_skill("scratching",200);
	    
	    map_skill("spells", "necromancy");
	    map_skill("unarmed", "tenderzhi");
	    map_skill("parry", "snowshade-sword");
	    map_skill("sword", "snowshade-sword");
	    map_skill("move", "notracesnow");
	    map_skill("dodge", "notracesnow");
	    map_skill("force","gouyee");
	
	    set_temp("apply/dodge", 200);
	    set_temp("apply/armor", 200);
	
	    setup();
	
	    if (!random(10))	
	    	carry_object(__DIR__"obj/sword_d2")->wield();
	    else
	    	carry_object(__DIR__"obj/sword2")->wield();	
	    	
	    carry_object(__DIR__"obj/robe2")->wear();
	    carry_object(__DIR__"obj/hat2")->wear();
	    carry_object(__DIR__"obj/shoe")->wear();
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
     	  
     	if (ob->query("family/master_name") != "清濯师太") {
     		message_vision("$N说：“去找小徒清濯修行几年吧。”\n",this_object(),ob);
     		return;
     	}
        if (ob->query_skill("taoism",1)<140) {
        	message_vision("$N说：“你的天师正道修行尚浅，去找小徒清濯多修行几年吧。（需140级）”\n",this_object(),ob);
        	return;
        }
        
        if (!REWARD_D->check_m_success( ob,"三清锄奸")){
        	message_vision(CYN"
$N沉吟道：你资质天赋，本是学我道术上上之选，可是。。。。
近年来我观内多出蹊跷，乘风师兄请来了风林火山四供奉，又令其子云鹤多加察看，
仍然是毫无头绪，此事一日不平，三清观不敢轻易再信新人。\n"NOR, this_object());
			REWARD_D->riddle_set( ob, "三清锄奸", 1);
			return;
		}     
             
        command("say 嗯，今日我收你为徒，需勤修道学，不可有一刻懈怠。");
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
//	object me = this_player();
	::init();
	add_action("do_killing", "kill");
}


int leave() {
	if (this_player()->query("class")!="taoist") return 0;
	message_vision(CYN"$N道。三清奇术，概不外传，你若走了可不要后悔。\n"NOR, this_object(),this_player());
	return 1;
}

int nec_book()
{
	object me,who;
	int i;
	me = this_object();
	who = this_player();
	i = REWARD_D->riddle_check(who,"无字天书");
	if (!i)
	{
		message_vision(CYN"$N说道：你问这个做什么？\n"NOR,me);
		return 1;
	}
	if (i != 2)
	{
		message_vision(CYN"$N叹了口气，双眼望向窗外修竹，显然不打算再理你。\n"NOR,me);
		return 1;
	}
	if (query("ggyying") || is_fighting() || is_busy())
	{
		message_vision(CYN"$N正忙，显然没空理你。\n"NOR,me);
		return 1;
	}
	set("ggyying",1);
	ccommand("sigh2");
	who->start_busy(20);
	call_out("do_ggyy",2,me,who,0);
	return 1;
}


void do_ggyy(object me,object target,int count)
{
	string msg;
	string *event_msg = ({
"丁白云「唉」的一声叹了口气。",
"丁白云说道：三年了，三年了，我还以为这件事永远不会有人再提起。",
"丁白云说道：既然你今日问到，也是有缘，我就不再隐瞒了。",
"丁白云说道：真正的『三清道宗』秘籍，早在三年前就已丢失。",
"丁白云说道：为维我三清威名不坠，防住邪门歪道乘机进犯，我假造了一本无字之书。",
"丁白云说道：却不料．．．今日竟被你得知。",
"丁白云说道：三清正法非邪道所及，秘籍丢失并不会有害三清。",
"丁白云说道：教中定有内奸，贼人才能得手——这才是真正让我忧心的事。",
"丁白云愁眉不展，转眼望向窗外修竹。",
});
	if (!me || !target)
		return;
	if (environment(me) != environment(target) || me->is_fighting() || target->is_fighting())
		return;
	msg = event_msg[count];
	message_vision(CYN+msg+"\n"NOR,me,target);
	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy",1+random(2),me,target,count+1);
	else
	{
		set("ggyying",0);
		target->stop_busy();
		REWARD_D->riddle_set(target,"无字天书",3);
		return;
	}
	return;

}


int accept_object(object who, object ob)
{
	
	mapping data;
	
	int i = REWARD_D->riddle_check(who,"无字天书");

	if (!ob->query("is_xbook"))
		return 0;
	
	if (i != 8)
	{
		ccommand("ack");
		ccommand("say 大胆偷书贼，还敢闯上三清送死？");
		kill_ob(who);
		return 1;
	}

	ccommand("ack");
	ccommand("thank "+who->query("id"));
	REWARD_D->riddle_done(who,"无字天书",100,1);
	
	    data = ([
				"name":		"无字天书",
				"target":	who,
				"att_1":	"kar",
				"att_1c":	1,
				"mark":		1,
		]);
		
		REWARD_D->imbue_att(data);
		
	
	return 1;
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
