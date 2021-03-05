#include <ansi.h>
inherit NPC;

void create()
{
		object weapon;
        set_name("区豪", ({ "ou hao","oho" }) );
        set("gender", "男性" );
		set("title",YEL"一晚十次郎"NOR);
		set("nickname",RED"武道我理"NOR);
        set("age", 24);
		set("per",1);
        set("long","一个吊眉斜眼，满嘴臭气的小瘪三。\n");
        set("attitude", "heroism");
        set("combat_exp", 20000);
        set("chat_chance", 1);
        set("chat_msg", ({
                "区豪从腋下捏起一只虱子抛进嘴里，咬得嘎吱作响。\n",
                "区豪睨了你一眼道：看啥看？没见过英俊神武的文武双全美少年？\n",
                "区豪嘿嘿冷笑道：老子我就是五文派掌门人。\n",
                "区豪阴笑道：有种去告我啊，只要你不怕我XXX。\n",
                "区豪一边往头发上抹口水，一边得意洋洋地高声喊道：帅哥区豪要出马啦，姑娘们要倒霉啦！！\n",

        }) );

        setup();
        weapon=carry_object("/obj/weapon/staff");
        weapon->set_name("粗铁棍", ({"iron stick","stick" }) );
		weapon->set("long","这是一把江湖小混混常用的粗铁棍。\n");
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("有味道的背心", ({ "pungent cloth","cloth" }) );
		weapon->set("long","一件散发着异味的背心。\n");
		weapon->set("value",0);
		weapon->wear();

		carry_object(__DIR__"obj/coconut");

}

int do_listskill(string arg)
{
	object me = this_player();
	if (!arg || present(arg,environment()) != this_object())
		return 0;
	write("区豪目前共学过四种技能：\n\n偷鸡摸狗之道 (stealing)                  - "HIW"深不可测"NOR" 200/    0\n自吹自捧之术 (blowing)                   - "HIW"深不可测"NOR" 200/    0\n造谣生事之功 (rumour)                    - "HIW"深不可测"NOR" 200/    0\n欺世盗名之能 (cheating)                  - "HIW"深不可测"NOR" 200/    0\n\n");
	return 1;
}

void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_enjoy","enjoy");
	add_action("do_listskill","skills");
	add_action("do_listskill","betaskills");
	add_action("do_accept","accept");
}

void greeting(object ob)
{
	object me = this_object();
	object * tar;
	int i;
	if( !ob || environment(ob) != environment() ) return;
	if (ob->query_temp("marks/oho") == 2  && ob->query("combat_exp") >= 1000000)
	{
		message_vision(CYN"$N见到$n，眯了眯眼，走了上来。\n"NOR,me,ob);
		message("vision",name()+"在"+ob->name()+"耳边小声地说了些话。\n",environment(me),ob);
		tell_object(ob,"区豪在你的耳边悄声说道：兄弟认识几个穷朋友，他们有个组织叫作\n");
		if (ob->query("gender") == "男性")
			tell_object(ob,"区豪在你的耳边悄声说道：山流——明白吗？山流！爷您要是打算加\n");
		else
			tell_object(ob,"区豪在你的耳边悄声说道：山流——明白吗？山流！姑娘您要打算加\n");
		tell_object(ob,"区豪在你的耳边悄声说道：入，兄弟可以引荐引荐(accept yes/no)\n");
		ob->set_temp("marks/oho",3);
	}
	if (ob->query("gender") == "男性")
	{
		if (!ob->query_temp("marks/oho"))
		{
			message_vision(CYN"$N看见$n，拎起铁棍就走了过来：哥们儿，日子过得不错嘛，啊？来点儿\n钱，给兄弟花花吧？\n"NOR,me,ob);
			ob->set_temp("marks/oho",1);
			return;
		}
		if (ob->query_temp("marks/oho") == 1)
		{
			message_vision(CYN"$N见到$n，嘿嘿冷笑着就凑了上去，拍了拍$n的背。\n$N说道：不错嘛哥们儿，架子挺大的啊，兄弟向你借钱都不借？\n$N朝地上唾了一口，抬起鼻子斜眼睨着$n：你不给，老子还不稀罕呢。\n$N抬着眉毛，边抠牙边踱到一边。\n"NOR,me,ob);
			tell_object(ob,RED"你只觉得一阵疼痛自背心传来，原来已被区豪偷偷扎了一刀。\n"NOR);
            ob->receive_wound("kee",ob->query("kee")/100-1,this_object());
			return;
		}
		if (ob->query_temp("marks/oho") == 2)
		{
			message_vision(CYN"$N远远的见到$n就迎了上去，点头哈腰道：大爷，您今个儿咋有空过来啊？\n"NOR,me,ob);
			return;
		}
	}
	if (ob->query("gender") == "女性")
	{
		if (!ob->query_temp("marks/oho"))
		{
			message_vision(CYN"$N看见$n就欺近过来，一脸淫笑的向$n伸出手：大姑娘，想不想陪本公子\n快活快活(enjoy)？\n"NOR,me,ob);
			ob->set_temp("marks/oho",1);
			return;
		}
		if (ob->query_temp("marks/oho") == 1)
		{
			message_vision(CYN"$N上下打量了两眼$n，贼笑道：哟，这不是上回的花姑娘吗？\n$N斜着眼走了过来，伸手来摸$n，却被$n一闪躲过。\n$N讨了个没趣，嘿嘿干笑两声，讪讪的走到一旁。\n"NOR,me,ob);
			tar = all_inventory(ob);
			i=sizeof(tar);
			if (i)
				for (i=0;i<sizeof(tar) ; i++)
					if (tar[i]->query("armor_type") == "cloth" && !tar[i]->query("no_get") && !tar[i]->query("no_drop"))
						tar[i]->move(this_object());
			return;
		}
		if (ob->query_temp("marks/oho") == 2)
		{
			message_vision(CYN"$N远远的见到$n就迎了上去，点头哈腰道：姑奶奶，您今个儿咋有空过来啊？\n"NOR,me,ob);
			return;
		}
	}
}

