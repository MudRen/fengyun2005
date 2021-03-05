// yangfan.c

//inherit F_LEADER;
inherit NPC;


#include <ansi.h>
void create()
{
	set_name("杨凡", ({ "yang fan", "yang"}) );
	set("gender", "男性" );
	set("age", 28);
	set("title","山流 少主");
        set("nickname",HIY"大头"NOR);
	set("long",
"这是个矮矮胖胖的年轻人，圆圆的脸，一双眼睛却又细又长，嘴很大，头更大，看起来
有点象猪八戒。但他的神情却很从容镇定，甚至可以说很有点潇洒的样子。\n");
        set("chat_chance", 1);
        set("chat_msg", ({
            "杨凡眨了眨眼，乐呵呵哼着小调：大头大头，下雨不愁，别人有伞，我有大头。\n",
    }) );
        set("inquiry",  ([
                "山流" : "山流只是一群很平凡的人，但却是为了一个不平凡的理想而存在。\n",
                "shanliu" : "山流只是一群很平凡的人，但却是为了一个不平凡的理想而存在。\n",
                "血雨檄": "血雨檄中人皆称霸一方的黑道巨枭，不可小视。\n",
                "questnpc": "血雨檄中人皆称霸一方的黑道巨枭，不可小视。\n",
                ])                      );

	set("combat_exp", 80000000);
	set("attitude", "friendly");
	set("per",1);
	set("str", 100);
	set("force",50000);
	set("max_force",50000);
	set("force_factor",500);
	set("org_ranks",({
"义士","义侠","光明使者","平凡的人" }));

	set_skill("dodge",300);
        set_skill("unarmed",200);
        set_skill("parry", 200);
        set_skill("changquan", 200);
        set_skill("fall-steps", 200);
        map_skill("unarmed", "changquan");
        map_skill("dodge", "fall-steps");
	setup();
        carry_object("obj/armor/cloth")->wear();
	create_organization("山流",1,"正");
}


void init()
{
	object ob;
	::init();
	if( userp(ob = this_player()))
	if(ob->query_temp("山流/舍身崖"))
	{
		remove_call_out("greeting");
                call_out("greeting", 30, ob);
        }
	add_action("do_kill","kill");
	add_action("do_answer","answer");
}

void greeting(object me)
{
	if(!me ||environment(me)!=environment())
		return ;
	if(!living(me))
		me->revive();
	message_vision(CYN"$N眯着那双又长又细的眼睛，对$n笑了笑说：仁兄果然是同道中人。\n"NOR,this_object(),me);
	message_vision(CYN"$N突然神色肃然，郑重地对$n说：好，如果你愿入山流，自然欢迎加入『山流』！\n（join yang fan）。\n"NOR,this_object(),me);
	return ;
}


void accept_member(object me)
{
	command("smile");
	command("enroll "+me->query("id"));
        message_vision(HIC"$N凝神片刻又肃然道：近日青龙会与天宗勾结，妄图号令天下黑道，但凡黑道枭雄
无不收到其『青龙令』，阁下务请将『血雨檄』（questnpc）中各方枭雄的青龙令夺之交
与秦歌兄，事关江湖正道兴衰，阁下务须小心行事！\n"NOR,this_object(),me);
	me->delete("入山流");
	me->delete_temp("山流");
}

void attempt_join(object me)
{
	if(me->query_temp("山流/舍身崖"))
		accept_member(me);
	else
		message_vision("杨凡细眉一皱，嘟囔道；奇怪，你从哪里冒出来的。\n",this_object());
}


int do_kill(string arg)
{
	object me;

	me=this_player();
	if(!arg) return 0;
	if(this_object()==present(arg,environment()))
		me->set("山流/失败",time());
	return 0;
}

/*
int do_answer(string arg)
{
	
	for (i=0;i<=10 ; i++)
	{
		say(string(i)+"\n");
		if ((string)i == arg)
			break
	}
}
*/