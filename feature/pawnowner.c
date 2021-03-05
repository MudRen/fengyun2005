// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

// Last Modified	- 02/16/2003 by silencer
// This file should be inherited by a pawnowner, who should have the following add_action
/* void init()
{
        ::init();
        add_action("do_value", "value");
        add_action("do_pawn", "pawn");
        add_action("do_sell", "sell");
        add_action("do_redeem", "redeem");
}
*/

#define MAX_PAWN 9
#include <dbase.h>
#include <ansi.h>

int do_value(string arg)
{
	object ob;
	int value;
	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("你要拿什麽物品给当铺估价？\n");
	if (ob->query("thief_obj"))
	{
		call_out( (: call_other, MONEY_D, "arresthim", this_player() :), 3);
		this_player()->perform_busy(2);
		return notify_fail("你感觉有点不对劲，好像周围有人紧紧地盯住了你。\n");
	}
	if( ob->query("money_id") )
		return notify_fail("这是「钱」，你没见过吗？\n");

	value = ob->query("value");
	if( !value || value < 4) printf("%s并不值几文钱。\n", ob->query("name"));
	else 	{
		printf("%s价值%s。\n如果你要典当(pawn)，可以拿到%s。\n如果卖断(sell)，可以拿到%s。\n",
			ob->query("name"), 
			MONEY_D->money_str(value),
			MONEY_D->money_str(value * 25 / 100), 
			MONEY_D->money_str(value * 80 / 100));
		if (ob->query("item_damaged"))
	       		tell_object(this_player(),"不过此物品已经损坏了，在修好之前恐怕没人会感兴趣的。\n");
	}
	return 1;
}

int do_pawn(string arg)
{
	string outstring="";
	object ob;
	string term,*terms, *vterms/*, *fterms*/;
	string data, p_c,capa;
	int value/*, pawn_count=0*/, i,j, k, extra;
//	int rvalue;
	mapping pawn,vpawn,fpawn;
	object me;
	me = this_player();
	pawn = me->query_pawn();
        vpawn = me->query_vpawn();
        fpawn = me->query_fpawn();

	if( !arg || !(ob = present(arg, this_player())) )
	{
	
	capa = "（"+ sizeof(vpawn)+"/"+ (this_player()->query("marks/pawn_expansion")+ MAX_PAWN+1)+"）";
		
	write( HIY"┌─────────┐"NOR + HIR"　目前典当物品"+capa+NOR + HIY" ┌─────────┐\n"NOR
	     + HIY"├─────────┘"NOR + HIR"～～～～～～～～～～～～"NOR + HIY"└─────────┤\n"NOR);
//	write("你目前典当的物品有：	（赎银为物品价值的75%）\n");
	if( !mapp(pawn) ||   !sizeof(pawn) )
		write("\t没有任何典当的物品。\n");
	else {
                        terms = keys(pawn);
			vterms = keys(vpawn);
                        for(i=0; i<sizeof(terms); i++) {
        			// Adjust spacing due to ANSI code
        			k = 0;
				extra = 0;
				for(j=0; j<strlen(pawn[terms[i]]); j++) {
					if(pawn[terms[i]][j] == ESC[0]) {
						k = 1;	
					}
					if(k == 1) {
						extra++;
					}
					if(pawn[terms[i]][j] == 'm') {
						k = 0;	
					}
				}					      			
        			outstring =sprintf("%s%s\t%-5s：  %-*s  价值：%-25s%s\n", 
        					outstring, 
        					HIY"│"NOR,
        					terms[i], 
        					16+extra,
        					pawn[terms[i]],
						MONEY_D->value_string(vpawn[vterms[i]]),
						HIY"│"NOR);
        		}
        		this_player()->start_more("", outstring, 0);
        		write(HIY"│								  │\n"	
        			+"└─────────"CYN" （赎银为物品价值的75%）"HIY"───────────┘\n"NOR);
              }
	return 1;
	}
	
	if (ob->query("thief_obj"))
	{
		call_out( (: call_other, MONEY_D, "arresthim", this_player() :), 3);
		this_player()->perform_busy(2);
		return notify_fail("你感觉有点不对劲，好像周围有人紧紧地盯住了你。\n");
	}
	
	if( ob->query("money_id") )	return notify_fail("你要当「钱」？\n");
	if (ob->query("no_pawn"))
	{
		return notify_fail("你不可以当这样东西。\n");
	}
	
	if (ob->query("item_damaged"))
		return notify_fail(this_object()->name()+"说：“本店不收购坏了的东西。”\n");
	
	value = ob->query("value");
	if( !(value/4) ) return notify_fail("这样东西并不值很多钱。\n");
        if( mapp(pawn) && sizeof(pawn))
                {
                        terms = keys(pawn);
			vterms = keys(vpawn);
                        if(sizeof(vterms) > MAX_PAWN + this_player()->query("marks/pawn_expansion"))
                        return notify_fail("你已典当太多物品了。\n");
                }
        if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成，不能典当物品。\n");
// to make life more realistic
	if( ((int)this_object()->query("richness")) < (value*25/100))
		return notify_fail(sprintf("%s的现钱已经不够了．．．\n",this_object()->name()));
	this_object()->add("richness",-(value*25/100));
	term = ob->query("name");
	data = base_name(ob)+ ".c";
	p_c = sprintf("%d",time()%10000);
	me->set_pawn(p_c, term);
        me->set_vpawn(p_c, value);
        me->set_fpawn(p_c, data);

	me->save();
	message_vision("$N把身上的" + ob->query("name") + "拿出来典当了"
		+ MONEY_D->money_str(value * 25 / 100) + "。\n", this_player());

	MONEY_D->pay_player(this_player(), value * 25 / 100 );
	ob->move(VOID_OB);
	destruct(ob);
	me->start_busy(1);
	return 1;
}


