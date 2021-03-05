inherit __DIR__"heroine";
#include <ansi.h>
void create()
{
	set_name("虹儿",({"hong er"}) );
	set("long", "她一袭白衣，如同从云中走下。那双新月般的眼睛，笑起来的时候， 
就好像有一抹淡淡的雾，谈淡的云。 
\n");
        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
             "虹儿轻轻叹息一声：“生命本是天赐的，何时竟然变得如此卑贱？”\n" ,
        }) );



	::create();
	setup();
	carry_object(__DIR__"obj/white_cloth")->wear();
}
	
mapping* event_list=({});
mapping query_answers(string topic)
{
	int i;
	
	for(i=0;i<sizeof(event_list);i++)
		if(event_list[i]["question"]==topic)
			return event_list[i];
	return 0;
}

mapping query_events(string topic)
{
	int i;
	
	for(i=0;i<sizeof(event_list);i++)
		if(event_list[i]["events"]==topic)
			return event_list[i];
	return 0;
}

string *killing_msg=({ 
       HIC"$N看着$n，眼睛里露出痛苦之色，忽然低下头，幽幽地说：“也许我本 
    不该来杀你，也许你根本不该来这里的。”\n"NOR, 
       HIR"花香在轻风中默默流动，$N忽然笑了笑，对$n说：“还是在杀人 ，可是你自己已经快完结了。”\n"NOR, 
       HIC"$N轻轻叹息了一声，带着种说不出的厌倦，悠悠的对$n道：“又是一个生命，又是一天过去了，日复一日，年复一年，这样的日子要过到什么时候为止？”\n"NOR, 
       HIY"$N用一种平静得已经接近冷酷的声音对$n说“天下本来就有很多无可奈何的 
事，在某一种情况中，一个人明明知道自己做的事不对也不能不做下去。”\n"NOR, 
       HIG"$N对$n浅笑道：“看不出来，你居然会敢在桃源行凶呢。”\n"NOR, 
       HIB"$N温柔地偎依在$n身边，轻轻地问：“让我杀了$n好吗？”\n"NOR, 

});

string query_killing_msg()
{
	return killing_msg[random(sizeof(killing_msg))];
}
void init()
{
	object me;
	
	::init();
	me=this_player();
	if(query("killing_person")==me)
	{
		if(!me->query("vendetta/taoyuan")||me->query("vendetta/taoyuan")+10800<time())
		{
			message_vision(CYN"$N细细打量了一下$n，叹了口气，转身离去。\n"NOR,this_object(),me);
			this_object()->move("/d/fy/church");
			delete("killing_person");
			delete("following_person");
			delete("no_leave");
			return ;
		}
		message_vision(query_killing_msg(),this_object(),me);
		// can adjust honger's level according to player here
		set("combat_exp", (int) me->query("combat_exp") *9/8 );
		kill_ob(me);
	}
}

void die()
{
	object me;
	
	if(me=query_temp("last_damage_from"))
		message_vision(HIG"$N目中突然现出一丝笑意，很渺茫，很难捉摸的笑意，有种说不出的疲倦和无奈。
$N转身飘然而去。 $n的耳边只留下了这一句“我会再回来的。”\n"NOR,this_object(),me);
	else
		message_vision(MAG"$N目中突然现出一丝笑意，很渺茫，很难捉摸的笑意，有种说不出的疲倦和无奈。
$N转身飘然而去。 \n"NOR,this_object());

	this_object()->move("/d/fy/church");
	this_object()->full_me();
//	"/cmds/imm/full"->main(this_object(),"");
	if(!me)
		me=query("killing_person");
	set("no_chasing",1);
	call_out("begin_chasing",60+random(60));
}

void unconcious()
{
	die();
}

int begin_chasing()
{ 	
	object me;
	if(!query("chasing_time")||query("chasing_time")+10800<time())
	{
		delete("killing_person");
		delete("following_person");
		return 1;
	}
	if(me=query("killing_person"))
	{ 
		delete("no_chasing");
		return 1;
	}
	call_out("begin_chasing",15+random(15));
	return 1;
}

int do_fighting()
{
	if(query_busy())
		return 1;
	if(!query_temp("daoqian"))
	{
		this_object()->ccommand("perform iron-cloth.bingwantianzhang");
		return 1;
	}	
	switch(random(3))
	{
		case 2:
		this_object()->ccommand("perform tanzhijinghun");
		break;
		
		case 1:
		this_object()->ccommand("perform dodge.yexuechuji");
		break;
	}
	return 1;
}

void heart_beat()
{
	::heart_beat();
	if(is_fighting())
		do_fighting();
}