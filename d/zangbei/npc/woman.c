inherit NPC;
#include <ansi.h>
int talk_show();

void create()
{
	set_name("洗衣妇", ({ "laundry woman","woman" }) );
	set("gender", "女性" );
	set("cor",20);
	set("age", 42);
	set("long","
沉甸甸的黑色长发，大金色耳环，手臂浑圆，肤色如铜，腰间铜饰叮当，
厚重粗笨凝满风沙油垢的黑氆氇藏袍从腰部直坠脚背。\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("chat_chance",1);
    	set("chat_msg",({
		(:  talk_show() :),
    	}) );  
	
    		
	set_skill("hammer",200);
	set_skill("dodge",200);
	set_skill("parry",200);
	set_skill("unarmed",200);
		
	setup();
	carry_object(__DIR__"obj/tcloth")->wear();
	carry_object(__DIR__"obj/l_hammer")->wield();
}


int talk_show() {
	object ob,girl;
	ob=this_object();
	
	if (ob->query_temp("talking")) return 1;
	if (random(3)) {
		message_vision("\n洗衣妇把几件花条围裙平铺在大石上，拿起洗衣锤梆梆地敲打起来。\n\n"NOR,ob);
		return 1;
	}
	
	girl=present("laundry girl",environment(ob));
	if (!girl || girl->is_fighting()) return 1;
	call_out("event1",1,this_player(),0);
	ob->set_temp("talking",1);
	return 1;
}
	
	
	
string *event1_msg=	({
	CYN"\n    洗衣妇笑嘻嘻地说：“珠玛，又在想林场的索仁了？”\n"NOR,
	
	CYN"    少女说：“妈，看你说哪儿去了，我想去拜丁白云学道术。”\n"NOR,

 	CYN"    少女比划了个手势，“刷，一道白光从你头顶穿过。。。。。”\n"NOR,

    	CYN"    洗衣妇惊讶地啊了一声。\n"NOR,
	
	CYN"    “珠玛，入了三清你以后就没法嫁人了！索仁可在等你呀。”\n"NOR,

	CYN"    少女狡诘地一笑：“妈，我打算学完了再还俗。”\n"NOR,

    	CYN"    少女凑到洗衣妇耳边轻轻地说：“索仁说了，他也打算这么到少林寺去学艺。”\n"NOR,

	CYN"    洗衣妇犹犹豫豫地说，“这成么？你舅舅在少林寺呆了三十年，还在看后山门呢。”\n"NOR,


});


void event1(object me, int count)
{
	object ob,girl;
	ob=this_object();
	if (environment(me)!=environment(this_object()) || this_object()->is_fighting()) return;
	
	girl=present("laundry girl",environment(ob));
	if (!girl || girl->is_fighting()) return;
	
	message_vision(event1_msg[count]+"\n",me);
	
	if(++count==sizeof(event1_msg))
	{
		message_vision(CYN"    。。。。。。。\n\n"NOR,me);
		ob->delete_temp("talking");
		return;
	}
	else call_out("event1",2,me,count);
	return ;
}
	