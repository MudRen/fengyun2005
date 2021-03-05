#include <ansi.h>
inherit NPC;
void create()
{
        set_name("苗烧天", ({ "miao shaotian", "miao" }) );
        set("long",
                "这人狮鼻阔口，满头赤发，耳中却戴着三枚金环。\n");
    	set("nickname", HIR"赤发帮 总瓢把子"NOR);
    	set("chat_chance",1);
	set("chat_msg",	({
			"苗烧天抖动着金环，夜枭般狂笑道：“你们这帮兔崽子，待会儿大爷\n我抢到那［孔雀图］，再把你们一个个....哈哈....哈哈!!”\n",
			})  );
        set("inquiry",([
 		"孔雀图"  :"“孔雀图吗，俺老苗是志在必得。”\n",
              ]) );
        set("combat_exp", 800000);
	
	set_skill("unarmed",150);
	set_skill("blade",150);
	set_skill("lianxin-blade",150);
	set_skill("tigerstrike",200);
	set_skill("dodge",100);
	set_skill("puti-steps",150);
	set_skill("parry",150);
	
	map_skill("parry","lianxin-blade");
	map_skill("dodge","puti-steps");
	map_skill("move","puti-steps");
	map_skill("unarmed","tigerstrike");
	map_skill("blade","lianxin-blade");
	
	setup();
        carry_object(__DIR__"obj/miaocloth")->wear();
	carry_object(__DIR__"obj/miaoblade")->wield();
}

int accept_object(object me, object obj)
{                                                                 
	if( (string) obj->query("name") == "孔雀图")
	{
		command("smile");
		message_vision(HIY"$N偷偷塞给$n一幅孔雀图。\n"NOR,me,this_object());
		message_vision(HIY"$N一楞,仔细看了看，不由哈哈大笑起来。\n"NOR,this_object());
		me->set_temp("marks/longlife_peacockmap",1);
		call_out("fighting",2,me);
		return 1;
	}
	else
 	{
		message_vision("$N说道：想贿赂俺老苗？东西照收，万事免谈！\n",this_object());
		return 1;
	}
 	  return 1;
}


int fighting(object me)
{
	object zhang,zhao;
	if (present(me,environment(this_object())))
	{
		if (zhang=present("zhang san",environment(this_object())))
		{
			zhang->kill_ob(this_object());
			message_vision("$N说道：谁想独吞孔雀图，我就要他的命！！\n",zhang);
			this_object()->kill_ob(zhang);
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