// waiter.c
#include <ansi.h>
inherit SMART_NPC;
inherit F_VENDOR;

int d_1();

void create()
{
	object weapon;
    set_name("小小的人", ({ "spirit" }) );
	set("gender", "男性" );
	set("age", 2);
//	set("price_modifier",10000);
	set("combat_exp", 0);
	set("attitude", "friendly");
	set("vendor_goods", ([
	"/obj/generate/commonweapon/70/axe":20,
	"/obj/generate/commonweapon/70/blade":20,
	"/obj/generate/commonweapon/70/fist":20,
	"/obj/generate/commonweapon/70/hammer":20,
	"/obj/generate/commonweapon/70/spear":20,
	"/obj/generate/commonweapon/70/staff":20,
	"/obj/generate/commonweapon/70/sword":20,
	"/obj/generate/commonweapon/70/throwing":20,
	"/obj/generate/commonweapon/70/whip":20,
	]) );
	
	set("inquiry",([
		"弹珠":     "我老人家两千岁了，早不玩那东西了。\n",
		"stone":	"我老人家两千岁了，早不玩那东西了。\n",
		"天灵翡翠":  "天灵翡翠，就是五彩灵石中最珍贵的那块呀。\n",
		"jade":     "天灵翡翠，就是五彩灵石中最珍贵的那块呀。\n",
        "五十六":	"它原是我种下的第五十六棵小草，至今已经是五百六十年了。。。。\n",
        "emerald":  "天灵翡翠，就是五彩灵石中最珍贵的那块呀。\n",
        "大树":		"恩，我这棵树可是三千年一开花、三千年一结果，你等的及么？\n",
        "tree":		"恩，我这棵树可是三千年一开花、三千年一结果，你等的及么？\n",
        "树":		"恩，我这棵树可是三千年一开花、三千年一结果，你等的及么？\n",
         "司空摘星":	"action小小的人唱道：天上星、是爱人的心、你要去追寻！\n",
        
        "小草":		(: d_1() :),
        "grass":	(: d_1() :),
        "草":		(: d_1() :),
        "绿石头":	"action小小的人咬呀切齿作痛恨状。",	
		"明烟草": "那是一种极珍贵的"YEL"药材"CYN"，我好容易找到一株养在家门口，上个月却让人砸死了。\n",
		"药材": "药材你都不懂？去问大夫，别来烦我。\n",
	]) );


	setup();

}


void init()
{	
	object ob;

	::init();
	add_action("do_vendor_list", "list");
}

int do_w()
{
//return notify_fail("小小的人摇头道：东西全卖光了，下次来早。\n");
}

int d_1()
{
	object me = this_player();
	if (REWARD_D->riddle_check(me,"天灵翡翠") != 2
		&& REWARD_D->riddle_check(me,"天灵翡翠") != 3)
	{
		message_vision("小小的人道：这山谷里到处是草，都很大。\n",me);
		return 1;
	}
	ccommand("hmm");
	ccommand("say 你是说我门前的小草啊，上个月让一块绿石头砸死了！");
	ccommand("say 那绿石头虽然不是什么好东西，不过先还我"HIG"明烟草"NOR CYN"来。");
	REWARD_D->riddle_set(me,"天灵翡翠",3);
	return 1;
}

int give_me_it(object me)
{
	object item;

	item = new("/obj/specials/stone/gstone");
	if (objectp(item)){
		message_vision(HIW"一块晶莹剔透的翡翠落入$N怀中。\n"NOR, me);
    	item->move(me);
 //   	me->set("stone_mark/gstone", 1);
    	log_file("riddle/IMBUE_LOG",
		sprintf("%s(%s) 得到天灵翡翠。 %s \n",
			me->name(1), geteuid(me), ctime(time()) ));
    }
	return 1;
}



int accept_object(object who, object ob)
{
	object me = who;
	if (REWARD_D->riddle_check(me,"天灵翡翠") != 9)
	{
		ccommand("emote 接过"+ob->name()+"，看也不看，随手丢到身边的坛坛罐罐里。\n");
		return 1;
	}
	if (ob->query("name") != HIG"明烟草"NOR || ob->query("real_flower") != 3)
	{
		ccommand("emote 接过"+ob->name()+"，看也不看，随手丢到身边的坛坛罐罐里。\n");
		return 1;
	}
	ccommand("ack");
	ccommand("emote 从枕头下摸出一块绿色的小石子，随手丢给"+who->name()+"。");
	give_me_it(me);
	ccommand("emote 捧着"HIG"明烟草"NOR CYN"，如捧至宝般小心翼翼地栽到一个小盆中。");
	REWARD_D->riddle_done(who,"天灵翡翠",200,1);
	return 1;
}