// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";


string lic();

void create()
{
	set("short", "瞭望台内");
    set("long", @LONG
这一处戒备森严，空气中竟隐隐弥漫著烽火金戈之气。四面的青砖石瓦亮
洁如新，整排整排锃亮的梨花铁枪并立在左墙兵器架上，右墙上则开了数个垛
口，战时在垛口上既可以长弓钳制整个明霞山道，亦可指挥瞭望台上的天罡破
阵弩以风引之箭远射，将风云城东直至帝王谷的数十里道路尽数涵覆。
LONG
NOR
        );
	set("objects", ([

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"eastdown" : "path6",
	]) );

	set("stat",1);
	set("free_cmds",1);

	set("area","cyan2");


	set("item_desc", ([

	"eastdown": (: lic :),

	]) );

	set("coor/x",-60);
	set("coor/y",30);
	set("coor/z",90);
	setup();
}


string lic()
{
	string str;
	object m;
	int i = time();

	if (!query("m"))
		return 0;
	if (query("stat") == 1)
		str="\n天空中阴云覆霾，山道上死一般的寂静，不时间有惊雷落在远处，兆示着一场狂风暴雨的来临。\n";

	if (query("stat") == 2 && !random(5))
	{
		str="\n在偶然划破天幕的电光里，你只见山道上无数黑压压的一片尽是倭人，正潮水一般向山上涌来。\n";
		i=query("apres_vague") - i;
		str += HIW"下一波攻击将在"+i+"秒之后到达瞭望台！\n"NOR;

	}
	else if (query("stat") == 2 )
		str="\n天空中阴云覆霾，远处的山峰黑沉沉压下，狂风在山嘏间来去横扫，只听得一阵阵枝断叶折的声音。\n";

	if (query("stat") == 3)
		str="\n倾盆大雨终于如约而至，雨水混杂着满山的鲜血，汇集成潺潺的小溪向山下流去．．．\n";

	return str;
}