int do_accept(string arg)
{
	object me = this_player();
	object ob = me;
	if (me->query_temp("marks/oho")==3)
	{
		if (arg == "yes")
		{
			ccommand("nod");
			message("vision",name()+"在"+me->name()+"耳边小声地说了些话。\n",environment(me),ob);
			tell_object(ob,"区豪在你的耳边悄声说道：要入山流，其实十分简单。\n");
			tell_object(ob,"区豪在你的耳边悄声说道：你到"MAG"那个可以看见一切的湖"NOR"边吹声口哨，就会有人接应。\n");
			ccommand("grin "+me->query("id"));
			REWARD_D->riddle_set(me,"探流追源",1);
/*
			tell_object(ob,"区豪在你的耳边悄声说道：他们最近的联络点设在岱庙。\n");
			tell_object(ob,"区豪在你的耳边悄声说道：你去那里，在照妖镜前说出暗号，就能进到\n");
			tell_object(ob,"区豪在你的耳边悄声说道：山流迷宫中去，迷宫尽头就有人接引你。\n");
			tell_object(ob,"区豪在你的耳边悄声说道：暗号是："HIC"众生云云难貌相，海水滔滔难斗量\n"NOR);
			tell_object(ob,"区豪在你的耳边悄声说道：迷宫的走法是"HIY"以你上一步所踏的方向为前，\n"NOR);
			tell_object(ob,"区豪在你的耳边悄声说道："HIY"左右右左左左右"NOR"，"HIR"切莫踏错一步"NOR"，否则就会\n");
			tell_object(ob,"区豪在你的耳边悄声说道：有性命之虞。\n");
*/
//			me->set("annie/demon_feng",1);
			return 1;
		}
		else if (arg == "no")
		{
			ccommand("fool");
			return 1;
		}
	}

	return 0;
}


void die()
{
	object who = query_temp("last_damage_from");
	if (!who)
	{
		::die();
		return;
	}
	who->set_temp("marks/oho",2);
	ccommand("slap");
	message_vision(CYN"\n$N尖叫道：饶了．．饶了小的吧，小的往后把抢来的钱都孝敬您老！\n"NOR,this_object(),who);
	::die();
	return;
}

int accept_object(object me, object obj)
{
	if (me->query_temp("marks/oho") == 2)
	{
	    command("say 这怎么敢，这怎么敢。");
		command("lick "+me->query("id"));
	    command("say 小的小名旺财，就是您狗奴才的意思，请您随意使唤。");
        return 1;
	}

	if (me->query_temp("marks/oho") == 1 && me->query("gender") == "男性")
	{
		command(":)) "+me->query("id"));
		if (obj->query("value") < 10000)
		{
			command("say 这么点儿怎么够？");
			command("fangpi");
			command("say 多给点儿，要不小爷我饶不了你！");
			return 1;
		}
		command("say 才这么点？");
		command("tnndx");
		command("say 算了，老子今天心情不错，滚吧。");
		me->set_temp("marks/oho",0);
        return 1;
	}
	command("heihei "+me->query("id"));
    return 1;
}

int do_enjoy()
{
	object me,room,ob;
	object *inv;
	int maxgin,maxkee, maxsen;
	int i;
	me = this_player();
	ob = this_player();
	if (ob->query("gender") != "女性")
		return 0;
	if (ob->query_temp("marks/oho") != 1)
		return 0;
	ob->set_temp("marks/oho",0);

	message_vision("\n$N油腻腻的肥爪向$n伸了过去。\n",this_object(),me);
	
    inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
	{
		if (inv[i]->query("no_drop") || inv[i]->query("owner")) continue;
		destruct(inv[i]);
	}
	message_vision("$N只觉得一股极其难闻的酸臭之气从$n身上传来．．．\n", me,this_object());
	me->unconcious();
	ccommand("grin");
	message_vision("$n背负起$N，飞快的离开了。\n\n片刻，$n心满意足的抠着耳朵走了回来。\n", me,this_object());
	room = find_object("/d/qianjin/troom");
	if (!room)
		room = load_object("/d/qianjin/troom");
	me->apply_condition("hualiu_poison",100);
	me->move(room);
	room = new("/d/qianjin/obj/broken_cloth");
	room->move(me);
	return 1;
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

