
inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
	set_name("薛陀子", ({ "hunchback xue","xue" }) );
	set("nickname","损人不利己");
	set("gender", "男性" );
	set("age", 69);
	set("long",	"这位驼子正用白多黑少的双眼盯着你，眼里充满了凄苦之色。
你忍不住想施舍些什么给他。\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("inquiry", ([
		"施舍":		(: command("yao") :),
	]));
	set("per",30);
	set_skill("unarmed",200);
	set_skill("dodge",200);
	set("vendor_goods", ([
            __DIR__"obj/baozi1":30,
            __DIR__"obj/baozi2":30,
            __DIR__"obj/baozi3":30,
			__DIR__"obj/baozi4":30,
            __DIR__"obj/baozi5":30,

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
	switch( random(10) ) {
		case 0:
message_vision("$N用白多黑少的眼睛盯了$n一眼．\n",this_object(),ob);
			break;
		case 1:
message_vision("$N捶了捶自己的陀背说道：这位"+RANK_D->query_respect(ob)+
"要买什么？\n",this_object(),ob);
			break;
		case 2:
message_vision("$N哼道：买包子还是买．．．？\n",this_object());
	}
}


int accept_object(object who, object ob)
{
        int val;
		object paper;

        who->add_temp("marks/xuetuozi",ob->value());
        
        if( who->query_temp("marks/xuetuozi") < 5000 ) {
        	command( "say 多谢这位" + RANK_D->query_respect(who) + "可怜我这没用的穷老人，只可惜，杯水车薪啊！\n");
            return 1;
        }

		paper = new(__DIR__"obj/baozhizhi");
		if( paper) {
			paper->set("targetprice", who->query_temp("marks/xuetuozi"));
			paper->move(who);
		}
		command("touch");
		tell_object(who,CYN"薛陀子说：大恩大德，无以为谢啊。
薛陀子悄悄地塞给你一张东西说：很久以前我曾经救过一个江湖浪人，他临走前给了
我这张信物，说如果以后有了什么难事，或者被人欺负了，只要在这张纸上写上自己
的名字放到城隍庙的某一个地方，他就会依约前来相助。我一个穷老头儿活不久了，
就给你吧。\n"NOR);
		who->delete_temp("marks/xuetuozi");
		return 1;		       
}

void reset()
{
	set("vendor_goods", ([
                __DIR__"obj/baozi1":30,
                __DIR__"obj/baozi2":30,
                __DIR__"obj/baozi3":30,
		__DIR__"obj/baozi4":30,
                __DIR__"obj/baozi5":30,

	]) );

}