int do_start(object me)
{
	object here = this_object();
	object a,b,c, s1, s2, s3, m;
	int i,j,k;
	string r,s,t;

	set("owner_ob",me->query("id"));
	set("ownerr",me->query("name"));

	s1 = new(__DIR__"npc/soldier");
	s1->move(here);
	s1->init_me(me,"garrison",1);
	s1->set("name","守军甲");
	s2 = new(__DIR__"npc/soldier");
	s2->move(here);
	s2->init_me(me,"garrison",1);
	s2->set("name","守军乙");
	s3 = new(__DIR__"npc/soldier2");
	s3->move(here);
	s3->init_me(me,"garrison",2);

	m = new(__DIR__"npc/wall");
	m->move(here);
	m->set("max_kee",me->query("max_kee")*10);
	m->set("eff_kee",me->query("max_kee")*10);
	m->set("kee",me->query("max_kee")*10);
	set("m",m);

tell_room(this_object(),CYN"
明霞守备长忧心忡忡地自垛口向外望了一眼：没想到今天贼寇趁狂风来犯，
我们又要让人上瞭望台转动风弩，又要留着人在这里守住机括，人手不够呀！

守军甲说道：官长放心，今天俺就算拼了性命不要，也绝不让那些贼寇马踏中原！

守军乙用力地搓了搓手道：老"+me->query("name")[0..1]+"，今天可就看咱的了！\n\n"NOR);

	set("commencer",time());
	set("apres_vague",time() + 30);
	
	call_out("attacks",30,me,m);

	call_out("delay",40,m,me,0);
	return 1;

}

void failed()
{
	object here = this_object();
	object r,*inv;
	int i;
	r=find_object("/d/cyan/kay");
	if (!r)
		r=load_object("/d/cyan/kay");


	inv = all_inventory(here);
	i = sizeof(inv);
		while(i--) 
				if(userp(inv[i])|| inv[i]->query("possessed")  || inv[i]->query("player") == 1) 
					inv[i]->move(r);
				else
					destruct(inv[i]);

	if (!query("a"))
	{	
		CHANNEL_D->do_channel(this_object(), "chat", HIC+""+query("ownerr")
			+"镇守明霞关隘失利，倭寇长驱直入中原．．．"+NOR,1);
		set("a",1);
	}

	"/d/phoenix/base/alive.c"->destruct_area(query("owner_ob"));



}



void failedd()
{
	object here = this_object();
	object r,*inv;
	int i;
	r=find_object("/d/cyan/kay");
	if (!r)
		r=load_object("/d/cyan/kay");


	inv = all_inventory(here);
	i = sizeof(inv);
		while(i--) 
				if(userp(inv[i])|| inv[i]->query("possessed")  || inv[i]->query("player") == 1) 
					inv[i]->move(r);
				else
					destruct(inv[i]);

	"/d/phoenix/base/alive.c"->destruct_area(query("owner_ob"));
}

void delay(object m, object me, int i)
{
	if (!m)
	{
		tell_room(this_object(),HIR"\n漫天的血雨潇潇，一阵阵打在毁损的天罡破阵弩上．．．\n"HIW"\n由于明霞关隘的失守，两个月后倭人海贼长驱直入，大肆屠杀，中原大地一时间\n哭声遍野，愁肠欲绝，数十万百姓流离失所，被迫西迁．．．"HIY"\n\n很遗憾，任务失败了。\n\n"NOR);
		failed();
		return;
	}

	if (i<9)
	{
		i++;
		set("wave",i);
		call_out("delay",30+random(30),m,me,i);
		tell_room(this_object(),HIC"\n瞭望台上有人喊道：再顶会儿，我们已经把大弩转好"+CHINESE_D->chinese_number(i)+"成了！\n\n"NOR);
		return;
	}

	tell_room(this_object(),HIC"\n瞭望台上有人大喝道：成了，成了！\n"HIR"只听得一声轰然巨响，整个瞭望台猛地一颤，满壁的瓦灰尘土簌簌而落。你自垛口\n探头望出，但见一条火龙沿着山道直窜而下，所过之处尽成焦土。正惊骇间又是一\n声大响，一阵热浪挟滚着烟气自瞭望台上笼下，间或夹杂着山下的无间惨号、台顶\n的欢呼大笑。\n\n"NOR);

	if (QUESTS_D->verify_quest(me, "垂暮老人"))
		QUESTS_D->special_reward(me, "垂暮老人");

	if (!query("a"))
	{
		CHANNEL_D->do_channel(this_object(), "chat", HIC+query("ownerr")+"血战明霞关，击退了倭寇的进犯。"+NOR,1);
		CHANNEL_D->do_channel(this_object(), "chat", HIC"垂暮老人用力拍著"+query("ownerr")+"的背：「好小子！干的好！」"+NOR,1);
		set("a",1);
	}

	failedd();
	return;

}

void attacks(object me, object m)
{

	object here = this_object();
	object a,b,c, s1, s2, s3;
	int i,j,k;
	string r,s,t;

	if (!m)
	{
		tell_room(this_object(),HIR"\n漫天的血雨潇潇，一阵阵打在毁损的天罡破阵弩上．．．\n"HIW"\n由于明霞关隘的失守，两个月后倭人海贼长驱直入，大肆屠杀，中原大地一时间\n哭声遍野，愁肠欲绝，数十万百姓流离失所，被迫西迁．．．"HIY"\n\n很遗憾，任务失败了。\n\n"NOR);
		failed();
		return;
	}

	set("stat",2);

	i = random(100);
	if (i<=2)
		j=4;
	else if (i<=7)
		j=3;
	else if (i<=47)
		j=2;
	else j=1;


	for (i=0; i<j; i++)
	{

	a = new(__DIR__"npc/attacker");
	a->move(here);
	a->init_me(me,"attacker",i+2);

		message_vision(WHT"\n一个惊雷陡而炸响，瞭望台中猛地一亮，有个人影自门外飞跃而来．．．\n"NOR,a);
		a->ccommand("kill launch mechanism");
		a->kill_ob(m);
		a->add_hate(m,2000+random(1000));

		if (b=present("fengyun garrison"))
		{
			b->ccommand("emote 大喝道：贼人休得猖獗！");
			b->ccommand("kill soldier");
			a->kill_ob(b);
			b->kill_ob(a);
			a->add_hate(b,1500+random(1000));
		}
		if (b=present("fengyun garrison 2"))
		{
			b->ccommand("emote 大喝道：贼人休得猖獗！");
			b->ccommand("kill soldier");
			a->kill_ob(b);
			b->kill_ob(a);
			a->add_hate(b,1500+random(1000));
		}
		if (b=present("fengyun garrison 3"))
		{
			b->ccommand("emote 大喝道：贼人休得猖獗！");
			b->ccommand("kill soldier");
			a->kill_ob(b);
			b->kill_ob(a);
			a->add_hate(b,1500+random(1000));
		}
	}

	k=40+random(10);
	k-=query("wave");
	set("apres_vague",time() + k);
	call_out("attacks",k,me,m);
	return;

}

int	valid_leave(object who, string dir)
{
	object me;
	me = who;
	return notify_fail("现在可不是到处闲逛的时候．．．\n");
}


/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/


