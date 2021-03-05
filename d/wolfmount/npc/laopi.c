#include <ansi.h>
inherit NPC;
void checking();

void create()
{
        set_name("老皮", ({ "laopi" }) );
        set("title", "赖皮匠" );
        set("long",
                "高大威武、相貌堂堂，但就是喜欢赖皮，脸皮比城墙还厚。。\n"
                );

        set("attitude", "peaceful");
        set("age", 35);

	set("no_arrest",1);
        set("combat_exp", 50000);

        set("chat_chance", 1);
        set("chat_msg", ({
                (: checking :),
        }) );

        set_skill("unarmed", 20);
        set_skill("parry", 20);
        set_skill("dodge", 30);

        setup();
        carry_object("/obj/armor/cloth")->wear();
}

void init()
{
	::init();
	add_action("do_whisper","whisper");
}

void checking()
{
        object laopi,sunwaiter;
	laopi = this_object();

        if (sunwaiter = present("sun legate",environment()))
	{
		message_vision("$N虔诚地跪在地上，舔着$n赤着的双足。\n",laopi,sunwaiter);
	}
	else
        {
        	message_vision("$N突然咧着嘴巴呵呵的傻笑起来，一条口水顺着嘴角流下...\n",laopi);
	}        
}

int do_whisper(string arg)
{
	object me,laopi;
	string dest, msg;
	me = this_player();
	laopi=this_object();

	if( !arg || sscanf(arg, "%s %s", dest, msg)!=2 )
		return notify_fail("你要对谁耳语些什麽？\n");
	if (dest != "laopi") return 0;
	
	if (me->is_fighting())	
	{
		tell_object(me,"打架时还有空闲说话？\n");
		return 1;
	}
	if (msg == "小马" || msg == "xiaoma")
	{
		message_vision("$N痴痴迷迷，不知如何回答$n。\n",laopi,me);
		me->set_temp("marks/wolf_asked_laopi",1);
		return 1;
	}
	else if ((msg == "朋友" || msg == "friend" || msg == "小马的朋友")&& me->query_temp("marks/wolf_asked_laopi"))
	{
		message_vision("$N向$n眨眨眼，继续舔太阳使者的脚。\n",laopi,me);
		me->delete_temp("marks/wolf_asked_laopi");
		me->set_temp("marks/wolf_laopi_friend",1);
		return 1;
	}
	else
		return 0;
}
