//bankowner.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
// Last modification:
//		- 07/16/2001 by Daniel Q. Yu.
//		- 02/16/2003 by silencer

// This file should be inherited by a banker, who should set add_action of following fuctions.
/*void init()
{
        ::init();
        add_action("do_loan","loan");
        add_action("do_convert", "convert");
        add_action("do_deposit", "deposit");
        add_action("do_balance", "balance");
        add_action("do_withdraw", "withdraw");
}
*/


#include <ansi.h>
#define MAX_CARRY 29

int do_convert(string arg) {
	string from, to;
	int amount, bv1, bv2;
	object from_ob, to_ob;
       
        // check for busy status. 
	if(this_player()->is_busy()) {
		return notify_fail("你的动作还没有完成，不能兑换钱。\n");
	}
	
	// check from args.
	if(!arg || sscanf(arg, "%d %s to %s", amount, from, to)!=3) {
		return notify_fail("指令格式：convert | duihuan <数量> <货币种类> to <货币种类>\n");
	}
	if(amount < 1) {
		return notify_fail("兑换货币一次至少要兑换一个。\n");
	}
	
	// check for from money type.	
	from_ob = present(from + "_money", this_player());
	if(!from_ob) {
		return notify_fail("你身上没有这种货币。\n");
	}
	if((int)from_ob->query_amount() < amount) {
		return notify_fail("你身上没有那麽多" + from_ob->query("name") + "。\n");
	}
	bv1 = from_ob->query("base_value");
	if(!bv1) {
		return notify_fail("这种东西不值钱。\n");
	}
	
	// check for to money type
	if(!objectp(to_ob = present(to + "_money", this_player())) && !objectp(to_ob = load_object("/obj/money/" + to + ".c"))) {
		return notify_fail("你想兑换哪一种钱？\n");
	}
	bv2 = to_ob->query("base_value");
	if(bv1 < bv2) amount -= amount % (bv2 / bv1);
	if(amount==0) {
		return notify_fail("这些" + from_ob->query("name") + "的价值太低了，换不起。\n");
	}
	
	if (bv1==bv2)
		return notify_fail("同样的货币，有什么可换的？\n");
	
	this_player()->start_busy(1);
	
	// exchange the money.
	to_ob = new("/obj/money/" + to);
	to_ob->set_amount(amount * bv1 / bv2);
	if (to_ob->move(this_player())) {
		message_vision(sprintf("$N从身上取出%s%s%s，换成%s%s%s。\n",
			chinese_number(amount), 
			from_ob->query("base_unit"), 
			from_ob->query("name"),
			chinese_number(amount * bv1 / bv2), 
			to_ob->query("base_unit"), 
        	 	to_ob->query("name")),
			this_player());
		from_ob->add_amount(-amount);
	}
	else {
		destruct(to_ob);
		return notify_fail("兑换没有成功。\n");
	}
	
	return 1;
}

int do_deposit(string arg) {
	int bv,amount;
	int damount;
	string type;
	object type_ob;
 
 	// check for busy status
 	if(this_player()->is_busy()) {
		return notify_fail("你的动作还没有完成，不能存钱。\n");
	}
	
	// check for command args
	if(!arg || sscanf(arg, "%d %s", amount, type)!=2 ) {
		return notify_fail("指令格式：deposit | cun <数量> <货币种类>\n");
	}
	if(amount <= 0) {
		return notify_fail("指令格式：deposit | cun <数量> <货币种类>\n");
	}

	// check for desposite.
	type_ob = present(type + "_money", this_player());
	if(!type_ob) {
		return notify_fail("你身上没有这种货币。\n");
	}
	if((int)type_ob->query_amount() < amount) {
		return notify_fail("你身上没有那麽多" + type_ob->query("name") + "。\n");
	}
	bv = type_ob->query("base_value");
	if(!bv) {
		return notify_fail("这种东西不值钱。\n");
	}
	
	damount = (int)this_player()->query("deposit");
	damount += amount * bv;
	// to make life more realistic
	this_object()->add("richness",amount * bv);
	this_player()->set("deposit", damount);
	message_vision(sprintf("$N存入了%s%s%s。\n", chinese_number(amount), 
			type_ob->query("base_unit"), type_ob->query("name")), this_player());
	type_ob->add_amount(-amount);
	this_player()->save();
	this_player()->start_busy(1);
	
	if (amount*bv >=10000)	// 仅纪录１ｇ以上的吧，防止被ｒｏｂｏｔ flooding
	log_file("BANKING_LOG", sprintf("%s,%s(%s)存入了%d文。\n",
		ctime(time()), this_player()->name(1),this_player()->query("id"), amount*bv));
	
	return 1;
}

int do_balance(string arg) {
	int value;
	value= (int) this_player()->query("deposit");
        if(value == 0){
        	tell_object(this_player(),"你现在没有存款。\n");
		return 1;
	}
	if(value > 0) 
		tell_object(this_player(),"你现在共有存款：\n");
	else {
		tell_object(this_player(),HIR"你现在共欠款：\n"NOR);
		value = -value;
	}
        
        tell_object(this_player(), HIY"		"+ MONEY_D->money_str(value) + "\n"NOR);
	return 1;
}


