inherit NPC;
inherit F_VENDOR;

void create() { 	
	set_name("红杏花", ({ "xinghua" }) );
	set("gender", "女性" );
	set("age", 67);	
	set("title", "老板娘");
	set("long","身穿红花裙，脸上抹着红胭脂，指甲上涂着凤仙花汁的一位花甲老妇人。\n");
	set("chat_chance", 1);
	set("chat_msg", ({
		"红杏花瞟了你一眼笑道 ：那位徐三大爷啊，今个儿在这儿单挑霸王\n枪，小店的生意可是红火了不少......\n",
		"红杏花叹道：看来一直得等到七十岁以后，我才能习惯一个人睡。\n",
	}) );
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",20);
	set_skill("unarmed",100);
	set_skill("dodge",100);
	
	set("vendor_goods", ([
		__DIR__"obj/sxqj":12,
		__DIR__"obj/gaoskin":12,
		__DIR__"obj/gaoliang":6,
		__DIR__"obj/hsnr":6,
		__DIR__"obj/pill":50,
		]) );
	
	setup();
	carry_object("/obj/armor/cloth")->wear();

}

	

void init(){
	object ob;
	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}	

	add_action("do_vendor_list", "list");

}



void greeting(object ob){
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) 
	{
		case 0:
            message_vision("$N一见$n来，连忙凑上前将一张桌子抹了抹，嗲声嗲气道：
这位"+RANK_D->query_respect(ob)+"好久没来了，我都怪想你的。。。\n",this_object(),ob);
			break;
		case 1:
            message_vision("$N摇摇头叹道：这个死丁喜，小王八蛋，也不知道死哪去了。
自从遇见王若兰那丫头后，就把老娘我扔到一边去了。\n",this_object(),ob);
			break;
		case 2:
			message_vision("$N望了$n一眼，用玉手掩着樱桃小嘴轻笑起来。\n",this_object(),ob);

			break;
	}
}

void reset ()
{
	set("vendor_goods", ([
		__DIR__"obj/sxqj":12,
        	__DIR__"obj/gaoskin":12,
        	__DIR__"obj/gaoliang":6,
		__DIR__"obj/hsnr":6,
		__DIR__"obj/pill":50,
		]) );
}

