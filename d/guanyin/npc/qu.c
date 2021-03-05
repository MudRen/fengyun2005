#include <ansi.h>
inherit NPC;
int direct();
int event1();
int event2();

void create()
{
        set_name("曲无容", ({ "wurong" }) );
        set("title",WHT"国色天香"NOR);
        set("gender", "女性" );
        set("age", 22);
		set("long","
体态如此轻盈，风姿如此绰约，可惜她的全身都是裹在一袭黑袍之内，
也不知道下面是如何一张"YEL"国色天香"NOR"的容貌。\n");
	
		set("combat_exp", 1800000);
        
        set("chat_chance", 1);
        set("chat_msg", ({
        	"曲无容冷冷道：“你要想出去，除非被抬出去。”\n",
        }) );
        
        set("inquiry", ([
                "石观音" : 	(: direct :),
                "shi guanyin" : (: direct :),
				"master guanyin": (:direct :),
				"master shi": 	(:direct :),
				"国色天香":	(: event1 :),
				"容貌":		(: event1 :),
				"丑":		"action曲无容冷冷地说：知道了，你可以滚了。\b",
				"不丑":		(: event2 :),
				"你很美":	(: event2 :),
				"你不丑":	(: event2 :),
        ]));

    	set("chat_chance_combat", 30);
    	set("chat_msg_combat", ({
        	(: perform_action, "unarmed.yaozhan" :),
        }) );

    	set_skill("unarmed", 150);
    	set_skill("force", 100);
    	set_skill("parry", 150);
    	set_skill("dodge", 150);
    	set_skill("kongshoudao", 150);
    	set_skill("ghosty-force", 150);
    	set_skill("ghosty-steps", 150);

    	map_skill("unarmed", "kongshoudao");
    	map_skill("blade", "wind-blade");
    	map_skill("force", "ghosty-force");
    	map_skill("dodge", "ghosty-steps");

        
        setup();
        carry_object(__DIR__"obj/bcloth")->wear();

}


int direct(){
	
	object me, ob;
	object room;
	me = this_player();
	ob = this_object();
	
	message_vision(CYN"$N对$n冷笑一声：你想见我师父？\n"NOR,ob, me);
	if ( !REWARD_D->check_m_success(me,"极乐之星")
		&& !me->query_temp("zangbei/龟兹_龟兹送宝",1) 
		&& REWARD_D->riddle_check( me,"浪人的悲哀")!=3) {
		message_vision(CYN"哪有这么容易的事儿，我劝你还是不要去送死了吧。\n"NOR,ob);
		return 1;
	}

	message_vision(CYN"那我就成全你！！\n",ob);
	room = load_object(AREA_GUANYIN"mirror");
	message_vision(YEL"$N脚下一松，整个人不见了！\n"NOR,me);
	me->move(room);	
    return 1;
}


int event1(){
	tell_object(this_player(),CYN"
曲无容厉声狂笑道：“天香国色……好，我就让你瞧瞧我的天香国色。”

她的手掀起蒙面丝巾，你的笑容立刻就凝结住。

这那里是人的脸，这简直是魔鬼的容貌。

你再也想不到这体态如此轻盈，风姿如此绰约的少女，一张脸竟是如此狰狞，

如此可怕。

只听她厉声笑道：“现在你瞧见了麽？你的眼福可真不浅，以後你也一定要记

住，曲无容乃是世上最"YEL"丑"CYN"的女人，再没有别人比得上。”\n\n"NOR);
	this_player()->set_temp("guanyin/qu_beauty",1);
	return 1;
}


void init()
{
	::init();
	add_action("do_whisper","answer");
}

int do_whisper(string msg)
{
	object me,qu;
//	string dest;
	me = this_player();
	qu=this_object();

	if (msg == "丑") {
		tell_object(me,"曲无容冷冷地说：知道了，你可以滚了。\n");
		return 1;
	}
		

	if (msg == "你不丑，你很美" || msg == "你不丑你很美" || msg == "你不丑" || msg =="你很美"
		|| msg == "不丑" )
	{
		if (!me->query_temp("guanyin/qu_beauty")) {
			message_vision(CYN"曲无容厉声叱道：“下去，下去，这里不是你多话的地方。”\n"NOR,me);
			return 1;
		}
		
		message_vision(CYN"
曲无容身子竟似微微一震，道：“你……你说什麽？”\n"NOR,qu);
		tell_object(me,CYN"
曲无容出神地瞧着你，深邃冷漠如井水般的眼波，竟似已被投入了一粒石子，
而生出了片片涟漪。\n"NOR);
		if (me->query_condition("no_force")) {
			tell_object(me,HIG"\n曲无容衣袖微展，一股清新的花香迎面扑来。。。\n"NOR);
			me->change_condition_duration("no_force",0);
		}
	}
	else
		message_vision(CYN"曲无容厉声叱道：“下去，下去，这里不是你多话的地方。”\n"NOR,me);
		return 1;
}

int event2(){
	object me,qu;
//	string dest;
	me = this_player();
	qu=this_object();

	if (!me->query_temp("guanyin/qu_beauty")){
		message_vision("$N眼望群山，似乎没有听到$n的说话。\n", qu, me);
		return 1;
	}
			
		message_vision(CYN"
曲无容身子竟似微微一震，道：“你……你说什麽？”\n"NOR,qu);
		tell_object(me,CYN"
曲无容出神地瞧着你，深邃冷漠如井水般的眼波，竟似已被投入了一粒石子，
而生出了片片涟漪。\n"NOR);
		if (me->query_condition("no_force")) {
			tell_object(me,HIG"\n曲无容衣袖微展，一股清新的花香迎面扑来。。。\n"NOR);
			me->change_condition_duration("no_force",0);
		}
	return 1;
}	
