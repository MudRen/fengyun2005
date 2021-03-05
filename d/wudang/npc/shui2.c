
inherit NPC;
#include <ansi.h>
#include <combat.h>
void smart_fight(object who);

void create()
{
	object armor,weapon;
	set_name("水如昔", ({ "shui ruxi","shui"}) );
	set("gender", "女性" );
	set("title",WHT"清秀少女"NOR);
	set("nickname",HIW"梦里花落"NOR);
	set("age", 20+random(10));

	set("attitude","friendly");

	set("long",
		"她正立在雾生云起的隐仙岩上，一身水蓝色的绡纱长裙在烈风\n里落落翻飞，束着淡紫发带的垂腰青丝亦在风里飘舞不定，尽\n管背对着你，面貌难见，依旧让你第一眼间误以为是错坠凡间\n的仙子，此刻正欲乘风归去。\n"
		);
	set("class","demon");
    set("combat_exp", 0);	
    set("score", 10000);
	set("fle",50);
	set("cor",40);
	set("cps",30);
	set("str",20);
	set("per",200);
	set("force",2500);
	set("atman",1500);
	set("max_atman",1500);
	set("mana",1500);
	set("max_mana",1500);

	set("no_fly",1);
	set("no_arrest",1);
		
	set("resistance/gin",60);
	set("resistance/kee",60);
	set("resistance/sen",60);

	set("max_kee",24000);
	set("max_gin",16000);
	set("max_sen",16000);
	


	set("chat_chance", 1);
        set("chat_msg", ({
                "水如昔轻轻一哼，说道：武当？连借力打力都已失传，还算什么武当？\n",
                "水如昔摇摇头道：石雁以下，个个草包．．．\n",
                "水如昔叹道：又是一年了，不知道绽青妹妹在那边过得如何．．．\n",
                "水如昔低首看了眼袖中，自语道：这还是上次就给绽青妹妹买的，什么时候才有空送去呢？\n",
                }) );
			

    set("inquiry", ([
        "太极心法": "可笑武当老掌门去后，太极心法中借力打力的心诀竟\n就失传，还去我半年时间方才自镇教秘籍中找到。",
        "武当派":   "可笑武当老掌门去后，太极心法中借力打力的心诀竟\n就失传，还去我半年时间方才自镇教秘籍中找到。",
        "武当":   "可笑武当老掌门去后，太极心法中借力打力的心诀竟\n就失传，还去我半年时间方才自镇教秘籍中找到。",
        "教主":   "action水如昔拂拂耳边发丝，似乎没有听到你的声音。",
        "魔教":   "action水如昔拂拂耳边发丝，似乎没有听到你的声音。",
        "大光明教":   "action水如昔拂拂耳边发丝，似乎没有听到你的声音。",
        "西方神教":   "action水如昔拂拂耳边发丝，似乎没有听到你的声音。",
        "草包":   "action水如昔噗嗤一笑，回首顾道：譬如你，就是个大草包。",
        "大草包":   "action水如昔噗嗤一笑，回首顾道：譬如你，就是个大草包。",
        "石雁":   "说什么五行真人，还不是和他那些弟子一样大草包，死不足惜。",
        "武当老掌门":   "老掌门倒也机灵，若不是那草包石雁鬼迷心窍，\n想取下这武当派还要有些曲折麻烦。\n水如昔撇撇嘴道：不过收下石雁这样的弟子，也就不过尔尔，\n识人不清，引狼入室，自绝生机，死的也不冤了。",
        "老掌门":   "老掌门倒也机灵，若不是那草包石雁鬼迷心窍，\n想取下这武当派还要有些曲折麻烦。\n水如昔撇撇嘴道：不过收下石雁这样的弟子，也就不过尔尔，\n识人不清，引狼入室，自绝生机，死的也不冤了。",
        "老刀把子":   "他？只不过是局里一颗棋子，过河小卒，不值一提。",
        "木道人":   "他？只不过是局里一颗棋子，过河小卒，不值一提。",
         ]) );

		add_temp("apply/iron-cloth", 200);
	
		set("NO_KILL","如此娇弱动人的女子，让人怎能忍得下心下手？\n");
	
	setup();

	carry_object(__DIR__"obj/longskirt")->wear();
}

int accept_object(object who, object ob)
{


	if (ob->query("name")==CYN"淡青银针"NOR 
		&& ob->query("id") == "cyan needle" 
		&& REWARD_D->check_m_success(who,"武当掌门"))
	{
		command("giggle shui ruxi");
		command("emote 掩嘴窃笑道：你竟然找得到我。");
		command("fox");
		command("say 那好吧．．．你且等我一刹。\n");
		remove_call_out("greeting");
		call_out("greeting", 1,who);

		return 1;
	}
	return 0;
}


void greeting(object ob)
{
	message_vision(HIC"\n你眼前一花，那清丽的女子已不知从何处握出一把浅红色的短刀。\n"NOR,ob);
	message_vision(HIW"\n水如昔美目流光，轻笑道：如今你已知是我杀了石雁，又待如何？\n\n"NOR,ob);
	ob = new(__DIR__"shui");
	ob->move(environment());
    if (environment())
		environment()->set("boss_out",time());
	destruct(this_object());
}