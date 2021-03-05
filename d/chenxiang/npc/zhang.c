#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("张三", ({ "zhang san", "zhang" }) );
        set("long",
                "一身雪白的急装劲束，特地将衣襟敞开，露出坚实强壮的胸膛，却比\n衣裳更白。\n");
    	set("nickname", HIW"白马"NOR);
    	set("chat_chance",1);
		set("chat_msg",	({
			"张三露出贪婪的目光，嘿嘿一笑。\n",
			})  );
        set("inquiry",([
        		"孔雀图"  :"要活命的话，还是不要瞎打听的好。\n",
              ]) );
        set("combat_exp", 800000);

		set_skill("unarmed",150);
		set_skill("dodge",150);
		set_skill("demon-steps",100);
		set_skill("tigerstrike",200);
		set_skill("parry",150);
	
		map_skill("unarmed","tigerstrike");
		map_skill("dodge","demon-steps");
	
		set("perform_busy_d", "demon/dodge/demon-steps/lianhuanbabu");
	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );

		setup();
        carry_object("/d/chenxiang/npc/obj/whitecloth")->wear();
}

int accept_object(object me, object obj)
{                                                                 
	if( (string) obj->query("name") == "孔雀图")
	{
		message_vision(HIY"$N偷偷塞给$n一幅孔雀图。\n",me,this_object());
		message_vision(HIY"$N看了看，突然兴奋的哈哈大笑起来。\n",this_object());
		me->set_temp("marks/longlife_peacockmap",1);
		call_out("fighting",2,me);
		return 1;
	}
	else
 	{
		message_vision("$N说道：东西小的照收，让我放弃孔雀图，没门！\n",this_object());
		return 1;
	}
 	  return 1;
}


int fighting(object me)
{
	object miao,zhao;
	if (present(me,environment(this_object())))
	{
		if (miao=present("miao shaotian",environment(this_object())))
		{
			miao->kill_ob(this_object());
			message_vision("$N说道：小兔崽子，交出孔雀图，我就饶了你！！\n",miao);
			this_object()->kill_ob(miao);
		}
		if (zhao=present("zhao yidao",environment(this_object())))
		{
			zhao->kill_ob(this_object());
			message_vision("$N说道：我是认图不认人，老爹老妈也照杀！！\n",zhao);
			this_object()->kill_ob(zhao);
		}
		return 1;
	}
	else
	{
		return 0;
	}
}
