inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
#define MONEY_VALUE 10000

void create()
{
        set_name("奎元馆伙计", ({ "huoji" }) );
        set("long","一个忙忙碌碌的奎元馆伙计，豆大的汗珠沿着他的脸颊直流下来。\n");
        set("attitude", "peaceful");
        set("agi", 60);

        set("combat_exp", 12000);
        set("inquiry", ([
                "酒" : "！我这的竹叶青，女儿红可是难得一觅的上佳美酒啊。\n",
                "好酒" : "客官可是还想要点极品的酒？那得看客官是否出的起钱。\n",
        ]) );
        set("chat_chance", 1);
        set("chat_msg", ({
                "奎元馆伙计笑呵呵道：客官，来壶酒吧？我这的竹叶青可是附近百里
难得一觅的上佳美酒啊。\n",
         }) );

        set_skill("unarmed", 20);
        set_skill("parry", 20);
        set_skill("dodge", 30);
        
        set("vendor_goods", ([
			__DIR__"obj/zhuskin":10,
			__DIR__"obj/shaoskin":10,
                __DIR__"obj/beef":15,
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
                        say( "奎元馆伙计笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来喝杯竹叶青，歇歇腿吧。\n");
                        break;
                case 1:
                        say( "奎元馆伙计用毛巾抹了抹靠门的一张桌子，说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
                case 2:
                        say( "奎元馆伙计说道：这位" + RANK_D->query_respect(ob)
                                + "，进来尝尝新出锅的酱牛肉。哇! 好香啊!...\n");
                        break;
        }
}

int accept_object(object me, object obj){	
		
	object poorpot;
    if( (int) obj->value() >= MONEY_VALUE)
        {
        	command("say 小人这酒可是极品绍兴女儿红，已经珍藏了数十年，
客官喝了就知道什么是好酒啦！\n");
        	poorpot = new(__DIR__"obj/poorpot");
        	if (poorpot)
        	if(!poorpot->move(me))
        		poorpot->move(environment(me));
        	message_vision("$N拿出一个"+HIB "烂瓦罐"NOR+"给$n。\n",this_object(),me);
        	return 1;       
        }
	else
	{
	    command("hehe");
	    message_vision(CYN"$N掂了掂说：就这点，。。"+ RANK_D->query_respect(me) +"还是就买堂上的酒吧！\n",this_object());
		return 0;
	}
}



void reset(){
    set("vendor_goods", ([
		__DIR__"obj/zhuskin":10,
		__DIR__"obj/shaoskin":10,
        __DIR__"obj/beef":15,
	]) );
}
