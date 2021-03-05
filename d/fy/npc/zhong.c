inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
string quest();
void create()
{
          set_name("钟旒秀", ({ "zhong liuxiu","zhong" }) );
        set("gender", "男性" );
        set("age", 31);
        set("title", CYN"袖里藏香"NOR);
        set("long","这位老板就是风云城中芳姑娘的丈夫，人称袖里藏香的钟旒秀。\n");
        set("combat_exp", 150000);
        set("attitude", "friendly");
        set("per",30);
        set("NO_KILL","钟旒秀说：知府大人是我媳妇二大舅的姥爷，你敢动手？\n");
        set("vendor_goods", ([
                __DIR__"obj/painting1" : 50,
                __DIR__"obj/painting2" : 50,
                __DIR__"obj/painting3" : 50,
                __DIR__"obj/painting4" : 50,
                __DIR__"obj/painting5" : 20,
                __DIR__"obj/painting6" : 20,
        ]) );
        
        set("inquiry", ([
	       	"招人": 	(: quest :),
	       	"工作": 	(: quest :),
	       	"zhaoren": (: quest :),
	       	"job": (: quest :),
         ]) );
        
        set_skill("unarmed",150);
        set_skill("dodge",150);
        set_skill("parry",150);
        setup();
        carry_object(__DIR__"obj/fycloth")->wear();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}


void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        if ( ob->query("gender") == "男性")
        {
                if (!random(4))
                        message_vision("$N看见"+ob->name()+"，迎上来笑道：这位"+RANK_D->query_respect(ob)+"，最新的美人出浴图到了，想看看吗？\n",this_object(),ob);
        }
        else
        {
                if (!random(4))
                        message_vision("$N看见"+ob->name()+"，迎上来笑道：这位"+RANK_D->query_respect(ob)+"，我们派去华山的人送来了最新的楚香帅画像，想看看吗？\n",this_object(),ob);
        }
        return;
}

void reset()
{
        set("vendor_goods", ([
                __DIR__"obj/painting1" : 50,
                __DIR__"obj/painting2" : 50,
                __DIR__"obj/painting3" : 50,
                __DIR__"obj/painting4" : 50,
                __DIR__"obj/painting5" : 20,
                __DIR__"obj/painting6" : 20,
        ]) );
}

string quest()
{
	string arg, room_name, *files,orig_name;
	int i, n, m, size, reward, exp;
	object me = this_player();
	
	if (me->query("quest/short") == "去钟旒秀处打听招人的事儿")
	{
		if (me->query("quest/duration") == 411)	// 除小兽
		{
				n=1+random(3);
				me->set("annie_quest/name","宣武堂暗杀蝎子");
				me->set("annie_quest/number", n);
				me->set("annie_quest/short", WHT"到宣武堂暗杀XXX"+WHT"个蝎子"NOR);
				me->set("annie_quest/target","蝎子");
				
				me->set("quest/short", WHT"到宣武堂暗杀"+ n + WHT"个蝎子"NOR);
				me->set("quest/location", "宣武堂");
				me->set("quest/difficulty",n*30);	// 每多一个就多30% reward
				me->set("quest/duration",900+n*180);	// 每多一个就多１分钟
				me->set("quest_time",time());
				arg= "其实我是山流的人，金钱帮在宣武堂训练蝎子杀手，速去刺杀几个。\n";
				tell_team(me,HIY+me->name()+HIY"的任务改变了！\n"NOR);
				return arg;
		}

		if (me->query("quest/duration") == 412)	// 除小兽
		{
				
				n=1+random(3);
				me->set("annie_quest/name","宣武堂除金衣卫");
				me->set("annie_quest/number", n);
				me->set("annie_quest/short", WHT"到宣武堂暗杀XXX"+WHT"个金衣卫"NOR);
				me->set("annie_quest/target","金衣卫");
				
				me->set("quest/short", WHT"到宣武堂暗杀"+ n + WHT"个金衣卫"NOR);
				me->set("quest/location", "宣武堂");
				me->set("quest/difficulty",n*70);	// 每多一个就多50% reward
				me->set("quest/duration",900+n*180);	// 每多一个就多2分钟
				me->set("quest_time",time());
				arg= "今晚山流攻打金钱宣武堂，请你先去刺杀几个穿金衣的人。\n";
				tell_team(me,HIY+me->name()+HIY"的任务改变了！\n"NOR);
				return arg;
		}
		
		if (me->query("quest/duration") == 431)	// 除小兽
		{
				n=1+random(3);
				me->set("annie_quest/name","金钱地牢之行尸");
				me->set("annie_quest/number", n);
				me->set("annie_quest/short", WHT"到金钱地牢杀死XXX"+WHT"个行尸"NOR);
				me->set("annie_quest/target","行尸");
				
				me->set("quest/short", WHT"到金钱地牢杀死"+ n + WHT"个行尸"NOR);
				me->set("quest/location", "金钱地牢");
				me->set("quest/difficulty",n*50);	// 每多一个就多50% reward
				me->set("quest/duration",900+n*180);	// 每多一个就多2分钟
				me->set("quest_time",time());
				arg= "金钱帮正在炼制药人，请你快去铲除几个行尸。\n";
				tell_team(me,HIY+me->name()+HIY"的任务改变了！\n"NOR);
				return arg;
		}
		
		if (me->query("quest/duration") == 432)	// 除小兽
		{
				n=1+random(3);
				me->set("annie_quest/name","金钱地牢之走肉");
				me->set("annie_quest/number", n);
				me->set("annie_quest/short", WHT"到金钱地牢杀死XXX"+WHT"个走肉"NOR);
				me->set("annie_quest/target","走肉");
				
				me->set("quest/short", WHT"到金钱地牢杀死"+ n + WHT"个走肉"NOR);
				me->set("quest/location", "金钱地牢");
				me->set("quest/difficulty",n*70);	// 每多一个就多50% reward
				me->set("quest/duration",900+n*180);	// 每多一个就多2分钟
				me->set("quest_time",time());
				arg= "金钱帮正在炼制药人，请你快去铲除几个走肉。\n";
				tell_team(me,HIY+me->name()+HIY"的任务改变了！\n"NOR);
				return arg;
		}

		if (me->query("quest/duration") == 433)	// 除小兽
		{
				n=1+random(3);
				me->set("annie_quest/name","金钱地牢之行尸走肉");
				me->set("annie_quest/number", n);
				me->set("annie_quest/short", WHT"到金钱地牢杀死XXX"+WHT"个行尸走肉"NOR);
				me->set("annie_quest/target","行尸走肉");
				
				me->set("quest/short", WHT"到金钱地牢杀死"+ n + WHT"个行尸走肉"NOR);
				me->set("quest/location", "金钱地牢");
				me->set("quest/difficulty",n*100);	// 每多一个就多50% reward
				me->set("quest/duration",900+n*240);	// 每多一个就多2分钟
				me->set("quest_time",time());
				arg= "金钱帮正在炼制药人，请你快去铲除几个行尸走肉。\n";
				tell_team(me,HIY+me->name()+HIY"的任务改变了！\n"NOR);
				return arg;
		}
		return "最近好象没什么事情，你不如趁机找巫师泡泡茶吧。\n";	// error mark.
	}
	else
		return "action钟旒秀笑着说：我这儿悠闲得很，不找人儿。";
	
	return " ";
}
