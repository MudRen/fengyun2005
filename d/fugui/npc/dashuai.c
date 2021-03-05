#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIY"金大帅"NOR, ({ "jin dashuai","jin" }) );
        set("long",
                "金大帅虽然已经有五十多岁，站在那里腰杆仍然笔直，眼睛仍然有光，
胡子虽然留得不太长，却很浓、很黑。。\n");

        set("attitude", "peaceful");
		set("age", 50);
        set("combat_exp", 1500000);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "金大帅吐气扬声，手中突然射出连珠神弹十二发，令你眼花缭乱。\n",
        }) );
/*		set("inquiry", ([
            "财叔" : "他可是大有来头的人物啊，嗯！大有来头。",
			"护镖" : "我已经委托财叔帮我找人了，你如果有兴趣可以到他那里打听打听。",
			"caishu" : "他可是大有来头的人物啊，嗯！大有来头。",
			"mission" : "我已经委托财叔帮我找人了，你如果有兴趣可以到他那里打听打听。",
        ]) );*/
        
        set_skill("unarmed", 150);
        set_skill("parry", 150);
        set_skill("dodge", 200);
        set_skill("throwing",200);
		set_skill("meihua-biao",100);
		
		map_skill("parry","meihua-biao");
		map_skill("throwing", "meihua-biao");		
		
		setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/ball")->wield();
}


/*
void init()
{
        ::init();
		add_action("do_accept", "accept");
}

int accept_object(object me, object ob)
{
	object cart,obj;
	if(ob->query("name") == "推荐信" && me->query_temp("marks/推荐") )
	{
		me->set_temp("marks/得到镖银",1);
		me->delete_temp("marks/推荐");
		me->start_busy(2);
		call_out("give_cart",2,me);
		return 1;
	}
	else
	{
	       	tell_object(me,"金大帅说道：这不是我想要的。\n");
        	return 0;  
        }    
}

void give_cart(object me)
{
	object jin,obj,cart,guard1,guard2;
	jin = this_object();
	command("spank " + me->query("id"));
	command("say 好吧，你将镖车送到富贵山庄柴房，自会有人安排。一路小心。");
	message_vision("$N手一招，两个金府家丁从后院推出一辆镖车。\n",jin);

	cart=new(__DIR__"cart");
	cart->move(environment());
	cart->set_owner(me);

	obj=new(SILVER_OB);
	obj->set_amount(4000);
	obj->set("name","金大帅府镖银");
	obj->move(cart);
	
	me->set_temp("dart_area","柴房");
	me->set_temp("dart_id","suanmei tang");
	me->set_temp("dart_name","酸梅汤");
	me->set_temp("protecting",cart);
}*/