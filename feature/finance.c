// finance.c
// abandoned by Tie
// can_afford() checks if this_object() can afford a price, it returns:
//
//      0:      cannot afford.
//      1:      can afford with proper money(coins).
//      2:      can afford, but don't have enough proper money(coins).
//

string money_str(int amount) {
	string c_money;
	int i_gold, i_silver, i_coin;
	i_gold = amount / 10000;
	i_silver = (amount%10000)/100;
	i_coin = (amount%100);
	if (i_coin)
		c_money = chinese_number(i_coin) + "文钱  ";
	else c_money = "  ";
	if (i_silver)
		c_money = chinese_number(i_silver) + "两银子  " + c_money;
	if (i_gold ) 
		 c_money = chinese_number(i_gold) + "两黄金  " + c_money;
	return c_money;
}



string value_string(int value)
{
	if( value < 1 ) value = 1;
	else if( value < 100 )
		return chinese_number(value) + "文钱";
	else
		return chinese_number(value/100) + "两"
			+ (value%100? "又" + chinese_number(value%100) + "文钱": "");
}


void pay_player(object who, int amount)

{
	object ob;

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

int affordable(object me, int amount)
{
        int total;
        object cash, tencash, gold, silver, coin;
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


int can_afford(int amount)
{
        int total;
        object cash, tencash, gold, silver, coin;

	tencash = present("tenthousand-cash_money");
	cash = present("thousand-cash_money");	
        gold = present("gold_money");
        silver = present("silver_money");
        coin = present("coin_money");

        total = 0;
	if( tencash) total += tencash->value();
	if( cash) total += cash->value();
        if( gold ) total += gold->value();
        if( silver ) total += silver->value();
        if( coin ) total += coin->value();

        if( total < amount ) return 0;

        return 1;
}

int pay_all(int amount)
{
        int total;
        object cash, tencash, gold, silver, coin;
	string debug;
        tencash = present("tenthousand-cash_money");
        cash = present("thousand-cash_money");
        gold = present("gold_money");
        silver = present("silver_money");
        coin = present("coin_money");
        total = 0;
        if( tencash) total += tencash->value();
	debug = sprintf("tencash is %d\n", total);
	write(debug);
        if( cash) total += cash->value();
        debug = sprintf("cash is %d\n", total);
        write(debug);
        if( gold ) total += gold->value();
        debug = sprintf("gold is %d\n", total);
        write(debug);
        if( silver ) total += silver->value();
        debug = sprintf("silver is %d\n", total);
        write(debug);
        if( coin ) total += coin->value();
        debug = sprintf("coin is %d\n", total);
        write(debug);
	debug = sprintf("total is %d, amount is %d, and change is %d",
			total, amount, total-amount);
	write(debug);
	return total-amount;
}

