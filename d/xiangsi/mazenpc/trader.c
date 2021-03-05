inherit NPC;
inherit F_BANKOWNER;
inherit F_PAWNOWNER;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
        set_name("小狂刀", ({ "xiao kuangdao","kuangdao" }) );
        set("gender", "男性" );
        set("age", 31);
        set("title", CYN"冰洞游魂"NOR);
		set("nickname",HIY"我爱小兔子"NOR);
		set("long",CYN"\n小狂刀说道：欢迎来到秘密商店。
小狂刀说道：在这里，你可以：
休息(Buy incense from geese)
购买药物(Buy herb from geese)
购买武器(Buy weapon from geese)
典当物品(Pawn/Redeem)
出售货物(Sell)
存取金钱(Deposit/Withdraw)
保存档案(Save)\n\n"NOR);
        set("combat_exp", 5000000);
        set("attitude", "friendly");
		set("class","moon");
        set("per",30);
        set("vendor_goods", ([
		
		__DIR__"obj/incense" : 10,
/*		"/obj/medicine/herb_annie_buff1" : 30,
		"/obj/medicine/herb_annie_buff2" : 30,
		"/obj/medicine/herb_annie_buff3" : 30,
		"/obj/medicine/herb_annie_buff4" : 30,
		"/obj/medicine/herb_annie_buff5" : 30,*/
		
		]) );
        set_skill("unarmed",1);
        set_skill("dodge",1);
        set_skill("parry",1);
        set_skill("lingxi-zhi",300);
        set_skill("stormdance",261);

        set_skill("force",200);
        set_skill("snowforce",200);

		map_skill("force","snowforce");
		map_skill("unarmed","lingxi-zhi");
		map_skill("dodge","stormdance");

        setup();
}

int	is_ghost() { return 1;}

void init()
{
	::init();
	add_action("do_value", "value");
	add_action("do_pawn", "pawn");
	add_action("do_sell", "sell");
	add_action("do_redeem", "redeem");
	add_action("do_vendor_list","list");
	add_action("do_loan","loan");
	add_action("do_convert", "convert");
	add_action("do_deposit", "deposit");
	add_action("do_balance", "balance");
	add_action("do_withdraw", "withdraw");
}



void reset()
{
        set("vendor_goods", ([
		__DIR__"obj/incense" : 10,
		"/obj/medicine/herb_annie_buff1" : 30,
		"/obj/medicine/herb_annie_buff2" : 30,
		"/obj/medicine/herb_annie_buff3" : 30,
		"/obj/medicine/herb_annie_buff4" : 30,
		"/obj/medicine/herb_annie_buff5" : 30,
        ]) );
	set("richness",5000000);
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
