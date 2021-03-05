#include <ansi.h>
inherit __DIR__"annieitem";
inherit F_BANKOWNER;

void create()
{
	set_name("财神雕像", ({ "automatic teller machine"}) );	// 让这个id有别于其他东西。不使用单字id!
	set_weight(30000);
    set("richness",999999999);
	set("unit", "个");
	set("desc", "一个满脸堆笑的财神雕像，在这里可以执行银行的指令。
convert     兑换钱币
withdraw    提取存款
deposit     存入钱币
balance     查询存款数额
loan	向钱庄借钱
transfer    直接转帐\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("no_split",1);
	set("item_type","n");
	set("size",1);
	set("tax",10);
	set("score_tax",1);
	set("value", 500000);
	seteuid(getuid());
}

void init()
{
	::init();
	if (environment()->is_owner(this_player()->query("id")))
	{
        add_action("do_convert", "convert");
        add_action("do_deposit", "deposit");
        add_action("do_balance", "balance");
        add_action("do_withdraw", "withdraw");
		add_action("do_loan","loan");
		add_action("do_transfer","transfer");
	}
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
