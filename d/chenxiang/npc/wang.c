//Tie
#include <ansi.h>

inherit NPC;
inherit F_VENDOR;
int tell_him();
int tell_him2();
int do_answer(string arg);

void create()
{
    	set_name("王石匠", ({ "wang", "shijiangfang" }) );
    	set("gender", "男性" );
    	set("age", 49);
    	set("long", @LONG
王石匠年纪已经颇大了，听说他年轻的时候有个大恩人。如果不是恩人的话，
王石匠恐怕早已经被人害死了。
LONG
        );
    	
    	set("combat_exp", 20000);
    	set("attitude", "friendly");
    
    	set_skill("dodge", 50);
    	set_skill("parry", 50);
    
    	set("vendor_goods", ([
        	__DIR__"obj/stone1":60,
        	__DIR__"obj/stone2":70,
        	__DIR__"obj/stone3":80,
        	__DIR__"obj/stone4":90,
        ]) );
    	set("inquiry", ([
	        "大恩人":	(: tell_him2 :),
	        "恩人":	(: tell_him2 :),
	        "玉脖套" : (: tell_him :),
	        "yubotao" : (: tell_him :),
        ]));
    	setup();
    	carry_object("/obj/armor/cloth")->wear();
}

void init()
{
    	object ob;

    	::init();
    	if( interactive(ob = this_player()) && !is_fighting() )
    	{
        	remove_call_out("greeting");
        	call_out("greeting", 1, ob);
    	}
    	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
    	if( !ob || environment(ob) != environment() ) return;
    	switch( random(10) )
    	{
    	case 0:
        	say( " 王石匠笑着道：这位"+ RANK_D->query_respect(ob)
             		+ "，买石狮子么？ \n");
        	break;
    	case 1:
        	say( " 王石匠笑着道：这位"+ RANK_D->query_respect(ob)
             		+ "，我这儿的大理石质量最好了。 \n");
        	break;
    	}
}


int tell_him2()
{
    	object me;
    	me=this_player();
    	tell_object(me,CYN"王石匠说：你认识我的大恩人？不可能吧，你说他叫什么？\n"NOR);
    	me->set_temp("marks/wangshijiang",1);
    	add_action("do_answer","answer");
    	return 1;
}



int do_answer(string arg)
{
		object me;
    	me=this_player();
    	
    	if (!me->query_temp("marks/wangshijiang"))	return 0;
    	
    	if (me->query_temp("marks/wangshijiang")==1)
    	{
    		if (arg == "康七" || arg == "kangqi") {
    			command("touch");
    			command("say 看来你真是天才，竟然连ｃｏｄｅ都看过了！");
    			ccommand("dapp "+me->query("id"));
				return 1;
			}
    		
    		if (arg != "张飞")	{
    			command("shake");
    			command("say 果然是冒充的。");
    			me->delete_temp("marks/wangshijiang");
    			return 1;
    		}
    		tell_object(me,CYN"王石匠说：你竟然知道我大恩人的名字，想来和他必有关联！\n"NOR);
    		
    		tell_object(me,CYN"
王石匠说：那我且再考你一考：大恩人救我那年，我的年龄是大恩人和我现在
年龄之和的一半，等我到了大恩人救我那年年龄两倍的时候，大恩人就是我现
在的年龄了。大恩人今年几岁？\n"NOR);
		   	me->set_temp("marks/wangshijiang",2);
    		return 1;
		}
		if (me->query_temp("marks/wangshijiang")==2)
    	{
    		if (arg != "30" && arg!="三十")	{
    			command("shake");
    			command("say 果然是冒充的。");
    			me->delete_temp("marks/wangshijiang");
    			me->add_temp("timer/wangshijiang",1);
    			return 1;
    		}
    		tell_object(me,CYN"
王石匠说：对头！看来你要么聪明，要么会瞎猜，或者有人教你。既然如此，
你有什么心愿老汉一定替你完成。 \n"NOR);   		
		   	me->delete_temp("marks/wangshijiang");
    		me->set_temp("marks/王石匠",1);
    		return 1;
		}
		
}		


int tell_him()
{
    	object me;
    	me = this_player();
    	if(me->query_temp("marks/王石匠")) 
        	message_vision("$N对$n道：我虽然年老眼花，但你是我恩人的朋友，"
                       "拿来给我看看吧！\n",this_object(),me);
    	else
        	message_vision("$N对$n道：我已经年老眼花，不能帮你做这么细的活了！\n",
                       this_object(),me);
    	return 1;
}



int accept_object(object me, object obj)
{
    if(me->query_temp("marks/王石匠") && obj->query("id") == "round jade" &&
        obj->query("need_fix") && !obj->query("fixed"))
    {
        obj->set("fixed",1);
		obj->set("long","一个用缅玉琢磨成的玉弧，大约有八寸宽，三分之一园。
两端有一凸一凹的两个槽。\n");
		message_vision("$N将$n接过去，将$n的两端刻出一凸一凹的两个槽。\n",
                       this_object(),obj);
		notify_fail(name()+"拍了拍身上的尘土，将缅玉弧给还了你。\n");
    }

    return 0;
}

void reset(){
    	set("vendor_goods", ([
        	__DIR__"obj/stone1":60,
        	__DIR__"obj/stone2":70,
        	__DIR__"obj/stone3":80,
        	__DIR__"obj/stone4":90,
        ]) );	
	
}