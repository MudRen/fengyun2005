inherit NPC;
#include <ansi.h>
int talk_show();

void create()
{
    	set_name("鸨儿",({"mother"}));
    	set("title",YEL"鹦鹉楼"NOR);
    	set("long","
白皙皙脸揸胡粉，红霏霏头戴绒花。胭脂浓抹露黄牙，发髻浑如斗大。正是
鹦鹉楼的一个老鸨。\n");
    	set("gender","女性");
    	set("age",55);
    	set("no_arrest",1);
    	
    	set("combat_exp",350000);  
    	set("attitude", "friendly");
    
	   	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
		]) ); 
    	
    	set("chat_chance",1);
    	set("chat_msg",({
		(:	talk_show() 	:),
    	}) );
    	setup();    
	carry_object(__DIR__"obj/ladycloth2")->wear();
}



int talk_show() {
	object ob,girl;
	ob=this_object();
	
	if (ob->query_temp("talking")) return 1;
	
	girl=present("bilian",environment(ob));
	if (!girl || girl->is_fighting()) return 1;
	call_out("event1",1,this_player(),0);
	ob->set_temp("talking",1);
	return 1;
}
	
	
	
string *event1_msg=	({
	
	
	
	CYN"\n    鸨儿道：“碧莲儿，你可晓得门户中的行径么？”\n"NOR,
	
	CYN"    碧莲道：“行径便怎的？”\n"NOR,

 	CYN"    鸨儿道：“我们门户人家，吃著女儿，用著女儿。侥幸讨得一个像样的，
分明是大户人家置了一所良田美产。年纪幼小时，巴不得风吹得大；到得梳弄
过后，便是田产成熟，日日指望花利到手受用。前门迎新，后门送旧，张郎送
米，李郎送柴，往来热闹，才是个出名的姊妹行家。”\n"NOR,

    	CYN"    碧莲道：“羞答答，我不做这样事！”\n"NOR,
	
	CYN"    鸨儿格的笑了一声，道：“不做这样事，可是由得你的？一家之中，有妈
妈做主。做小娘的若不依教训，动不动一顿皮鞭，打得你不生不死。那时不怕
你不走我的路儿。”\n"NOR,

	CYN"    鸨儿又道：“那时熬这些痛苦不过，只得接客，却不把千金声价弄得低微
了？还要被姊妹中笑话。依我说，吊桶已自落在他井里，挣不起了。不如千欢
万喜，倒在娘的怀里，落得自己快活。”\n"NOR,


});



void event1(object me, int count)
{
	object ob,girl;
	ob=this_object();
	if (environment(me)!=environment(this_object()) || this_object()->is_fighting()) return;
	
	girl=present("bilian",environment(ob));
	if (!girl || girl->is_fighting()) return;
	
	message_vision(event1_msg[count]+"\n",me);
	
	if(++count==sizeof(event1_msg))
	{
		message_vision(CYN"    碧莲满脸通红，低著头一声不吭。\n\n"NOR,me);
		ob->delete_temp("talking");
		return;
	}
	else call_out("event1",2,me,count);
	return ;
}
	