#include <ansi.h>
inherit NPC;

void create()
{
        set_name("王夫人", ({ "ms wang","wang" }) );
        set("gender", "女性" );
        set("title", "云梦仙子" );
        set("long",
		"一个华韶虽过，风韵犹存的半老徐娘。她星目含春，只是眼角已经有了岁月的痕迹。 \n"
                );
        set("attitude", "peaceful");
	set("chat_chance_combat",50);
	set("chat_msg_combat",({
                      (:perform_action,"dodge.lianhuanbu":),
              })      );
	set("age", 45);
        set("combat_exp", 600000);

        set_temp("apply/armor",50);
        set_temp("apply/attack", 50);
        
        set_skill("unarmed", 150);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        set_skill("move", 300);
        set_skill("nine-moon-steps", 150);
        set_skill("nine-moon-claw", 150);
        map_skill("dodge", "nine-moon-steps");
        map_skill("unarmed", "nine-moon-claw");
                
        setup();
        carry_object(__DIR__"obj/mask")->wear();
	carry_object(__DIR__"obj/jifu")->wear();
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

int greeting(object me)
{
	object ob;
	ob = this_object();
	if( !me || environment(me) != environment() ) return 1;
	if( userp(me) && me->query_temp("marks/jade_to_zhu"))
	{
		message_vision("$N神色一紧，银牙一咬，喝道：什么人，决不能让你发现本仙子的秘密！\n",ob,me);
		ob->kill_ob(me);
		me->kill_ob(ob);
	}
	return 1;
}

void die()
{
	object me;
	object box;
    object room;
	
	if(objectp(me = query_temp("last_damage_from")))
	{
		if (objectp(me->query("possessed")))
			me = me->query("possessed");
			
		if (me->query_temp("marks/jade_to_zhu"))
		{
			command("say 本仙子绝世妙计，竟然毁在你的手里，我不甘心啊！！\n");
			me->set_temp("marks/knight_kill_wang",1);
			me->delete_temp("marks/jade_to_zhu");
			box = new(__DIR__"obj/box");
			room = find_object("/d/loulan/baihuagong");
			if(!objectp(room)) 
				room = load_object("/d/loulan/baihuagong");
			box->move(room);
		}
		else
		{
			command("say 本仙子自诩武功，智慧独步武林，竟然败在你的手里，我不甘心啊！！\n");
		}
	        ::die();
	}
}
