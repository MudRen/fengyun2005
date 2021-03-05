#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "断崖平台");
        set("long", @LONG
自山崖上攀爬下到这里，喘息良久方定。抬眼回望，只见不知觉中竟爬下了数
十丈高，惊得你冷汗淋漓。举目四顾，却是置身在一个三面皆空的断崖平台上。这
平台倒有十坪方圆，可是半天临空，上既不得，下又不能，当真是死路一条。
LONG
        );
	set("no_fly",1);
	set("no_fight",1);
	set("no_magic",1);
	set("coor/x",-40);
	set("coor/y",200);
	set("coor/z",100);
	set("outdoors", "bashan");
	setup();
}

void init()
{
	if (userp(this_player()))
	{
		add("count",1);
		if (query("count") == 2)
			call_out("attack",10,this_player());
	}
}

int attack(object ob)
{
	if (!ob)
		ob=this_player();
	message_vision(CYN"你正自彷徨无际，却突然听到人声自崖下传来。\n"NOR,ob);
	call_out("do_ggyy",1,ob,ob,0);
	return 1;
}

void do_ggyy(object me,object target,int count)
{
	int i,j;
	object item,env=this_object();
	string msg;
	string *event_msg = ({
"趴在崖边下望，只见光秃秃的十丈石壁之下就是谷底，谷中有十余个人，僧道尼俗\n各色打扮，手里拿着刀枪剑戟，正自团团围着个妙龄少女。凝神看去，那女子\n不正是在武当见过的水如昔？\n\n",
"却听水如昔道：诸位都请回罢，敝教教主此刻实是不在教中。\n",
"西首一个道人哼道：魔教果然好大的架子，连待客之道也不知晓？\n",
"水如昔裣衽一礼，柔声道：教主不在，小女子见识浅薄，多有怠慢，还请担待。\n",
"东面手中提斧的一人冷笑道：笑话，为进到这里我们也不知折了多少人手，费了\n多大力气，你这黄毛丫头三两句话就想打发？\n",
"水如昔微一皱眉，说道：诸位要想怎的，还请明言示下。\n",
"北边的道姑应道：姑娘既守於如此要道，想来必是魔教中一流人物。若是执意不\n肯退让，也就怪不得我们恃众强闯了。\n",
"水如昔轻叹了口气：也罢．．．既是如此，小女子只好斗胆讨教。却不知哪位愿\n先行出手赐教？\n",
"先前那道人嘿嘿干笑两声道：寻常武林同道比试，自然是以一对一，对付你们这\n魔教孽种，又何必讲什么江湖规矩？\n",
"水如昔微微变色：原来是这样以众凌寡的如意算盘，想是以欺负我一介弱质女流\n为乐了？\n",
"天峰大师刚要答话，就见那持斧之人眯了眯眼，抢道：不错。如果我们输了，自\n然无话可说，如果你输了．．．嘿嘿，可少不得要陪本公子快活快活。\n",
"水如昔脸上现出怒意，扬起两指就向那人双眼戳去，天峰大师暗叹一声，喝道：\n大家都动手罢！\n",
});
	if (!me || !target)
		return;
	if (environment(target) != env)
		return;
//	if (me != environment(target) || target->is_fighting())
//		return;
	msg = event_msg[count];
	message_vision(CYN+msg+"\n"NOR,target);
	if (count == 0)
	{
		me = new(__DIR__"npc/shui");
		me->move(env);
		this_object()->get_taoist();
		this_object()->get_monk();
	}
	if (count == 1)
	{
		this_object()->get_nun();
		this_object()->get_tx();
		this_object()->get_others();
	}
	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy",2,me,target,count+1);
	else
	{
		this_object()->fight(me);
		return;
	}
	return;
}

