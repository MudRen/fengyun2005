// keeper.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("塔祝", ({ "keeper" }) );
        set("gender", "男性" );
        set("age", 74);
        set("long","
这个老人看起来七十多岁了，他的一生中不知道经过了多少风风雨雨，他已经
看惯了死亡，看穿了世情，望着他佝偻的身影，你忽然觉得心情沉重了下来。\n");
        set("combat_exp", 3000);
        set("attitude", "friendly");
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
}

void greeting(object ob)
{
        object book;
        if( !ob || !present(ob, environment(this_object())) ) return;
        if (REWARD_D->riddle_check(ob,"新手入门")==3)	{
		message_vision(CYN"$N一拱手说：“老爷子请了，天机老人问老伯好！”\n"NOR,ob);
		message_vision(CYN"
塔祝呵呵一笑说：“好久没见到天机老哥了，他的徒子徒孙倒常到我这儿
喝茶，也代老汉向他问好！难为你长途跋涉，这本书也许你用得着。既然
到了大昭寺就到处看看，如果想回风云城，可搭乘迎梅客栈的马车”\n"NOR,this_object());
		tell_object(ob,CYN"塔祝塞给你一本小册子（新手指南）。\n"NOR);
		tell_object(ob,CYN"
塔祝悄悄地对你说：再告诉你一个诀窍，回风云前，最好先到这儿的石场
工作捞点"WHT"银子"CYN"，天机这个老财迷说不定会叫你替他买东西呢。\n"NOR);

		tell_object(ob,WHT"\n你完成了天机老人的使命，你的咒术/法术提高了！！！\n"NOR);
		book = new("/obj/item/newbie_book1");
		if (!book->move(ob))
			book->move(environment(ob));
		if (ob->query_skill("magic",1)<10)  ob->set_skill("magic",10);
		if (ob->query_skill("spells",1)<10)  ob->set_skill("spells",10);
		ob->delete_temp("marks/newbie_quest");
		ob->set_temp("marks/guanwai_mache",1);
		REWARD_D->riddle_set(ob,"新手入门",4);
		return;
	}
        
        say( "塔祝说道：这位" + RANK_D->query_respect(ob)
                + "，捐点香火钱积点阴德吧。\n");
}

int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val )
                return notify_fail("这东西不值什么钱。\n");
        else if( val > 100 ) 
        {
                if( (who->query("bellicosity") > 0)&&(random(val/10) > (int)who->query("kar")) )
                        who->add("bellicosity", -(random((int)who->query("kar")) + val/1000) );
        }
        say( "塔祝说道：多谢这位" + RANK_D->query_respect(who)
                + "，佛祖一定会保佑你的。\n");

        return 1;
}