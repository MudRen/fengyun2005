// Moneyd.c -- by Silencer@fy4 workgroup
// I put these functions into daemon since they have more use than banker/pawner.
// Adding Creditcard to solve carry issues  1/11/2006

#include <dbase.h>
#include <ansi.h>

//   转化成 9 两黄金 9 两银子 10 文钱
string money_str(int amount) {
	string c_money;
	int i_gold, i_silver, i_coin;
	i_gold = amount / 10000;
	i_silver = (amount%10000)/100;
	i_coin = (amount%100);
	if (i_coin)
		c_money = chinese_number(i_coin) + "文钱";
	else c_money = "";
	if (i_silver)
		c_money = chinese_number(i_silver) + "两银子" + c_money;
	if (i_gold ) 
		 c_money = chinese_number(i_gold) + "两黄金" + c_money;
	return c_money;
}

//   转化成 九十九两银子 十文钱
string value_string(int value)
{
	if( value < 1 ) value = 1;
	else if( value < 100 )
		return chinese_number(value) + "文钱";
	else
		return chinese_number(value/100) + "两"
			+ (value%100? "又" + chinese_number(value%100) + "文钱": "");
}


//	付钱 --- 注意：5种货币不能保证移入(inventory MAX_LIMIT 限制)
//	flag = 1, 支取现钱, flag = 0, 允许 creditcard
varargs void pay_player(object who, int amount, int flag)

{
	object ob;

//	CREDIT_CARD	
	if (who->query("env/e_money")&& !flag){
		who->add("deposit",amount);
		tell_object(who,"你的银行里转入了"+money_str(amount)+"。\n");
		return;
	}		
		
	if( amount < 1 ) amount = 1;
        if( amount/1000000 ) {
                ob = new(TECASH_OB);
                ob->set_amount(amount/1000000);
                ob->move(who);
                amount %= 1000000;
        }
        if( amount/100000 ) {
                ob = new(THCASH_OB);
                ob->set_amount(amount/100000);
                ob->move(who);
                amount %= 100000;
        }
	if( amount/10000 ) {
		ob = new(GOLD_OB);
		ob->set_amount(amount/10000);
		ob->move(who);
		amount %= 10000;
	}
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
	if( amount ) {
		ob = new(COIN_OB);
		ob->set_amount(amount);
		ob->move(who);
	}
}


//	CREDIT_CARD	
void  charge_him(object who, int amount){
		who->add("deposit",-amount);	
		tell_object(who,"你的银行账户上转走了"+ money_str(amount)+"。\n");
}

//	买卖 --- 同上，不能保证一定成功。
//  其过程是摧毁所有金钱，然后给amount量的金钱。用于原来的付钱方式
void pay_him(object who, int amount)
{
//		object ob;
        object cash, tencash, gold, silver, coin;
        tencash = present("tenthousand-cash_money", who);
        cash = present("thousand-cash_money", who);
        gold = present("gold_money",who);
        silver = present("silver_money",who);
        coin = present("coin_money",who);
		if(tencash) destruct(tencash);
        if(cash) destruct(cash);
        if(gold) destruct(gold);
        if(silver) destruct(silver);
        if(coin) destruct(coin);
		pay_player(who, amount);
}


//	你有钱么？flag = 1 只检查身上, flag = 0 允许credit card 付账
varargs int affordable(object me, int amount,int flag )
{
        int total;
        object cash, tencash, gold, silver, coin;

//	CREDIT_CARD        
        if (me->query("env/e_money") && !flag){
        	total = me->query("deposit");
        	if (total < amount)	return 0;
        	return total;
    	}
        
        tencash = present("tenthousand-cash_money", me);
        cash = present("thousand-cash_money", me);
        gold = present("gold_money",me);
        silver = present("silver_money",me);
        coin = present("coin_money",me);
        total = 0;
        if( tencash) total += tencash->value();
        if( cash) total += cash->value();
        if( gold ) total += gold->value();
        if( silver ) total += silver->value();
        if( coin ) total += coin->value();
        if( total < amount ) return 0;
        return total;
}

//	黑市商品检测，建议以后加入更多可能。
void arresthim(object me)
{
	object *inv;
//	object npc;
	if (objectp(me))
	{
//		message_vision("$N突然冷笑道：“真是对不起这位"+RANK_D->query_respect(me)+"了，您的东西官差们要检查。”\n\n", npc);
		message_vision(HIR"暗中跳出来几个捕快对$N冷笑道：“等你好久了，跟爷们走一趟吧。”\n\n"NOR, me);
		tell_object(me,YEL"你心中大呼不妙，可后悔已太迟。\n");
		message_vision("捕快对$N冷笑道：“我们在这里追捕小偷已经很久了，乖乖跟我们走吧！” \n",me);
		message_vision("捕快将$N押向大牢。 \n\n"NOR,me);
		me->set("vendetta/authority", 1);
		me->move("/d/jinan/laofang1");
		message_vision(HIY"\n$N被搜空所有的东西，一脚踢进了牢房！\n"NOR,me);
		inv = all_inventory(me);
		for(int i=0; i<sizeof(inv); i++) 
		{
			if (inv[i]->query("id")=="treasure box")	
				inv[i]->do_qqsave(me);
        	else if (!inv[i]->query("no_drop"))
        		destruct(inv[i]);
		}
	}
	return;
}