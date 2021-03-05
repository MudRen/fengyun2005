inherit NPC;
inherit F_VENDOR;

#include <ansi.h>

int show_me();

int annie_drug()
{
	object me = this_player();

	if (me->query_temp("annie/find_herb/普生") 
		&& me->query_temp("annie/find_herb/百里灵") 
		&& me->query_temp("annie/find_herb/万小春") 
		&& me->query_temp("annie/find_herb/万春流") 
		&& me->query_temp("annie/find_herb/百里雪") 
		&& me->query_temp("annie/find_herb/叶星士")	)
	{
		message_vision(query("name")+"疑道：大家都不知道？那……那……\n",me);
		message_vision(query("name")+"突地一拍头笑道：你看我这记性，怎的忘了梅大先生？\n",me);
		return 1;
	}

	if (me->query_temp("annie/find_herb/普生"))
	{
		message_vision(query("name")+"摇头道：我委实不曾听过。\n",me);
		return 1;
	}
	message_vision(query("name")+"皱眉思索了半晌：明烟草？请恕老朽无知，不曾听过。\n",me);

	message_vision(query("name")+"说道："+"据说医仙叶星士让白云城主请去看病，你或许可以去白云岛问问。\n",me);
	me->set_temp("annie/find_herb/普生",1);
	return 1;
}

void create()
{
	set_name("普生", ({ "pu sheng","sheng" }) );
	set("gender", "男性" );
	set("age", 31);
	set("title", GRN "赛华陀"NOR);
	set("long",
		"这位普生堂老板武功，医道精湛。救死扶伤无数。\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",30);
	
	set("inquiry", ([
        	"陶氏" : 	(: show_me :),
        	"明烟草" : 	(: annie_drug :),
        	"陶保义把式" : 	(: show_me :),
             	"药方" :	"我每天开的药方成百上千，你问的是哪一张？\n",
             	"龙鲤鱼" :	(: show_me :),
             	"药引子" :	"我每天开的药方成百上千，你问的是哪一张？\n",
   	]));
	
	
	set("vendor_goods", ([
                __DIR__"obj/sendrug":200,
                __DIR__"obj/keedrug":200,
                __DIR__"obj/gindrug":200,

	]) );
	set_skill("unarmed",100);
	set_skill("parry",150);
	set_skill("dodge",150);
	set_skill("changquan",150);
	set_skill("move",150);
	map_skill("unarmed", "changquan");
	
	setup();
	carry_object(__DIR__"obj/fycloth")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(20) ) {
		case 0:
message_vision("$N望了$n一眼，低声说道：你面黄肌瘦，肾水亏空，是否．．．过度？\n",this_object(),ob);
			break;
	}
}


int show_me() {
	command("say 哦，你问的是两个月前来的那个陶把式的药方吧，龙鲤鱼十分罕见，只有沼泽地才有。");
	command("say 不过，一般人不叫它龙鲤鱼，他们叫它为“神仙鱼”。");
	return 1;
}

void reset()
{
	set("vendor_goods", ([
                __DIR__"obj/sendrug":12,
                __DIR__"obj/keedrug":22,
                __DIR__"obj/gindrug":12,
	]) );
}