int do_sell(string arg)
{
	object ob;
	int value,old, amount;
	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("你要卖断什麽物品？\n");
        if( this_player()->is_busy() )
                return notify_fail("你上一个动作还没有完成，不能卖物品。\n");
	if (ob->query("thief_obj"))
	{
		call_out( (: call_other, MONEY_D, "arresthim", this_player() :), 3);
		this_player()->perform_busy(2);
		return notify_fail("你感觉有点不对劲，好像周围有人紧紧地盯住了你。\n");
	}
	if( ob->query("money_id") )	return notify_fail("你要卖「钱」？\n");
	value = ob->query("value");
        
        if (ob->query("no_sell")|| ob->query("no_drop")||ob->query("no_transfer"))
	       	return notify_fail("你不可以卖这样东西。\n");
	       	
        if( value<4)       	
        	 return notify_fail("这样东西并不值很多钱。\n");
	
	if (ob->query("item_damaged"))
		return notify_fail(this_object()->name()+"说：“本店不收购坏了的东西。”\n");
		
// to make life more realistic
        if( ((int)this_object()->query("richness")) < (value*80/100))
                return notify_fail(sprintf("%s的现钱已经不够了．．．\n",this_object()->name()));
        this_object()->add("richness",-(value*80/100));

	if (this_player()->query_temp("timer/sale")+2 > time())
		return notify_fail(this_object()->name()+"堆笑道：“客官稍候，马上就来招呼！”\n");
	this_player()->set_temp("timer/sale",time());

	message_vision("$N把身上的" + ob->query("name") + "卖掉。\n",
		this_player());
	old = this_object()->query_with_slash("vendor_goods."+base_name(ob));
// modified combined and throwing items. If the amount>base volumn, then calculate it and put
// in inventory, otherwise disgard it.	-- by Silencer 12/19/2002
	amount = ob->query("base_unit")? 
		 ob->query_amount()/ob->query_volumn():
		 1;
	if (amount)
		this_object()->set_with_slash("vendor_goods."+base_name(ob), old + amount);
	
	MONEY_D->pay_player(this_player(), value  * 80 / 100);
	ob->move(VOID_OB);
	destruct(ob);
//	this_player()->start_busy(1);	用timer代替busy，每一秒钟交易一次。
	return 1;
}


int do_redeem(string arg)
{
        string num;
        int amount;
        string ob_file;
        object ob;
        int obnum;
        object me;
	string /*term,*/ *terms;
	mapping pawn,vpawn,fpawn;
        int afford;
        if( !arg || sscanf(arg, "%s", num)!=1 )
                return notify_fail("指令格式：redeem <物品标号>\n");
        me = this_player();
        if( this_player()->is_busy() )
                return notify_fail("你上一个动作还没有完成，不能赎物品。\n");
	pawn = me->query_pawn();
	vpawn=me->query_vpawn();
	fpawn=me->query_fpawn();
	
	if (!mapp(pawn) || !mapp(fpawn) || !mapp(vpawn))
		return notify_fail("你没有典当任何物品。\n");
		
	terms = keys(vpawn);
	amount = (int) vpawn[arg];
        if( !amount )
                return notify_fail("有这个物品标号吗？\n");
        amount = amount * 3 /4;
        if( afford = MONEY_D->affordable(me, amount) ) {
			ob_file = fpawn[arg];
            ob = new(ob_file);

			// SOmetimes items are deleted
			if (!ob) {
				me->delete_pawn(arg);
				me->delete_vpawn(arg);
				me->delete_fpawn(arg);
				me->save();
				tell_object(me, "游戏变动，该物品在系统内已经不存在了，自动消除纪录。\n");
				return 1;
			}	

//                ob->set_amount(1);
// changed by karry 2002.5.13  当多少赎多少
            ob->query("base_unit")?((amount*100/75)/ob->query("base_value")<1?obnum=1:obnum=(amount*100/75)/ob->query("base_value")):obnum=1;
            ob->set_amount(obnum);
            if (ob->move(me)) {
				if (ob->query("no_transfer"))
				{
					ob->set("no_drop",1);	
				}	
				me->delete_pawn(arg);
	            me->delete_vpawn(arg);
	            me->delete_fpawn(arg);
		// to make life more realistic
		        this_object()->add("richness",amount);
		        	
		        	// CREDIT CARD
			    if (me->query("env/e_money")) {
					MONEY_D->charge_him(me,amount);
				} else
				{
					MONEY_D->pay_him(me, afford-amount);
				}
		        	
				me->save();
	            message_vision("$N赎回了$n。\n", me, ob);
	            return 1;
	        }
            else  {
               	destruct(ob);
               	return notify_fail("现在没办法赎回来。\n");
            }
                
        } else
            return notify_fail("你的钱不够。\n");
		me->start_busy(1);
}