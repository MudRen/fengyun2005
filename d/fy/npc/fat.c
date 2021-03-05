#include <ansi.h>
#define MONEY_VALUE 1000
inherit NPC;

void create()
{
	set_name("小胖子", ({ "little fatman","fatman" }) );
	set("gender", "男性" );
	set("title", HIG"花街大少"NOR);
	set("age", 26);
	set("long",
		"这个家伙长得还算是眉清目秀，但是看上去总给人一种坏坏的感觉。．．\n");
	set("combat_exp", 5000);
	set("attitude", "friendly");
    	set("chat_chance", 1);
	set("chat_msg", ({
                "小胖子不屑道：奶奶个熊～～老子当年行走江湖，花街大少的名头那个不知，\n谁人不晓～～\n",
                "小胖子神秘的道：哥们，知道老子是谁吗？说出来吓死你，老子就是人间活宝，\n人见人爱的胖胖～的～豆～～腐～～天～～使～～！～～\n",
                "小胖子突然从身后拿出一个鸟笼，对着鸟笼里的小鸟道：亲爱的小弟弟，就你\n给我的快乐最多！\n",
                "小胖子叹了口气，悲伤的说道：最近窑子逛多了，手头周转不灵，看来得把鸟\n笼卖了才成。！\n",
        }) );
	set("chat_msg_combat", ({
        	"小胖子高叫道：奶奶个熊～～～跟老子打架，看老子教训教训你～～\n",
	}) );

    set_skill("move", 100);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("force", 200);
    set_skill("unarmed", 20);
	set_skill("wuzheng-force",220);
        set_skill("literate", 200);
        set_skill("meng-steps",220);
	map_skill("force", "wuzheng-force");
        map_skill("dodge","meng-steps");
        map_skill("move","meng-steps"); 
	setup();
    carry_object("/d/fugui/npc/obj/m_cloth2")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) 
        {
                case 0:
			message_vision("$N斜看了$n一眼道：想知道江湖大事吗？问我吧，今天心情好。\n",this_object(),ob);
                        break;
                case 1:
			message_vision("$N向$n问道：知道最近谁PK最凶吗？给我点钱，我告诉你！\n",this_object(),ob);
                        break;
                case 3:
			message_vision("$N贼兮兮的对$n说道：千金楼的姑娘又涨价了，要不要我给你指条明路？\n",this_object(),ob);
                        break;
                case 4:
			message_vision("$N摇摇头，无辜的说道：我干活，你享乐，还来骂我。大爷，给点同情心\n好不好？\n",this_object());
                        break;
                case 5:
			message_vision("$N偷偷笑着说道：昨天晚上我表现不错，今天土娼邀请我吃饭。\n",this_object(),ob);
                        break;
                case 6:
			message_vision("$N悄悄向$n说道：风云城里最好的大夫知道是谁吗？是普生，他两下就治\n好了我的难言之隐。\n",this_object(),ob);
                        break;
                case 7:
			if(ob->query("gender") == "女性")
			{
				command("lure");
				command("say 这位" + RANK_D->query_respect(ob)+ "，最近有没有空啊？午夜时分是不是感到寂寞呀？让我安慰安慰你\n那需要滋润的心吧！\n");
			}
			else
			{
				command("heihei");
				command("say 哥们，有没有漂漂妹妹介绍啊？有的话，老子给你点奖励。\n");
                        }
                        break;
                case 8:
			message_vision("$N拍了拍$n的肩膀，说道：最近，济南城新加了不少有趣的东东，咱们俩一\n起去看看如何？\n",this_object(),ob);
                        break;
                case 9:
			message_vision("$N委屈的向$n说道：什么世道，以前老子杀别人，现在被别人杀，心里憋糗啊。\n",this_object(),ob);
                        break;
        }
}

int accept_object(object me, object obj)
{	
	object birdcase;
	
        if( (int) obj->value() >= (MONEY_VALUE+ random(MONEY_VALUE)) )
        {
        	if (me->query("gender") == "女性")
        	{
        		command("qsister "+me->query("id"));
        		message_vision("$N嬉皮笑脸的说：妹妹贵姓？\n",this_object());
        	       	message_vision("$N从鸟笼中拿出小鸟，然后把空的鸟笼递给$n。\n",this_object(),me);
        	}
		else
		{
			command("kick "+me->query("id"));
        	       	message_vision("$N恨恨的说：要不是缺钱逛窑子，老子才不卖呢。\n",this_object());
        	       	message_vision("$N从鸟笼中拿出小鸟，然后把空的鸟笼递给$n。\n",this_object(),me);
        	}
        	birdcase = new(__DIR__"obj/birdcase");
        	if(birdcase)
        	birdcase->move(me);
        	return 1;       
        }
	else
	{
		command("heihei");
        	command("say 多谢这位" + RANK_D->query_respect(me) +"，下次请你喝酒！");
        	return 1;
        }
	return 0;
}
