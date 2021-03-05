inherit NPC;
#include <ansi.h>

void create()
{
	set_name("归东景", ({ "gui", "gui dong jing"}) );
	set("nickname", RED "福星高照"NOR);
	set("gender", "男性" );
	set("age", 44);
	set("per", 25);
	set("attitude","friendly");
	set("reward_npc", 1);
	set("difficulty", 5);
	set("long",	"一张方方正正的脸表情却很丰富，胡子又粗又密，却总是刮得很干净。\n");
	set("chat_chance", 1);
	set("chat_msg", ({
"归东景得意地道：“丁喜，老夫已经重创百里长青，邓定候也成了我
的阶下囚。现在，这个小妞，也落到我的手里....依你的人材武功，
要是愿意和老夫携手，呵呵....称霸武林，指日可待啊。”\n",
        }) );
	set("combat_exp", 3500000);
	
	set_skill("move", 180);
	set_skill("dodge", 180);
	set_skill("iron-cloth", 150);
	set_skill("xisui", 100);
	set_skill("unarmed",160);
	set_skill("puti-steps",100);
	set_skill("tanzhi-shentong",150);
	set_skill("dragonstrike",160);
	set_skill("throwing",180);
	set_skill("parry",160);
	set_skill("perception",200);
	
	map_skill("iron-cloth","xisui");
	map_skill("dodge", "puti-steps");
	map_skill("unarmed", "dragonstrike");
	map_skill("throwing","tanzhi-shentong");
	map_skill("parry", "tanzhi-shentong");
	
	setup();
    carry_object("/obj/armor/cloth")->wear();
    carry_object("/obj/weapon/dart")->wield();
}

void init()
{
	object me;
	::init();
	if( !query_heart_beat(this_object()) ) set_heart_beat(1); 
	if( interactive(me = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, me);
	}
}

void greeting(object me)
{
	if( !me || environment(me) != environment() ) return;
	if((string)me->name() != "老山东" && !me->query_temp("marks/keychain_ehg"))
	{
		message_vision("$N一见$n来，喝道：“什么人！胆敢乱闯本寨聚义厅，找死！”\n",this_object(),me);
		this_object()->kill_ob(me);
		me->kill_ob(this_object());
	}
	else
	{
		message_vision("$N笑道：“老山东，带了烧鸡来可否？待我与这位小姐风流快活\n一番，再来品尝你的手艺。”\n",this_object(),me);	
		message_vision("$N转头冲王若兰淫笑两声：“小妞，别着急......嘻嘻”\n",this_object(),me);		
	}
}
