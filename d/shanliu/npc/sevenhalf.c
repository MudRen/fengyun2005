// yangfan.c

inherit NPC;

#include <ansi.h>
void create()
{
        set_name("七个半",  ({  "wineseller"  }) );
	set("title","牛肉铺子 老板");
        set("gender", "男性" );
	set("age", 50);
	set("long",
"他是这的老板，因为干什么都只需七个半铜板，所以便被人称做七个半，看上去
是个很奇怪的人，虽然脚有些瘸，头也有些秃，穿着也很粗俗，武功看上去也高
不到哪去，但就是有股叫人想和他大碗喝酒，生死相随的味道。\n");
        set("chat_chance", 1);
        set("chat_msg", ({
            "七个半阴阳怪气地把碗筷一摆，冷声道：客官吃些什么？\n",
    }) );
	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("per",1);
	set("str", 100);
	set("force",5000);
	set("max_force",5000);
	set("force_factor",500);
	set_skill("dodge",300);
        set_skill("unarmed",200);
        set_skill("parry", 200);
        set_skill("changquan", 200);
        set_skill("fall-steps", 200);
        map_skill("unarmed", "changquan");
        map_skill("dodge", "fall-steps");
	setup();
        carry_object("obj/armor/cloth")->wear();

}

int accept_object(object me,object ob)
{
	if(ob->query("id")!="letter" && ob->query("id") != "tanmubox") return 0;
	if (ob->query("送东西人") != me)
	{
		message_vision("$N接过东西，看了看，对$n冷笑道：你从哪里得来的东西。竟敢糊弄我。\n",this_object(),me);
		kill_ob(me);
		return 1;
	}
	if (ob->query("open"))
	{
		message_vision(
HIC"$N撇了$n一眼，冷冷的道：“缘已至此，兄台还是回头是岸吧。”\n"NOR,this_object(),me);
		me->delete_temp("山流/送东西");
		return 1;
	}
	if(ob->query("name")=="给七个半的信")
	{
		if (me->query_temp("givebox"))
		{
			
			message_vision(
HIW"$N拆开信，看了半晌，再上上下下打量了$n一番，咧嘴笑道：“果然是好兄弟，
好吧，再往前走，有个梵音寺，后山有个叫舍身崖的地方，诚心的话，那就跳下去吧，能
不能入得了山流，就看缘分了。\n"NOR,this_object(),me);
			tell_object(me,"掀开铺子后的帘子(open curtain)，再往前走，就看到梵音寺了。\n");
			//me->delete_temp("山流/送东西");
			me->set_temp("山流/七个半",1);
		}else
		{
			me->set_temp("giveletter",1);
			message_vision("$N冷冷看$n一眼，道：还有一样东西呢？\n",this_object(),me);
		}
	}
	if (ob->query("name") == YEL"檀木盒"NOR)
	{
		if (me->query_temp("giveletter"))
		{
			message_vision(
HIW"$N打开盒子，看了半晌，再上上下下打量了$n一番，咧嘴笑道：“果然是好兄弟，
好吧，再往前走，有个梵音寺，后山有个叫舍身崖的地方，诚心的话，那就跳下去吧，能
不能入得了山流，就看缘分了。\n"NOR,this_object(),me);
			tell_object(me,"掀开铺子后的帘子(open curtain)，再往前走，就看到梵音寺了。\n");
			//me->delete_temp("山流/送东西");
			me->set_temp("山流/七个半",1);
		}else
		{
			me->set_temp("givebox",1);
			message_vision("$N冷冷看$n一眼，道：还有一样东西呢？\n",this_object(),me);
		}
	}
	return 1;
}





