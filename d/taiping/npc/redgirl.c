#include <ansi.h>
#include <command.h>

inherit SMART_NPC;

int show_me();
int ask_tie();

void create()
{

		set_name("红衣裳的小姑娘",({"redgirl","girl"}));
    	set("title","鹦鹉楼");
    	set("long", "穿着套红衣裳的小姑娘，一双眸子黑如点漆。\n");
		set("age",40);
		set("combat_exp", 7000000);
        	
	
		set("inquiry", ([
        	"韦七娘" : 	(: show_me :),
           	"wei qiniang" : (: show_me :),
           	"tie hen" : 	(: ask_tie :),
           	"铁恨" : 	(: ask_tie :),
   		]));
	
	
		set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	     
        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
	
    	}) );    	
    	
		auto_npc_setup("wang",250,200,0,"/obj/weapon/","fighter_w","tanzhi-shentong",2);
		set_skill("tanzhi-shentong",160);
		setup();	
		carry_object(__DIR__"obj/redskirt")->wear();
		carry_object(__DIR__"obj/needle")->wield();
}


void init(){
	::init();
	add_action("do_look", "look");
}


int do_look(string arg) {
	if(arg == "redgirl" || arg == "girl"){
		write("穿着套红衣裳的小姑娘，一双眸子黑如点漆。\n");
		write("她看起来约十多岁。\n");
		write("她长的不胖不瘦，武功看起来好象"+BLU "不堪一击"NOR+"，出手似乎极轻。\n");
		write("她精神饱满，正处于巅峰状态。\n");
		write("她身穿红短裙(Red skirt)\n");
		return 1;
	}
	return 0;
}

int accept_object(object who, object ob)
{
	if( ob->name()==HIG"碧玉"NOR) {
    	if (REWARD_D->riddle_check(who,"喋血鹦鹉")==4
    		 && who->query_temp("marks/parrot/ask_wei")) {
            
            command("say 原来你是铁捕头的朋友，刚才失礼了。此地人多杂，不是谈话之地。");
            command("say 这样，你可去找镇上驿站的安子豪，就说是我叫你去的。");
            REWARD_D->riddle_set(who,"喋血鹦鹉",5);
 //         who->set("marks/parrot/韦七娘",1);
            return 1;
		}                 
        	command("say 这位"+RANK_D->query_respect(who)+"，还是留着赏给姑娘们吧。");
        	return 0;
        }        
        return 0;
} 


int show_me()	{
	
	if (this_player()->query("marks/parrot/韦七娘"))
		ccommand("say 铁恨，安子豪和我都在追查太平王府失窃珠宝的下落。");
	else {
		command("ack "+this_player()->get_id());
		this_object()->set("name","韦七娘");
		this_player()->set_temp("marks/parrot/ask_wei",1);
		command("say 你竟然知道我的来历！不过，我前后在江湖上七年，已太累了。");
		command("say 我现在只是鹦鹉楼一个开门的丫头。");
	}
	return 1;
}


int ask_tie()  {
	
	object who;
	who=this_player();
	if (REWARD_D->riddle_check(who,"喋血鹦鹉")>=5)
		ccommand("say 铁恨，安子豪和我都在追查太平王府失窃珠宝的下落。");
		else
		ccommand("say 铁恨？是不是昨儿个晚上来找翠花的那位大爷？");
	return 1;
}	

