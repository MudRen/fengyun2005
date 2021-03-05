#include <ansi.h>
inherit NPC;

string quest();

void create()
{
    	set_name("老农", ({ "old farmer", "farmer" }) );
    	set("gender", "男性");
    	set("age", 46);
    	set("long",
        	"一位年近五十的农夫。\n"
		);
		
		set("inquiry", ([
	       	"难事": 	(: quest :),
	       	"难题": 	(: quest :),	
	       	"nanti":	(: quest :),	
	       	"nanshi": (: quest :),
	       	"difficulty": (: quest :),
	       	"job": 	(: quest :),
         ]) );
		
		
		
		set("combat_exp",2000);
		set("NO_KILL","这么老的老头儿，还是饶了他吧。\n");
		set_skill("blade", 10+random(50));
    	setup();
    	carry_object(__DIR__"obj/liandao")->wield();
    	carry_object("/obj/armor/cloth")->wear();
}

int accept_object(object who, object ob)
{
    	object          book1;
    	object 	    book2;
    	if( ob->name() == "饭篮") {
        	say("老农接过饭篮，说道：多谢这位" + RANK_D->query_respect(who) + "，我正饿着呢。\n");
        	if( present("rice", ob) && present("qing cai", ob)) {
            		say("这位" + RANK_D->query_respect(who) +"象是习武之人，这本书可能对您有用，请收下。\n");
            		book2 = new(BOOKS"skills_31");
            		if (!book2->move(who))
            			destruct(book2);
            		if (QUESTS_D->verify_quest(who,"武当送饭")) 
            			QUESTS_D->special_reward(who,"武当送饭");
            		return 1;
        	}
        	else {
            		say("老农打开饭篮看了看，说道：咦？这位" + RANK_D->query_respect(who) + 
                		"开我的玩笑吗？这里没有饭菜呀。\n");
            		return 1;
        	}
    }
    return 0;
} 

/*
	白花蛇	400k
	九尾火貂	450k
	红毛狐狸 350k
	花蝴蝶 200k
	桃花雾妖 500k
	大山兔 300k

	小鹿 	50k
*/

string quest()
{
	string arg, room_name, *files,orig_name;
	int i, n, m, size, reward, exp;
	int x;
	object me = this_player();
	string *list2=({
	"白花蛇",
	"九尾火貂",
	"红毛狐狸",
	"桃花雾妖",
	});
	
	string *list1=({
	"大山兔",
	"花蝴蝶",
	});
	
	if (me->query("quest/short") == "去武当老农处解决难题")
	{
		if (me->query("quest/duration") == 401)	// 除小兽
		{
				i = random(2);
				n=1+random(3);
				me->set("annie_quest/name","桃花林除小兽"+list1[i]);
				me->set("annie_quest/number", n);
				me->set("annie_quest/short", WHT"到桃花林猎杀XXX"+WHT"个"+list1[i]+NOR);
				me->set("annie_quest/target",list1[i]);
				
				me->set("quest/short", WHT"到桃花林猎杀"+ n + WHT"个"+list1[i]+NOR);
				me->set("quest/location", "桃花林");
				me->set("quest/difficulty",n*30);	// 每多一个就多30% reward
				me->set("quest/duration",900+n*60);	// 每多一个就多１分钟
				me->set("quest_time",time());
				arg= "桃花林里的野兽每到晚上就出来糟蹋庄稼，还请前去捕杀几个"+list1[i]+"。\n";
				tell_team(me,HIY+me->name()+HIY"的任务改变了！\n"NOR);
				return arg;
		}

		if (me->query("quest/duration") == 402)	// 除小兽
		{
				i = random(4);
				n=1+random(3);
				if (i==3) x=2;
					else x=1;
				me->set("annie_quest/name","桃花林除野兽"+list2[i]);
				me->set("annie_quest/number", n);
				me->set("annie_quest/short", WHT"到桃花林猎杀XXX"+WHT"个"+list2[i]+NOR);
				me->set("annie_quest/target",list2[i]);
				
				me->set("quest/short", WHT"到桃花林猎杀"+n+ WHT"个"+list2[i]+NOR);
				me->set("quest/location", "桃花林");
				me->set("quest/difficulty",n*50*x);	// 每多一个就多30% reward
				me->set("quest/duration",900+n*240);	// 每多一个就多１分钟
				me->set("quest_time",time());
				arg= "桃花林里的野兽每到晚上就出来糟蹋庄稼，还请前去捕杀几个"+list2[i]+"。\n";
				tell_team(me,HIY+me->name()+HIY"的任务改变了！\n"NOR);
				return arg;
		}

		return "最近好象没什么事情，你不如趁机找巫师泡泡茶吧。\n";	// error mark.
	}
	else
		return "action老农笑着说：我这儿悠闲得很，哪儿有什么难事。";
	
	return " ";
}
