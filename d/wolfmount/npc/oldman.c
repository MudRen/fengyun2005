inherit NPC;
#include <ansi.h>
#define MONEY_VALUE 3000
#define GUEST_MONEY_VALUE 30000

void create()
{
	set_name("跛足老人", ({ "lame oldman", "oldman"}) );
	set("gender", "男性" );
	set("age", 54);
	set("reward_npc", 1);
	set("difficulty", 3);
	set("per", 35);
	set("attitude","friendly");

	set("long","一个白发苍苍的跛足老人，不停地咳着，似乎都要咳出血来。。\n");
	set("combat_exp", 3000000);
	set_skill("move", 120);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("unarmed",300);
	set("inquiry", ([
        	"夜狼王": "夜狼王是狼山上最最神秘的人物....嗯...没有人知\n道他在哪里。\n",
        	"朱五太爷": "朱五太爷是狼山上真正的主宰，各种各样的狼都要听\n命于他。\n",
	]) );
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{	
	object me;
	::init();
	me = this_player();
	if( interactive(me) && !is_fighting() && !me->query("marks/wolf_pass_oldman") )
	{
		remove_call_out("greeting");
		call_out("greeting", 0, me);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() )
		return;
   
	if (ob->query("class") != "wolfmount")
	{
        	message_vision(HIW"$N并不抬头，冷冷道：＂没有礼物，就爬回去！＂\n"NOR,this_object());
		return;
	}
	else
	{
        	message_vision("$N笑道：＂乖孙儿，最近又有什么好货孝敬爷爷？＂\n",this_object());
		return;
	}
	return;
}

int accept_object(object me, object obj)
{	
       	object npc;
       	npc = this_object();
       	if (me->query("class") != "wolfmount")
       	{
		if( (int) obj->query("value") >= GUEST_MONEY_VALUE || (int) obj->value() >= GUEST_MONEY_VALUE )
        	{
        		message_vision(YEL"$N突然笑了，一双衰老疲倦的眼睛里也充满笑容．\n"NOR,npc);
        		message_vision(YEL"$N拍了拍$n，笑着说：走进去，看到一扇大门，敲三下，就推门进去．\n"NOR,npc,me);
        		me->set("marks/wolf_pass_oldman",1);
        		return 1;       
        	}
		else
		{
        		tell_object(me,"跛足老人一脸的不屑：＂这是什么东西，老夫不需要！\n");
			return 0;
		}
	}
       	else
       	{
       		if( (int) obj->query("value") >= MONEY_VALUE || (int) obj->value() >= MONEY_VALUE )
        	{
        		command("say 好！好！你很孝顺！我很欣赏你！\n");
        		command("whisper "+me->query("id")+" 一直走，看到一扇大门，敲三下，就\n推门进去．\n");
        		me->set("marks/wolf_pass_oldman",1);
        		return 1;       
        	}
		else
		{
        		tell_object(me,"跛足老人一脸的不屑：＂这是什么东西，老夫不需要！\n");
			return 0;
		}
	}
	return 1;
}