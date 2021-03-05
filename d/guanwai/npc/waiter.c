// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("吕恭", ({ "waiter" }) );
	set("gender", "男性" );
    	set("title", "老板" );
	set("age", 62);
	set("long",
		"一个老头正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set_skill("iron-cloth", 2000);
	set_skill("unarmed", 100);
	set_skill("bloodystrike", 50);
	map_skill("unarmed", "bloodystrike");
	set("rank_info/respect", "老二哥");
	set("vendor_goods", ([
		__DIR__"obj/junksword":50,
		__DIR__"obj/junkblade":50,
		__DIR__"obj/junkstaff":50,
		__DIR__"obj/jade3":50,
		"/obj/item/bag":50,
        	"/obj/medicine/snake_drug":50,
        __DIR__"obj/huboots":50,
		__DIR__"obj/wineskin":50,
        __DIR__"obj/guskin":50,
		__DIR__"obj/sheep_leg":50,
		__DIR__"obj/jingtong": 50,

	]) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
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
	add_action("do_rent","rent");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
		case 0:
			say( "店老板吕恭笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，进来喝杯茶，歇歇腿吧。\n");
			break;
		case 1:
			say( "店老板吕恭用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
				+ "，请进请进。\n");
			break;
		case 2:
			say( "店老板吕恭说道：这位" + RANK_D->query_respect(ob)
				+ "，进来喝几盅小店的酒吧，这几天才从窖子里开封的哟。\n");
			break;
	}
}

int do_rent(string arg)
{

	object ob, chefu;
	object me = this_player();
//	object silver;
	if (arg != "carriage" && arg != "mache")
	{
		return notify_fail("你要租什么？\n");
	}

	if (query("mark/rented"))
	{
		tell_object(me,"
吕恭说：哎呀，马车已经租出去了，这位客官是不是过会儿再来？
如果等不及，我给你指点一条捷径吧。输入Help newbie，而后选择
路径指南，那里有几大城镇的往返路径说明。\n");
		return 1;
	}
	if (me->query_temp("marks/guanwai_mache",1))
		me->delete_temp("marks/guanwai_mache");
	else {
	    if (me->query("deposit")<800)
	    	return notify_fail("你银行里的存款不足八两银子。\n");
		me->add("deposit",-800);
		tell_object(me, "风云驿站从你的账户上转走了八两银子。\n");
	}
	
	ob=new("/d/fy/npc/obj/carriage");
    	ob->move(environment());
	message_vision("$N驶了过来 \n",ob);

    chefu=new("/d/fy/npc/chefu");
    chefu->move(environment());
    chefu->get_quest("/d/guanwai/guanwaicarriageway");
    chefu->set_carriage(ob);
	message_vision("$N走了过来 \n",chefu);

	set("mark/rented",1);
	message_vision("$N打开马车门，坐进了马车 \n",me);
	me->move(ob);
	chefu->go_now();
	
	call_out("check_status",30,chefu);
	return 1;
}

int check_status(object ob)
{
	if (!ob)
	{
		set("mark/rented",0);
	}else
	{
		call_out("check_status",30,ob);
	}
}

void reset()
{
	set("vendor_goods", ([
		__DIR__"obj/junksword":50,
		__DIR__"obj/junkblade":50,
		__DIR__"obj/junkstaff":50,
		__DIR__"obj/jade3":50,
		"/obj/item/bag":50,
        	"/obj/medicine/snake_drug":50,
        __DIR__"obj/huboots":50,
		__DIR__"obj/wineskin":50,
        __DIR__"obj/guskin":50,
		__DIR__"obj/sheep_leg":50,
		__DIR__"obj/jingtong": 50,

	]) );
}