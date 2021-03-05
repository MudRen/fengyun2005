#include <ansi.h>
inherit __DIR__"annieitem";

#define MAX_ITEM 9

void create()
{
	set_name("黑色的大箱子", ({ "black case"}) );	// 让这个id有别于其他东西。不使用单字id!
	set_weight(30000);
	set("prep","on");
	set("unit", "个");
	set("desc", "这个箱子用来存放特殊物件。使用指令为：
Stack：	将物品放入黑色的大箱子
	不带参数时察看箱内物品的编号
Retrieve：从大箱子里取出某编号的物品
Dispose：　从大箱子中销毁某编号的物品
\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","r");
	set("size",1);
	set("lore_item",1);
	set("value", 500000);
set("tax",10);
set("score_tax",10);
set("max_item",MAX_ITEM);
	seteuid(getuid());
}

void init()
{
	::init();
	if (environment() != this_player())
	{
		// add special action here.
        if (environment()->is_owner(this_player()->query("id"))) {
	        add_action("do_pawn", "stack");
	        add_action("do_expand","expand");
	        add_action("do_redeem1", "retrieve");
	        add_action("do_redeem2", "dispose");
		}
	}
}

int reset_item_list(object dest)
{
	return 1;
}

int do_expand(string arg){
	
	object env, item, me;
	string deco;
	me = this_player();
	
	if (!arg)
		return notify_fail("你想加什么附件?？\n");
		
	if (arg != "black tanmu")
		return notify_fail("你只能用家具店出售的黑檀木。\n");
	
	item = present(arg, me);
	if (!item)
		return notify_fail("你身上没有这件物品。\n");
		
	if (item->query("item_type")!= "xx")
		return notify_fail("你只能用家具店出售的黑檀木来扩容。\n");
	
	env = environment();
	
	if (query("extra_blackcase_size") >= 20)
		return notify_fail("大黑箱子已经不能再扩容了。\n");
	
	message_vision("$N拿起"+item->name()+"丁丁当当地敲打了一阵，大黑箱子变得更大了。\n", me);
	
	environment()->add("extra_blackcase_size",5);
	environment()->save();
	destruct(item);
	return 1;
	
}

int do_pawn(string arg)
{
	string outstring="";
	object ob;
	string term,*terms, *vterms, *fterms;
	string data, p_c,capa;
	int value, pawn2_count=0, i,j, k, extra;
	int rvalue;
	mapping pawn2,vpawn2,fpawn2;
	object me;
	me = this_player();
	pawn2 = me->query_pawn2();
	vpawn2 = me->query_vpawn2();
	fpawn2 = me->query_fpawn2();

	if( !arg || !(ob = present(arg, this_player())) )
	{
	if( !mapp(pawn2) ||   !sizeof(pawn2) )
		write("\t没有任何存放的物品。\n");
	else {
		terms = keys(pawn2);
		vterms = keys(vpawn2);	
		capa = "（"+ sizeof(terms)+"/"+ (environment()->query("extra_blackcase_size")+MAX_ITEM+1)+"）";	
			
			write( HIY"┌─────────┐"NOR + HIR" 目前存放的物品"+ capa + NOR + HIY"┌─────────┐\n"NOR
	     		+ HIY"├─────────┘"NOR + HIR"～～～～～～～～～～～～"NOR + HIY"└─────────┤\n"NOR);
                    
                for(i=0; i<sizeof(terms); i++) {
        			// Adjust spacing due to ANSI code
        			k = 0;
				extra = 0;
				for(j=0; j<strlen(pawn2[terms[i]]); j++) {
					if(pawn2[terms[i]][j] == ESC[0]) {
						k = 1;	
					}
					if(k == 1) {
						extra++;
					}
					if(pawn2[terms[i]][j] == 'm') {
						k = 0;	
					}
				}					      			
        			outstring =sprintf("%s%s\t%-5s：  %-*s  价值：%-25s%s\n", 
        					outstring, 
        					HIY"│"NOR,
        					terms[i], 
        					16+extra,
        					pawn2[terms[i]],
						MONEY_D->value_string(vpawn2[vterms[i]]),
						HIY"│"NOR);
        		}
        		this_player()->start_more("", outstring, 0);
        		write(HIY"│								  │\n"NOR);
        		write(HIY"│"NOR "察看（stack）放入（stack 物品英文名）				  "HIY"│\n"NOR);
        		write(HIY"│"NOR "取出（retrieve 物品编号）永久销毁（dispose 物品编号）		  "HIY"│\n"NOR);
        		write(HIY"└─────────"CYN"────────────"HIY"───────────┘\n"NOR);
              	
              }
	return 1;
	}


	if( !ob->query("generate_item") )
		return notify_fail("你不可以存放这样东西。\n");
	if (ob->query("no_stack"))
		return notify_fail("你不可以存放这样东西。\n");
	if (ob->query("no_drop"))
		return notify_fail("你不可以存放这样东西。\n");
	
       if( mapp(pawn2) && sizeof(pawn2))
                {
                        terms = keys(pawn2);
			vterms = keys(vpawn2);
                        if(sizeof(vterms) > MAX_ITEM+environment()->query("extra_blackcase_size"))
                        return notify_fail("你已存放太多物品了。\n");
                }
        if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成，不能存放物品。\n");
// to make life more realistic
	term = ob->query("name");
	data = base_name(ob)+ ".c";
	p_c = sprintf("%d",time()%10000);
	me->set_pawn2(p_c, term);
        me->set_vpawn2(p_c, 1);
        me->set_fpawn2(p_c, data);
   ob->unequip();
	me->save();
	message_vision("$N把身上的" + ob->query("name") + "放进黑色的大箱子中" + "。\n", this_player());

	ob->move(VOID_OB);
	destruct(ob);
	me->start_busy(1);
	return 1;
}




int do_redeem1(string arg)
{
        string num;
        int amount;
        string ob_file;
        object ob;
        int obnum;
        object me;
	string term, *terms;
	mapping pawn,vpawn,fpawn;

	object *inv;
	int i;

        int afford;
        if( !arg || sscanf(arg, "%s", num)!=1 )
                return notify_fail("指令格式：retrieve <物品标号>\n");
        me = this_player();
        if( this_player()->is_busy() )
                return notify_fail("你上一个动作还没有完成，不能取物品。\n");
	pawn = me->query_pawn2();
	vpawn=me->query_vpawn2();
	fpawn=me->query_fpawn2();
	
	if (!mapp(pawn) || !mapp(fpawn) || !mapp(vpawn))
		return notify_fail("你没有典当任何物品。\n");
	
	terms = keys(vpawn);
	amount = (int) vpawn[arg];
	if( !amount )
			return notify_fail("有这个物品标号吗？\n");
amount = amount * 3 /4;
	
	ob_file = fpawn[arg];
	ob = new(ob_file);

	inv=all_inventory(me);
			for(i=0;i<sizeof(inv);i++)
				if(ob->query("name")==inv[i]->query("name"))
					return notify_fail("这样东西你最多只能有一件。\n");

	if (ob->move(me)) {
	ob->set("no_drop",1);	
	ob->set("no_sell",1);	
	ob->set("no_stack",1);	
	ob->set("no_drop",1);

	me->save();
	message_vision("$N取出了一个$n。\n", me, ob);
	return 1;
	}
	else  {
		destruct(ob);
		return notify_fail("你身上的东西太多了……\n");
	}
	return 1;
}


int do_redeem2(string arg)
{
        string num;
        int amount;
        string ob_file;
        object ob;
        int obnum;
        object me;
	string term, *terms;
	mapping pawn,vpawn,fpawn;
        int afford;
        if( !arg || sscanf(arg, "%s", num)!=1 )
                return notify_fail("指令格式：dispose <物品标号>\n");
        me = this_player();
        if( this_player()->is_busy() )
                return notify_fail("你上一个动作还没有完成，不能销毁物品。\n");
	pawn = me->query_pawn2();
	vpawn=me->query_vpawn2();
	fpawn=me->query_fpawn2();
	
	if (!mapp(pawn) || !mapp(fpawn) || !mapp(vpawn))
		return notify_fail("你没有典当任何物品。\n");
		
	terms = keys(vpawn);
	amount = (int) vpawn[arg];
	if( !amount )
			return notify_fail("有这个物品标号吗？\n");
amount = amount * 3 /4;
	
	ob_file = fpawn[arg];
     ob = new(ob_file);

			me->delete_pawn2(arg);
			me->delete_vpawn2(arg);
			me->delete_fpawn2(arg);

	me->save();
	message_vision("$N销毁了存放在黑色的大箱子里的$n。\n", me, ob);
   	destruct(ob);
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
