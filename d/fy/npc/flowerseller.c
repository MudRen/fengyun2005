inherit NPC;
inherit F_VENDOR;
inherit F_FLOWERSELLER;
#include <ansi.h>

void create()
{
	set_name("花满城", ({ "hua mancheng","hua","huaman" }) );
	set("gender", "男性" );
	set("title", BLU "月老"NOR);
	set("long","这位老板正对你露出慈祥的笑容。\n");
	
	set("age", 81);
	set("per",20);
	
	set("combat_exp", 350000);
	set("attitude", "friendly");
	set("no_arrest", 1);
	
	set("vendor_goods", ([
                __DIR__"obj/purple_flower":	50,
                __DIR__"obj/red_flower":	50,
                __DIR__"obj/yellow_flower":	50,
                __DIR__"obj/blue_flower":	50,
                __DIR__"obj/white_flower":	50,
                __DIR__"obj/black_flower":	50,
	]) );
	set_skill("unarmed",50);
	set_skill("dodge",50);
	
	set("inquiry",([
        	"押金" : (: give_deposit :),
        	"deposit" : (: give_deposit :),
        	"送花":		"送花的方法，请看店里的告示（sign）。\n",
        	"delivery":	"送花的方法，请看店里的告示（sign）。\n",	
    	
    	]) );

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
	add_action("assign_delivery","delivery");
	add_action("cancel_delivery","cancel");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(10) ) {
		case 0:
message_vision("$N笑着说道：各种新鲜花朵，买些回去给你的心上人吧。\n",this_object(),ob);
			break;
		case 1:
message_vision("$N笑咪咪地说道：这位"+RANK_D->query_respect(ob)+
"要买什么花儿？\n",this_object(),ob);
			break;
	}
}


void reset()
{
	set("vendor_goods", ([
                __DIR__"obj/purple_flower":50,
                __DIR__"obj/red_flower":50,
                __DIR__"obj/yellow_flower":50,
                __DIR__"obj/blue_flower":50,
                __DIR__"obj/white_flower":50,
                __DIR__"obj/black_flower":50,
	]) );
}


