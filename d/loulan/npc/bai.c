#include <ansi.h>
inherit SMART_NPC;

void create()
{
        set_name("白飞飞", ({ "bai feifei","bai" }) );
        set("gender", "女性" );
        set("title", "幽灵宫主" );
        set("nickname", HIB"红尘有尽恨无常"NOR );
        set("long","
一个秀发如云，披散双肩的白衣少女。楚楚动人之态扣人心弦。白玉般的
身子如晶莹美玉，双腿圆润修长，柔软温暖的胸膛微微起伏着。。。 \n"
                );
		set("class","shenshui");
        set("attitude", "peaceful");
	
		set("perform_busy_d", "shenshui/dodge/nine-moon-steps/lianhuanbu");
	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
        
		set("age", 25);
        set("combat_exp", 600000);
        
        set("chat_chance", 1);
        set("chat_msg", ({
		"白飞飞伏在沈浪胸膛上，阖起眼帘悠悠道：我一心想瞧瞧，我们生下来的\n孩子，是怎么样的一个人，我真是想得要发疯，想得要死。。。\n",
		"白飞飞支着腮，吃吃笑道：天下最正直、最侠义、智慧最高的男人，和天下最邪\n恶、最毒辣、智慧也最高的女人，他们生下来的孩子，又会是怎样一个人？ \n",
        }) );

        set_skill("unarmed", 150);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("move", 200);
        set_skill("nine-moon-steps", 150);
        set_skill("nine-moon-claw", 150);
        map_skill("dodge", "nine-moon-steps");
        map_skill("unarmed", "nine-moon-claw");
        map_skill("move","nine-moon-claw");
        
        setup();
        carry_object(__DIR__"obj/baisha")->wear();        
        
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
	object *inv;
	int i;
	int j;
	object ob;
	j = 0;
	ob = this_object();
	if( !me || environment(me) != environment() ) return 1;
	if( userp(me) && me->query_temp("marks/chai_get_command"))
	{
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{
			if(inv[i]->query("item_owner")=="方心骑" && (int)inv[i]->query("equipped"))
			{
				message_vision("$N扭过脸看着$n，哼声道：我知道了，这就去。\n",this_object(),me);
				call_out("leave",10,me);
				j = 1;
			}
		}
		if ( j==1 )
		{
			message_vision("$N咯咯笑道：你，你想看？坏蛋．．．\n",ob);
		}
	}
	return 1;
}

void leave(object me)
{
	object ob;
	if (living(this_object()) && environment(me) == environment())
	{
		if (ob=present("shen lang", environment(this_object())))
		{
			message_vision("$N柔声对$n说：我先离开会，你若再有需要，可别不敢说啊。\n",this_object(),ob);
			message_vision("$N嫣然一笑，披上长裙，咯咯笑着离开．．． \n",this_object());
			me->set_temp("marks/chai_notify_bai",1);
			me->delete_temp("marks/chai_get_command",1);
			destruct(this_object());
		}
		else
		{
			message_vision("$N披上长裙，咯咯笑着离开．．． \n",this_object());
			destruct(this_object());
		}
	}
	else
		remove_call_out("leave");
}