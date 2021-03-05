/*


  )(    夕颜家居
  ~~ 简约.时尚.典雅

*/



// 你必须有一把旱烟枪才可以塑造这个雕像。
// 草药田，粉刷组件
// sign & flag bug: print flag IWant 天

// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("夕颜", ({ "xi yan","xiyan" }) );
	set("title","风解云裳");
	set("attitude", "friendly");
	set("class","moon");
	set("long","风云家具店老板娘，端的是货源充足。\n");
	set("gender", "女性" );
//	set("price_modifier",30);
	set("age", 22);
	set("per", 56);
	
	set("no_arrest",1);
	set("NO_KILL","对一介弱女子你也下得了手？\n");

    set("vendor_goods", ([
		__DIR__"obj/remodel_contract": 10,
		__DIR__"obj/payoff_contract": 10,
		__DIR__"obj/emergency.c" : 10, 
		__DIR__"obj/atm.c" : 10, 
		__DIR__"obj/jasperbed.c" : 10, 
		__DIR__"obj/lake.c" : 10, 
		__DIR__"obj/pond.c" : 10, 
		__DIR__"obj/pool.c" : 10, 
		__DIR__"obj/pendant":	10,
		__DIR__"obj/statue.c"  : 10, 
		__DIR__"obj/sign.c"  : 10, 
		__DIR__"obj/sandbag_inst.c"  : 10, 
		__DIR__"obj/pumpkinfarm.c"  : 10, 
		__DIR__"obj/groundnutbonsai.c"  : 10, 
		__DIR__"obj/cactusbonsai.c"  : 10, 
		__DIR__"obj/shed_grape.c"  : 20, 
		__DIR__"obj/fatangel.c"  : 100, 
		__DIR__"obj/stackfield_tiny":	10,
		__DIR__"obj/emergency_tanmu":	10,

/*		
__DIR__"obj/statuette_ruby.c" : 10, 
__DIR__"obj/statuette_sapphire.c" : 10, 
__DIR__"obj/emergency.c" : 10, 
__DIR__"obj/altar.c" : 10, 
__DIR__"obj/atm.c" : 10, 
__DIR__"obj/bookcase_big.c" : 10, 
__DIR__"obj/bookcase_small.c" : 10, 
__DIR__"obj/dressingcabinet.c" : 10, 
__DIR__"obj/fountain.c" : 10, 
__DIR__"obj/ivorybed.c" : 10, 
__DIR__"obj/jasperbed.c" : 10, 
__DIR__"obj/lake.c" : 10, 
__DIR__"obj/magazine.c" : 10, 
__DIR__"obj/mini_pagoda.c" : 10, 
__DIR__"obj/pavilion.c" : 10, 
__DIR__"obj/pond.c" : 10, 
__DIR__"obj/pool.c" : 10, 
__DIR__"obj/rockery.c" : 10, 
__DIR__"obj/stackfield_large.c" : 10, 
__DIR__"obj/stackfield_medium.c" : 10, 
__DIR__"obj/stackfield_tiny.c" : 10, 
__DIR__"obj/statuette_beryl.c" : 10, 
__DIR__"obj/statuette_coral.c" : 10, 
__DIR__"obj/statuette_ivory.c" : 10, 
__DIR__"obj/statuette_ruby.c" : 10, 
__DIR__"obj/statuette_sapphire.c" : 10, 
__DIR__"obj/swing.c" : 10, 
__DIR__"obj/tablewarecabinet_indoors.c" : 10, 
__DIR__"obj/tablewarecabinet_outdoors.c" : 10, 
__DIR__"obj/wardrobe_big.c" : 10, 
__DIR__"obj/wardrobe_small.c" : 10, 
__DIR__"obj/well.c" : 10, 
__DIR__"obj/woodcase_big.c" : 10, 
__DIR__"obj/woodcase_medium.c" : 10, 
__DIR__"obj/woodcase_small.c"  : 10, 
		
__DIR__"obj/statue.c"  : 10, 
__DIR__"obj/sign.c"  : 10, 
__DIR__"obj/flag.c"  : 10, 
__DIR__"obj/herbfield.c"  : 10, 
__DIR__"obj/sandbag_inst.c"  : 10, 
__DIR__"obj/sandbag2_inst.c"  : 10, 
__DIR__"obj/sandbag3_inst.c"  : 10, 

__DIR__"obj/pumpkinfarm.c"  : 10, 
__DIR__"obj/strawberrylawn.c"  : 10, 
__DIR__"obj/bilberrylawn.c"  : 10, 
__DIR__"obj/groundnutbonsai.c"  : 10, 
__DIR__"obj/cactusbonsai.c"  : 10, 
__DIR__"obj/figbonsai.c"  : 10, 
__DIR__"obj/tree_lemon.c"  : 10, 
__DIR__"obj/tree_apricot.c"  : 10, 
__DIR__"obj/tree_olive.c"  : 10, 
__DIR__"obj/shed_ivy.c"  : 10, 
__DIR__"obj/stool.c"  : 10, 
__DIR__"obj/winebarrel.c"  : 10, 
__DIR__"obj/fatangel.c"  : 100, 
*/		
	]) );
	setup();

	carry_object(__DIR__"obj/longskirt")->wear();

}


