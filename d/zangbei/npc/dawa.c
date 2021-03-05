inherit SMART_NPC;
inherit F_VENDOR;
#include <ansi.h>

int bite();

void create()
{
	set_name("达娃", ({ "dawa" }) );
	set("title","放牧的姑娘");
	set("gender", "女性" );
	set("cor",20);
	set("age", 22);
	set("long","
沉甸甸的黑色长发，大金色耳环，手臂浑圆，肤色如铜，腰间铜饰叮当，
厚重粗笨凝满风沙油垢的黑氆氇藏袍从腰部直坠脚背。\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("chat_chance",1);
    	set("chat_msg",({
		CYN"\n达娃唱道：“绿色牧草茂盛的时候，是皎白的羔羊快乐之时。
     	     耗牛盛产鲜奶的时候，是年轻的姑娘快乐之时。”\n\n"NOR,
     	     CYN"\n达娃唱到：“山羊喜欢岩石，绵羊喜欢草原，姑娘喜欢舞场，寻觅心中"HIR"情人"NOR+CYN"。”\n\n"NOR,
    	}) );  
	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
		100:	(: bite() :),
        ]) );  
	
	set("inquiry", ([
 		"情人":"你问的是哪一个?\n",
   	]));
   	
	set_skill("thunderwhip",100);
	set_skill("whip",100);
	set_skill("dodge",100);
	set_skill("zuixian-steps",150);
	set_skill("parry",100);
	set_skill("unarmed",100);
	set_skill("pofeng-strike",100);
	map_skill("unarmed","pofeng-strike");
	map_skill("whip","thunderwhip");
	map_skill("parry","thunderwhip");
	map_skill("dodge","zuixian-steps");
	
	set("vendor_goods", ([
		__DIR__"obj/ricecake" : 80,
		__DIR__"obj/drymeat" : 80,
		"/d/guanwai/npc/obj/wineskin":	80,
	]) );
	setup();
	carry_object(__DIR__"obj/dawacloth")->wear();
	carry_object(__DIR__"obj/whip")->wield();
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
	message_vision( CYN"达娃唱到：“远方来的客人呀，喝口香甜的酥油茶吧。”\n"NOR,this_object());
}

int bite(){
	object dog,ob=this_object();
	object *enemy=ob->query_enemy();
	int i;
	
	if (!dog=present("wolfdog",environment(ob))) return 1;
	
	for (i=0;i<sizeof(enemy);i++){
		if (dog->is_fighting(enemy[i])) continue;
		message_vision(WHT"\n达娃唿哨一声，藏獒向$N恶狠狠地扑了上来。\n"NOR,enemy[i]);
		dog->kill_ob(enemy[i]);
	}
	return 1;
}


void reset(){
	set("vendor_goods", ([
		__DIR__"obj/ricecake" : 80,
		__DIR__"obj/drymeat" : 80,
		"/d/guanwai/npc/obj/wineskin":	80,
	]) );
}