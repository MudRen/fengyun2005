#include <ansi.h>
inherit __DIR__"annieitem";

void create()
{
	set_name("飘舞大旗", ({ "big flag"}) );	// 让这个id有别于其他东西。不使用单字id!
	set_weight(30000);
	set("unit", "面");
	set("desc", "一面迎风招展，猎猎作响的大旗。\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","p");
	set("lore_item",1);
	set("outdoors",1);
	set("size",1);
	set("value", 50000);
set("tax",5);
set("score_tax",2);
	seteuid(getuid());
}

void init()
{
	::init();
	if (environment() != this_player())
	   	add_action("do_print","print");
}

int do_print(string arg)
{
	object obj, tarobj, tempobj;
	string sheet, target,color;
	object me = this_player(),env=environment(me),ob=this_object();

	if( !arg || sscanf(arg, "%s - %s %s", target,color,sheet)!=3 )
		return notify_fail("指令格式：print <目标> - <颜色> <文字>\n");
	if (present(target,env) != ob)
		return 0;
	if (!env->is_owner(me->query("id")))
		return notify_fail("屋子里的物件只有主人才能使用。\n");
	if (!CHINESE_D->check_chinese(sheet))
		return notify_fail("只有中文才适合题字耶．．．\n");
	if( strlen(sheet) > 14 ) {
		return notify_fail("旗上的地方不够大，写不下这么多文字。\n");
	}
	sheet = color + sheet;
	sheet = replace_string(sheet, "$BLK$", BLK);
	sheet = replace_string(sheet, "$RED$", RED);
	sheet = replace_string(sheet, "$GRN$", GRN);
	sheet = replace_string(sheet, "$YEL$", YEL);
	sheet = replace_string(sheet, "$BLU$", BLU);
	sheet = replace_string(sheet, "$MAG$", MAG);
	sheet = replace_string(sheet, "$CYN$", CYN);
	sheet = replace_string(sheet, "$WHT$", WHT);
	sheet = replace_string(sheet, "$HIR$", HIR);
	sheet = replace_string(sheet, "$HIG$", HIG);
	sheet = replace_string(sheet, "$HIY$", HIY);
	sheet = replace_string(sheet, "$HIB$", HIB);
	sheet = replace_string(sheet, "$HIM$", HIM);
	sheet = replace_string(sheet, "$HIC$", HIC);
	sheet = replace_string(sheet, "$HIW$", HIW);
	sheet = replace_string(sheet, "$NOR$", NOR);
	sheet = sheet+NOR;

	if (me->query_skill("literate") == 150)
		message_vision(CYN"$N大笔一挥，在旗上龙飞凤舞的题下几个大字："+sheet+CYN"。\n"NOR,me);
	else
		message_vision(CYN"$N大笔一挥，在旗上歪歪扭扭的题下几个大字："+sheet+CYN"。\n"NOR,me);
	set("text",sheet);
	set("desc", "一面迎风招展，猎猎作响的大旗，飘扬中依稀可以见到大旗上写的是：\n\n\t\t\t"+query("text")+"\n\n");
	reset_item_list(env);
	return 1;
}

int restore_item()
{
	object item;
	mapping item_list,mitem;
	string *lists,str;
	int i,idx;

	item_list = environment()->query("stock_"+query("item_type"));
	if (!environment()->query("stock_"+query("item_type")+"/text"))
		return 1;
	// 没有任何文字。
	set("text",environment()->query("stock_"+query("item_type")+"/text"));
	set("desc", "一面迎风招展，猎猎作响的大旗，飘扬中依稀可以见到大旗上写的是：\n\n\t\t\t"+environment()->query("stock_"+query("item_type")+"/text")+"\n\n");
	return 1;
}

int reset_item_list(object dest)
{
	environment()->set("stock_"+query("item_type")+"/text",query("text"));
	environment()->save();
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
