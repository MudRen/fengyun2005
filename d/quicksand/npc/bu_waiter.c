#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

int shen();
void create()
{
    	set_name("孙小红", ({ "sun xiaohong","sun" }) );
	set("gender", "女性" );
	set("age", 22);
    	set("title", "辫子姑娘" );
	set("long", "天机老人的孙女儿,粗粗的辫子,大大的眼睛,可爱动人。\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("rank_info/respect", "老板娘");
	
	set("inquiry", ([
      		"老板娘":  (: shen() :),	
        	"沈璧君" : (: shen() :),
        	"少奶奶": (: shen() :),	
        	"女红高手": (: shen() :),		
   	]));
	set("vendor_goods", ([
		__DIR__"obj/bu1" : 10,
		__DIR__"obj/bu2" : 30,
		__DIR__"obj/bu3" : 10,
		__DIR__"obj/bu4" : 5,
	]) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
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
	switch( random(3) ) {
		case 0:
            say( "孙小红道了个万福，笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，要买什么？\n");
			break;
		case 1:
            say( "孙小红似乎自言自语道：这位" + RANK_D->query_respect(ob)
                + "，最近有没有听到关于李寻欢大哥的消息？\n");
			break;
		case 2:
            say( "孙小红向你问道：这位" + RANK_D->query_respect(ob)
                + "，可知道李大哥和上官金虹一战究竟怎么样？\n");

			break;
	}
}

int shen() {
	message_vision(CYN"
孙小红甩了甩又黑又亮的大辫子，咯咯笑道：你说连夫人啊，她年前将这家布铺
盘给我后，就回无垢山庄了吧，哎，女人若是象她那样能找到连城璧这样的人中
之龙，实在几辈子也修不来的福气啊。\n\n"NOR, this_object());
	return 1;
}

int	accept_object( object who, object what) {
	
	if (what->query("name") == HIG"缀满梅花的纱巾"NOR) 
	{
		message_vision(CYN"
孙小红说：这纱巾倒是这店里卖出去的，不过，我年前才盘下这儿，以前的老板
娘做的买卖我也不太清楚。\n\n"NOR,who);
	}
	return 0;
}