get_taoist()
{
	object *inv, ob;
	string *sname=({"种桃","抱朴","出尘","守拙","入松","渡鹤","凌云","听风",
});
	string *snick=({"北极","天枢","天璇","天玑","天权","玉衡","开阳","摇光",
});

	int i ;
	for (i=0; i<8;i++ )
	{
		ob=new(__DIR__"npc/taoist");
		ob->move(this_object());
	}
	ob=present("wudang taoist", this_object());
	if(ob) ob->set("name","种桃道人");
	if(ob) ob->set("nickname",HIY"北极"NOR);
	if (ob) ob->set("resistance/kee",65);
	inv = all_inventory();
	if(ob)
	{
		ob->dismiss_team();
		for(i=0 ;i < sizeof(inv);i++)
		{
			if(inv[i]->query("id") == "wudang taoist" && inv[i]!= ob)
			{
				ob->add_team_member(inv[i]);
				inv[i]->set("name",sname[i]+"道人");	
				inv[i]->set("nickname",CYN+snick[i]+NOR);
			}
		}
	}
}


get_monk()
{
	object *inv, ob;
	string *sname=({"天峰","无视","无听","无言",// 非礼啊...*snicker
});
	string *snick=({HIW"前任方丈"NOR,"戒律院首座","掌经殿首座","般若堂首座",
});

	int i ;
	for (i=0; i<4;i++ )
	{
		ob=new(__DIR__"npc/monk");
		ob->move(this_object());
	}
	ob=present("shaolin monk", this_object());
	if(ob) ob->set("name","天峰大师");
	if(ob) ob->set("nickname",HIW"前任方丈"NOR);
	if (ob) ob->set("resistance/kee",70);
	inv = all_inventory();
	if(ob)
	{
		ob->dismiss_team();
		for(i=0 ;i < sizeof(inv);i++)
		{
			if(inv[i]->query("id") == "shaolin monk" && inv[i]!= ob)
			{
				ob->add_team_member(inv[i]);
				inv[i]->set("name",sname[i]+"大师");	
				inv[i]->set("nickname",HIR BLK+snick[i]+NOR);
			}
		}
	}
}


get_nun()
{
	object *inv, ob;
	string *sname=({"清叶","清雪","清亭",
});

	int i ;
	for (i=0; i<3;i++ )
	{
		ob=new(__DIR__"npc/nun");
		ob->move(this_object());
	}
	ob=present("sanqing nun", this_object());
	if(ob) ob->set("name","清叶师太");
	if (ob) ob->set("resistance/kee",60);
	inv = all_inventory();
	if(ob)
	{
		ob->dismiss_team();
		for(i=0 ;i < sizeof(inv);i++)
		{
			if(inv[i]->query("id") == "sanqing nun" && inv[i]!= ob)
			{
				ob->add_team_member(inv[i]);
				inv[i]->set("name",sname[i]+"师太");	
			}
		}
	}
}

get_others()
{
object ob;
	ob=new(__DIR__"npc/cici");
	ob->move(this_object());
	ob=new(__DIR__"npc/khl");
	ob->move(this_object());

}

get_tx()
{
	object *inv, ob;
	string *sname=({"新月","温柔",
});

	int i ;
	ob=new(__DIR__"npc/txmale");
	ob->move(this_object());
	ob=new(__DIR__"npc/txfemale");
	ob->move(this_object());
	if(ob) ob->set("name","新月");
	if(ob) ob->set("nickname",HIG"小公主"NOR);
	if (ob) ob->set("resistance/kee",60);
	inv = all_inventory();
	if(ob)
	{
		ob->dismiss_team();
		for(i=0 ;i < sizeof(inv);i++)
		{
			if(inv[i]->query("id") == "tiexue apprentice" && inv[i]!= ob)
			{
				ob->add_team_member(inv[i]);
				inv[i]->set("name",sname[i]);	
				inv[i]->set("nickname",HIG"大螃蟹"NOR);	
			}
		}
	}
}

fight(object me)
{
	object *inv, ob;
	int i;
	inv = all_inventory();
	for(i=0 ;i < sizeof(inv);i++)
	{
		if(inv[i]->query_temp("condition_type") == NOR CYN" <山崖下>"NOR && inv[i]!= me)
		{
			inv[i]->kill_ob(me);
			me->kill_ob(inv[i]);
		}
	}
}
/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
/*
goto /d/bashan/hole3;update here;updatep /d/bashan/npc/;call here->attack();l
*/