int do_withdraw(string arg)
{
	int amount;
	int hamount;
	object *inv,type_ob;
	string type, t;;
	
    if( this_player()->is_busy() )
    	return notify_fail("你上一个动作还没有完成，不能取钱。\n");
    if(!arg || sscanf(arg, "%d %s", amount, type)!=2 ) {
		return notify_fail("指令格式：withdraw | qu <数量> <货币种类>\n");
	}
    	if(amount <= 0) {
		return notify_fail("你想取出多少钱？\n");
	}
	 if( file_size("/obj/money/" + type + ".c") < 0 )
            return notify_fail("你想取出什么钱？\n");
	 t = "/obj/money/" + type;
	
    type_ob=get_object(t);
    amount=amount*type_ob->query("base_value");
    hamount = (int) this_player()->query("deposit");

	if(amount>hamount) 
		return notify_fail("你没这么多存款 ！！\n");

 // to make life more realistic
    if( ((int)this_object()->query("richness")) < amount)
        return notify_fail(sprintf("%s的现钱已经不够了．．．\n",this_object()->name()));
        
    inv = all_inventory(this_player());
	if(sizeof(inv) >= MAX_CARRY) 
		return notify_fail("你身上已经带着太多东西了，无法再取钱。\n");
			
    this_object()->add("richness",-amount);
	hamount -= amount;
	this_player()->set("deposit", hamount);
	MONEY_D->pay_player(this_player(), amount,1);
	tell_object(this_player(), "你取出了" +MONEY_D->money_str(amount)+ "。\n");
	this_player()->save();
	this_player()->start_busy(1);
	
	// 仅纪录１ｇ以上的吧，防止被ｒｏｂｏｔ flooding
	if (amount>=10000)
		log_file("BANKING_LOG", sprintf("%s,%s(%s)取出了%d文。\n",
			ctime(time()), this_player()->name(1),this_player()->query("id"), amount));
	
	return 1;

}


int do_loan(string arg)
{
	int amount;
	int hamount;
	if( (int)this_player()->query("mud_age") < 3600)
		return notify_fail("你刚刚踏入风云，不能借钱。\n");
	if( this_player()->is_busy() )
		return notify_fail("你上一个动作还没有完成，不能借钱。\n");
	
	return notify_fail("风云银行后台（山西土匪）携款潜逃，已经无法贷出款项了。\n");
		
	if( sscanf(arg, "%d", amount)!=1 )
		return notify_fail("指令格式：loan | jie <数量> \n");
	
	hamount = (int) this_player()->query("deposit");
	if(hamount > 0 ) return notify_fail("你还有存款！\n");
    	if(amount <=0)
               return notify_fail("指令格式：loan | jie <数量> \n");
	if((int)this_player()->query("combat_exp") < amount - hamount)
			return notify_fail("你借不到这么多钱．．．\n");
	//seems no need this check, well, it doesn't hurt, leave it now
	if( hamount - amount > hamount)
			return notify_fail("你借不到这么多钱．．．\n");
 // to make life more realistic
        if( ((int)this_object()->query("richness")) < amount)
                return notify_fail(sprintf("%s的现钱已经不够了．．．\n",this_object()->name()));
    
    this_object()->add("richness",-amount);
    this_player()->set("deposit", hamount - amount);
    MONEY_D->pay_player(this_player(), amount,1);
        tell_object(this_player(), "ＯＫ \n");
	this_player()->save();
	this_player()->start_busy(1);
        return 1;

}

int do_transfer(string arg) {
	string to;
	int amount, hamount;
	object to_player;
       
    	// check for busy status. 
	if(this_player()->is_busy()) {
		return notify_fail("你的动作还没有完成，不能转帐。\n");
	}
	
	// check from args.
	if(!arg || sscanf(arg, "%d to %s", amount,to)!=2) {
		return notify_fail("指令格式：transfer | zhuan <数量> to <玩家ID>\n");
	}
	if(amount <=0 )
		return notify_fail("指令格式：transfer | zhuan <正数额> to <玩家ID>\n");
	
	hamount = (int) this_player()->query("deposit");
	if(amount>hamount) 
		return notify_fail("你没这么多存款 ！！\n");
	if (!to_player = find_player(to))
	{
		return notify_fail("你只可转帐给在线玩家。\n");
	}
	hamount -=amount;
	this_player()->set("deposit", hamount);
	hamount = (int) to_player->query("deposit");
	hamount += amount;
	to_player->set("deposit", hamount);
//	tell_object(this_player(),"你转了"+(string)amount+"文钱给"+to_player->name()+"\n");
	tell_object(this_player(),WHT"你转了  "+ MONEY_D->money_str(amount)+"给"+to_player->name()+"。\n"NOR);
	tell_object(to_player, WHT""+this_player()->name()+"转了  "+ MONEY_D->money_str(amount) + "给你。\n"NOR);
	this_player()->save();
	this_player()->start_busy(1);
	
		// 仅纪录１ｇ以上的吧，防止被ｒｏｂｏｔ flooding
	if (amount>=10000)
		log_file("BANKING_LOG", sprintf("%s,%s(%s)把%d文转给了%s(%s)。\n",
			ctime(time()), 
			this_player()->name(1),this_player()->query("id"),
			amount,
			to_player->name(1), to_player->query("id")));
		
	return 1;
}
