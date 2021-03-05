inherit NPC;
#include <ansi.h>
#include <command.h>

void create()
{
    	set_name("珍珠",({"zhenzhu"}));
    	set("title",YEL"鹦鹉楼"NOR);
    	set("long","
珍珠肌肤微丰，合中身材，本是大户人家出身，家道破落沦落到风尘中，鸨儿
见她懂些诗画，专门给她布置这间屋子接待客人中的风骚之士。\n");
    	set("gender","女性");
    	set("age",22);
    	set("no_arrest",1);
    	
    	set("combat_exp",600000);  
    	set("attitude", "friendly");
    
   	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	]) ); 
    	
    	set("chat_chance",1);
    	set("chat_msg",({
		"珍珠吟道：“劝君莫惜金缕衣，劝君惜取少年时。。。”\n",	
    	}) );
    	setup();    
	carry_object(__DIR__"obj/ladycloth1")->wear();
}

 void init()	{
	::init();
	add_action("do_love","answer");
	add_action("do_enjoy","enjoy");
}

  
int do_love(string arg)
{
	object me;
	object ob;
	ob=this_object();
	me=this_player();
	if(arg == "有花堪折直需折，莫待无花空折枝。"
		|| arg == "有花堪折直需折，莫待无花空折枝"
		|| arg == "有花堪折直需折，莫待无花空折枝！"
		|| arg == "有花堪折直须折，莫待无花空折枝。"
		|| arg == "有花堪折直须折，莫待无花空折枝"
		|| arg == "有花堪折直须折，莫待无花空折枝！"	) {
                if (me->query("gender")=="男性")
                	message_vision(MAG "\n$N对$n叹道：公子真是知情达趣之士，小女子恨不能以身相许。\n"NOR, ob,me);
                else 
                	message_vision(MAG "\n$N对$n道：这位姐姐真是性情中人，小女子若是男身，要定了姐姐。\n"NOR, ob,me);
                me->set_temp("mark/enjoy",1);
                return 1;
        }
    
    command("shake");    
	command("say ");
	return 1;
}        

int do_enjoy()
{
	object me;
	object wo;
	object *inv;
	int maxgin,maxkee, maxsen;
	int i;
	me = this_player();
	if(!me->query_temp("mark/enjoy")){
	        command("say 哎哟．．．这位" + RANK_D->query_respect(me)+"，奴家可不是那种随便上床的人！");
		return 1;
	}
	if (query_temp("enjoy_time")+60>time()){
		message_vision(CYN"珍珠娇喘吁吁地说：＂饶了奴家，让奴家歇上片刻吧。＂\n"NOR,this_object());
		return 1;
	}
	message_vision("$N轻飘飘地向$n走过来，温柔的抚弄$n的黑发。。。。\n",this_object(),me);
	me->unconcious();
	set_temp("enjoy_time",time());
    
    me->full_me();	
	wo = new(__DIR__"obj/grass");
	wo->move(me);
	return 1;
}
	