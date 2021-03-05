#include <ansi.h>
#include <command.h>
inherit NPC;

void create()
{
	set_name("柳三郎", ({"liu sanlang","sanlang"}) );
        set("gender", "男性" );
        set("nickname", HIM"色狼"NOR);
        set("long", "这是一个落魄随意的长发青年，眼睛里散发着种奇异的欲望。\n");
	 	set("attitude", "friendly");
		set("age", 18+random(10));

        set("combat_exp", random(600000)+200000);
        create_family("狼山", 4, "弟子");
        set_skill("blade", 50+random(20));
        set_skill("parry", 50+random(20));
        set_skill("dodge", 50+random(20));
        set_skill("move", 50+random(20));
        set("chat_chance", 1);
        set("chat_msg", ({
        	"柳三郎温柔地说道：只要是女人，碰到我就会欲仙欲死，小姐愿意与我共赴巫山么？\n",
        }) );
        setup();
        carry_object(__DIR__"obj/silk_cloth")->wear();
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
}

void greeting(object ob)
{
	object *inv;
	int i;
	if (!ob || environment(ob)!=environment(this_object()))	return;
	if ((string)ob->query("gender") == "女性")
	{
        message_vision(MAG"$N色迷迷盯着$n，抚摩着$n的酥胸，呓语般道：美人儿，
睡吧，睡吧，你会享受到人间极乐的感觉。\n"NOR, this_object(),ob );
        if ((int)ob->query_cps()<random(15)&& !ob->query_temp("sleeped") ){
   			message_vision("$N不禁神智模糊，糊里糊涂倒了下去，鼾声大作睡了起来。\n", ob);
   			tell_object(ob, "很快你就进入了梦乡。\n");
			ob->set_temp("sleeped",1);
			ob->set_temp("disable_inputs",1);
			ob->add_temp("block_msg/all",1);
			ob->set_temp("is_unconcious",1);
			ob->set("disable_type",HIG "<睡梦中>"NOR);

			inv = all_inventory(ob);
			if(sizeof(inv)) {
				for(i=0; i<sizeof(inv); i++) {
					inv -= ({ 0 });
					if(sizeof(inv)) {
						if(inv[i]->query("equipped")) {
							inv[i]->unequip();
						}
					}
				}
			}
	  		call_out("wake", 8, ob);
	  		return;
	  	}
	  	else
	  	{
	  		message_vision("$N转过脸去，红着脸啐了一口：好不要脸！\n", ob);
	  		return;
	  	}
	  }
	  return;
}

void wake(object ob)
{
	if (!ob)	return;
	ob->delete_temp("disable_inputs");
	ob->delete("disable_type");
	if (ob->query_temp("block_msg/all")>=1)
	    ob->add_temp("block_msg/all", -1);
	ob->delete_temp("is_unconcious");
	if(!ob->is_ghost())
	{
		message_vision(CYN"$N睁开了眼睛，觉得身上凉嗖嗖的，伸手一摸，不禁大声尖叫起来。\n", ob); 
   		message_vision("$N正自惊吓，扭头一看，柳三郎呲牙咧嘴捂着要害，苦着脸对柳幺妹悲泣道：
我说幺妹啊，你平时那个俏哥这个乖弟，我说什么了么？偏生我就难得出墙一次，
还没真干，你。。竟然把我活生生废了!呜~~呜~~\n"NOR,ob);  
		return;
	}
	return;
}