void init()
{
	::init();
	add_action("do_vendor_list","list");
	add_action("do_buy","buy");
/*	add_action("do_nothing","call");
	add_action("do_nothing","more");
	add_action("do_nothing","info");
	add_action("do_nothing","edit");
	add_action("do_nothing","tail");
	add_action("do_nothing","update");
	add_action("do_nothing","localcmds");
	add_action("do_nothing","dest");
	add_action("do_test","test");
	add_action("do_test2","test2");
	add_action("do_test3","test3");*/

}

int do_buy(string arg)
{
	if ("/cmds/std/buy"->main(this_player(),arg))
//		add("price_modifier",10);
		add("price_modifier",0);
	else
	{
		this_player()->delete_temp("timer/buy");
		return 0;
	}
	return 1;
}

int do_nothing(string arg)
{
	if (this_player()->query("id") == "mingyue")
		return 0;

	write("这条指令已经被废除了。\n");
	return 1;
}

int do_test2_1(int count)
{
	string *msg=({
 "/d/shaolin/yangxing",
 "/d/shaolin/tayuan",
 "/d/shaolin/yonglu",
	});
	int i;
	object room,killer;

	if (!room = find_object(msg[count]))
		room = load_object(msg[count]);
	for (i=0; i<10; i++)
	{
		killer = new("/d/bashan/mazenpc/killer5");
		killer->move(room);
	}
	if (count < 3)
		call_out("do_test2_1",1,count+1);
	return 1;
}

int do_test2(string arg)
{
	int i;
	object room,killer;
	string msg;
	if (!wizardp(this_player()))
		return 0;
	set_name("高猛", ({ "gao meng" }) );
	ccommand("chat 紧那罗部众集结听令，一刻时后血洗少林！");
	set_name("清辉", ({ "qing hui" }) );
	call_out("do_test2_1",450,0);
	return 1;
}

int do_test(string arg)
{
	int i;
	string str;
	if (!wizardp(this_player()))
		return 0;
	if (!arg)
		return notify_fail("Give me ur string.\n");
	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);
	str = arg;
	arg=crypt(str,19880120);
	write(arg+"\n");
	write(crypt(str,arg));
	return 1;
}



int do_test3(string arg)
{
	int i;
	string str;
	if (!wizardp(this_player()))
		return 0;
	write(crypt(arg,0)+"\n");
	return 1;
}

void reset(){
	    set("vendor_goods", ([
		__DIR__"obj/remodel_contract": 10,
		__DIR__"obj/payoff_contract": 10,
		__DIR__"obj/emergency.c" : 10, 
		__DIR__"obj/atm.c" : 10, 
		__DIR__"obj/jasperbed.c" : 10, 
		__DIR__"obj/lake.c" : 10, 
		__DIR__"obj/pond.c" : 10, 
		__DIR__"obj/pool.c" : 10, 
		__DIR__"obj/pendant":	10,
		__DIR__"obj/statue.c"  : 10, 
		__DIR__"obj/sign.c"  : 10, 
		__DIR__"obj/sandbag_inst.c"  : 10, 
		__DIR__"obj/pumpkinfarm.c"  : 10, 
		__DIR__"obj/groundnutbonsai.c"  : 10, 
		__DIR__"obj/cactusbonsai.c"  : 10, 
		__DIR__"obj/pumpkinfarm.c"  : 10, 
		__DIR__"obj/fatangel.c"  : 10, 
		__DIR__"obj/shed_grape.c"  : 10, 
		__DIR__"obj/stackfield_tiny":	10,
		__DIR__"obj/emergency_tanmu":	10,
		]));
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

